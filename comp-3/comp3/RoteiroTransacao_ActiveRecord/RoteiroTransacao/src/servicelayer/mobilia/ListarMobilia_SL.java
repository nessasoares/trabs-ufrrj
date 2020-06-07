package servicelayer.mobilia;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import entidades.Mobilia;
import ts.mobilia.ListarMobilia_TS;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.SQLException;
import java.util.List;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;

@WebServlet("/ListarMobilia")
public class ListarMobilia_SL extends HttpServlet {
	
	private static final long serialVersionUID = 1L;
	private ListarMobilia_TS listar;
    
    public ListarMobilia_SL() {
    	listar = new ListarMobilia_TS();
    }

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doPost(request, response);
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
			List<Mobilia> l = listar.execute();
			request.setAttribute("mobilias", l);
		
			getServletContext().getRequestDispatcher("/ListarMobilia.jsp").forward(request, response);
	}
}

