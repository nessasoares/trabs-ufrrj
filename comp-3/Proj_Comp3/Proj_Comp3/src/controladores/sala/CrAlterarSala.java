package controladores.sala;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import entidades.Sala;
import singleton.Singleton;

import java.io.IOException;
import javax.servlet.ServletException;

@WebServlet("/CrAlterarSala")
public class CrAlterarSala extends HttpServlet {
	
	private static final long serialVersionUID = 1L;
    
    /**
     * @see HttpServlet#HttpServlet()
     */
    public CrAlterarSala() {
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
		getServletContext().getRequestDispatcher("/AlterarSala.jsp").forward(request, response);
    
    }
    
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		processRequest(request, response);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		String descHidden = request.getParameter("descHidden");
		String desc = request.getParameter("desc");
    	Singleton.getInstance().findSala(descHidden).setDescricao(desc);
    	getServletContext().getRequestDispatcher("/ListarSala.jsp").forward(request, response);
	}
	

}

