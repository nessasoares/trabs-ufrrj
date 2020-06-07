package entidades;

public class ItemVenda {

	private int quantidade;
	private int idMobilia;

	public ItemVenda(){
		
	}
	public ItemVenda(int quantidade, int idMobilia){
		setId(idMobilia);
		setQuantidade(quantidade);
	}	
	
	public int getQuantidade() {
		return quantidade;
	}

	public void setQuantidade(int quantidade) {
		this.quantidade = quantidade;
	}
	public int getId() {
		return idMobilia;
	}
	public void setId(int id) {
		this.idMobilia = id;
	}
}
