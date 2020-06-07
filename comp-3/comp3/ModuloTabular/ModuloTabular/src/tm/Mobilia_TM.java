package tm;

import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import dao.MobiliaDAO;
import entidades.Mobilia;

public class Mobilia_TM {

	public  static List<Mobilia>  ListarMobiliaComodo(String id){
		List <Mobilia> l = new ArrayList<Mobilia>();
		try {
			l = MobiliaDAO.listMobiliaComodo(id);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return l;
	}
	
	public   void DeletarMobilia(String id){
		try {
			MobiliaDAO.deleteMobilia(id);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public   List<Mobilia>  ListarMobilia(){
		List<Mobilia> l = null ; 
		try {
			l = MobiliaDAO.listaMobilia();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return l;
	}
	
	
	public   void CriarMobilia(String desc, float custo, int tempoEntrega){
		try {
			MobiliaDAO.insereMobilia(desc, custo, tempoEntrega);
			
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public void AlterarMobilia(String id, String desc, float custo, int tempoEntrega, ArrayList<String>comodos){
		Mobilia m = new Mobilia(id, desc, custo, tempoEntrega);
		try {
			MobiliaDAO.alterMobilia(m, comodos);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}
	
	
	
}
