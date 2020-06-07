# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models, migrations


class Migration(migrations.Migration):

    dependencies = [
        ('rcomendacao', '0001_initial'),
    ]

    operations = [
        migrations.AddField(
            model_name='livro',
            name='image',
            field=models.CharField(default=1, max_length=200),
            preserve_default=False,
        ),
        migrations.AlterField(
            model_name='livro',
            name='sinopse',
            field=models.ImageField(upload_to=b'images/rcomendacao'),
        ),
    ]
