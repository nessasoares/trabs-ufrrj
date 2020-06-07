package ts.comodo;

import java.sql.SQLException;

import entidades.Comodo;
import entidades.ComodoComposto;
import entidades.Cozinha;
import entidades.Quarto;
import entidades.Sala;
import mapper.ComodoMAPPER;

public class AlterarComodo_TS {

	public void execute(String id, String desc, String tipo){
		Comodo c = null;
		try {
			switch(tipo){
			case "Quarto":
					c = new Quarto(id, desc, tipo);
					break;
			case "Sala":
				c = new Sala(id, desc, tipo);
				break;
			case "Cozinha":
				c = new Cozinha(id, desc, tipo);
				break;
			case "ComodoComposto":
				c = new ComodoComposto(id, desc, tipo);
				break;
			}
			ComodoMAPPER.alterComodo(c);
			
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}	
		
		

		}
	}
	
