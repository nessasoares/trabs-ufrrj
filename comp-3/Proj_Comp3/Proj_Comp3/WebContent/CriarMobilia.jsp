<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
	<%@include file="header.jsp" %>
	
</head>
<%@ page import = "dao.MobiliaDAO" %>
<body>
 <div class="col-lg-3 col-lg-offset-4" >
	<h3><center><font face="Calibri" color="gray">Estilo:</font> </center></h3>
	<h5><center><font face="Calibri" color="gray">Personalize seu cômodo!</font> </center></h5><br>
		
	<form method="post" action="CrCriarMobilia">
			<div class="form-group">
			  <input class="form-control" name="descricao" id="descricao" type="text" style='margin-bottom:3%;' placeholder="Descrição do mobilia" required>
			  <input class="form-control" name="custo" id="custo" type="number" step=0.01 placeholder="Custo" style='margin-bottom:3%;' required>
			  <input class="form-control" name="tempoEntrega" id="tempoEntrega" type="number" placeholder="Tempo de entrega" style='margin-bottom:3%;' required>
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