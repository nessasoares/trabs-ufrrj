package ts.contrato;

import java.sql.SQLException;

import entidades.Contrato;


public class CancelarContrato_TS {

	public void execute(){
			try {
				Contrato.cancelContrato();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
	}
	
}
