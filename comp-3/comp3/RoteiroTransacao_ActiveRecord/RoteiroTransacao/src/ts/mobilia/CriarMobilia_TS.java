package ts.mobilia;

import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import entidades.Comodo;
import entidades.Mobilia;

public class CriarMobilia_TS {

	public void execute(String desc, float custo, int tempoEntrega){
		try {
			Mobilia.insereMobilia(desc, custo, tempoEntrega);
			
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}