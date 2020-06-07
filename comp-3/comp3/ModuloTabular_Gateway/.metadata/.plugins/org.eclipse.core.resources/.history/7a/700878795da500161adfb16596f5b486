<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
	<%@include file="header.jsp" %>
	<%@ page import = "java.net.URLEncoder" %>
	<%@ page import = "java.io.*" %>
	<%@ page import = "java.util.*" %>
	<%@ page import = "entidades.Ambiente" %>
	<%@ page import="controladores.mobilia.*"%>
	
</head>

<script type="text/javascript">
$(document).ready(function(){
	$('#cancelBtn').click(function(){
			 $('input[name="method"]').val("cancel");	
	});
});
</script>
<body>
 <div class="col-lg-3 col-lg-offset-4" style="position:relative;float:left;" >
	<h3><center><font face="Calibri" color="gray">Contrato</font> </center></h3>
		<form method="post" action="FinalizarContrato" id='list_form'>
		
		  <input class="form-control" name="comissao" min="0.01" id="comissao" step=0.01 type="number" placeholder="Comissão" style='margin-bottom:3%;width:97%;' required>
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
	<input type='hidden' name='idAmbiente' id='idAmbiente'/>
	<input type='hidden' value='' name='method' id='method'>
	
	<div style="width:130%">
		<a class="btn btn-primary"  href="CriarAmbiente">Criar Outro Ambiente</a>
        <button type="submit" class="btn btn-primary" id='cancelBtn'>Excluir</button>
		<button type="submit" class="btn btn-success">Finalizar Contrato</button>
		
		
	</div>
	</form>
</div>

</center>	
</body>
</html>