package ts.ambiente;

import java.sql.SQLException;

import entidades.Comodo;


public class DeletarAmbiente_TS {

	public void execute(String id){
			try {
				Comodo.deleteComodo(id);
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
	}
	
}
