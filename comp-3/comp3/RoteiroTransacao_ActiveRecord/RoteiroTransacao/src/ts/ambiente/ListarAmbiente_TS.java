package ts.ambiente;

import java.sql.SQLException;
import java.util.List;

import entidades.Ambiente;
import entidades.Comodo;

public class ListarAmbiente_TS {

	public List<Ambiente>  execute(){
		List<Ambiente> l = null ; 
		try {
			l =Ambiente.listaAmbiente();

		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return l;
	}
}
