<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
 
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
	<%@include file="header.jsp" %>
</head>

<%@ page import = "controladores.mobilia.CrListarMobilia" %>
<%@ page import = "entidades.Mobilia" %>
<%@ page import = "singleton.Singleton" %>
<%@ page import = "dao.MobiliaDAO" %>
<script type="text/javascript">

	function hiddenFunction(id){
		$('input[name="idMobilia"]').val(id);
	    document.getElementById("list_form").submit();
	} 
	
</script>
<body>
<p align='right'><table border='1px' class="table table-striped table-hover col-lg-8 ">
<thead>
		<tr>
			<th>Descricao</th>
			<th>Custo (R$)</th>
			<th>Tempo de Entrega (Dias)</th>
		</tr>
</thead>
<tbody>
	<form method="post" action="CrListarMobilia" id='list_form'>
	<%  
		for(Mobilia u: MobiliaDAO.listaMobilia() ){ 
			out.println("<tr>");
			out.println("<td><a onclick='hiddenFunction("+u.getId()+")'"
						+" value='"+u.getId()+"'>" + u.getDescricao() +"</a></td>");
			out.println("<td><a value='"+u.getId() +"'>" + u.getCusto() +"</a></td>");
			out.println("<td><a value='"+u.getId() +"'>" + u.getTempoEntrega() +"</a></td>");
			out.println("</tr>");
		}
	    out.println("</table></p>");
	%>
	<input type='hidden' name='idMobilia' id='idMobilia'/>
	</form>
</tbody></body>
</html>