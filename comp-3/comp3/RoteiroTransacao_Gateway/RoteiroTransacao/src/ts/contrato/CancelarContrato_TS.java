package ts.contrato;

import java.sql.SQLException;

import gateway.ContratoGTW;

public class CancelarContrato_TS {

	public void execute(){
			try {
				ContratoGTW.cancelContrato();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
	}
	
}
