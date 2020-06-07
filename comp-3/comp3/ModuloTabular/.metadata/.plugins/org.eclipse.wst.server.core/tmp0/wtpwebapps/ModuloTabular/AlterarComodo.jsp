<%@page import="dao.ComodoDAO"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
	<%@include file="header.jsp" %>
	<%@ page import = "java.net.URLEncoder" %>
	<%@ page import = "java.io.*" %>
	<%@ page import = "dao.*" %>
	<script type='text/javascript'>
		$(document).ready(function(){
			$('#deleteBtn').click(function(){
					 $('input[name="method"]').val("delete");	
			});
			$('#saveBtn').click(function(){
				 $('input[name="method"]').val("save");
			});
		});
	</script>
</head>
<body>
 <div class="col-lg-3 col-lg-offset-4" >
	<h3><center><font face="Calibri" color="gray">Edição:Comodo</font> </center></h3>
		
		<form method="post" action="AlterarComodo">
			<div class="form-group">
			  
			  <%
			  	  out.println(" <input class='form-control' name='desc' id='desc' type='text' placeholder='Descrição do comodo' value='"
			  	  +request.getParameter("desc")+ "'>");
			  				/* + request.getParameter("idComodo") +"'" );*/ 
				   out.println(" <input type='hidden' value='" + request.getParameter("id") 
				  			 +"' name='id' id='id'>");
			  %>
			  </div>
			<div class="col-lg-15 col-lg-offset-1">
			  	<input type='hidden' value='' name='method' id='method'>
				<button type="reset" onclick="history.back();" class="btn btn-default">Cancelar</button>
		        <button type="submit" class="btn btn-primary" id='deleteBtn'>Excluir</button>
		        <button type="submit" class="btn btn-success" id='saveBtn'>Salvar</button>
		      
		        
	        </div>
	</form>
</div>
</center>	
</body>
</html>