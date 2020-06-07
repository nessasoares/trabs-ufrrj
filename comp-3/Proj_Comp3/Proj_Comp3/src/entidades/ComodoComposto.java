package entidades;

import java.util.List;

public class ComodoComposto extends Comodo{

	public ComodoComposto(String id, String d) {
		setDescricao(d);
		setId(id);
	}

	@Override
	public List<Mobilia> listaMobiliaDisponivel() {
		// TODO Auto-generated method stub
		return null;
	}

}
