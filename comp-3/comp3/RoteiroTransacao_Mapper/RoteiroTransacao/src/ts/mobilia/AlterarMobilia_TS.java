package ts.mobilia;

import java.sql.SQLException;
import java.util.ArrayList;

import entidades.Mobilia;
import mapper.ComodoMAPPER;
import mapper.MobiliaMAPPER;

public class AlterarMobilia_TS {

	public void execute(String id, String desc, float custo, int tempoEntrega, ArrayList<String>comodos){
		Mobilia m = new Mobilia(id, desc, custo, tempoEntrega);
		try {
			MobiliaMAPPER.alterMobilia(m, comodos);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}
	
}
