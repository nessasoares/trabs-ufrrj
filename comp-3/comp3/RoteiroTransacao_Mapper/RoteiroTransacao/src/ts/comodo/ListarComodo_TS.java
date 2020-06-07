package ts.comodo;

import java.sql.SQLException;
import java.util.List;

import entidades.Comodo;
import mapper.ComodoMAPPER;

public class ListarComodo_TS {

	public List<Comodo>  execute(){
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
