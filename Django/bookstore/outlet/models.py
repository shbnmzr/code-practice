from django.db import models
from django.core.validators import MinValueValidator, MaxValueValidator
from django.urls import reverse
from django.utils.text import slugify

# Create your models here.
class Address(models.Model):
    street = models.CharField(max_length=50)
    city = models.CharField(max_length=50)

    def __str__(self,):
        return f'{self.street}, {self.city}'
    
    # Register Meta configurations
    class Meta:
        verbose_name_plural = 'Address Entries'

class Author(models.Model):
    first_name = models.CharField(max_length=100)
    last_name = models.CharField(max_length=100)

    # Setting a one-to-one relationship
    address = models.OneToOneField(Address, on_delete=models.CASCADE, null=True)

    def fullname(self,):
        return f'{self.first_name} {self.last_name}'

    def __str__(self,):
        return self.fullname()


class Book(models.Model):
    title = models.CharField(max_length=100)
    rating = models.FloatField(validators=[MinValueValidator(1), MaxValueValidator(10)])
    # CASCADE -> if an author is deleted, the book is deleted
    author = models.ForeignKey(Author, on_delete=models.CASCADE, null=True, related_name='book')
    is_best_seller = models.BooleanField(default=False)
    # editable -> The fields does not appear in the form
    # blank -> allows the fields to be blank
    slug = models.SlugField(default='', null=False, db_index=True)

    def get_absolute_url(self):
        return reverse("book_details", args=[
            self.slug
        ])
    
    def save(self, *args, **kwargs):
        self.slug = slugify(self.title)
        super().save(*args, **kwargs)

    def __str__(self):
        return f'Title: {self.title}, Author: {self.author}, Rating: {self.rating}, { self.is_best_seller }'