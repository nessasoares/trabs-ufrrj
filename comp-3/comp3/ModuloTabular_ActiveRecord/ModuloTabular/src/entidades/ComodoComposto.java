package entidades;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import dao.*;
import java.util.ArrayList;
import java.util.List;


public class ComodoComposto extends Comodo{
	private String id;

	public ComodoComposto(String id, String d) {
		setDescricao(d);
		setId(id);
	}

	@Override
	public List<Mobilia> listaMobiliaDisponivel(List <String> set) {
		List<Mobilia> array = new ArrayList<>();
			try {
				for(Mobilia m: Mobilia.listMobiliaComodo(getId())){
					if(!set.contains(m.getId())){
						array.add(m);
					}
				}	
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			
			return array;
		
		}
	
public static void insertComodoComposto(String desc, ArrayList<String> cc1) throws SQLException{
		
		Connection conn = null;
		 try
	        {
             conn = DAO.getConnection();

	            	PreparedStatement stmt = conn.prepareStatement(
	            			"INSERT INTO comodo_composto (id_comodo, id_comodo_associado) "
	            			+ "VALUES ((select id from comodo order by id desc limit 1),"
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

//----------------------------------------------------------------
//						sql
//------------------------------------------------------------------


public static void delete(String id) throws SQLException{
	
	Connection conn = null;
	 try
        {
		 	conn = DAO.getConnection();

            	PreparedStatement stmt = conn.prepareStatement(
            			"DELETE FROM comodo_composto where id_comodo = ?);");
            	stmt.setString(1, id);
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
