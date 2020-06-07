package ts.ambiente;

import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import entidades.Ambiente;
import entidades.Comodo;
import entidades.ItemVenda;
import mapper.AmbienteMAPPER;
import mapper.ComodoCompostoMAPPER;
import mapper.ComodoMAPPER;

public class CriarAmbiente_TS {

	public void execute(int paredes, int portas, float metragem, ArrayList<ItemVenda> iv){
		Ambiente a = null; 
		try {
			a = new Ambiente(paredes, portas, metragem);
			float custo = a.custo(iv);
			AmbienteMAPPER.insereAmbiente(a, custo);
			a.tempoEntrega();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
