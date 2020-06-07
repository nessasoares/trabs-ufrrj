# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models, migrations


class Migration(migrations.Migration):

    dependencies = [
        ('rcomendacao', '0005_auto_20151214_0853'),
    ]

    operations = [
        migrations.AddField(
            model_name='livro',
            name='curtidas',
            field=models.IntegerField(default=1),
        ),
    ]
