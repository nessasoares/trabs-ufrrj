package ts.itemVenda;

import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import entidades.Comodo;
import entidades.ItemVenda;
import mapper.ComodoCompostoMAPPER;
import mapper.ComodoMAPPER;
import mapper.ItemVendaMAPPER;

public class CriarItemVenda_TS {

	public void execute(ArrayList<ItemVenda>iv){
		try {
			ItemVendaMAPPER.insereItemVenda(iv);

		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
