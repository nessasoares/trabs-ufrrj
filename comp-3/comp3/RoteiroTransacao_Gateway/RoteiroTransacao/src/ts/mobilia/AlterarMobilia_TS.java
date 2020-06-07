package ts.mobilia;

import java.sql.SQLException;
import java.util.ArrayList;

import entidades.Mobilia;
import gateway.MobiliaGTW;

public class AlterarMobilia_TS {

	public void execute(String id, String desc, float custo, int tempoEntrega, ArrayList<String>comodos){
		Mobilia m = new Mobilia(id, desc, custo, tempoEntrega);
		try {
			MobiliaGTW.alterMobilia(desc, custo, tempoEntrega, id, comodos);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}
	
}
