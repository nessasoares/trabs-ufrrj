package mapper;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.util.ArrayList;

import javax.naming.Context;
import javax.naming.InitialContext;
import javax.sql.DataSource;

public class ComodoCompostoMAPPER extends ConnectionBD{

public static void insertComodoComposto(ArrayList<String> cc1) throws SQLException{
		
		Connection conn = null;
		 try
	        {
             conn = getConnection();

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

public static void delete(String id) throws SQLException{
	
	Connection conn = null;
	 try
        {
		 	conn = getConnection();

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
