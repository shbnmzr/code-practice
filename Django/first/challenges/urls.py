from django.urls import path
from . import views

urlpatterns = [
    # This routes to various urls inside the same app
    path("", views.index, name='index'),
    path("<int:month>", views.monthly_challenge_by_number),
    path("<str:month>", views.monthly_challenge, name='month-challenge'),

]
