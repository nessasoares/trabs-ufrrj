package ts.contrato;

import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import entidades.Ambiente;
import entidades.Comodo;
import entidades.Contrato;
import entidades.ItemVenda;

public class CriarContrato_TS {

	public void execute(){
		try {
			Contrato.criaContrato();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}
}
