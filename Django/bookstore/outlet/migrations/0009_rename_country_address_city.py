# Generated by Django 4.2.3 on 2023-07-17 07:39

from django.db import migrations


class Migration(migrations.Migration):

    dependencies = [
        ('outlet', '0008_alter_author_address'),
    ]

    operations = [
        migrations.RenameField(
            model_name='address',
            old_name='country',
            new_name='city',
        ),
    ]
