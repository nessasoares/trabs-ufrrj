package servicelayer.comodo;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import entidades.Ambiente;
import entidades.Comodo;
import gateway.ComodoCompostoGTW;
import gateway.ComodoGTW;
import tm.Comodo_TM;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import javax.servlet.ServletException;

@WebServlet("/CriarComodo")
public class CriarComodoSL extends HttpServlet {
	
	private static final long serialVersionUID = 1L;
    
	private Comodo_TM comodo;

	public CriarComodoSL() {
    	comodo = new Comodo_TM();
	}

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
    		List <Comodo> c = comodo.ListarComodo();
			request.setAttribute("comodos", c);
		getServletContext().getRequestDispatcher("/CriarComodo.jsp").forward(request, response); 
	}

    
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		String desc = request.getParameter("descricao");
		String tipo = request.getParameter("tipoComodo");
		comodo.criarComodo(desc, tipo);
		if(tipo.equals("ComodoComposto")){
			ArrayList<String> comodos = new ArrayList<String>(Arrays.asList(request.getParameter("idComodos").split(",")));
			comodo.criarComodoComposto(desc, comodos);
		}
		request.setAttribute("comodo", desc);
		getServletContext().getRequestDispatcher("/ListarComodo").forward(request, response);
	}
	
	

}

