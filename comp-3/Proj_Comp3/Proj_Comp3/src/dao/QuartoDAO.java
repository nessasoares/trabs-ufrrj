package dao;

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

import entidades.Quarto;
import jdbc.PostgreSQLJDBC;

public class QuartoDAO {

	
	public static void insereQuarto(String desc) throws SQLException{
		
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
	            	PreparedStatement stmt = conn.prepareStatement("INSERT INTO quarto (descricao) "
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
	
	public static List<Quarto> listaQuarto() throws SQLException{
		Connection conn = null;
		Statement stmt = null;
		String sql = "select * from quarto;";
		List<Quarto> l = new ArrayList<Quarto>();
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
	            		Quarto c = new Quarto(id, d);
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
	
public static void deleteQuarto(String id) throws SQLException{
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
	            	PreparedStatement stmt = conn.prepareStatement("delete from quarto where id = ?;");
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

public static Quarto searchQuarto(String s_id) throws SQLException{
	Connection conn = null;
	Statement stmt = null;
	Quarto c = null;
	String sql = "select descricao from quarto where id = '"+s_id +"';";
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
           		c = new Quarto(id, d);
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


public static void alterQuarto(String id, String new_desc) throws SQLException{
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
            	PreparedStatement stmt = conn.prepareStatement("UPDATE quarto SET descricao=? "+
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
