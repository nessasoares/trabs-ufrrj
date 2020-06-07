<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>

    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta name="description" content="">
    <meta name="author" content="">
    <title>Cadastro | ***</title>
    <link href="multicolor-4/css/bootstrap.min.css" rel="stylesheet">
    <link href="multicolor-4/css/font-awesome.min.css" rel="stylesheet">
    <link href="multicolor-4/css/lightbox.css" rel="stylesheet"> 
    <link href="multicolor-4/css/animate.min.css" rel="stylesheet"> 
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
<style type="text/css">
 #botaoEnviarCadastro {
    position:absolute;
    left:55%;
    top:107%;
    margin-left:-110px;
    margin-top:20px;
    }
    
    
    
#labelGenero{
   
    margin-top: 2%;
    
    
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

                    <a class="navbar-brand" href="index.html">
                        <h1><img src="multicolor-4/images/logo.png" alt="logo"></h1>
                    </a>
                    
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
                            <h1 class="title">Cadastro de Usuário</h1>
                            <!--<p>Why our Clients love to work with us.</p>-->
                        </div>
                     </div>
                </div>
            </div>
        </div>
   </section>
    <!--/#page-breadcrumb-->

    
    
    
       <div class="row mt">
                <div class="col-lg-12">
                  <div class="form-panel">
                     <br>
                     <br>
                      <form class="form-horizontal style-form formularioLivro" method='get' action='servletCadastroUsuario'>
                          <div class="form-group">
                              <label class="col-sm-15 col-sm-15 control-label">Nome: </label>
                              <div class="formsCadastro">
                                  <input type="nome" name="nome" id="inputNome"  class="form-control formBook" placeholder="">
                              </div>
                          </div>

                          <div class="form-group">
                              <label class="col-sm-15 col-sm2-15 control-label">Email: </label>
                              <div class="formsCadastro">
                                  <input type="email" name="email" id="inputEmail"  class="form-control formBook" placeholder="">
                              </div>
                          </div>
                     
                          <div class="form-group">
                              <label class="col-sm-15 col-sm-15 control-label">Username: </label>
                              <div class="formsCadastro">
                                  <input type="username" name="username" id="inputUsername"  class="form-control formBook" placeholder="">
                              </div>


                          </div>
                          
                          
                          <div class="form-group">
                              <label class="col-sm-15 col-sm-15 control-label">Senha: </label>
                              <div class="formsCadastro">
                                  <input type="password" name="senha" id="inputSenha"  class="form-control formBook" placeholder=""  >
                              </div>


                          </div>
                          
                          
                           
                          <div class="form-group">
                              <label class="col-sm-15 col-sm-15 control-label"> </label>
                              <div class="formsCadastro">
                                  <input type="password" name="confirmaSenha" id="inputConfirmaSenha"  class="form-control formBook" placeholder="Confirmação de senha"  >
                              </div>


                          </div>
                          
                          
                           <div class="form-group">
                              <label id="labelGenero"class="col-sm-15 col-sm-15 control-label">Gênero: </label>
                                 <div class="radioBtn">
                                  <label class="radio-inline"><input type="radio" name="sex" value = "FEMININO" checked>Feminino</label>
                                  <label class="radio-inline"><input type="radio" name="sex" value = "MASCULINO">Masculino</label>
                              </div>


                               
                                
                          </div>
                          
                          
                                            
 <button class="btn btn-sm btn-info botaoEnviarCadastroLivro" type="submit" id ="botaoEnviarCadastroLivro ">Enviar</button>
                            <!--<a href="CadastroUsuario.html" class="btn btn-sm btn-info" type="submit" id = "botaoEnviarCadastro">Enviar</a>-->
        
                      </form>
                      
                  </div>
                </div><!-- col-lg-12-->         
            </div><!-- /row -->

    <!-- BASIC FORM ELELEMNTS -->
  

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