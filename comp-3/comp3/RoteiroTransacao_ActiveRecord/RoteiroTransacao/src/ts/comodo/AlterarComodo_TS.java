package ts.comodo;

import java.sql.SQLException;

import entidades.Comodo;


public class AlterarComodo_TS {

	public void execute(String id, String method, String desc){
			try {
				Comodo.alterComodo(id, desc);
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}

		}
	}
	
