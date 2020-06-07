package controladores.sala;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import entidades.Ambiente;
import entidades.Sala;
import singleton.Singleton;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.ServletException;

@WebServlet("/CrCriarSala")
public class CrCriarSala extends HttpServlet {
	
	private static final long serialVersionUID = 1L;
    
    /**
     * @see HttpServlet#HttpServlet()
     */
    public CrCriarSala() {
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
		String desc = request.getParameter("descricao");
    	request.setAttribute("descricao", desc);
    	/*Sala c = new Sala(desc);
		Singleton.getInstance().insereSala(c);*/
		getServletContext().getRequestDispatcher("/ListarSala.jsp").forward(request, response);
	}

}

