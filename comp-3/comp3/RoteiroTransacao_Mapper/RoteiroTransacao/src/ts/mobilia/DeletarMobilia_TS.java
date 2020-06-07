package ts.mobilia;

import java.sql.SQLException;

import mapper.ComodoMAPPER;
import mapper.MobiliaMAPPER;

public class DeletarMobilia_TS {

	public void execute(String id){
			try {
				MobiliaMAPPER.deleteMobilia(id);
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
	}
	
}
