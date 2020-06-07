package ts.mobilia;

import java.sql.SQLException;

import gateway.MobiliaGTW;

public class DeletarMobilia_TS {

	public void execute(String id){
			try {
				MobiliaGTW.deleteMobilia(id);
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
	}
	
}
