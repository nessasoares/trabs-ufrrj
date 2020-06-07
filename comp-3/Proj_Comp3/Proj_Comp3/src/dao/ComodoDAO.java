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

import entidades.Comodo;
import entidades.ComodoComposto;
import entidades.Cozinha;
import entidades.Quarto;
import entidades.Sala;
import jdbc.PostgreSQLJDBC;

public class ComodoDAO {

	
	public static void insereComodo(String desc, String tipo) throws SQLException{
		
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
	            	PreparedStatement stmt = conn.prepareStatement("INSERT INTO comodo (descricao, tipo) VALUES"+
	            								"( ?,(SELECT id from tipo_comodo WHERE tipo = ?) );");
	            	stmt.setString(1, desc);
	            	stmt.setString(2, tipo);
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
	
	public static void insereComodoComposto(String desc, String cc1, String cc2) throws SQLException{
		
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
	            	PreparedStatement stmt = conn.prepareStatement(
	            			"INSERT INTO comodo_composto (id_comodo, comodo_1, comodo_2) "
	            			+ "VALUES ((select c.id from comodo as c where descricao = ?),"
	            			+ " (select c.id from tipo_comodo as c where tipo = ?),"
	            			+ " (select c.id from tipo_comodo as c where tipo = ?));");
	            	stmt.setString(1, desc);
	            	stmt.setString(2, cc1);
	            	stmt.setString(3, cc2);
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

	
	public static List<Comodo> listaComodo() throws SQLException{
		Connection conn = null;
		Statement stmt = null;
		String sql = "select c.id, c.descricao, t.tipo from comodo as c "+
						"left join tipo_comodo as t "+
						"on (c.tipo = t.id) order by c.id;";
		List<Comodo> l = new ArrayList<Comodo>();
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
	            		String tipo = rs.getString("tipo");
	            		Comodo c = selectType(d, id, tipo); 
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
	
public static Comodo selectType(String d, String id, String tipo){
	Comodo c = null;
	switch (tipo) {
	case "quarto":
		c = new Quarto(id, d);
		break;

	case "sala":
		c = new Sala(id, d);
		break;
	case "cozinha":
		c = new Cozinha(id, d);
		break;
	case "comodoComposto":
		c = new ComodoComposto(id, d);
		break;
	default:
		break;
	}
	return c;
	
}

public static void deleteComodo(String id) throws SQLException{
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

public static void alterComodo(String id, String new_desc) throws SQLException{
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

public static List<String> allComodo() throws SQLException{
	Connection conn = null;
	String sql = "select * from tipo_comodo;";
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
	
}
	
}
