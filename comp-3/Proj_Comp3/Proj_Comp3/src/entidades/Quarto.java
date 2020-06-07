package entidades;

import java.util.List;

public class Quarto extends Comodo {

private String id;
	
	public Quarto(String id, String d){
		setDescricao(d);
		setId(id);
	}

	@Override
	public List<Mobilia> listaMobiliaDisponivel() {
		// TODO Auto-generated method stub
		return null;
	}
}
