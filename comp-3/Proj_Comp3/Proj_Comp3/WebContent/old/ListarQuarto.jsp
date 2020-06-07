<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
 
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
	<%@include file="header.jsp" %>
</head>
<%@ page import = "controladores.quarto.CrListarQuarto" %>
<%@ page import = "entidades.Quarto" %>
<%@ page import = "singleton.Singleton" %>
<%@ page import = "dao.QuartoDAO" %>
<script type="text/javascript">

	function hiddenFunction(id){
		$('input[name="idComodo"]').val(id);
	    document.getElementById("list_form").submit();
	} 
	
</script>
<body>
<p align='right'><table border='1px' class="table table-striped table-hover col-lg-8 ">
<thead>
		<tr>
			<th>Descricao</th>
			<th>Tipo</th>
		</tr>
</thead>
<tbody>
	<form method="post" action="CrListarQuarto" id='list_form'>
	<%  
		for(Quarto u: QuartoDAO.listaQuarto()){
			out.println("<tr>");
			out.println("<td><a onclick='hiddenFunction("+u.getId()+")'"
						+"value='"+u.getDescricao()+"'>" + u.getDescricao() +"</a></td>");
			out.println("</tr>");
		}
	    out.println("</table></p>");
	%>
	<input type='hidden' name='idComodo' id='idComodo'/>
	</form>
</tbody></body>
</html>