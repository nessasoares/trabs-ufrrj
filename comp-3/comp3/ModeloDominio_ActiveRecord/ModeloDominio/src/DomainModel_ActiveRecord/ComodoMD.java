package DomainModel_ActiveRecord;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;


public abstract class ComodoMD extends ConnectionBD {

	private String id;
	private String descricao;
	
	/*public Comodo(String id, String d){
		setDescricao(d);
		setId(id);
	}
	*/
	
	abstract public List<MobiliaMD> listaMobiliaDisponivel(List <String> set);
	
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
	
	public static void associar(ArrayList<String> comodos){
		
		try {
			associarComodo(comodos);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	} 
	public static  void criar(String desc, String tipo){
		try {
			insereComodo(desc, tipo);
			
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	

	
	public static void delete(String id) throws SQLException{
		try {
			deleteComodo(id);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public  static List<ComodoMD>  listar(){
		List<ComodoMD> l = null ; 
		try {
			l = ComodoMD.listaComodo();
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return l;
	}
	
	public static  void alterar(String id, String method, String desc){
		try {
			alterComodo(id, desc);
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

	
	//----------------------------------------------------------------------------------------------------------
	//										SQL						
	//----------------------------------------------------------------------------------------------------------

	public static   void insereComodo(String desc, String tipo) throws SQLException{
		
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
	
	
	
	public static   List<ComodoMD> listaComodo() throws SQLException{
		Connection conn = null;
		Statement stmt = null;
		String sql = "select c.id, c.descricao_comodo, c.tipo_comodo from comodo as c "+
						"order by c.id;";
		List<ComodoMD> l = new ArrayList<ComodoMD>();
		 try
	        {
			 	conn = getConnection();

	            	stmt = conn.createStatement();
	            	ResultSet rs = stmt.executeQuery(sql);
	            	while(rs.next()){
	            		String id = rs.getString("id");
	            		String d = rs.getString("descricao_comodo");
	            		String tipo = rs.getString("tipo_comodo");
	            		ComodoMD c = selectType(d, id, tipo); 
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
	
public static  ComodoMD selectType(String d, String id, String tipo){
	ComodoMD c = null;
	switch (tipo) {
	case "Quarto":
		c = new QuartoMD(id, d);
		break;

	case "Sala":
		c = new SalaMD(id, d);
		break;
	case "Cozinha":
		c = new CozinhaMD(id, d);
		break;
	case "ComodoComposto":
		c = new ComodoCompostoMD(id, d);
		break;
	default:
		break;
	}
	return c;
	
}

public static  void deleteComodo(String id) throws SQLException{
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

public static  void alterComodo(String id, String new_desc) throws SQLException{
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

public static  List<String> allComodo() throws SQLException{
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

public static   void associarComodo(ArrayList<String> cc1) throws SQLException{
	
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