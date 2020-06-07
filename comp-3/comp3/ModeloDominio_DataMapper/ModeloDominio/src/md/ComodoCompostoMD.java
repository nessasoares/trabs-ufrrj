package md;

import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import mapper.ComodoCompostoMAPPER;
import mapper.MobiliaMAPPER;

public class ComodoCompostoMD extends ComodoMD{
	public ComodoCompostoMD(String id, String desc, String tipo){ 
		setDescricao(desc);
		setId(id);
		setTipo(tipo);
	}
	@Override
	public List<MobiliaMD> listaMobiliaDisponivel(List <String> set) {
		List<MobiliaMD> array = new ArrayList<>();
			try {
				for(MobiliaMD m: MobiliaMAPPER.listMobiliaComodo(getId())){
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
	
	public static void criar(String desc, ArrayList<String> comodos){
		try {
			ComodoCompostoMAPPER.insertComodoComposto(comodos);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
