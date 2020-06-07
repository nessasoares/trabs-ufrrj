package br.recomendacao.livros;

public class Autor {
	private int id;

	private String nomeAutor;
	
	public Autor(){}
	
	public Autor(String nomeA){
		this.nomeAutor=nomeA;
	}
	
	public String getNomeAutor() {
		return nomeAutor;
	}

	public void setNomeAutor(String nomeAutor) {
		this.nomeAutor = nomeAutor;
	}
	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}

}
