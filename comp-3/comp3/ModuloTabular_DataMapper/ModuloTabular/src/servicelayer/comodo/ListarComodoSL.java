package servicelayer.comodo;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import entidades.Comodo;
import mapper.ComodoMAPPER;
import tm.Comodo_TM;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;

@WebServlet("/ListarComodo")
public class ListarComodoSL extends HttpServlet {
	
	private static final long serialVersionUID = 1L;
	private Comodo_TM comodo;

	public ListarComodoSL() {
		comodo = new Comodo_TM();
	}

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doPost(request, response);
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
			List <Comodo> list = comodo.ListarComodo();
			request.setAttribute("lista_comodos", list);
		getServletContext().getRequestDispatcher("/ListarComodo.jsp").forward(request, response);
	}
	
}

