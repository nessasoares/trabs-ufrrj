<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
     <%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c" %>
     

<html>
<head>
    <meta http-equiv="Content-Type" content="text/html; charset=utf8" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="description" content="">
    <meta name="author" content="">
    <title>Cadastro Livro| WS book's</title>
    <link href="multicolor-4/css/bootstrap.min.css" rel="stylesheet">
    <link href="multicolor-4/css/font-awesome.min.css" rel="stylesheet">
    <link href="multicolor-4/css/lightbox.css" rel="stylesheet"> 
    <link href="multicolor-4/css/animate.min.css" rel="stylesheet"> 
	<link href="multicolor-4/css/main.css" rel="stylesheet">
	<link href="multicolor-4/css/responsive.css" rel="stylesheet">
	
	
	<script src="multicolor-4/sweetalert-master/dist/sweetalert.min.js"></script>
	 <link rel="stylesheet" type="text/css" href="multicolor-4/sweetalert-master/dist/sweetalert.css">
	    <script src="multicolor-4/js/jsFunctions.js" type="text/javascript"></script>
	
	
	<link rel="stylesheet" href="multicolor-4/css/star-rating.css" media="all" rel="stylesheet" type="text/css"/>
    <script src="http://ajax.googleapis.com/ajax/libs/jquery/2.1.1/jquery.min.js"></script>
    <script src="js/star-rating.js" type="text/javascript"></script>
    
    
    
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
<style type="text/css">

#labelImg{
	margin-top:2%;
}
</style>
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
                        <li class="dropdown"><a href="homeUsuario.jsp">Home</a></li>
                        <li class="dropdown"><a href="buscarLivro.jsp">Livros <i class="fa fa-angle-down"></i></a>
                            <ul role="menu" class="sub-menu">
                                <li><a href="buscarLivro.jsp">Buscar</a></li>
                                <li class= "active"><a href="CadastroLivro.jsp">Inserir</a></li>
                            </ul>
                        </li>
                       
                        <li class="dropdown"><a href="">${usuarioLogado}<i class="fa fa-angle-down"></i></a>
                            <ul role="menu" class="sub-menu">
                                <li><a href="profile.jsp">Profile</a></li>
                                <li><a href="deslogar.jsp">LOGOUT</a></li>
                                
                            </ul>
                        </li>
                                 
                    </ul>
                </div>
               <!-- 
               LUPA DE PESQUISA
///////////////////////////////////////////////////////////////////////////////////////////////
               <div class="search">
                    <form role="form">
                        <i class="fa fa-search"></i>
                        <div class="field-toggle">
                            <input type="text" class="search-form" autocomplete="on" placeholder="Search">
                        </div>
                    </form>
                </div> 
                ///////////////////////////////////////////////////////////////////////////////////////////////
 -->
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
                            <h1 class="title">Cadastro de Livros</h1>
                            <!--<p>Why our Clients love to work with us.</p>-->
                        </div>
                     </div>
                </div>
            </div>
        </div>
   </section>
    <!--/#page-breadcrumb-->


    <!-- BASIC FORM ELELEMNTS -->
            <div class="row mt">
                <div class="col-lg-12">
                  <div class="form-panel">
                     <br>
                     <br>
        
            
          <c:if test="${msgsAlert eq '1'}">
       
       <script>
 			 retorno = true;
        	 msg = "Livro Inserido!";
        	swal({   title: "Good job!",   text: msg,   type: "success",   confirmButtonText: "Ok"});
        	//swal("Good job!", "Livro inserido!", "success");
        	        </script>

        </c:if>
        
         <c:if test="${msgsAlert eq '2'}">
      <script>
 		 retorno = true; 
		 msg = "ARQUIVO JÁ EXISTE";
         swal({   title: "Aviso!",   text: msg,   type: "warning",   confirmButtonText: "Ok"});
      </script>

        </c:if>
        
        <c:if test="${msgsAlert eq '3'}">
      <script>
    		    retorno = false; 
				msg = "ESTE TÍTULO JA EXISTE";
				swal({   title: "Aviso!",   text: msg,   type: "warning",   confirmButtonText: "Ok"});
     </script>

        </c:if>
        
        	
<script>
        function verificaCampos(){        	
  			var msg = '';
  			var retorno = true;
      		var y = verificarCamposJs();
	
	    		if(y == 4){
	    				msg = "CAMPOS VAZIOS";
	    	    		//alert(msg);
	
	    				retorno = false;
	    		}
	    		else if(y==5){
	    				msg="ANO INVÁLIDO";
	
	    				retorno = false;
	    		}
	    		

			if(retorno == false){
				swal({   title: "Aviso!",   text: msg,   type: "warning",   confirmButtonText: "Ok"});
			}		
    		return retorno;
    		
    	}
      
        </script>

                      <form class="form-horizontal style-form formularioLivro" method="post" action="servletCadastroLivro" onsubmit="return verificaCampos();" enctype="multipart/form-data" >
                          
                          <div class="form-group">
                              <label class="col-sm-15 col-sm-15 control-label">Titulo: </label>
                              <div class="formsCadastro">
                                  <input type="titulo" name="titulo" id="inputTitulo"  class="form-control formBook" placeholder="Título">
                              </div>
                          </div>

                          <div class="form-group">
                              <label class="col-sm-15 col-sm2-15 control-label">Autor: </label>
                              <div class="formsCadastro">
                                  <input type="autor" name="autor" id="inputAutor"  class="form-control formBook" placeholder="Autor">
                              </div>
                          </div>
                     
                          <div class="form-group">
                              <label class="col-sm-15 col-sm-15 control-label">Editora: </label>
                              <div class="formsCadastro">
                                  <input type="editora" name="editora" id="inputEditora"  class="form-control formBook" placeholder="Editora">
                              </div>


                          </div>
                          
                          
                          <div class="form-group">
                              <label class="col-sm-15 col-sm-15 control-label">Ano: </label>
                              <div class="formsCadastro">
                                  <input type="ano" name="ano" id="inputAno"  class="form-control formBook" placeholder="Ano de Lançamento" onkeypress= "return OnlyNum(event);" >
                              </div>


                          </div>
                          
                          
                          
							
                           <div class="form-group">
                              <label class="col-sm-15 col-sm-15 control-label">Sinopse: </label>
                              <div class="formsCadastro">
                                <textarea type="sinopse" name="sinopse" id="inputSinopse"  class="form-control formBook"  placeholder="Sinopse"></textarea>
                              </div>
                              
                             
                          
              </div>
                <div class="form-group">
                              <label id="labelImg" class="col-sm-15 col-sm-15 control-label">Imagem: </label>
                              <div class="formsCadastro">
                                 <input type="file" name="arquivo" id="inputArquivo"  class="form-control formBook"   >
                              </div>
               </div>
              
                                            
 <button class="btn btn-sm btn-info botaoEnviarCadastroLivro" type="submit" id ="botaoEnviarCadastroLivro" >Enviar</button>
                            <!--<a href="CadastroUsuario.html" class="btn btn-sm btn-info" type="submit" id = "botaoEnviarCadastro">Enviar</a>-->
  
                      </form>
                      
                  </div>
                </div><!-- col-lg-12-->         
            </div><!-- /row -->

    <!--/#team-->

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
    <script type="text/javascript" src="multicolor-4/js/jquery.countTo.js"></script>
    <script type="text/javascript" src="multicolor-4/js/main.js"></script>   
   
</body>
</html>
