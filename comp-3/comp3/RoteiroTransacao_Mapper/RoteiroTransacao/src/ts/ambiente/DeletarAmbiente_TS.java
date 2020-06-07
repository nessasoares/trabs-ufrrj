package ts.ambiente;

import java.sql.SQLException;

import mapper.ComodoMAPPER;

public class DeletarAmbiente_TS {

	public void execute(String id){
			try {
				ComodoMAPPER.deleteComodo(id);
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
	}
	
}
