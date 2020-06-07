package ts.contrato;

import java.sql.SQLException;
import java.util.List;

import entidades.*;
import gateway.ContratoGTW;

public class UpdateContrato_TS {

	public Contrato execute(float comissao, List<Ambiente> ambientes){
		float valor = Contrato.valorContrato(ambientes, comissao);
		int prazo = Contrato.prazo(ambientes);
		Contrato c = new Contrato(comissao, valor, prazo);
		try {
			ContratoGTW.updateContrato(comissao, prazo, valor);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		return c;
	}
	
}
