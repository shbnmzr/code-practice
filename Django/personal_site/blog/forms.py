from django import forms
from .models import Comment

class CommentForm(forms.ModelForm):
    class Meta:
        model = Comment
        exclude = ['corresponding_post']
        label = {
            'author': 'Your Name',
            'comment_text': 'Your Comment',
        }
        