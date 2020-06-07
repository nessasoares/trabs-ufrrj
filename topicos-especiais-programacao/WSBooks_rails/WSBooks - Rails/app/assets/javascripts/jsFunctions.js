
function verificarCamposJs(){
	
	if (document.getElementById('inputTitulo') != null && document.getElementById('inputTitulo').value == '') {
		return 4;
	}
	if (document.getElementById('inputAutor') != null && document.getElementById('inputAutor').value == '') {
		return 4;
	}
	if (document.getElementById('inputAno') != null && document.getElementById('inputAno').value == '') {
		return 4;
	}
	if (document.getElementById('inputEditora') != null && document.getElementById('inputEditora').value == '') {
		return 4;
	}
	if(document.getElementById("inputAno").value< 1900 || document.getElementById("inputAno").value > 2015){
		return 5;
	}
	
	
}

function verificarCamposUsuario(){

	if (document.getElementById('inputNome') != null && document.getElementById('inputNome').value == '') {
		return 4;
	}
	if (document.getElementById('inputEmail') != null && document.getElementById('inputEmail').value == '') {
		return 4;
	}
	if (document.getElementById('inputSenha') != null && document.getElementById('inputSenha').value == '') {
		return 4;
	}
	if (document.getElementById('inputUsername') != null && document.getElementById('inputUsername').value == '') {
		return 4;
	}
	if (document.getElementById('inputConfirmaSenha') != null && document.getElementById('inputConfirmaSenha').value == '') {
		return 4;
	}
	if(document.getElementById("inputConfirmaSenha").value !=   document.getElementById("inputSenha").value ){
		return 5;
	}
	
}

function OnlyNum(e){
	var tecla=(window.event)?event.keyCode:e.which;
	if((tecla>47 && tecla<58)) return true;
	else{
		if (tecla==8 || tecla==0) return true;
		else  return false;
	}	
	
}

