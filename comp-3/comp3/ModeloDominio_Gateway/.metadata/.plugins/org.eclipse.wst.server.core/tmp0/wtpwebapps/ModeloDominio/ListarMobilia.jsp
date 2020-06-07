<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
 
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
	<%@include file="header.jsp" %>
</head>

<%@ page import = "servicelayer.mobilia.*" %>
<%@ page import = "md.*" %>
<%@ page import = "java.util.*" %>

<body>
<p align='right'><table border='1px' class="table table-striped table-hover col-lg-8 ">
<thead>
		<tr>
			<th>Descricao</th>
			<th>Custo (R$)</th>
			<th>Tempo de Entrega (Semanas)</th>
		</tr>
</thead>
<tbody>
	<%  
		List<MobiliaMD> l = (List)request.getAttribute("mobilias"); 
		for(MobiliaMD u: l ){ 
			out.println("<tr>");
			out.println("<td><a href='AlterarMobilia?id="+u.getId()+"&desc="+u.getDescricao()+"&custo="+u.getCusto()+"&tempo="+u.getTempoEntrega()+"');'"
						+" value='"+u.getId()+"'>" + u.getDescricao() +"</a></td>");
			out.println("<td><a>" + u.getCusto() +"</a></td>");
			out.println("<td><a>" + u.getTempoEntrega() +"</a></td>");
			out.println("</tr>");
		}
	    out.println("</table></p>");
	%>
	<input type='hidden' name='idMobilia' id='idMobilia'/>
</tbody></body>
</html>