package ts.comodo;

import java.sql.SQLException;
import java.util.ArrayList;

import mapper.ComodoMAPPER;

public class AssociarComodo_TS {

	public void execute(ArrayList<String> comodos){
		
		try {
			ComodoMAPPER.associarComodo(comodos);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}
	
}
