package servicelayer.mobilia;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import dao.ComodoDAO;
import dao.MobiliaDAO;
import md.ComodoMD;
import md.MobiliaMD;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import javax.servlet.ServletException;

@WebServlet("/CriarMobilia")
public class CriarMobilia_SL extends HttpServlet {
	
	private static final long serialVersionUID = 1L;

    public CriarMobilia_SL() {
    	super();
    }


    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
    	
    	request.setAttribute("comodos", ComodoMD.listar());
		getServletContext().getRequestDispatcher("/CriarMobilia.jsp").forward(request, response);
    	
	}


    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		ArrayList<String> comodos = new ArrayList<String>(Arrays.asList(request.getParameter("idComodos").split(",")));
		String desc = request.getParameter("descricao");
		Float custo = Float.valueOf(request.getParameter("custo"));
		int tempoEntrega = Integer.parseInt(request.getParameter("tempoEntrega"));
		
		MobiliaMD.criar(desc, custo, tempoEntrega);
		ComodoMD.associar(comodos);
		getServletContext().getRequestDispatcher("/ListarMobilia").forward(request, response);
	}

}

