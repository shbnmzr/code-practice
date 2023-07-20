from django.shortcuts import render, get_object_or_404
from .models import Post

# Create your views here.
def starting_page(request):
    latest_posts = Post.objects.all().order_by('-date')[:3]

    return render(request, 'blog/index.html', {
        "posts": latest_posts,
    })

def posts(request):
    posts_list = Post.objects.all().order_by('-date')
    return render(request, 'blog/all_posts.html', {
        "all_posts": posts_list,
    })

def post_details(request, slug):
    identified_post = get_object_or_404(Post, slug=slug)
    return render(request, "blog/post_details.html", {
        "post": identified_post,
        "tags": identified_post.tag.all()
    })