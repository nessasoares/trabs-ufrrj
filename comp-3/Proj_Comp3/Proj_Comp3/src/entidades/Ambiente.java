package entidades;

public class Ambiente {

	private int numParedes;
	private int numPortas;
	private float metragem;
	
	
	public float custo(){
		float c = 1;
		
		return c;
	}
	
	public int tempoEntrega(){
		int t = 1;
		
		return t; 
	}

	public int getNumParedes() {
		return numParedes;
	}

	public void setNumParedes(int numParedes) {
		this.numParedes = numParedes;
	}

	public int getNumPortas() {
		return numPortas;
	}

	public void setNumPortas(int numPortas) {
		this.numPortas = numPortas;
	}

	public float getMetragem() {
		return metragem;
	}

	public void setMetragem(float metragem) {
		this.metragem = metragem;
	}

}

