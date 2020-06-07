package ts.comodo;

import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import entidades.Comodo;
import entidades.ComodoComposto;

public class CriarComodoComposto_TS {

	public void execute(String desc, ArrayList<String> comodos){
		try {
			ComodoComposto.insertComodoComposto(desc, comodos);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
