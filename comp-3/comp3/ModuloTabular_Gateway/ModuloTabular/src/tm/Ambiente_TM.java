package tm;

import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import entidades.Ambiente;
import entidades.ItemVenda;
import gateway.AmbienteGTW;
import gateway.ComodoGTW;

public class Ambiente_TM {

	public void CriarAmbiente(int paredes, int portas, float metragem, ArrayList<ItemVenda> iv){
		Ambiente a = null; 
		try {
			a = new Ambiente(paredes, portas, metragem);
			float custo = a.custo(iv);
			AmbienteGTW.insereAmbiente(paredes, portas, metragem, custo);
			a.tempoEntrega();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public   void DeletarAmbiente(String id){
		try {
			ComodoGTW.deleteComodo(id);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public   List<Ambiente>  GetAmbiente(){
		List<Ambiente> l = null ; 
		try {
			l =AmbienteGTW.selectAmbiente();

		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return l;
	}
	
	public   List<Ambiente>  ListarAmbiente(){
		List<Ambiente> l = null ; 
		try {
			l =AmbienteGTW.listaAmbiente();

		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return l;
	}
}
