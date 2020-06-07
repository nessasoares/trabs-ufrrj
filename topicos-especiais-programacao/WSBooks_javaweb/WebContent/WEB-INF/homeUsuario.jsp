<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="description" content="">
    <meta name="author" content="">
    <title>Home | ***</title>
    <link href="multicolor-4/css/bootstrap.min.css" rel="stylesheet">
    <link href="multicolor-4/css/font-awesome.min.css" rel="stylesheet">
    <link href="multicolor-4/css/animate.min.css" rel="stylesheet"> 
    <link href="multicolor-4/css/lightbox.css" rel="stylesheet"> 
    <link href="multicolor-4/css/main.css" rel="stylesheet">
    <link href="multicolor-4/css/responsive.css" rel="stylesheet">

    <!--[if lt IE 9]>
        <script src="js/html5shiv.js"></script>
        <script src="js/respond.min.js"></script>
    <![endif]-->       
    <link rel="shortcut icon" href="multicolor-4/images/ico/favicon.ico">
    <link rel="apple-touch-icon-precomposed" sizes="144x144" href="multicolor-4/images/ico/apple-touch-icon-144-precomposed.png">
    <link rel="apple-touch-icon-precomposed" sizes="114x114" href="multicolor-4/images/ico/apple-touch-icon-114-precomposed.png">
    <link rel="apple-touch-icon-precomposed" sizes="72x72" href="multicolor-4/images/ico/apple-touch-icon-72-precomposed.png">
    <link rel="apple-touch-icon-precomposed" href="multicolor-4/images/ico/apple-touch-icon-57-precomposed.png">
</head><!--/head-->

<body>
    <header id="header">      
        
                
                  <div class="navbar navbar-inverse" role="banner">
            <div class="container">
                
                
                <div class="navbar-header">
                    <button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-collapse">
                        <span class="sr-only">Toggle navigation</span>
                        <span class="icon-bar"></span>
                        <span class="icon-bar"></span>
                        <span class="icon-bar"></span>
                    </button>

                    <a class="navbar-brand" href="homeUsuario.jsp">
                        <h1><img src="multicolor-4/images/logo.png" alt="logo"></h1>
                    </a>
                    
                     
                    
                </div>
                <div class="collapse navbar-collapse">
                    <ul class="nav navbar-nav navbar-right">
                        <li class="active"><a href="homeUsuario.jsp">Home</a></li>
                        <li class="dropdown"><a href="homeUsuario.jsp">Livros <i class="fa fa-angle-down"></i></a>
                            <ul role="menu" class="sub-menu">
                                <li><a href="buscarLivro.jsp">Buscar</a></li>
                                <li><a href="CadastroLivro.jsp">Inserir</a></li>
                            </ul>
                        </li>
                       
                        <li class="dropdown"><a href="#">${usuarioLogado}<i class="fa fa-angle-down"></i></a>
                            <ul role="menu" class="sub-menu">
                                <li><a href="profile.jsp">Profile</a></li>
                                <li><a href="index.html">LOGOUT</a></li>
                                
                            </ul>
                        </li>
                                 
                    </ul>
                </div>
          
            </div>
        </div>
               
            </div>
        </div>
    </header>
    <!--/#header-->


<section id="page-breadcrumb">
        <div class="vertical-center sun">
             <div class="container">
                <div class="row">
                    <div class="action">
                        <div class="col-sm-12">
                            <h1 class="title">Lançamentos</h1>
                           
                        </div>
                     </div>
                </div>
            </div>
        </div>
   </section>

    <section id="team">
        <div class="container">
            <div class="row">
                <div id="team-carousel" class="carousel slide wow fadeIn" data-ride="carousel" data-wow-duration="400ms" data-wow-delay="400ms">
                    <!-- Indicators -->
                    <ol class="carousel-indicators visible-xs">
                        <li data-target="#team-carousel" data-slide-to="0" class="active"></li>
                        <li data-target="#team-carousel" data-slide-to="1"></li>
                    </ol>
                    <!-- Wrapper for slides -->
                    <div class="carousel-inner">
                        <div class="item active">
                            <div class="col-sm-3 col-xs-6">
                                <div class="team-single-wrapper">
                                    <div class="team-single">
                                        <div class="person-thumb">
                                            <img src="multicolor-4/images/books/resize/harry4.jpg" class="img-responsive" alt="">
                                        </div>
                                        <div class="social-profile">
                                            <ul class="nav nav-pills">
                                                <li><a href="#"><i class="fa fa-heart"></i></a></li>
                                            </ul>
                                        </div>
                                    </div>
                                    <div class="person-info">
                                        <h2>Harry Potter e o Cálice de Fogo</h2>
                                        <p>J.K. Rowling</p>
                                    </div>
                                </div>
                            </div>
                            <div class="col-sm-3 col-xs-6">
                                <div class="team-single-wrapper">
                                    <div class="team-single">
                                        <div class="person-thumb">
                                            <img src="multicolor-4/images/books/resize/wayne_de_gotham.jpg" class="img-responsive" alt="">
                                        </div>
                                        <div class="social-profile">
                                            <ul class="nav nav-pills">
                                                <li><a href="#"><i class="fa fa-heart"></i></a></li>
                                            </ul>
                                        </div>
                                    </div>
                                    <div class="person-info">
                                        <h2>Wayne de Gotham</h2>
                                        <p>Tracy Hickman</p>
                                    </div>
                                </div>
                            </div>
                            <div class="col-sm-3 col-xs-6">
                                <div class="team-single-wrapper">
                                    <div class="team-single">
                                        <div class="person-thumb">
                                            <img src="multicolor-4/images/books/resize/todo_dia.jpg" class="img-responsive" alt="">
                                        </div>
                                        <div class="social-profile">
                                            <ul class="nav nav-pills">
                                                <li><a href="#"><i class="fa fa-heart"></i></a></li>
                                            </ul>
                                        </div>
                                    </div>
                                    <div class="person-info">
                                        <h2>Todo Dia</h2>
                                        <p>David Levithan</p>
                                    </div>
                                </div>
                            </div>
                            <div class="col-sm-3 col-xs-6">
                                <div class="team-single-wrapper">
                                    <div class="team-single">
                                        <div class="person-thumb">
                                            <img src="multicolor-4/images/books/resize/esperanca.jpg" class="img-responsive" alt="">
                                        </div>
                                        <div class="social-profile">
                                            <ul class="nav nav-pills">
                                                <li><a href="#"><i class="fa fa-heart"></i></a></li>
                                            </ul>
                                        </div>
                                    </div>
                                    <div class="person-info">
                                        <h2>Jogos Vorazes : A Esperança</h2>
                                        <p>Suzanne Collins</p>
                                    </div>
                                </div>
                            </div>
                        </div>
                        <div class="item">
                            <div class="col-sm-3 col-xs-6">
                                <div class="team-single-wrapper">
                                    <div class="team-single">
                                        <div class="person-thumb">
                                            <img src="multicolor-4/images/books/resize/game_of_thrones.jpg" class="img-responsive" alt="">
                                        </div>
                                        <div class="social-profile">
                                            <ul class="nav nav-pills">
                                                <li><a href="#"><i class="fa fa-heart"></i></a></li>
                                            </ul>
                                        </div>
                                    </div>
                                    <div class="person-info">
                                        <h2>As crônicas de gelo e fogo. A fúria dos reis</h2>
                                        <p>George R. R. Martin</p>
                                    </div>
                                </div>
                            </div>
                            <div class="col-sm-3 col-xs-6">
                                <div class="team-single-wrapper">
                                    <div class="team-single">
                                        <div class="person-thumb">
                                            <img src="multicolor-4/images/books/resize/garota_exemplar.jpg" class="img-responsive" alt="">
                                        </div>
                                        <div class="social-profile">
                                            <ul class="nav nav-pills">
                                                <li><a href="#"><i class="fa fa-heart"></i></a></li>
                                            </ul>
                                        </div>
                                    </div>
                                    <div class="person-info">
                                        <h2>Garota Exemplar</h2>
                                        <p>Gillian Flin</p>
                                    </div>
                                </div>
                            </div>
                            <div class="col-sm-3 col-xs-6">
                                <div class="team-single-wrapper">
                                    <div class="team-single">
                                        <div class="person-thumb">
                                            <img src="multicolor-4/images/books/resize/inferno.jpg" class="img-responsive" alt="">
                                        </div>
                                        <div class="social-profile">
                                            <ul class="nav nav-pills">
                                                <li><a href="#"><i class="fa fa-heart"></i></a></li>
                                            </ul>
                                        </div>
                                    </div>
                                    <div class="person-info">
                                        <h2>Inferno</h2>
                                        <p>Dan Brown</p>
                                    </div>
                                </div>
                            </div>
                            <div class="col-sm-3 col-xs-6">
                                <div class="team-single-wrapper">
                                    <div class="team-single">
                                        <div class="person-thumb">
                                            <img src="multicolor-4/images/books/resize/jogador_n1.jpg" class="img-responsive" alt="">
                                        </div>
                                        <div class="social-profile">
                                            <ul class="nav nav-pills">
                                                <li><a href="#"><i class="fa fa-heart"></i></a></li>
                                            </ul>
                                        </div>
                                    </div>
                                    <div class="person-info">
                                        <h2>Jogador nº1</h2>
                                        <p>Ernest Cline</p>
                                    </div>
                                </div>
                            </div>
                        </div>
                    </div>

                    <!-- Controls -->
                    <a class="left team-carousel-control hidden-xs" href="#team-carousel" data-slide="prev">left</a>
                    <a class="right team-carousel-control hidden-xs" href="#team-carousel" data-slide="next">right</a>
                </div>
            </div>
        </div>
    </section>

    <!--/#home-slider-->

   
    <!--/#services-->

    <!--/#action-->


<section id="page-breadcrumb">
        <div class="vertical-center sun">
             <div class="container">
                <div class="row">
                    <div class="action">
                        <div class="col-sm-12">
                            <h1 class="title">Mais Procurados</h1>
                           
                        </div>
                     </div>
                </div>
            </div>
        </div>
   </section>

 
<!--/#table-container-->
<section id="services">
        <div class="container">
            <h2><img src="multicolor-4/images/portfolio/icon.png" alt=""> LIVROS</h2>

            <div class="row">
                <div class="col-sm-4 text-center maisVisitados wow fadeIn" data-wow-duration="1000ms" data-wow-delay="300ms">
                    <div class="single-service">
                        <div class="wow scaleIn" data-wow-duration="500ms" data-wow-delay="300ms">
                        <a href="#"><img src="multicolor-4/images/books/resize/pequeno_principe.jpg" alt=""></a>
                        </div>
                        <h3>Pequeno Príncipe</h3>
                        <p>Antonie De Saint-Exupéry</p>
                    </div>
                </div>
                <div class="col-sm-4 text-center maisVisitados wow fadeIn" data-wow-duration="1000ms" data-wow-delay="300ms">
                    <div class="single-service">
                        <div class="wow scaleIn" data-wow-duration="500ms" data-wow-delay="300ms">
                                    <a href="#"><img src="multicolor-4/images/books/resize/cidades_de_papel.jpg" alt=""></a>
                        </div>
                        <h3>Cidades de Papel</h3>
                        <p>John Green</p>
                    </div>
                </div>
                <div class="col-sm-4 text-center maisVisitados wow fadeIn" data-wow-duration="1000ms" data-wow-delay="300ms">
                    <div class="single-service">
                        <div class="wow scaleIn" data-wow-duration="500ms" data-wow-delay="300ms">
                                    <a href="#"><img src="multicolor-4/images/books/resize/guerra_civil.png" alt=""></a>
                        </div>
                        <h3>Guerra Civil</h3>
                        <p>Stuart Moore</p>
                    </div>
                </div>
                
                <div class="col-sm-4 text-center maisVisitados wow fadeIn" data-wow-duration="1000ms" data-wow-delay="300ms">
                    <div class="single-service">
                        <div class="wow scaleIn" data-wow-duration="500ms" data-wow-delay="300ms">
                                    <a href="#"><img src="multicolor-4/images/books/resize/guerra_civil.png" alt=""></a>
                        </div>
                        <h3>Guerra Civil</h3>
                        <p>Stuart Moore</p>
                    </div>
                </div>
                
                <div class="col-sm-4 text-center maisVisitados wow fadeIn" data-wow-duration="1000ms" data-wow-delay="300ms">
                    <div class="single-service">
                        <div class="wow scaleIn" data-wow-duration="500ms" data-wow-delay="300ms">
                                    <a href="#"><img src="multicolor-4/images/books/resize/guerra_civil.png" alt=""></a>
                        </div>
                        <h3>Guerra Civil</h3>
                        <p>Stuart Moore</p>
                    </div>
                </div>
                
                
                </div><h2><img src="multicolor-4/images/portfolio/icon.png" alt=""> AUTORES</h2>


                <div class="row">
                <div class="col-sm-4 text-center maisVisitados wow fadeIn" data-wow-duration="1000ms" data-wow-delay="300ms">
                    <div class="single-service">
                        <div class="wow scaleIn" data-wow-duration="500ms" data-wow-delay="300ms">
                            <img src="multicolor-4/images/home/icon1.png" alt="">
                        </div>
                        <h3>J.K. Rowling</h3>
                        <p></p>
                    </div>
                </div>
                
                <div class="col-sm-4 text-center maisVisitados wow fadeIn" data-wow-duration="1000ms" data-wow-delay="600ms">
                    <div class="single-service">
                        <div class="wow scaleIn" data-wow-duration="500ms" data-wow-delay="600ms">
                            <img src="multicolor-4/images/home/icon2.png" alt="">
                        </div>
                        <h3>Dan Brown</h3>
                        <p></p>
                    </div>
                </div>
                <div class="col-sm-4 text-center maisVisitados wow fadeIn" data-wow-duration="1000ms" data-wow-delay="900ms">
                    <div class="single-service">
                        <div class="wow scaleIn" data-wow-duration="500ms" data-wow-delay="900ms">
                            <img src="multicolor-4/images/home/icon3.png" alt="">
                        </div>
                        <h3>George R. R. Martin</h3>
                        <p></p>
                    </div>
                </div>
                    
                <div class="col-sm-4 text-center maisVisitados wow fadeIn" data-wow-duration="1000ms" data-wow-delay="900ms">
                    <div class="single-service">
                        <div class="wow scaleIn" data-wow-duration="500ms" data-wow-delay="900ms">
                            <img src="multicolor-4/images/home/icon3.png" alt="">
                        </div>
                        <h3>George R. R. Martin</h3>
                        <p></p>
                    </div>
                </div>
                    
                <div class="col-sm-4 text-center maisVisitados wow fadeIn" data-wow-duration="1000ms" data-wow-delay="900ms">
                    <div class="single-service">
                        <div class="wow scaleIn" data-wow-duration="500ms" data-wow-delay="900ms">
                            <img src="multicolor-4/images/home/icon3.png" alt="">
                        </div>
                        <h3>George R. R. Martin</h3>
                        <p></p>
                    </div>
                </div>    
                    
            </div>
        </div>
    </section>
    <!--/#services-->

    


     <!--/#features-->


<section id="page-breadcrumb">
        <div class="vertical-center sun">
             <div class="container">
                <div class="row">
                    <div class="action">
                        <div class="col-sm-12">
                            <h1 class="title">Visitas Recentes</h1>
                           
                        </div>
                     </div>
                </div>
            </div>
        </div>
   </section>


 <section id="recent-projects" class="recent-projects">
        <div class="container">
            <div class="row">

               
                <div class="col-sm-3 col-xs-6 wow fadeIn" data-wow-duration="1000ms" data-wow-delay="300ms">
                    <div class="portfolio-wrapper">   
                        <div class="portfolio-single">
                            <div class="portfolio-thumb">
                                <img src="multicolor-4/images/books/resize/krypton.jpg" class="img-responsive" alt="">
                            </div>
                            <div class="portfolio-view">
                                <ul class="nav nav-pills">
                                    <li><a href="multicolor-4/images/portfolio/1.jpg" data-lightbox="example-set"><i class="fa fa-eye"></i></a></li>
                                </ul>
                            </div>
                        </div>
                        <div class="portfolio-info">
                            <h2>Os últimos dias de Krypton</h2>
                            <h4>Kevin J. Anderson </h4>

                        </div>
                    </div>
                </div>
                <div class="col-sm-3 col-xs-6 wow fadeIn" data-wow-duration="1000ms" data-wow-delay="400ms">
                    <div class="portfolio-wrapper">   
                        <div class="portfolio-single">
                            <div class="portfolio-thumb">
                                <img src="multicolor-4/images/books/resize/todo_dia.jpg" class="img-responsive" alt="">
                            </div>
                            <div class="portfolio-view">
                                <ul class="nav nav-pills">
                                    <li><a href="multicolor-4/images/portfolio/2.jpg" data-lightbox="example-set"><i class="fa fa-eye"></i></a></li>
                                </ul>
                            </div>
                        </div>
                        <div class="portfolio-info">
                           <h2>Todo Dia</h2>
                            <h4>David Levithan</h4>

                        </div>
                    </div>
                </div>
                <div class="col-sm-3 col-xs-6 wow fadeIn" data-wow-duration="1000ms" data-wow-delay="500ms">
                    <div class="portfolio-wrapper">   
                        <div class="portfolio-single">
                            <div class="portfolio-thumb">
                                <img src="multicolor-4/images/books/resize/amanhecer.jpg" class="img-responsive" alt="">
                            </div>
                            <div class="portfolio-view">
                                <ul class="nav nav-pills">
                                    <li><a href="multicolor-4/images/portfolio/3.jpg" data-lightbox="example-set"><i class="fa fa-eye"></i></a></li>
                                </ul>
                            </div>
                        </div>
                        <div class="portfolio-info">
                            <h2>A Saga Crepúsculo: Amanhecer</h2>
                            <h4>Stephenie Meyer</h4>
                        </div>
                    </div>
                </div>
                <div class="col-sm-3 col-xs-6 wow fadeIn" data-wow-duration="1000ms" data-wow-delay="600ms">
                    <div class="portfolio-wrapper">   
                        <div class="portfolio-single">
                            <div class="portfolio-thumb">
                                <img src="multicolor-4/images/books/resize/inferno.jpg" class="img-responsive" alt="">
                            </div>
                            <div class="portfolio-view">
                                <ul class="nav nav-pills">
                                    <li><a href="multicolor-4/images/portfolio/4.jpg" data-lightbox="example-set"><i class="fa fa-eye"></i></a></li>
                                </ul>
                            </div>
                        </div>
                        <div class="portfolio-info">
                            <h2>Inferno</h2>
                            <h4>Dan Brown</h4>                        </div>
                    </div>
                </div>
            </div>
        </div>
    </section>
<!-- 
    <section id="clients">
        <div class="container">
            <div class="row">
                <div class="col-sm-12">
                    <div class="clients text-center wow fadeInUp" data-wow-duration="500ms" data-wow-delay="300ms">
                        <p><img src="images/home/clients.png" class="img-responsive" alt=""></p>
                        <h1 class="title">Happy Clients</h1>
                        <p>Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. <br> Ut enim ad minim veniam, quis nostrud </p>
                    </div>
                </div>
            </div>
        </div>
     </section> -->
    <!--/#clients-->

    <footer id="footer">
        <div class="container">
            <div class="row">
                <div class="col-sm-12 text-center bottom-separator">
                    <img src="multicolor-4/images/home/under.png" class="img-responsive inline" alt="">
                </div>
             

                <!--<table>
                    <thead>
                        <tr><h2 class="page-header">Frases</h2></tr>
                    </thead>
                    <tbody>
                        <tr>
                            <td><blockquote>
                                    <p>Quem lê muito e anda muito, vai longe e sabe muito.</p>
                                    <footer><cite title="Source Title">Cervantes, Miguel</cite></footer>
                                </blockquote></td>
                            <td><blockquote>
                                    <p>Dupla delícia</p>
                                    <p>O livro traz a vantagem de a gente poder estar só e ao mesmo tempo acompanhado.</p>
                                    <footer><cite title="Source Title">Quintana, Mario</cite></footer>
                                </blockquote>
                            </td>
                        </tr>
                    </tbody>
                </table> -->
               
                <div class="col-sm-12">
                    <div class="copyright-text text-center">
                        <p>&copy; Your Company 2014. All Rights Reserved.</p>
                        <p>Designed by <a target="_blank" href="http://www.themeum.com">Themeum</a></p>
                    </div>
                </div>
            </div>
        </div>
    </footer>
    <!--/#footer-->

    <script type="text/javascript" src="multicolor-4/js/jquery.js"></script>
    <script type="text/javascript" src="multicolor-4/js/bootstrap.min.js"></script>
    <script type="text/javascript" src="multicolor-4/js/lightbox.min.js"></script>
    <script type="text/javascript" src="multicolor-4/js/wow.min.js"></script>
    <script type="text/javascript" src="multicolor-4/js/main.js"></script>   
</body>
</html>
