from django.db import models

# Create your models here.
class UserProfileModel(models.Model):
    image = models.ImageField(upload_to='images')