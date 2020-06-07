package entidades;

import java.sql.SQLException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;

import mapper.MobiliaMAPPER;

public class Cozinha extends Comodo{
	
	
	public Cozinha(String id, String desc, String tipo){
		setDescricao(desc);
		setId(id);
		setTipo(tipo);
	}

	@Override
	public List<Mobilia> listaMobiliaDisponivel(List <String> set) {
		List<Mobilia> array = new ArrayList<>();
			try {
				for(Mobilia m: MobiliaMAPPER.listMobiliaComodo(getId())){
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
