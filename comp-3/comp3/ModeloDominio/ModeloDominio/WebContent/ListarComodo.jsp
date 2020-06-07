<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
 
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
	<%@include file="header.jsp" %>
</head>

<%@ page import = "servicelayer.comodo.ListarComodoSL" %>
<%@ page import = "md.*" %>
<%@ page import = "dao.ComodoDAO" %>
<%@ page import = "java.util.*" %>
<script type="text/javascript">

	function hiddenFunction(id){
		if($('#'+ id+'').html() == "ComodoComposto"){
			alert("Você não pode editar/excluir um cômodo composto");
		}else{
			$('input[name="idComodo"]').val(id);
		    document.getElementById("list_form").submit();
		}
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
	<form method="post" action="AlterarComodo.jsp" id='list_form'>
	<%  
		List <ComodoMD> l = (List)request.getAttribute("lista_comodos");
		for(ComodoMD u:  l){ 
			out.println("<tr>");
			out.println("<td><a href='AlterarComodo.jsp?id="+u.getId()+"&desc="+u.getDescricao()+"&tipo="+u.getClass().getSimpleName()+"');'"
						+" value='"+u.getDescricao()+"'>" + u.getDescricao() +"</a></td>");
			out.println("<td><label>" + u.getClass().getSimpleName() +"</label></td>");

			out.println("</tr>");
		}
	    out.println("</table></p>");
	%>
	<input type='hidden' name='idComodo' id='idComodo'/>
	
	</form>
</tbody></body>
</html>