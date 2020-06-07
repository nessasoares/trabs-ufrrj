<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
	<%@include file="header.jsp" %>
	
</head>
<body>
 <div class="col-lg-3 col-lg-offset-4" >
	<h3><center><font face="Calibri" color="gray">Estilo:</font> </center></h3>
	<h5><center><font face="Calibri" color="gray">Personalize seu cômodo!</font> </center></h5><br>
		
	<form method="post" action="CrCriarSala">
			<div class="form-group">
			  <input class="form-control" name="descricao" id="descricao" type="text" placeholder="Descrição do comodo">
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