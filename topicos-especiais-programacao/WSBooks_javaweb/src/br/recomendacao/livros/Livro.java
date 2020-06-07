package br.recomendacao.livros;

public class Livro {
	
	private int id;
	private String titulo;
	private String autor;
	private String editora;
	private String ano;
	private String sinopse;
	private String arquivo;
	private Integer visita;
	private Integer curtida; 
	
	

	public Livro(){}
	
	public Livro(String t, String aut, String e, String a, String s, String arq, int vis, int l){
		this.titulo=t;
		this.autor=aut;
		this.editora=e;
		this.ano=a;
		this.sinopse=s;
		this.arquivo=arq;
		this.visita=vis;
		this.curtida=l;
	}
	
	public String getTitulo() {
		return titulo;
	}
	public void setTitulo(String titulo) {
		this.titulo = titulo;
	}
	public String getEditora() {
		return editora;
	}
	public void setEditora(String editora) {
		this.editora = editora;
	}
	public String getAno() {
		return ano;
	}
	public void setAno(String ano) {
		this.ano = ano;
	}
	public String getSinopse() {
		return sinopse;
	}
	public void setSinopse(String sinopse) {
		this.sinopse = sinopse;
	}
	public String getAutor() {
		return autor;
	}
	public void setAutor(String nomeAutor) {
		this.autor = nomeAutor;
	}
	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	public String getArquivo() {
		return arquivo;
	}
	public void setArquivo(String arquivo) {
		this.arquivo = arquivo;
	}
	public int getVisita() {
		return visita;
	}
	public void setVisita(Integer visita) {
		this.visita = visita;
	}

	public Integer getCurtida() {
		return curtida;
	}

	public void setCurtida(Integer curtida) {
		this.curtida = curtida;
	}
	
}
