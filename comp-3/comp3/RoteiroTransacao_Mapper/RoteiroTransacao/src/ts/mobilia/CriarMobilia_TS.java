package ts.mobilia;

import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import entidades.Comodo;
import entidades.Mobilia;
import mapper.ComodoCompostoMAPPER;
import mapper.ComodoMAPPER;
import mapper.MobiliaMAPPER;

public class CriarMobilia_TS {

	public void execute(String desc, float custo, int tempoEntrega){
		try {
			Mobilia m = new Mobilia(desc, custo, tempoEntrega);
			MobiliaMAPPER.insereMobilia(m);
			
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
