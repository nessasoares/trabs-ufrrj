package jdbc;

import javax.naming.*;
import javax.sql.*;
import java.sql.*;
public class PostgreSQLJDBC 
{

    static String foo = "Not Connected";
    
    public static void init() 
    {
        try
        {
            Context ctx = new InitialContext();
            if(ctx == null )
                throw new Exception("Boom - No Context");
            // /jdbc/postgres is the name of the resource above 
            DataSource ds = (DataSource)ctx.lookup("java:comp/env/jdbc/postgres");
            if (ds != null) 
            {
                Connection conn = ds.getConnection();
              /*  if(conn != null) 
                {
                    conn.close();
                }*/
            }
        }
        catch(Exception e) 
        {
            e.printStackTrace();
        }
    }

}