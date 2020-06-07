package ts.contrato;

import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import entidades.Ambiente;
import entidades.Comodo;
import entidades.ItemVenda;
import gateway.ContratoGTW;

public class CriarContrato_TS {

	public void execute(){
		try {
			ContratoGTW.criaContrato();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}
}
