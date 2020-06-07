package ts.comodo;

import java.sql.SQLException;
import java.util.List;

import entidades.Comodo;
import gateway.ComodoGTW;

public class ListarComodo_TS {

	public List<Comodo>  execute(){
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
