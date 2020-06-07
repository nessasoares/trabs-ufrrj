package md;

import java.sql.SQLException;
import java.util.*;

import mapper.AmbienteMAPPER;
import mapper.ContratoMAPPER;

public class ContratoMD {
	
	private float comissao;
	private float valor;
	private int prazo;
	
	public ContratoMD(float comissao, float valor, int prazo){
		setComissao(comissao);
		setValor(valor);
		setPrazo(prazo);
	}
	
	public ContratoMD(){}
	
	public float getComissao() {
		return comissao;
	}

	public void setComissao(float comissao) {
		this.comissao = comissao;
	}
	
	public static float valorContrato(List<AmbienteMD> ambiente, float comissao){
		float soma_ambientes = 0, total;
		for(AmbienteMD a: ambiente){
			soma_ambientes = soma_ambientes + a.getCusto();
		}
		total = soma_ambientes * (1+comissao);
		return total;
	}
	
	public static int prazo(List<AmbienteMD> ambiente){
		int total = 0;
		for(AmbienteMD a: ambiente){
			total = total + a.getTempo();
		}
		return total;
		
	}

	public float getValor() {
		return valor;
	}

	public void setValor(float valor) {
		this.valor = valor;
	}

	public int getPrazo() {
		return prazo;
	}

	public void setPrazo(int prazo) {
		this.prazo = prazo;
	}
	
	public static void cancelar(){
		try {
			ContratoMAPPER.cancelContrato();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public static void criar(){
		try {
			ContratoMAPPER.criaContrato();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}
	
	public static List<AmbienteMD>  listar(){
		List<AmbienteMD> l = null ; 
		try {
			l =AmbienteMAPPER.listaAmbiente();

		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return l;
	}
	
	public static ContratoMD update(float comissao, List<AmbienteMD> ambientes){
		float valor = ContratoMD.valorContrato(ambientes, comissao);
		int prazo = ContratoMD.prazo(ambientes);
		ContratoMD c = new ContratoMD(comissao, valor, prazo);
		try {
			ContratoMAPPER.updateContrato(c);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		return c;
	}
}
