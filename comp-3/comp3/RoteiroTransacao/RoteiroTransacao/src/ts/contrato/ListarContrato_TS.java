package ts.contrato;

import java.sql.SQLException;
import java.util.List;

import dao.AmbienteDAO;
import dao.ComodoDAO;
import entidades.Ambiente;
import entidades.Comodo;

public class ListarContrato_TS {

	public List<Ambiente>  execute(){
		List<Ambiente> l = null ; 
		try {
			l =AmbienteDAO.listaAmbiente();

		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return l;
	}
}