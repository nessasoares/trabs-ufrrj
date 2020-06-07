<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
 
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
	<%@include file="header.jsp" %>
</head>

<%@ page import = "controladores.sala.CrListarSala" %>
<%@ page import = "entidades.Sala" %>
<%@ page import = "singleton.Singleton" %>

<body>
<p align='right'><table border='1px' class="table table-striped table-hover col-lg-8 ">
<thead>
		<tr>
			<th>Descricao</th>
			<th class="col-lg-25 col-lg-offset-8"></th>
			<th></th>
		</tr>
</thead>
<tbody>
	<form method="post" action="CrListarSala">
	<%  
		for(Sala u: Singleton.getInstance().getSala() ){
			
		out.println("<tr>");
		out.println("<td>"+ u.getDescricao()+"</td>");
		out.println("<td><ul class='nav nav-pills'><li class='active'><a class='btn btn-default' href='CrListarSala?desc="
					+u.getDescricao()+"&metodo=asdjalsdj'>Editar</a></li></td>");
		out.println("<td><ul class='nav nav-pills'><li class='active'><a class='btn btn-default'"+
						"href='CrListarSala?desc="+u.getDescricao()+"&metodo=deleteSala"	
					+"'>Excluir </a></li></td>");
		out.println("</tr>");

		}
	    out.println("</table></p>");
    	
	%>	
	</form>
</tbody></body>
</html>