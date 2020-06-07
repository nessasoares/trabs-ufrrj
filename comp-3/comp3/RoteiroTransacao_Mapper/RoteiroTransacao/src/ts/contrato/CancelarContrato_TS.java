package ts.contrato;

import java.sql.SQLException;

import mapper.ComodoMAPPER;
import mapper.ContratoMAPPER;

public class CancelarContrato_TS {

	public void execute(){
			try {
				ContratoMAPPER.cancelContrato();
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
	}
	
}
