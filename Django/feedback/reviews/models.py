from django.db import models

# Create your models here.
class Review(models.Model):
    name = models.CharField(max_length=100)
    email_address = models.EmailField()
    review = models.TextField()
    rating = models.IntegerField()
    

    def __str__(self,):
        return f'{self.name} says: {self.review}, and rates us {self.rating} / 5'
    