package gateway;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

import javax.naming.Context;
import javax.naming.InitialContext;
import javax.sql.DataSource;

import entidades.Sala;

public class SalaGTW {

	
	public static void insereSala(String desc) throws SQLException{
		
		Connection conn = null;
		 try
	        {
	            Context ctx = new InitialContext();
	            if(ctx == null )
	                throw new Exception("Boom - No Context");
	            DataSource ds = (DataSource)ctx.lookup("java:comp/env/jdbc/postgres");
	            if (ds != null) 
	            {
	                conn = ds.getConnection();
	            	PreparedStatement stmt = conn.prepareStatement("INSERT INTO comodo (descricao) "
	            			+ "VALUES (?);");
	            	stmt.setString(1, desc);
                    stmt.execute();
                    stmt.close();
	                
                   // if(rst.next())
	            }
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
	
	public static List<Sala> listaSala() throws SQLException{
		Connection conn = null;
		Statement stmt = null;
		String sql = "select * from comodo;";
		List<Sala> l = new ArrayList<Sala>();
		 try
	        {
	            Context ctx = new InitialContext();
	            if(ctx == null )
	                throw new Exception("Boom - No Context");
	            DataSource ds = (DataSource)ctx.lookup("java:comp/env/jdbc/postgres");
	            if (ds != null) 
	            {
	                conn = ds.getConnection();
	            	stmt = conn.createStatement();
	            	ResultSet rs = stmt.executeQuery(sql);
	            	while(rs.next()){
	            		String id = rs.getString("id");
	            		String d = rs.getString("descricao");
	            		Sala c = new Sala(id, d);
	            		l.add(c);
	            	}
	            }
	        }
	        catch(Exception e) 
	        {
	            e.printStackTrace();
	        }
		 	finally
		 	{
		 		conn.close();
		 	}
		return l;
		
	}
	
public static void deleteSala(String id) throws SQLException{
		int int_id = Integer.parseInt(id);
		Connection conn = null;
		 try
	        {
	            Context ctx = new InitialContext();
	            if(ctx == null )
	                throw new Exception("Boom - No Context");
	            DataSource ds = (DataSource)ctx.lookup("java:comp/env/jdbc/postgres");
	            if (ds != null) 
	            {
	                conn = ds.getConnection();
	            	PreparedStatement stmt = conn.prepareStatement("delete from comodo where id = ?;");
	            	stmt.setInt(1, int_id);
                    stmt.execute();
                    stmt.close();
	                
                   // if(rst.next())
	            }
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

public static Sala searchSala(String s_id) throws SQLException{
	Connection conn = null;
	Statement stmt = null;
	Sala c = null;
	String sql = "select descricao from comodo where id = '"+s_id +"';";
	 try
        {
            Context ctx = new InitialContext();
            if(ctx == null )
                throw new Exception("Boom - No Context");
            DataSource ds = (DataSource)ctx.lookup("java:comp/env/jdbc/postgres");
            if (ds != null) 
            {
                conn = ds.getConnection();
            	stmt = conn.createStatement();
            	ResultSet rs = stmt.executeQuery(sql);
           		String id = rs.getString("id");
           		String d = rs.getString("descricao");
           		c = new Sala(id, d);
            }
        }
        catch(Exception e) 
        {
            e.printStackTrace();
        }
	 	finally
	 	{
	 		conn.close();
	 	}
	return c;
	
}


public static void alterSala(String id, String new_desc) throws SQLException{
	int int_id = Integer.parseInt(id);
	Connection conn = null;
	 try
        {
            Context ctx = new InitialContext();
            if(ctx == null )
                throw new Exception("Boom - No Context");
            DataSource ds = (DataSource)ctx.lookup("java:comp/env/jdbc/postgres");
            if (ds != null) 
            {
                conn = ds.getConnection();
            	PreparedStatement stmt = conn.prepareStatement("UPDATE comodo SET descricao=? "+
										            			"WHERE id=?;");
            	stmt.setString(1, new_desc);
            	stmt.setInt(2, int_id);
                stmt.execute();
                stmt.close();
                
               // if(rst.next())
            }
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
