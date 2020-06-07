package ts.mobilia;

import java.sql.SQLException;
import java.util.List;

import entidades.Comodo;
import entidades.Mobilia;
import gateway.MobiliaGTW;

public class ListarMobilia_TS {

	public List<Mobilia>  execute(){
		List<Mobilia> l = null ; 
		try {
			l = MobiliaGTW.listaMobilia();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return l;
	}
}
