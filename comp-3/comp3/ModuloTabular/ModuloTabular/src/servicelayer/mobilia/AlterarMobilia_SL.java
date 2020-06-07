package servicelayer.mobilia;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import org.postgresql.util.PSQLException;

import dao.MobiliaDAO;
import dao.ComodoDAO;
import dao.CozinhaDAO;
import entidades.Comodo;
import entidades.Mobilia;
import tm.*;

import java.io.IOException;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import javax.servlet.ServletException;

@WebServlet("/AlterarMobilia")
public class AlterarMobilia_SL extends HttpServlet {
	
	private static final long serialVersionUID = 1L;
	private Comodo_TM comodo;
	private Mobilia_TM mobilia;

    
    public AlterarMobilia_SL() {
    	comodo = new Comodo_TM();
    	mobilia = new Mobilia_TM();
    }

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

		request.setAttribute("desc", request.getParameter("desc"));
		request.setAttribute("custo", request.getParameter("custo"));
		request.setAttribute("tempo", request.getParameter("tempo"));
		request.setAttribute("comodos", comodo.ListarComodo());
		String id = request.getParameter("id");
		request.setAttribute("id", id);
		getServletContext().getRequestDispatcher("/AlterarMobilia.jsp").forward(request, response);
	}
	
	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		ArrayList<String> comodos = new ArrayList<String>(Arrays.asList(request.getParameter("idComodos").split(",")));
    	String id = request.getParameter("idHidden");
		String m = request.getParameter("method"); 
		String desc = request.getParameter("desc");
		Float custo = Float.valueOf(request.getParameter("custo"));
		int tempoEntrega = Integer.parseInt(request.getParameter("tempoEntrega"));
		if(m.equals("delete")){
			mobilia.DeletarMobilia(id);
		}else{
			mobilia.AlterarMobilia(id, desc, custo, tempoEntrega, comodos);
		}
		getServletContext().getRequestDispatcher("/ListarMobilia").forward(request, response);
	}
	

}

