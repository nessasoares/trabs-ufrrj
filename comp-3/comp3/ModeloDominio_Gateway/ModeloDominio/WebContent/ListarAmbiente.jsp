<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
 
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
	<%@include file="header.jsp" %>
</head>

<%@ page import = "servicelayer.ambiente.*" %>
<%@ page import = "md.*" %>
<%@ page import = "java.util.*" %>

<script type="text/javascript">

	function hiddenFunction(id){
		$('input[name="idAmbiente"]').val(id);
	    document.getElementById("list_form").submit();
	} 
	
</script>
<body>
<p align='right'><table border='1px' class="table table-striped table-hover col-lg-8 ">
<thead>
		<tr>
			<th>id</th>
			<th>paredes</th>
			<th>portas</th>
			<th>metragem</th>
			
		</tr>
</thead>
<tbody>
	<form method="post" action="ListarAmbiente" id='list_form'>
	<%  
		List <AmbienteMD> l = (List)request.getAttribute("ambientes");
		for(AmbienteMD u:  l){ 
			out.println("<tr>");
			out.println("<td><a onclick='hiddenFunction("+u.getId()+")'"
						+" value='"+u.getId()+"'>" + u.getId() +"</a></td>");
			out.println("<td><a value='"+u.getId() +"'>" + u.getNumParedes() +"</a></td>");
			out.println("<td><a value='"+u.getId() +"'>" + u.getNumPortas() +"</a></td>");
			out.println("<td><a value='"+u.getId() +"'>" + u.getMetragem() +"</a></td>");

			out.println("</tr>");
		}
	    out.println("</table></p>");
	%>
	<input type='hidden' name='idAmbiente' id='idAmbiente'/>
	</form>
	<div>
		<a class="btn btn-primary"  href="CriarAmbiente">Criar Outro Ambiente</a>
		<a class="btn btn-primary" href="VisualizarContrato">Finalizar Contrato</a>
	</div>
	
</tbody></body>
</html>