package md;

import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

import gateway.AmbienteGTW;
import gateway.MobiliaGTW;

public class AmbienteMD {

	private int id;
	private int numParedes;
	private int numPortas;
	private float metragem;
	private float custo;
	private int tempo;
	
	public AmbienteMD(int i, int paredes, int portas, float m){
		setId(i);
		setNumParedes(paredes);
		setNumPortas(portas);
		setMetragem(m);
	}
	
	public AmbienteMD(int paredes, int portas, float m){
		setNumParedes(paredes);
		setNumPortas(portas);
		setMetragem(m);
	}
	
	public AmbienteMD(int paredes, int portas, float m, float c, int t){
		setNumParedes(paredes);
		setNumPortas(portas);
		setMetragem(m);
		setCusto(c);
		setTempo(t);
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

	public int getId() {
		return id;
	}

	public void setId(int id) {
		this.id = id;
	}
	
	public float custo(ArrayList<ItemVendaMD> iv){
		float total = 0;

		for(ItemVendaMD i: iv){
			try {
				MobiliaMD m = MobiliaGTW.getMobiliaById(i.getId());
				total = total + (m.getCusto()*i.getQuantidade());
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		total = (float) (total + (10*getNumParedes()) + (5*getNumPortas()) + (2.5*getMetragem()));
		return total;
	}
	
	public void tempoEntrega(){
		int total = 0;
		int t =0; 
			try {
				t = MobiliaGTW.getMobiliaByTempo();
				total = t + (2*getNumParedes())+(getNumPortas()/2);
				AmbienteGTW.insertTempoAmbiente(total);

			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
	}

	public float getCusto() {
		return custo;
	}

	public void setCusto(float custo) {
		this.custo = custo;
	}

	public int getTempo() {
		return tempo;
	}

	public void setTempo(int tempo) {
		this.tempo = tempo;
	}
	
	public static void criar(int paredes, int portas, float metragem, ArrayList<ItemVendaMD> iv){
		AmbienteMD a = null; 
		try {
			a = new AmbienteMD(paredes, portas, metragem);
			float custo = a.custo(iv);
			AmbienteGTW.insereAmbiente(paredes, portas, metragem, custo);
			a.tempoEntrega();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public static List<AmbienteMD>  get(){
		List<AmbienteMD> l = null ; 
		try {
			l =AmbienteGTW.selectAmbiente();

		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return l;
	}
	
	public static List<AmbienteMD>  listar(){
		List<AmbienteMD> l = null ; 
		try {
			l =AmbienteGTW.listaAmbiente();

		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return l;
	}

}
