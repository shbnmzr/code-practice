from django.contrib import admin
from .models import Author, Post, Tag, Comment

# Register your models here.
class PostAdmin(admin.ModelAdmin):
    list_filter = ('author', 'tag', 'date')
    list_display = ('title', 'author', 'date')
    prepopulated_fields = {
        'slug': ('title',),
    }

admin.site.register(Author)
admin.site.register(Post, PostAdmin)
admin.site.register(Tag)
admin.site.register(Comment)
