package gateway;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

import javax.naming.Context;
import javax.naming.InitialContext;
import javax.sql.DataSource;

import entidades.Contrato;

public class ContratoGTW extends Connectionbd{

	
	public static void criaContrato() throws SQLException{
		
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
	
	public static void updateContrato(float comissao, int prazo, float valor) throws SQLException{
		Connection conn = null;
		 try
	        {
             conn = getConnection();

	            	PreparedStatement stmt = conn.prepareStatement("UPDATE contrato SET comissao=?,"
	            													+ "prazo=?, valor=? "+
											            			"WHERE id=(select id from contrato order by id desc limit 1);");
	            	stmt.setFloat(1, comissao);
	            	stmt.setInt(2, prazo);
	            	stmt.setFloat(3, valor);
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
	
	
	public static void cancelContrato() throws SQLException{
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
