<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
	<%@include file="header.jsp" %>
	<%@ page import = "java.net.URLEncoder" %>
	<%@ page import = "java.io.*" %>
	<%@ page import = "java.util.*" %>
	<%@ page import = "entidades.*" %>
	<%@ page import="controladores.mobilia.*"%>
	
</head>
<body>
 <div class="col-lg-3 col-lg-offset-4" style="position:relative;float:left;" >
	<h3><center><font face="Calibri" color="gray">Contrato</font> </center></h3>
		<div class="panel panel-primary" style="margin-left:3%;" >
		  
		  <div class="panel-heading">
		    <h3 class="panel-title">Custo (R$)</h3>
		  </div>
		  <div class="panel-body">
			<%
				Contrato c = (Contrato)request.getAttribute("contrato");
				out.println(c.getValor());
			%>
		  </div>
		  <div class="panel-heading">
		    <h3 class="panel-title">Prazo</h3>
		  </div>
		  <div class="panel-body">
		    <%
				out.println(c.getPrazo());
			%>
		  </div>
		</div>				  
		<h4>Ambiente criados:</h4>
		<p align='center' bottom="middle"><table border='2px' class="table table-hover col-lg-3 ">
		<thead>
				<tr class='success'>
					<th>Número de paredes</th>
					<th>Número de portas</th>
					<th>Metragem</th>
					<th>Tempo de entrega (semanas)</th>
					<th>Custo (R$)</th>
				</tr>
		</thead>
		<tbody>
	<%  
		List <Ambiente> l = (List)request.getAttribute("ambientes");

		for(Ambiente u:  l){ 
			out.println("<tr>");
			out.println("<td><a value='"+u.getId() +"'>" + u.getNumParedes() +"</a></td>");
			out.println("<td><a value='"+u.getId() +"'>" + u.getNumPortas() +"</a></td>");
			out.println("<td><a value='"+u.getId() +"'>" + u.getMetragem() +"</a></td>");
			out.println("<td><a value='"+u.getId() +"'>" + u.getTempo() +"</a></td>");
			out.println("<td><a value='"+u.getId() +"'>" + u.getCusto() +"</a></td>");

			out.println("</tr>");
		}
	    out.println("</table></p>");
	    
	%>
	<a class="btn btn-success"  href="index.jsp">OK</a>
	
</div>

</center>	
</body>
</html>