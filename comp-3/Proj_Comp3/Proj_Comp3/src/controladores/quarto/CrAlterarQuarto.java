package controladores.quarto;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import dao.CozinhaDAO;
import dao.QuartoDAO;
import entidades.Cozinha;
import singleton.Singleton;

import java.io.IOException;
import java.sql.SQLException;

import javax.servlet.ServletException;

@WebServlet("/CrAlterarQuarto")
public class CrAlterarQuarto extends HttpServlet {
	
	private static final long serialVersionUID = 1L;
    
    /**
     * @see HttpServlet#HttpServlet()
     */
    public CrAlterarQuarto() {
        super();
        // TODO Auto-generated constructor stub
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
    	String desc = request.getParameter("desc");
    	request.setAttribute("desc", desc);
		getServletContext().getRequestDispatcher("/AlterarQuarto.jsp").forward(request, response);
    
    }
    
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		getServletContext().getRequestDispatcher("/login.jsp").forward(request, response);
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
				QuartoDAO.deleteQuarto(id);
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}else{
			try {
				QuartoDAO.alterQuarto(id, new_desc);
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}

		}
		getServletContext().getRequestDispatcher("/ListarQuarto.jsp").forward(request, response);
	}
	

	

}

