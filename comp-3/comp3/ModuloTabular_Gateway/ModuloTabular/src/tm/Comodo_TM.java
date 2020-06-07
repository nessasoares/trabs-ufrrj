package tm;

import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import entidades.Comodo;
import gateway.ComodoCompostoGTW;
import gateway.ComodoGTW;

public class Comodo_TM {
	
	public   void criarComodo(String desc, String tipo){
		try {
			ComodoGTW.insereComodo(desc, tipo);
			
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public    void criarComodoComposto(String desc, ArrayList<String> comodos){
		try {
			ComodoCompostoGTW.insertComodoComposto(comodos);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public   void alterarComodo(String id, String desc){
		try {
			ComodoGTW.alterComodo(id, desc);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}
	
	
	public   void associarComodo(ArrayList<String> comodos){
		
		try {
			ComodoGTW.associarComodo(comodos);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}
	
	public   void DeletarComodo(String id){
		try {
			ComodoGTW.deleteComodo(id);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public List<Comodo> ListarComodo(){
		List<Comodo> l = null ; 
		try {
			l = ComodoGTW.listaComodo();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return l;
	}

}
