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

import entidades.Mobilia;
import jdbc.PostgreSQLJDBC;

public class MobiliaDAO {

	
	public static void insereMobilia(String desc, float custo, int tempoEntrega) throws SQLException{
		
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
	            	PreparedStatement stmt = conn.prepareStatement("INSERT INTO mobilia (descricao, custo, tempoEntrega) VALUES"+
	            								"( ?,?,?);");
	            	stmt.setString(1, desc);
	            	stmt.setFloat(2, custo);
	            	stmt.setInt(3, tempoEntrega);
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
	
	public static List<Mobilia> listaMobilia() throws SQLException{
		Connection conn = null;
		Statement stmt = null;
		String sql = "select * from mobilia order by id;";
		List<Mobilia> l = new ArrayList<Mobilia>();
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
	            		Float custo = Float.valueOf(rs.getString("custo"));
	            		int tempo = Integer.parseInt(rs.getString("tempoEntrega"));
	            		Mobilia c = new Mobilia(id,d,custo,tempo); 
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
	
public static void deleteMobilia(String id) throws SQLException{
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
	            	PreparedStatement stmt = conn.prepareStatement("delete from mobilia where id = ?;");
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

public static void alterMobilia(String id, String desc, Float custo, int tempo) throws SQLException{
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
            	PreparedStatement stmt = conn.prepareStatement("UPDATE mobilia SET descricao=?,"
            													+ "custo=?, tempoentrega=? "+
										            			"WHERE id=?;");
            	stmt.setString(1, desc);
            	stmt.setFloat(2, custo);
            	stmt.setInt(3, tempo);
                stmt.setInt(4, int_id);
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

/*
public static List<String> allMobilia() throws SQLException{
	Connection conn = null;
	String sql = "select * from tipo_mobilia;";
	Statement stmt = null;

	List<String> l = new ArrayList<String>();
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
         		String d = rs.getString("tipo");
         		l.add(d);
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
	
}*/
	
}
