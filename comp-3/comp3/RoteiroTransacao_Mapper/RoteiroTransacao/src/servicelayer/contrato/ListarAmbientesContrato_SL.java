package servicelayer.contrato;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import entidades.Comodo;
import mapper.AmbienteMAPPER;
import ts.ambiente.GetAmbiente_TS;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.SQLException;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;

@WebServlet("/ListarAmbientesContrato")
public class ListarAmbientesContrato_SL extends HttpServlet {
	
	private static final long serialVersionUID = 1L;
	private GetAmbiente_TS get;
    
    public ListarAmbientesContrato_SL() {
    	get = new GetAmbiente_TS();
    }

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		request.setAttribute("ambientes", get.execute());
		getServletContext().getRequestDispatcher("/ListarAmbientesContrato.jsp").forward(request, response);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		request.setAttribute("ambientes", get.execute());
		getServletContext().getRequestDispatcher("/ListarAmbientesContrato.jsp").forward(request, response);	}
}

