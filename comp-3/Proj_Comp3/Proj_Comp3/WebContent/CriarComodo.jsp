<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
	<%@include file="header.jsp" %>
	
</head>
<%@ page import = "dao.ComodoDAO" %>
<script type='text/javascript'>
	$(document).ready(function(){
		$('#tipoComodo').on('change', function() {
			alert(this.value);
			  if( this.value == "comodoComposto"){
				  $('#comodosCC').show();
				  this.value = "comodoComposto";
			  } else{
				  $('#comodosCC').hide();
			  }
			});
	});
</script>

<body>
 <div class="col-lg-3 col-lg-offset-4" >
	<h3><center><font face="Calibri" color="gray">Estilo:</font> </center></h3>
	<h5><center><font face="Calibri" color="gray">Personalize seu cômodo!</font> </center></h5><br>
		
	<form method="post" action="CrCriarComodo">
			<div class="form-group">
			  <input class="form-control" name="descricao" id="descricao" type="text" placeholder="Descrição do comodo">
			  </div>
			  <div style="margin-bottom:3%;">
			  <label>Tipo de cômodo:</label>
			  <select name ="tipoComodo" id="tipoComodo">
			  	<%for(String c : ComodoDAO.allComodo()){
					out.println("<option value=\"" + c+ "\" >" + c+ "</option>");
			  	}
			  	%>
			  </select>
			</div>
			<div id="comodosCC" style="margin-bottom:3%;display:none;" >
			<h5>Escolha os tipo de cômodo:</h5>
			  <label>Tipo de cômodo 1:</label>
			  <select name ="primeiroComodo" id="primeiroComodo">
			  	<%for(String c : ComodoDAO.allComodo()){
					out.println("<option value=\"" + c+ "\" >" + c+ "</option>");
			  	}
			  	%>
			  </select>
				
			  <label>Tipo de cômodo 2:</label>
			  <select name ="segundoComodo" id="segundoComodo">
			  	<%for(String c : ComodoDAO.allComodo()){
					out.println("<option value=\"" + c+ "\" >" + c+ "</option>");
			  	}
			  	%>
			  </select>
				
			</div>
			
			<div class="col-lg-10 col-lg-offset-2">
				<button type="reset" class="btn btn-default">Cancel</button>
		        <button type="submit" class="btn btn-primary">Submit</button>
	        </div>
	</form>
</div>
</center>	
</body>
</html>