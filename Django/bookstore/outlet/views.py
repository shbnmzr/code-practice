from django.shortcuts import render
from django.http import Http404

from .models import Book
from django.db.models import Q, Avg

# Create your views here.
def index(request):
    all_books = Book.objects.all().order_by('-rating')
    total_count = all_books.count()
    avg_rating = all_books.aggregate(Avg('rating'))

    return render(request, 'outlet/index.html', {
        'all_books': all_books,
        'total_count': total_count,
        'avg_rating': avg_rating,
    })

def book_details(request, slug):
    if (book:= Book.objects.get(slug=slug)):
        return render(request, 'outlet/book_details.html', {
            'book_title': book.title,
            'book_author': book.author,
            'book_rating': book.rating,
            'is_best_seller': book.is_best_seller,
        })
    raise Http404()