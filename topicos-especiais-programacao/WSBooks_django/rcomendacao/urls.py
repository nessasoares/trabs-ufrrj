from django.conf.urls import include, url
from . import views
from django.conf import settings
from django.conf.urls.static import static

urlpatterns = [
    url(r'^$', views.index),
    url(r'^livro/(?P<pk>[0-9]+)/$', views.livro_detail),
    url(r'^livro/new/$', views.livro_new, name='livro_new'),
    url(r'^livro/search/$', views.livro_search, name='livro_search'),
    url(r'^registrar/$', views.registrar, name='registrar'), # pagina de cadastro
    url(r'^login/$', views.logar, name='login'), # pagina de cadastro
    url(r'^login/$', views.logar, name='logout'), # pagina de cadastro
    url(r'^home/$', views.livro_list, name='home'), # pagina de cadastro
    url(r'^livro/(?P<pk>[0-9]+)/edit/$', views.livro_edit, name='livro_edit'),



]+ static(settings.MEDIA_URL, document_root=settings.MEDIA_ROOT)