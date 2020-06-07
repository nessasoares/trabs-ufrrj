package entidades;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;

import dao.DAO;

public abstract class Comodo extends DAO{

	private String id;
	private String descricao;
	
	/*public Comodo(String id, String d){
		setDescricao(d);
		setId(id);
	}
	*/
	
	abstract public List<Mobilia> listaMobiliaDisponivel(List <String> set);
	
	public String getDescricao() {
		return descricao;
	}
	public void setDescricao(String descricao) {
		this.descricao = descricao;
	}
	public String getId() {
		return id;
	}
	public void setId(String id) {
		this.id = id;
	}
	
	//--------------------------------------------------------------------
	// 						SQL
	//-------------------------------------------------------------------
		
public static void insereComodo(String desc, String tipo) throws SQLException{
		
		Connection conn = null;
		 try
	        {
             conn = getConnection();

			 PreparedStatement stmt = conn.prepareStatement("INSERT INTO comodo (descricao_comodo, tipo_comodo) VALUES"+
	            								"( ?,?);");
	            	stmt.setString(1, desc);
	            	stmt.setString(2, tipo);
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
	
	
	
	public static List<Comodo> listaComodo() throws SQLException{
		Connection conn = null;
		Statement stmt = null;
		String sql = "select c.id, c.descricao_comodo, c.tipo_comodo from comodo as c "+
						"order by c.id;";
		List<Comodo> l = new ArrayList<Comodo>();
		 try
	        {
			 	conn = getConnection();

	            	stmt = conn.createStatement();
	            	ResultSet rs = stmt.executeQuery(sql);
	            	while(rs.next()){
	            		String id = rs.getString("id");
	            		String d = rs.getString("descricao_comodo");
	            		String tipo = rs.getString("tipo_comodo");
	            		Comodo c = selectType(d, id, tipo); 
	            		l.add(c);
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
	case "Quarto":
		c = new Quarto(id, d);
		break;

	case "Sala":
		c = new Sala(id, d);
		break;
	case "Cozinha":
		c = new Cozinha(id, d);
		break;
	case "ComodoComposto":
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
             conn = getConnection();
			 PreparedStatement stmt = conn.prepareStatement("delete from comodo where id = ?;");
	            	stmt.setInt(1, int_id);
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

public static void alterComodo(String id, String new_desc) throws SQLException{
	int int_id = Integer.parseInt(id);
	Connection conn = null;
	 try
        {
         conn = getConnection();

            	PreparedStatement stmt = conn.prepareStatement("UPDATE comodo SET descricao_comodo=? "
										            			+"WHERE id=?;");
            	stmt.setString(1, new_desc);
            	stmt.setInt(2, int_id);
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

public static List<String> allComodo() throws SQLException{
	Connection conn = null;
	String sql = "select * from comodo;";
	Statement stmt = null;

	List<String> l = new ArrayList<String>();
	 try
        {
         conn = getConnection();

         	stmt = conn.createStatement();
         	ResultSet rs = stmt.executeQuery(sql);
         	while(rs.next()){
         		String d = rs.getString("descricao_comodo");
         		l.add(d);
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

public static void associarComodo(ArrayList<String> cc1) throws SQLException{
	
	Connection conn = null;
	 try
        {
         conn = getConnection();

            	PreparedStatement stmt = conn.prepareStatement(
            			"INSERT INTO comodo_mobilia (id_mobilia, id_comodo) "
            			+ "VALUES ((select id from mobilia order by id desc limit 1),"
            			+ " (select c.id from comodo as c where id = ?));");
            	for(String c : cc1){
            		stmt.setInt(1, Integer.parseInt(c));
                    stmt.execute();
            	}
            	
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
