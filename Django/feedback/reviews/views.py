from typing import Any, Dict
from django.shortcuts import render
from django.http import HttpResponseRedirect
from .forms import ReviewForm
from .models import Review
from django.views import View
from django.views.generic.base import TemplateView
from django.views.generic import ListView, DetailView
from django.views.generic.edit import FormView, CreateView


# Create your views here.

## VIEW CLASS
# Class-based approach is cleaner -> Preferred
class ReviewView(CreateView):
    model = Review
    form_class = ReviewForm
    template_name = 'reviews/review.html'

    success_url = 'thanks'


# class ReviewView(FormView):
#     form_class = ReviewForm
#     template_name = 'reviews/review.html'
#     # Where to go on successful submission
#     success_url = 'thanks'

#     def form_valid(self, form):
#         form.save()
#         return super().form_valid(form)


#     # def post(self, request,):
#     #     form = ReviewForm(request.POST)

#     #     # 1) Validate inputs, 2) Populate a field with new data 
#     #     if form.is_valid():

#     #         # When ModelForm is used, this can be used to add data to the model
#     #         form.save()


#     #         ## When ModelForm is used there's no need to add data this way!!

#     #         # Dictionary containing new data
#     #         # review = Review(name=form.cleaned_data['name'],
#     #         #                 email_address = form.cleaned_data['email_address'],
#     #         #                 review = form.cleaned_data['review'],
#     #         #                 rating = form.cleaned_data['rating'])
            
#     #         # review.save()
#     #         return HttpResponseRedirect('thanks')


## VIEW FUNCTION
def review(request):
    if request.method == 'POST':
        form = ReviewForm(request.POST)

        # 1) Validate inputs, 2) Populate a field with new data 
        if form.is_valid():

            # When ModelForm is used, this can be used to add data to the model
            form.save()


            ## When ModelForm is used there's no need to add data this way!!

            # Dictionary containing new data
            # review = Review(name=form.cleaned_data['name'],
            #                 email_address = form.cleaned_data['email_address'],
            #                 review = form.cleaned_data['review'],
            #                 rating = form.cleaned_data['rating'])
            
            # review.save()
            return HttpResponseRedirect('thanks')
    else:
        form = ReviewForm()


    reviews = Review.objects.all()    
    return render(request, 'reviews/review.html', {
        'form': form,
        'reviews': reviews,
    })


class ThankYouView(TemplateView):
    template_name = "reviews/thanks.html"

    def get_context_data(self, **kwargs: Any) -> Dict[str, Any]:

        context = super().get_context_data(**kwargs)
        context['message'] = 'Thank you!'
        return context


class AllReviewsView(ListView):
    template_name = 'reviews/all_reviews.html'
    # Which model is to be fetched
    model = Review
    # The name to be used to access all data
    context_object_name = 'all_reviews'


class SingleReviewView(DetailView):
    template_name = 'reviews/single_review.html'
    model = Review

    # Which instance should be fetched -> pk
    