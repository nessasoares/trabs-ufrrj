package mapper;

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
import entidades.Mobilia;
import entidades.Quarto;
import entidades.Sala;

public class MobiliaMAPPER extends ConnectionBD{

	
	public static void insereMobilia(Mobilia m) throws SQLException{
		
		Connection conn = null;
		 try
	        {
             conn = getConnection();

	            	PreparedStatement stmt = conn.prepareStatement("INSERT INTO mobilia (descricao_mobilia, custo, tempoEntrega) VALUES"+
	            								"( ?,?,?);");
	            	stmt.setString(1, m.getDescricao());
	            	stmt.setFloat(2, m.getCusto());
	            	stmt.setInt(3, m.getTempoEntrega());
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
public static void insereComodoMobilia(String id, ArrayList<String> comodos) throws SQLException{
		
		Connection conn = null;
		 try
	        {
             conn = getConnection();

	                PreparedStatement stmt = conn.prepareStatement("INSERT INTO comodo_mobilia (id_mobilia, id_comodo) "
	            			+ "VALUES (?,"
	            			+ " (select c.id from comodo as c where id = ?));");
					stmt.setInt(1, Integer.parseInt(id));
					for(String c : comodos){
						stmt.setInt(2, Integer.parseInt(c));
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
	
	public static List<Mobilia> listaMobilia() throws SQLException{
		Connection conn = null;
		Statement stmt = null;
		String sql = "select * from mobilia order by id;";
		List<Mobilia> l = new ArrayList<Mobilia>();
		 try
	        {
             conn = getConnection();

	            	stmt = conn.createStatement();
	            	ResultSet rs = stmt.executeQuery(sql);
	            	while(rs.next()){
	            		String id = rs.getString("id");
	            		String d = rs.getString("descricao_mobilia");
	            		Float custo = Float.valueOf(rs.getString("custo"));
	            		int tempo = Integer.parseInt(rs.getString("tempoEntrega"));
	            		Mobilia c = new Mobilia(id,d,custo,tempo); 
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
	
public static void deleteMobilia(String id) throws SQLException{
		int int_id = Integer.parseInt(id);
		Connection conn = null;
		 try
	        {
             conn = getConnection();

	            	PreparedStatement stmt = conn.prepareStatement("delete from mobilia where id = ?;");
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

public static void deleteComodoMobilia(String id) throws SQLException{
	int int_id = Integer.parseInt(id);
	Connection conn = null;
	 try
        {
		 		conn = getConnection();

            	PreparedStatement stmt = conn.prepareStatement("delete from comodo_mobilia where id = ?;");
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

public static void alterMobilia(Mobilia m, ArrayList<String>comodos) throws SQLException{
	int int_id = Integer.parseInt(m.getId());
	Connection conn = null;
	 try
        {
		 		conn = getConnection();

            	PreparedStatement stmt = conn.prepareStatement("UPDATE mobilia SET descricao_mobilia=?,"
            													+ "custo=?, tempoentrega=? "+
										            			"WHERE id=?;");
            	stmt.setString(1, m.getDescricao());
            	stmt.setFloat(2, m.getCusto());
            	stmt.setInt(3, m.getTempoEntrega());
                stmt.setInt(4, int_id);
                stmt.execute();
                
                stmt = conn.prepareStatement("delete from comodo_mobilia where id_mobilia = ?;");
				stmt.setInt(1, int_id);
				stmt.execute();

				stmt = conn.prepareStatement("INSERT INTO comodo_mobilia (id_mobilia, id_comodo) "
	            			+ "VALUES (?,"
	            			+ " (select c.id from comodo as c where id = ?));");
				stmt.setInt(1, Integer.parseInt(m.getId()));
				for(String c : comodos){
					stmt.setInt(2, Integer.parseInt(c));
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
public static void associarMobilia(String comodo, Object[] m) throws SQLException{
	
	Connection conn = null;
	 try
        {
         conn = getConnection();

            	PreparedStatement stmt = conn.prepareStatement("UPDATE comodo SET mobilia=? "
										            			+"WHERE descricao_mobilia=?;");
            	final java.sql.Array sqlArray = conn.createArrayOf("text", m);
            	stmt.setArray(1, sqlArray);
            	stmt.setString(2, comodo);
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


public static List<String> allMobilia() throws SQLException{
	Connection conn = null;
	String sql = "select * from tipo_mobilia;";
	Statement stmt = null;

	List<String> l = new ArrayList<String>();
	 try
        {
         conn = getConnection();

         	stmt = conn.createStatement();
         	ResultSet rs = stmt.executeQuery(sql);
         	while(rs.next()){
         		String d = rs.getString("tipo");
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

public static List<Mobilia> listMobiliaComodo(String id) throws SQLException{
	Connection conn = null;
	int i = Integer.parseInt(id);
	String sql = "select cm.id_mobilia, m.descricao_mobilia, m.custo, m.tempoentrega from comodo_mobilia as cm, "
				 + "mobilia as m where id_comodo = " + i  +" and cm.id_mobilia = m.id ORDER BY cm.id_mobilia;";
	Statement stmt = null;
	List<Mobilia> l = new ArrayList<Mobilia>();
	 try
        {
         conn = getConnection();

         	stmt = conn.createStatement();
         	ResultSet rs = stmt.executeQuery(sql);
         	while(rs.next()){
         		String id_mobilia = rs.getString("id_mobilia");
         		String m_descricao = rs.getString("descricao_mobilia");
         		Float m_custo = Float.valueOf(rs.getString("custo"));
         		int m_tempo = Integer.parseInt(rs.getString("tempoentrega"));
         		Mobilia d = new Mobilia(id_mobilia, m_descricao, m_custo, m_tempo);
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


public static List<Comodo> getComodos(String id) throws SQLException{
	Connection conn = null;
	int i = Integer.parseInt(id);
	String sql = "select c.descricao_comodo, c.id, c.tipo_comodo from comodo as c, comodo_mobilia as cm "+
				 "where id_mobilia = ? and cm.id_comodo = c.id;";
	List<Comodo> l = new ArrayList<Comodo>();
	 try
        {
         conn = getConnection();

         	PreparedStatement stmt = conn.prepareStatement("select c.descricao_comodo, c.id, c.tipo_comodo from comodo as c, comodo_mobilia as cm "+
         													"where id_mobilia = ? and cm.id_comodo = c.id;");
         	stmt.setInt(1, Integer.parseInt(id));
             ResultSet rs = stmt.executeQuery();
             
         	while(rs.next()){
         		String id_comodo = rs.getString("id");
         		String desc = rs.getString("descricao_comodo");
         		String tipo = rs.getString("tipo_comodo");
         		Comodo d = selectType(desc, id_comodo, tipo);
         		l.add(d);
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
	return l;
	
}

public static Comodo selectType(String d, String id, String tipo){
	Comodo c = null;
	switch (tipo) {
	case "Quarto":
		c = new Quarto(id, d, tipo);
		break;

	case "Sala":
		c = new Sala(id, d, tipo);
		break;
	case "Cozinha":
		c = new Cozinha(id, d, tipo);
		break;
	case "ComodoComposto":
		c = new ComodoComposto(id, d, tipo);
		break;
	default:
		break;
	}
	return c;
	
}

public static Mobilia getMobiliaById(int id) throws SQLException{
	Connection conn = null;
	Mobilia m = null;
	 try
        {
         conn = getConnection();

         	PreparedStatement stmt = conn.prepareStatement("select * from mobilia where id=?");
         	stmt.setInt(1, id);
             ResultSet rs = stmt.executeQuery();
             
         	while(rs.next()){
         		String id_mobilia = rs.getString("id");
         		float custo = rs.getFloat("custo");
         		String desc = rs.getString("descricao_mobilia");
         		int tempo = rs.getInt("tempoentrega");
         		m = new Mobilia(id_mobilia, desc, custo, tempo);
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
	return m;
	
}

public static int getMobiliaByTempo() throws SQLException{
	Connection conn = null;
	int i = 0;
	try
        {
        conn = getConnection();

             PreparedStatement stmt = conn.prepareStatement("SELECT max(m.tempoentrega)"
            		 										+" FROM mobilia as m"
            		 										+" INNER JOIN item_venda as i"
            		 										+" ON i.id_mobilia=m.id and i.id_ambiente="
            		 										+" (select id from ambiente order by id desc limit 1);");
              ResultSet rs = stmt.executeQuery();
              
          	while(rs.next()){
          		int tempo = rs.getInt("max");
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
	return i;
	
}

}