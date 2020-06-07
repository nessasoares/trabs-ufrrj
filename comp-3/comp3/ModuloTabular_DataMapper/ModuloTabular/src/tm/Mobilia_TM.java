package tm;

import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import entidades.Mobilia;
import mapper.MobiliaMAPPER;

public class Mobilia_TM {

	public  static List<Mobilia>  ListarMobiliaComodo(String id){
		List <Mobilia> l = new ArrayList<Mobilia>();
		try {
			l = MobiliaMAPPER.listMobiliaComodo(id);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return l;
	}
	
	public   void DeletarMobilia(String id){
		try {
			MobiliaMAPPER.deleteMobilia(id);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public   List<Mobilia>  ListarMobilia(){
		List<Mobilia> l = null ; 
		try {
			l = MobiliaMAPPER.listaMobilia();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return l;
	}
	
	
	public   void CriarMobilia(String desc, float custo, int tempoEntrega){
		try {
			Mobilia m = new Mobilia(desc, custo, tempoEntrega);
			MobiliaMAPPER.insereMobilia(m);
			
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public void AlterarMobilia(String id, String desc, float custo, int tempoEntrega, ArrayList<String>comodos){
		Mobilia m = new Mobilia(id, desc, custo, tempoEntrega);
		try {
			MobiliaMAPPER.alterMobilia(m, comodos);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}
	
	
	
}
