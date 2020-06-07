package ts.contrato;

import java.sql.SQLException;
import java.util.List;

import entidades.Ambiente;
import entidades.Comodo;
import gateway.AmbienteGTW;

public class ListarContrato_TS {

	public List<Ambiente>  execute(){
		List<Ambiente> l = null ; 
		try {
			l =AmbienteGTW.listaAmbiente();

		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return l;
	}
}
