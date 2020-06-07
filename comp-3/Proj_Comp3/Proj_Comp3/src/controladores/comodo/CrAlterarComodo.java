package controladores.comodo;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import dao.ComodoDAO;
import dao.CozinhaDAO;
import entidades.Comodo;
import singleton.Singleton;

import java.io.IOException;
import java.sql.SQLException;

import javax.servlet.ServletException;

@WebServlet("/CrAlterarComodo")
public class CrAlterarComodo extends HttpServlet {
	
	private static final long serialVersionUID = 1L;
    
    /**
     * @see HttpServlet#HttpServlet()
     */
    public CrAlterarComodo() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
	}
	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
    	String id = request.getParameter("descHidden");
		String m = request.getParameter("method"); 
		String new_desc = request.getParameter("desc");
		if(m.equals("delete")){
			try {
				ComodoDAO.deleteComodo(id);
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}else{
			try {
				ComodoDAO.alterComodo(id, new_desc);
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}

		}
		getServletContext().getRequestDispatcher("/ListarComodo.jsp").forward(request, response);
	}
	

}

