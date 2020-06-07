from django.db import models
from django.utils import timezone
from django import forms

class Livro(models.Model):
    
    titulo = models.CharField(max_length=50)
    autor = models.CharField(max_length=200)
    ano = models.IntegerField()
    editora = models.CharField(max_length=200)
    image =models.ImageField(upload_to="images/rcomendacao") 
    #image =models.FileField(upload_to="images/rcomendacao") 
    sinopse = models.CharField(max_length=1000)
    curtidas = models.IntegerField(default=1)


    def __str__(self):
        return self.titulo
        
        
class Usuario(models.Model):
    
    nome = models.CharField(max_length=15)
    senha = forms.CharField(widget=forms.PasswordInput())
   
    
    def __str__(self):
        return self.nome
