from typing import Any, Dict
from django.db.models.query import QuerySet
from django.shortcuts import render, get_object_or_404
from .models import Post
from django.views.generic import ListView, DetailView

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

class PostDetails(DetailView):
    template_name = 'blog/post_details.html'
    model = Post
    
    def get_context_data(self, **kwargs: Any) -> Dict[str, Any]:
        context = super().get_context_data(**kwargs)
        context['tags'] = self.object.tag.all()
        return context
