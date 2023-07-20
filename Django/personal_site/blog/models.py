from django.db import models
from django.utils.text import slugify
from django.core.validators import MinLengthValidator
# Post - Author - tag


# Create your models here.
class Author(models.Model):
    first_name = models.CharField(max_length=100)
    last_name = models.CharField(max_length=100)
    email = models.EmailField()

    def fullname(self):
        return f'{self.first_name} {self.last_name}'

    def __str__(self,):
        return self.fullname()

class Tag(models.Model):
    caption = models.CharField(max_length=20)

    def __str__(self,):
        return f'{self.caption}'

class Post(models.Model):
    title = models.CharField(max_length=100)
    slug = models.SlugField(unique=True, default='', null=True, db_index=True)
    excerpt = models.CharField(max_length=200)
    image = models.ImageField(upload_to='uploads/posts/', null=True)
    date = models.DateField(auto_now=True)
    content = models.TextField(validators=[MinLengthValidator(10)])
    # One-to-many relationship with Author table
    author = models.ForeignKey(Author, null=True, on_delete=models.SET_NULL, related_name='posts')

    # Many-to-many relationship with Tag table
    tag = models.ManyToManyField(Tag)

    def save(self, *args, **kwargs):
        self.slug = slugify(self.title)
        super().save(*args, **kwargs)

    def __str__(self,):
        return f'{self.title} {self.author} {self.tag}'
