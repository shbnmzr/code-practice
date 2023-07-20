from django import forms
from .models import Review

# class ReviewForm(forms.Form):
#     name = forms.CharField(max_length=100, label='Your Name', error_messages={
#         'required': 'Your name must not be empty',
#         'max_length': 'Please enter a shorter name',
#     })
#     email_address = forms.EmailField(label='Your Email')
#     review = forms.CharField(label='Your Feedback', widget=forms.Textarea, max_length=1000)
#     rating = forms.IntegerField(label='Yout Rating', min_value=1, max_value=5)


# The form is inferred from the model
class ReviewForm(forms.ModelForm):
    class Meta():
        # The model to which this form is related
        model = Review

        # Which fields of the original model should be an input 
        fields = ['name', 'email_address', 'review', 'rating']
        labels = {
            'name': 'Your Name',
            'email_address': 'Your email',
            'review': 'What do you think?',
            'rating': 'Your Rating',
        }
        