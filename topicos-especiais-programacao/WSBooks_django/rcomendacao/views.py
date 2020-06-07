from django.shortcuts import render
from models import Livro
from django.shortcuts import render, get_object_or_404, render_to_response
from .forms import LivroForm
from django.shortcuts import redirect
from django.contrib.auth.forms import UserCreationForm # Formulario de criacao de usuarios
from django.http import HttpResponseRedirect # Funcao para redirecionar o usuario
from django.contrib.auth.forms import AuthenticationForm # Formulario de autenticacao de usuarios
from django.contrib.auth import login # funcao que salva o usuario na sessa
from django.contrib.auth import logout # funcao que salva o usuario na sessa
from django.core.urlresolvers import reverse #delete


def index(request):
    return render_to_response("rcomendacao/index.html")



def livro_search(request):
    #livros = list(Livro.objects.all())
    livros= Livro.objects.all()
    var_get_search = request.GET.get('titulo')
    if var_get_search is not None:
        livros = livros.filter(titulo__icontains=var_get_search)
    
    return render(request, 'rcomendacao/livro_search.html', {'livros':livros})
    
    
def livro_list(request):
    livros = list(Livro.objects.all())
    livros.reverse()
    livros = livros[0:4]
    return render(request, 'rcomendacao/livro_list.html', {'livros':livros})
    
def livro_detail(request, pk):
    livro = get_object_or_404(Livro, pk=pk)
    
    return render(request, 'rcomendacao/livro_detail.html', {'livro': livro})
    
    
def livro_new(request):
    if request.method == "POST":
        form = LivroForm(request.POST, request.FILES)
        if form.is_valid():
            #handle_uploaded_file(request.FILES['image'])
            #return HttpResponseRedirect('/')

           livro = form.save(commit=False)
            #livro.author = request.user
           livro.save()
           return redirect('rcomendacao.views.livro_detail', pk=livro.pk)
    else:
        form = LivroForm()
        return render(request, 'rcomendacao/livro_edit.html', {'form': form})
    #    return render_to_response('rcomendacao/livro_edit.html', {'form': form})    
 
    
    
def livro_edit(request, pk):
    livro = get_object_or_404(Livro, pk=pk)
    if request.method == "POST":
        form = LivroForm(request.POST, instance=livro)
        if form.is_valid():
            livro = form.save(commit=False)
            #post.author = request.user
            livro.save()
            return redirect('rcomendacao.views.livro_detail', pk=livro.pk)
    else:
        form = LivroForm(instance=livro)
    return render(request, 'rcomendacao/livro_edit.html', {'form': form})
    
    
    # pagina de cadastro de jogador
def registrar(request):
    
    # Se dados forem passados via POST
    if request.method == 'POST':
        form = UserCreationForm(request.POST)
        
        if form.is_valid(): # se o formulario for valido
            form.save() # cria um novo usuario a partir dos dados enviados 
            return HttpResponseRedirect("/login/") # redireciona para a tela de login
        else:
            # mostra novamente o formulario de cadastro com os erros do formulario atual
            return render(request, "rcomendacao/registrar.html", {"form": form})
    
    # se nenhuma informacao for passada, exibe a pagina de cadastro com o formulario
    return render(request, "rcomendacao/registrar.html", {"form": UserCreationForm() })
    
    
    
# pagina de login do jogador
def logar(request):
    if request.method == 'POST':
        form = AuthenticationForm(data=request.POST) # Veja a documentacao desta funcao
        
        if form.is_valid():
            #se o formulario for valido significa que o Django conseguiu encontrar o usuario no banco de dados
            #agora, basta logar o usuario e ser feliz.
            login(request, form.get_user())
            return HttpResponseRedirect("/home/") # redireciona o usuario logado para a pagina inicial
        else:
            return render(request, "rcomendacao/logar.html", {"form": form})
    
    #se nenhuma informacao for passada, exibe a pagina de login com o formulario
    return render(request, "rcomendacao/logar.html", {"form": AuthenticationForm()})    
    
    
    
    
def logout_view(request):
    logout(request)
    return render(request, "rcomendacao/index.html", {"form": UserCreationForm() })
    
    
def handle_uploaded_file(f):
    with open('/image/name.txt', 'wb+') as destination:
        for chunk in f.chunks():
            destination.write(chunk)

    