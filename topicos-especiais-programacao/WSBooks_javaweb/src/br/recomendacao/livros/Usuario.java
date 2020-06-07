package br.recomendacao.livros;

import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

import sun.misc.BASE64Encoder;

public class Usuario {
	
	private int id;
	private String nome;
	private String email;
	private String username;
	private String senha;
	//private String confirmaSenha;
	private String genero;
	
	public Usuario(){}
	
	public Usuario(String n,String e, String u, String s, String g){
		this.nome=n;
		this.email=e;
		this.username=u;
		this.senha=s;
		
		if(g.equals(GeneroUsuario.MASCULINO.toString())){
			this.genero=GeneroUsuario.MASCULINO.toString();
		}else{
			this.genero=GeneroUsuario.FEMININO.toString();
		}
		
	}
	
	
	public String getNome() {
		return nome;
	}
	public void setNome(String nome) {
		this.nome = nome;
	}
	public String getEmail() {
		return email;
	}
	public void setEmail(String email) {
		this.email = email;
	}
	public String getUsername() {
		return username;
	}
	public void setUsername(String username) {
		this.username = username;
	}
	public String getSenha() {
		return senha;
	}
	public void setSenha(String senha) {
		this.senha = senha;
	}
	/*public String getConfirmaSenha() {
		return confirmaSenha;
	}
	public void setConfirmaSenha(String confirmaSenha) {
		this.confirmaSenha = confirmaSenha;
	}*/
	public String getGenero() {
		return genero;
	}
	public void setGenero(String genero) {
		this.genero = genero;
	}
	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	
	public String criptografa(String senha){  
        try{  
         MessageDigest digest = MessageDigest.getInstance("MD5");  
                       digest.update(senha.getBytes());  
         BASE64Encoder encoder = new BASE64Encoder();  
                return encoder.encode(digest.digest());  
        }catch(NoSuchAlgorithmException ns){  
            ns.printStackTrace();  
        }  
        return senha;  
    } 
}
