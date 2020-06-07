package tm;

import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import entidades.Comodo;
import entidades.ItemVenda;
import mapper.ComodoMAPPER;
import mapper.ItemVendaMAPPER;

public class ItemVenda_TM {
	public   List<Comodo>  ListarItemVenda(){
		List<Comodo> l = null ; 
		try {
			l = ComodoMAPPER.listaComodo();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return l;
	}
	
	public   void DeletarItemVenda(String id){
		try {
			ComodoMAPPER.deleteComodo(id);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public   void CriarItemVenda(ArrayList<ItemVenda>iv){
		try {
			ItemVendaMAPPER.insereItemVenda(iv);

		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
