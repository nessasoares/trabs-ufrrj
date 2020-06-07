<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
	<%@include file="header.jsp" %>
	<%@ page import = "controladores.comodo.*" %>
	<%@ page import = "entidades.Comodo" %>
	<%@ page import = "java.util.*" %>
	
</head>
<%@ page import = "dao.ComodoDAO" %>
<script type='text/javascript'>
	$(document).ready(function(){
		$('#tipoComodo').on('change', function() {
			  if( this.value == "ComodoComposto"){
				  $('#comodosCC').show();
				  this.value = "ComodoComposto";
			  } else{
				  $('#comodosCC').hide();
			  }
			});
	});
	
	function getComodos(){
		var comodos = [];
	    $('input[name="comodos"]:checked').each(function(i){
	    	comodos[i] = $(this).val();
	      console.log(this.value);
        });
	    $('input[name="idComodos"]').val(comodos);
	}
	
	
</script>

<body>
 <div class="col-lg-3 col-lg-offset-4" >
	<h3><center><font face="Calibri" color="gray">Estilo:</font> </center></h3>
	<h5><center><font face="Calibri" color="gray">Personalize seu cômodo!</font> </center></h5><br>
		
	<form method="post" action="CriarComodo">
			<div class="form-group">
			  <input class="form-control" name="descricao" id="descricao" type="text" placeholder="Descrição do comodo">
			  </div>
			  <div style="margin-bottom:3%;margin-left:3%;">
			  <label>Tipo de cômodo:</label>
			  <select name ="tipoComodo" id="tipoComodo">
			  	<option value="Quarto">Quarto</option>
			  	<option value="Sala">Sala</option>
			  	<option value="Cozinha">Cozinha</option>
			  	<option value="ComodoComposto">Comodo Composto</option>

			  </select>
			</div>
			<div id="comodosCC" style="margin-bottom:3%;display:none;" >
			<h5>Escolha os cômodo:</h5>
			
			<!--"<td><div class='checkbox'><label>"
						+"<input class='checkbox' name='comodos' id='"+ u.getId()
						+ "' type='checkbox' style='margin-bottom:3%;' value =" +u.getId() +" >"
						+ u.getDescricao()+"</label></div></td>
				-->
				<tbody>
					<% 
						List <Comodo> l = (List)request.getAttribute("comodos");
						for(Comodo u: l){ 
							out.println("<tr>");
							out.println("<td><div class='checkbox'><label>"
										+"<input class='checkbox' name='comodos' id='"+ u.getId()
										+ "' type='checkbox' style='margin-bottom:3%;' value =" +u.getId() +" >"
										+ u.getDescricao()+"</label></div></td>");
							out.println("</tr>");
							
						}
					    out.println("</table></p>");
					%>
					<input type='hidden' name='idComodos' id='idComodos'/>
					<div class="col-lg-10 col-lg-offset-2">
					</div>
				</tbody>
			</div>
			
			<div class="col-lg-10 col-lg-offset-2">
				<button type="reset" class="btn btn-default">Cancel</button>
		        <button type="submit" onclick='getComodos()' class="btn btn-success">Submit</button>
	        </div>
	</form>
</div>
</center>	
</body>
</html>