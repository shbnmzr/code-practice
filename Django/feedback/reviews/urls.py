from django.urls import path
from . import views
urlpatterns = [
    path('', views.ReviewView.as_view()),
    path('thanks', views.ThankYouView.as_view()),
    path('all_reviews', views.AllReviewsView.as_view()),
    path('all_reviews/<int:pk>', views.SingleReviewView.as_view()),
]