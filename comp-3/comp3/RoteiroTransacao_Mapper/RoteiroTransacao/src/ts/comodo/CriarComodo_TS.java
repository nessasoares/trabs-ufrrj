package ts.comodo;

import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import entidades.*;
import mapper.ComodoCompostoMAPPER;
import mapper.ComodoMAPPER;

public class CriarComodo_TS {

	public void execute(String desc, String tipo){
		Comodo c = null;
		try {
			switch(tipo){
			case "Quarto":
					c = new Quarto("", desc, tipo);
					break;
			case "Sala":
				c = new Sala("", desc, tipo);
				break;
			case "Cozinha":
				c = new Cozinha("", desc, tipo);
				break;
			case "ComodoComposto":
				c = new ComodoComposto("", desc, tipo);
				break;
			}
			ComodoMAPPER.insereComodo(c);
			
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
