package ts.mobilia;

import java.sql.SQLException;
import java.util.List;

import dao.ComodoDAO;
import dao.MobiliaDAO;
import entidades.Comodo;
import entidades.Mobilia;

public class ListarMobilia_TS {

	public List<Mobilia>  execute(){
		List<Mobilia> l = null ; 
		try {
			l = MobiliaDAO.listaMobilia();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return l;
	}
}