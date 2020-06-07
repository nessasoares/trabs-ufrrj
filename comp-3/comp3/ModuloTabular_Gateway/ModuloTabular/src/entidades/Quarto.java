package entidades;

import java.sql.SQLException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;

import gateway.MobiliaGTW;

public class Quarto extends Comodo {

private String id;
	
	public Quarto(String id, String d){
		setDescricao(d);
		setId(id);
	}

	@Override
	public List<Mobilia> listaMobiliaDisponivel(List <String> set) {
		List<Mobilia> array = new ArrayList<>();
			try {
				for(Mobilia m: MobiliaGTW.listMobiliaComodo(getId())){
					if(!set.contains(m.getId())){
						array.add(m);
					}
				}	
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
			return array;
		
		}
		
		}