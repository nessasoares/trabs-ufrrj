<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    <%@page import="br.recomendacao.livros.LivroDAO"%>
    
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
 <%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
<html>
<head>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="description" content="">
    <meta name="author" content="">
    <title>Livro | WS book's</title>
    <link href="multicolor-4/css/bootstrap.min.css" rel="stylesheet">
    <link href="multicolor-4/css/font-awesome.min.css" rel="stylesheet">
    <link href="multicolor-4/css/animate.min.css" rel="stylesheet"> 
    <link href="multicolor-4/css/lightbox.css" rel="stylesheet"> 
	<link href="multicolor-4/css/main.css" rel="stylesheet">
	<link href="multicolor-4/css/responsive.css" rel="stylesheet">
    
    <link rel="stylesheet" href="multicolor-4/css/star-rating.css" media="all" rel="stylesheet" type="text/css"/>
    <script src="http://ajax.googleapis.com/ajax/libs/jquery/2.1.1/jquery.min.js"></script>
    <script src="multicolor-4/js/star-rating.js" type="text/javascript"></script>

    
    <link href="//maxcdn.bootstrapcdn.com/font-awesome/4.2.0/css/font-awesome.min.css" rel="stylesheet">
	

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
                
                
            <!--   <div class="search">
                    <form role="form">
                        <i class="fa fa-search"></i>
                        <div class="field-toggle">
                            <input type="text" class="search-form" autocomplete="on" placeholder="Search">
                        </div>
                    </form>
                </div>
                -->
                
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
                        <li class="dropdown"><a href="homeUsuario.jsp">Home</a></li>
                        <li class="active"><a href="buscarLivro.jsp">Livros <i class="fa fa-angle-down"></i></a>
                            <ul role="menu" class="sub-menu">
                                <li><a href="buscarLivro.jsp">Buscar</a></li>
                                <li><a href="CadastroLivro.jsp">Inserir</a></li>
                            </ul>
                        </li>
                       
                        <li class="dropdown"><a href="#">${usuarioLogado}<i class="fa fa-angle-down"></i></a>
                            <ul role="menu" class="sub-menu">
                                <li><a href="profile.jsp">Profile</a></li>
                                <li><a href="deslogar.jsp">LOGOUT</a></li>
                                
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

<!-- section -->

    <section id="portfolio-information" class="padding-top">
     <c:forEach var = "book" items = "${listaLivro}" >
        <div class="container">
            <div class="row">
                <div class="livroImg">
                    <img src="multicolor-4/images/books/${book.arquivo}" class="img-responsive" alt="">
                </div>
                <div class="infoLivro"><font face="Lato">
                    <div class="project-name overflow">
                        <h2 class="bold"><b>${book.titulo}</b> </h2>
                        <ul class="nav navbar-nav navbar-default">
                            <li><a href="#"><i class="fa fa-tag"></i>${book.autor}</a></li>
                            <li><a href="#"><i class="fa fa-clock-o"></i>${book.ano}</a></li>
                            <li><a href="#"><i class="fa fa-tag"></i>${book.editora}</a></li>

                        </ul>
                    </div>
                    <div class="project-info overflow">
                        <h3>Sipnose</h3>
                        <p>${book.sinopse}</p>  
                    </div>
                    
              <script>
              	function teste(){
              		alert("${book.id}");
              	}
              
              </script>
                  
         <!--    <div class="btn-classificacao">
              
	           <input type="hidden" name="curtida" class="btn btn-default" value="${book.id}">
  
              
                <input type="submit" value="Gostei!" class="btn btn-default glyphicon glyphicon-heart"></input>
   	            <%--
	       		String c = request.getParameter("curtida");
	       		
			       		LivroDAO dao = new LivroDAO();
	
		       			dao.updateLikeLivro(c);
		       	--%>
   	           
   	           </div>-->  
                </div>
            </font></div>
        </div>
        </div>
        </c:forEach>
    </section>




<!-- end  section -->

    <footer id="footer">
        <div class="container">
            <div class="row">
                <div class="col-sm-12 text-center bottom-separator">
                    <img src="multicolor-4/images/home/under.png" class="img-responsive inline" alt="">
                </div>
            
                <table>
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
                </table>

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
