package tm;

import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import entidades.*;
import mapper.ComodoCompostoMAPPER;
import mapper.ComodoMAPPER;

public class Comodo_TM {
	
	public   void criarComodo(String desc, String tipo){
		Comodo c = null;
		try {
			switch(tipo){
			case "Quarto":
					c = new Quarto("", desc, tipo);
					break;
			case "Sala":
				c = new Sala("", desc, tipo);
				break;
			case "Cozinha":
				c = new Cozinha("", desc, tipo);
				break;
			case "ComodoComposto":
				c = new ComodoComposto("", desc, tipo);
				break;
			}
			ComodoMAPPER.insereComodo(c);
			
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
	}
	
	public    void criarComodoComposto(String desc, ArrayList<String> comodos){
		try {
			ComodoCompostoMAPPER.insertComodoComposto( comodos);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public   void alterarComodo(String id, String desc, String tipo){
		Comodo c = null;
		try {
			switch(tipo){
			case "Quarto":
					c = new Quarto(id, desc, tipo);
					break;
			case "Sala":
				c = new Sala(id, desc, tipo);
				break;
			case "Cozinha":
				c = new Cozinha(id, desc, tipo);
				break;
			case "ComodoComposto":
				c = new ComodoComposto(id, desc, tipo);
				break;
			}
			ComodoMAPPER.alterComodo(c);
			
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}	
	}
	
	
	public   void associarComodo(ArrayList<String> comodos){
		
		try {
			ComodoMAPPER.associarComodo(comodos);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}
	
	public   void DeletarComodo(String id){
		try {
			ComodoMAPPER.deleteComodo(id);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public List<Comodo> ListarComodo(){
		List<Comodo> l = null ; 
		try {
			l = ComodoMAPPER.listaComodo();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return l;
	}

}