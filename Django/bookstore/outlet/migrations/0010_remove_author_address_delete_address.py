# Generated by Django 4.2.3 on 2023-07-17 07:40

from django.db import migrations


class Migration(migrations.Migration):

    dependencies = [
        ('outlet', '0009_rename_country_address_city'),
    ]

    operations = [
        migrations.RemoveField(
            model_name='author',
            name='address',
        ),
        migrations.DeleteModel(
            name='Address',
        ),
    ]
