package ts.contrato;

import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import entidades.Ambiente;
import entidades.Comodo;
import entidades.ItemVenda;
import mapper.AmbienteMAPPER;
import mapper.ComodoCompostoMAPPER;
import mapper.ComodoMAPPER;
import mapper.ContratoMAPPER;

public class CriarContrato_TS {

	public void execute(){
		try {
			ContratoMAPPER.criaContrato();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}
}
