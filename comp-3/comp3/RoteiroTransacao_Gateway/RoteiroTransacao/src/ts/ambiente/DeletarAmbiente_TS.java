package ts.ambiente;

import java.sql.SQLException;

import gateway.ComodoGTW;

public class DeletarAmbiente_TS {

	public void execute(String id){
			try {
				ComodoGTW.deleteComodo(id);
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
	}
	
}
