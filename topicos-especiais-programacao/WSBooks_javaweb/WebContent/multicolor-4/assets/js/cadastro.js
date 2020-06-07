function OnlyNum(e){
				var tecla=(window.event)?event.keyCode:e.which;
				if((tecla>47 && tecla<58)) return true;
				else{
					if (tecla==8 || tecla==0) return true;
					else  return false;
				}	
				
}


function verificaTecla(e)
{
	 var x = (window.event)?event.keyCode:e.which;
	 var myExpression =/\W/g;
	 
	 alert(myExpression.test(x.value));
}
			
function verificaSenhas(){
	var senha1 = document.getElementById("senha");
	var senha2 = document.getElementById("confirmSenha");
	
	if(senha1.value != senha2.value){
		alert("SENHAS DIFERENTES");
        document.formulario.confirmSenha.focus();  

	}
}

function verificaUser(){
	if(document.getElementById('username').length() == 0){
		alert("INVALID USERNAME");
	}
}

function verificaCampos(){
	verificaSenhas();
	verificaUser();
}