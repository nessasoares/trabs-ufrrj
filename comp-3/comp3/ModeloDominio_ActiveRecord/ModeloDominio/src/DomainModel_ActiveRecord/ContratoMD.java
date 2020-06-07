package DomainModel_ActiveRecord;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.util.*;

public class ContratoMD extends ConnectionBD {
	
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
	
	public   float valorContrato(List<AmbienteMD> ambiente, float comissao){
		float soma_ambientes = 0, total;
		for(AmbienteMD a: ambiente){
			soma_ambientes = soma_ambientes + a.getCusto();
		}
		total = soma_ambientes * (1+comissao);
		return total;
	}
	
	public   int prazo(List<AmbienteMD> ambiente){
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
	
	public   void cancelar(){
		try {
			cancelContrato();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public   void criar(){
		try {
			criaContrato();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}
	
	public   List<AmbienteMD>  listar(){
		List<AmbienteMD> l = null ; 
		AmbienteMD a = new AmbienteMD();
		try {
			l =a.listaAmbiente();

		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return l;
	}
	
	public   ContratoMD update(float comissao, List<AmbienteMD> ambientes){
		float valor = valorContrato(ambientes, comissao);
		int prazo = prazo(ambientes);
		ContratoMD c = new ContratoMD(comissao, valor, prazo);
		try {
			updateContrato(c);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		return c;
	}
	
	//----------------------------------------------------------------------------------------------------------
	//										SQL						
	//----------------------------------------------------------------------------------------------------------
	
public   void criaContrato() throws SQLException{
		
		Connection conn = null;
		 try
	        {
             conn = getConnection();

	            	PreparedStatement stmt = conn.prepareStatement("INSERT INTO contrato (prazo) values (0);");
		            stmt.execute();
	            	stmt.close();
	            }
	        
	        catch(Exception e) 
	        {
	            e.printStackTrace();
	        }
		 	finally
		 	{
		 		conn.close();
		 	}
		
	}
	
	public   void updateContrato(ContratoMD c) throws SQLException{
		Connection conn = null;
		 try
	        {
             conn = getConnection();

	            	PreparedStatement stmt = conn.prepareStatement("UPDATE contrato SET comissao=?,"
	            													+ "prazo=?, valor=? "+
											            			"WHERE id=(select id from contrato order by id desc limit 1);");
	            	stmt.setFloat(1, c.getComissao());
	            	stmt.setInt(2, c.getPrazo());
	            	stmt.setFloat(3, c.getValor());
	                stmt.execute();
	                stmt.close();
	                
	               // if(rst.next())
	            }
	        
	        catch(Exception e) 
	        {
	            e.printStackTrace();
	        }
		 	finally
		 	{
		 		conn.close();
		 	}
		
	}
	
	
	public   void cancelContrato() throws SQLException{
		Connection conn = null;
		 try
	        {
             conn = getConnection();

	            	PreparedStatement stmt = conn.prepareStatement("DELETE FROM contrato where id=(SELECT MAX(id) FROM contrato);");
	                stmt.execute();
	                stmt.close();
	                
	               // if(rst.next())
	            }
	        catch(Exception e) 
	        {
	            e.printStackTrace();
	        }
		 	finally
		 	{
		 		conn.close();
		 	}
		
	}
	
}
