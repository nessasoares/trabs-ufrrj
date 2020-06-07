<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="description" content="">
    <meta name="author" content="Dashboard">
    <meta name="keyword" content="Dashboard, Bootstrap, Admin, Template, Theme, Responsive, Fluid, Retina">

    <link rel="shortcut icon" href="multicolor-4/images/ico/favicon.ico">
    <title>Login | ***</title>

    <!-- Bootstrap core CSS -->
    <link href="multicolor-4/assets/css/bootstrap.css" rel="stylesheet">
    <!--external css-->
    <link href="multicolor-4/assets/font-awesome/css/font-awesome.css" rel="stylesheet" />
        
    <!-- Custom styles for this template -->
    <link href="multicolor-4/assets/css/style.css" rel="stylesheet">
    <link href="multicolor-4/assets/css/style-responsive.css" rel="stylesheet">

  </head>

  <body>

      <!-- **********************************************************************************************************************************************************
      MAIN CONTENT
      *********************************************************************************************************************************************************** -->

	  <div id="login-page">
	  	<div class="container">
	  	


		      <form class="form-login" method='post' action='servletLoginUsuario'>
		        <h2 class="form-login-heading">LOGIN</h2>
		        <div class="login-wrap">
		            <input type="username" name= "username" id="inputUsername" class="form-control" placeholder="Username" autofocus>
		            <br>
		            <input type="password" name="senha" id= "inputSenha" class="form-control" placeholder="Senha">
		            <label class="checkbox">
		                <span class="pull-right">
		                    <a data-toggle="modal" href="login.html#myModal">Esqueceu a senha?</a>
		                </span>
		            </label>
		            <button class="btn btn-theme btn-block" href="index.html" type="submit"><i class="fa fa-lock"></i> Entrar</button>
		            
		            <div class="registration">
		              <br> Ainda não tem conta?<br/>
		                <a class="" href="CadastroUsuario.html">
		                    Crie uma conta
		                </a>
		            </div>
		
		        </div>
		
		          <!-- Modal -->
		          <div aria-hidden="true" aria-labelledby="myModalLabel" role="dialog" tabindex="-1" id="myModal" class="modal fade">
		              <div class="modal-dialog">
		                  <div class="modal-content">
		                      <div class="modal-header">
		                          <button type="button" class="close" data-dismiss="modal" aria-hidden="true">&times;</button>
		                          <h4 class="modal-title">Esqueceu a senha ?</h4>
		                      </div>
		                      <div class="modal-body">
		                          <p>Insira seu email para recuperar sua senha</p>
		                          <input type="text" name="email" placeholder="Email" autocomplete="off" class="form-control placeholder-no-fix">
		
		                      </div>
		                      <div class="modal-footer">
		                          <button data-dismiss="modal" class="btn btn-default" type="button">Cancelar</button>
		                          <button class="btn btn-theme" type="button">Enviar</button>
		                      </div>
		                  </div>
		              </div>
		          </div>
		          <!-- modal -->
		
		      </form>	  	
	  	
	  	</div>
	  </div>

    <!-- js placed at the end of the document so the pages load faster -->
    <script src="multicolor-4/assets/js/jquery.js"></script>
    <script src="multicolor-4/assets/js/bootstrap.min.js"></script>

    <!--BACKSTRETCH-->
    <!-- You can use an image of whatever size. This script will stretch to fit in any screen size.-->
    <script type="text/javascript" src="multicolor-4/assets/js/jquery.backstretch.min.js"></script>
    <script>
        $.backstretch("multicolor-4/images/livros2.jpg", {speed: 500});
    </script>


  </body>
</html>
