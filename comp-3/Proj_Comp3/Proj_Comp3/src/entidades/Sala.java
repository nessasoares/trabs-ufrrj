package entidades;

import java.util.List;

public class Sala extends Comodo {

	
	public Sala (String id, String d){
		setDescricao(d);
		setId(id);
	}

	@Override
	public List<Mobilia> listaMobiliaDisponivel() {
		// TODO Auto-generated method stub
		return null;
	}
}
