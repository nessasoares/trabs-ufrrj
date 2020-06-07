package ts.contrato;

import java.sql.SQLException;
import java.util.List;

import entidades.*;

public class UpdateContrato_TS {

	public Contrato execute(float comissao, List<Ambiente> ambientes){
		float valor = Contrato.valorContrato(ambientes, comissao);
		int prazo = Contrato.prazo(ambientes);
		Contrato c = new Contrato(comissao, valor, prazo);
		try {
			Contrato.updateContrato(c);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		return c;
	}
	
}