from django.shortcuts import render
from django.http import HttpResponse, HttpResponseRedirect, Http404
from django.urls import reverse
# Create your views here.

months = {
    "january": 'Let\'s have a great year!',
    "february": 'Studying is fun',
    "march": 'Learn a new thing everyday',
    "april": 'Data is amusing',
    "may": 'It\'s great to be intelligent',
    "june": 'Eat healthy everyday',
    "july": 'Exercise regularly',
    "august": 'Maybe some fun stuff in August',
    "september": 'What a great year you have had so far',
    "october": None,
    "novermber": 'Practice Django',
    "december": 'Wrap up and get ready for christmas'
}


def index(request):
    month_names = list(months.keys())

    return render(request, 'challenges/index.html', {
        'months': month_names,
    })


# Dynamic Segments


def monthly_challenge(request, month):

    if month in months:
        challenge_text = months[month]
        return render(request, 'challenges/challenge.html', {
            'month_name': month,
            'text': challenge_text,
        })
    raise Http404()


def monthly_challenge_by_number(request, month):
    months_number = list(months.keys())
    redirection_path = reverse(
        'month-challenge', args=[months_number[month - 1]])
    # This redirects the request to its respective view without repetition
    return HttpResponseRedirect(redirection_path)
