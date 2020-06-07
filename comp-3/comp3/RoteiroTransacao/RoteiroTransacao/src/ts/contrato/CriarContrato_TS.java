package ts.contrato;

import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import dao.AmbienteDAO;
import dao.ComodoCompostoDAO;
import dao.ComodoDAO;
import dao.ContratoDAO;
import entidades.Ambiente;
import entidades.Comodo;
import entidades.ItemVenda;

public class CriarContrato_TS {

	public void execute(){
		try {
			ContratoDAO.criaContrato();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}
}
