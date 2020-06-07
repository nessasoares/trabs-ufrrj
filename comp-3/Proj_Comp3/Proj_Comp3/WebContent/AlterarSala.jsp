<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
	<%@include file="header.jsp" %>
	<%@ page import = "java.net.URLEncoder" %>
	<%@ page import = "java.io.*" %>
	
</head>
<body>
 <div class="col-lg-3 col-lg-offset-4" >
	<h3><center><font face="Calibri" color="gray">Edição:Sala</font> </center></h3>
		
		<form method="post" action="CrAlterarSala">
			<div class="form-group">
			  
			  <%
			 	out.println("<input class='form-control' name='desc' id='desc' value=");
			  	out.println("'" + request.getParameter("desc") + "'");
			  	out.println(" type='text'>");
			  	out.println("<input class='form-control' name='descHidden' id='descHidden' type='hidden' value=");
			  	out.println("'" + request.getParameter("desc") + "'>");
			  %>
			</div>
			<div class="col-lg-10 col-lg-offset-2">
				<button type="reset" onclick="history.back();" class="btn btn-default">Cancelar</button>
		        <button type="submit" class="btn btn-primary">Salvar</button>
	        </div>
	</form>
</div>
</center>	
</body>
</html>