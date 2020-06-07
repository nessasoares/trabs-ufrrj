package ts.comodo;

import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import entidades.Comodo;
import mapper.ComodoCompostoMAPPER;
import mapper.ComodoMAPPER;

public class CriarComodoComposto_TS {

	public void execute(ArrayList<String> comodos){
		try {
			ComodoCompostoMAPPER.insertComodoComposto(comodos);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
