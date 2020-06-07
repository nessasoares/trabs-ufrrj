<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
	<%@include file="header.jsp" %>
	
</head>
<%@ page import = "dao.MobiliaDAO" %>
<%@ page import = "servicelayer.*" %>
<%@ page import = "java.util.*" %>
<%@ page import = "md.*" %>

<script>
	function getComodo(){
		var comodos = [];
		if($('input[name="comodos"]:checked').length > 0){
			$('input[name="comodos"]:checked').each(function(i){
		    	comodos[i] = $(this).val();
		      console.log(this.value);
		    });
		    $('input[name="idComodos"]').val(comodos);	
		    document.getElementById("create_form").submit();
		}else{
			alert("Nenhum cômodo foi selecionado!");
		}
	    
	}
</script>

<body>
 <div class="col-lg-3 col-lg-offset-4" >
	<h3><center><font face="Calibri" color="gray">Criar Mobilia:</font> </center></h3>
		
	<form method="post" action="CriarMobilia" id="create_form">
			<div class="form-group">
			  <input class="form-control" name="descricao" id="descricao" type="text" style='margin-bottom:3%;' placeholder="Descrição do mobilia" required>
			  <input class="form-control"  name="custo" id="custo" type="number" step=0.01 placeholder="Custo" style='margin-bottom:3%;' required>
			  <input class="form-control" min="1" name="tempoEntrega" id="tempoEntrega" type="number" placeholder="Tempo de entrega" style='margin-bottom:3%;' required>
			  </div>
			
	        <div style="margin-left:4%;">
	        <h4>Escolha os cômodos: </h4>
	        <%  
	        	List <ComodoMD> l = (List)request.getAttribute("comodos");
	        	
				for(ComodoMD u: l){  
					out.println("<div class='checkbox'><label>"
								+"<input class='checkbox' name='comodos' id='"+ u.getId()
								+ "' type='checkbox' style='margin-bottom:3%;' value =" +u.getId() +" >"
								+ u.getDescricao()+"</label></div>");
				}
			    out.println("</table></p>");
			%>
			</div>
			<input type='hidden' name='idComodos' id='idComodos'/>
			
			<div class="col-lg-10 col-lg-offset-2">
				<button type="reset" class="btn btn-default">Cancel</button>
		        <a class="btn btn-success" onclick="getComodo()">Submit</a>
	        </div>
	        
	</form>
</div>
</center>	
</body>
</html>