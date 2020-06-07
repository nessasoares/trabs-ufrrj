package servicelayer.comodo;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import gateway.ComodoCompostoGTW;
import gateway.ComodoGTW;
import md.*;

import java.io.IOException;
import java.sql.SQLException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;

@WebServlet("/AlterarComodo")
public class AlterarComodoSL extends HttpServlet {
	
	private static final long serialVersionUID = 1L;

    public AlterarComodoSL() {
    	super();
        // TODO Auto-generated constructor stub
    }

    
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
	}
	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
    	String id = request.getParameter("id"); //id
    	String path = ""; 
		RequestDispatcher rd = null;
		String m = request.getParameter("method"); 
		String desc = request.getParameter("desc");
		if(m.equals("delete")){
			try {
				ComodoMD.delete(id);
				path = "/ListarComodo";
			} catch (Exception e) {
				e.printStackTrace();
				path = "/ListarComodo";
			}
		}else{
			try {
				ComodoMD.alterar(id, m, desc);
				path = "/ListarComodo";
			} catch (Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				path = "/ListarComodo";
				
			}
		}
		rd = getServletContext().getRequestDispatcher(path);
	    rd.forward(request, response);
	}
}
	


