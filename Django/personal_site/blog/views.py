from typing import Any, Dict
from django.db.models.query import QuerySet
from django.shortcuts import render, get_object_or_404
from .models import Post
from django.views.generic import ListView
from .forms import CommentForm
from django.views import View
from django.http import HttpResponseRedirect
from django.urls import reverse

# Create your views here.
class StaringPageView(ListView):
    template_name = 'blog/index.html'
    model = Post
    ordering = ['-date'] # How to order the list
    context_object_name = 'posts'

    def get_queryset(self) -> QuerySet[Any]:
        queryset = super().get_queryset()
        data = queryset[:3]
        return data


class Posts(ListView):
    template_name = 'blog/all_posts.html'
    ordering = ['-date']
    model = Post
    context_object_name = 'all_posts'


class PostDetails(View):
    
    def get(self, request, slug):
        post = Post.objects.get(slug=slug)
        context = {
            'post': post,
            'tags': post.tag.all(),
            'comment_form': CommentForm()
        }
        return render(request, 'blog/post_details.html', context)
    
    def post(self, request, slug):
        fetched_post = Post.objects.get(slug=slug)
        comment_form = CommentForm(request.POST)
        if comment_form.is_valid():
            comment = comment_form.save(commit=False)
            comment.corresponding_post = fetched_post
            comment.save()
            return HttpResponseRedirect(reverse('post_details_page', args=[slug]))
        
        context = {
            'post': fetched_post,
            'tags': fetched_post.tag.all(),
            'comment_form': CommentForm()
        }
        return render(request, 'blog/post_details.html', context)
