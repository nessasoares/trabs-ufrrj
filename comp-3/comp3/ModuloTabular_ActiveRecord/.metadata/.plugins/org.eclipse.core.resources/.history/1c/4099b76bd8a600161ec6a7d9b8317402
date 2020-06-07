package tm;

import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import dao.ComodoDAO;
import dao.ItemVendaDAO;
import entidades.Comodo;
import entidades.ItemVenda;

public class ItemVenda_TM {
	public   List<Comodo>  ListarItemVenda(){
		List<Comodo> l = null ; 
		try {
			l = ComodoDAO.listaComodo();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return l;
	}
	
	public   void DeletarItemVenda(String id){
		try {
			ComodoDAO.deleteComodo(id);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public   void CriarItemVenda(ArrayList<ItemVenda>iv){
		try {
			ItemVendaDAO.insereItemVenda(iv);

		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
