# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models, migrations


class Migration(migrations.Migration):

    dependencies = [
        ('rcomendacao', '0002_auto_20151211_1721'),
    ]

    operations = [
        migrations.AlterField(
            model_name='livro',
            name='image',
            field=models.ImageField(upload_to=b'images/rcomendacao'),
        ),
        migrations.AlterField(
            model_name='livro',
            name='sinopse',
            field=models.CharField(max_length=200),
        ),
    ]
