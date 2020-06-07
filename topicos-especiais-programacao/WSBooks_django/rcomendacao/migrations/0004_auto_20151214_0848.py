# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models, migrations


class Migration(migrations.Migration):

    dependencies = [
        ('rcomendacao', '0003_auto_20151211_1743'),
    ]

    operations = [
        migrations.AlterField(
            model_name='livro',
            name='image',
            field=models.FileField(upload_to=b'images/rcomendacao'),
        ),
        migrations.AlterField(
            model_name='livro',
            name='sinopse',
            field=models.CharField(max_length=1000),
        ),
        migrations.AlterField(
            model_name='livro',
            name='titulo',
            field=models.CharField(max_length=50),
        ),
    ]
