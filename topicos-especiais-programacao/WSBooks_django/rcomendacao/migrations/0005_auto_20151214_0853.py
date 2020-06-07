# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models, migrations


class Migration(migrations.Migration):

    dependencies = [
        ('rcomendacao', '0004_auto_20151214_0848'),
    ]

    operations = [
        migrations.AlterField(
            model_name='livro',
            name='image',
            field=models.ImageField(upload_to=b'images/rcomendacao'),
        ),
    ]
