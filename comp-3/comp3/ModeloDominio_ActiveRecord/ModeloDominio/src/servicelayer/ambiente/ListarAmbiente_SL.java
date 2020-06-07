package servicelayer.ambiente;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import DomainModel_ActiveRecord.*;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.SQLException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;

@WebServlet("/ListarAmbiente")
public class ListarAmbiente_SL extends HttpServlet {
	
	private static final long serialVersionUID = 1L;
	private AmbienteMD ambiente;
    public ListarAmbiente_SL() {
    	ambiente = new AmbienteMD();
    }

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		doPost(request, response);
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		request.setAttribute("ambientes", ambiente.listar());
		request.setAttribute("id", request.getParameter("idComodo"));
		getServletContext().getRequestDispatcher("/ListarAmbiente.jsp").forward(request, response);
	}
}

