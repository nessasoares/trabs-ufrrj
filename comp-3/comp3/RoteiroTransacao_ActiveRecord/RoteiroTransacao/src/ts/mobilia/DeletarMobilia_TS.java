package ts.mobilia;

import java.sql.SQLException;

import entidades.Mobilia;

public class DeletarMobilia_TS {

	public void execute(String id){
			try {
				Mobilia.deleteMobilia(id);
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
	}
	
}
