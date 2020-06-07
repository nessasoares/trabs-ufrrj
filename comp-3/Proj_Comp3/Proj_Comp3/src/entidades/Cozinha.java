package entidades;

import java.util.List;

public class Cozinha extends Comodo{
	
	private String id;
	
	public Cozinha(String id, String d){
		setDescricao(d);
		setId(id);
	}

	@Override
	public List<Mobilia> listaMobiliaDisponivel() {
		// TODO Auto-generated method stub
		return null;
	}
	
}
