<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
	<%@include file="header.jsp" %>
	<%@ page import = "java.net.URLEncoder" %>
	<%@ page import = "java.io.*" %>
	<%@ page import = "java.util.*" %>
	<%@ page import = "entidades.Comodo" %>
	<%@page import="controladores.mobilia.*"%>
	
	
<script type='text/javascript'>

		$(document).ready(function(){
			$('#deleteBtn').click(function(){
					 $('input[name="method"]').val("delete");	
			});
			$('#saveBtn').click(function(){
				 $('input[name="method"]').val("save");
			});
			
		});
		
		function getComodo(){
			var comodos = [];
		    $('input[name="comodos"]:checked').each(function(i){
		    	comodos[i] = $(this).val();
		      console.log(this.value);
		    });
		    $('input[name="idComodos"]').val(comodos);
		}
	</script>
</head>
<body>
 <div class="col-lg-3 col-lg-offset-4" >
	<h3><center><font face="Calibri" color="gray">Edição:Mobilia</font> </center></h3>
		
		<form method="post" action="AlterarMobilia">
			<div class="form-group">
			  
			  <%
			 	out.println("<input class='form-control' name='desc' id='desc' value='"+request.getParameter("desc") +"'");
			  	out.println(" style='margin-bottom:3%;' placeholder='descricão' type='text'>");
			  	out.println("<input class='form-control' name='custo' id='custo' min='0.01' value='"+request.getParameter("custo") +"'");
			  	out.println(" style='margin-bottom:3%;' placeholder='custo' type='number' step=0.01 >");
			  	out.println("<input class='form-control' name='tempoEntrega' min='1' id='tempoEntrega' value='"+request.getParameter("tempo") +"'");
			  	out.println(" style='margin-bottom:3%;' placeholder='tempo de entrega' type='number'>");
			  	out.println("<input class='form-control' name='idHidden' id='idHidden' type='hidden' value=");
			  	out.println("'" + request.getParameter("id") + "'>");
			  %>
			</div>
			
			<div class="col-lg-15 col-lg-offset-1">
			 <h4>Escolha os cômodos: </h4>
	        <%  
			List <Comodo> l = (List)request.getAttribute("comodos");
				for(Comodo u: l){  
					out.println("<div class='checkbox'><label>"
								+"<input class='checkbox' name='comodos' id='"+ u.getId()
								+ "' type='checkbox' style='margin-bottom:3%;' value =" +u.getId() +">"
								+ u.getDescricao()+"</label></div>");
			}
			    out.println("</table></p>");
			%>
			</div>
			<input type='hidden' name='idComodos' id='idComodos'/>
			<div class="col-lg-15 col-lg-offset-1">
			  	<input type='hidden' value='' name='method' id='method'>
				<button type="reset" onclick="history.back();" class="btn btn-default">Cancelar</button>
		        <button type="submit" class="btn btn-primary" id='deleteBtn'>Excluir</button>
		        <button type="submit" class="btn btn-success" id='saveBtn' onclick="getComodo()">Salvar</button>
		      
		        
	        </div>
	</form>
</div>
</center>	
</body>
</html>