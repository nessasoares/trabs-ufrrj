package ts.comodo;

import java.sql.SQLException;

import dao.ComodoDAO;

public class AlterarComodo_TS {

	public void execute(String id, String method, String desc){
			try {
				ComodoDAO.alterComodo(id, desc);
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}

		}
	}
	
