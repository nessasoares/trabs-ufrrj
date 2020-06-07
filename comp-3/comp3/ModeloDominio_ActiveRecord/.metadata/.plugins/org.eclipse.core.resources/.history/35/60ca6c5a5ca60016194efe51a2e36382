package servicelayer.mobilia;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import dao.MobiliaDAO;
import md.MobiliaMD;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.SQLException;
import java.util.List;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;

@WebServlet("/ListarMobilia")
public class ListarMobilia_SL extends HttpServlet {
	
	private static final long serialVersionUID = 1L;
    
    public ListarMobilia_SL() {
    	super();
    }

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doPost(request, response);
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
			List<MobiliaMD> l = MobiliaMD.listar();
			request.setAttribute("mobilias", l);
		
			getServletContext().getRequestDispatcher("/ListarMobilia.jsp").forward(request, response);
	}
}

