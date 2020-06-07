package controladores.comodo;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import dao.ComodoDAO;
import entidades.Ambiente;
import entidades.Comodo;
import singleton.Singleton;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.SQLException;

import javax.servlet.ServletException;

@WebServlet("/CrCriarComodo")
public class CrCriarComodo extends HttpServlet {
	
	private static final long serialVersionUID = 1L;
    
    /**
     * @see HttpServlet#HttpServlet()
     */
    public CrCriarComodo() {
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
		String primeiro = null;
		String segundo = null;
		String desc = request.getParameter("descricao");
		String tipo = request.getParameter("tipoComodo");
		try {
			ComodoDAO.insereComodo(desc, tipo);
			if(tipo.equals("comodoComposto")){
				primeiro = request.getParameter("primeiroComodo");
				segundo = request.getParameter("segundoComodo");
				ComodoDAO.insereComodoComposto(desc, primeiro, segundo);
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		/*Comodo c = new Comodo(desc);
		Singleton.getInstance().insereComodo(c);*/
		getServletContext().getRequestDispatcher("/ListarComodo.jsp").forward(request, response);
	}

}

