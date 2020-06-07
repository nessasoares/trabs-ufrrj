package servicelayer.ambiente;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import DomainModel_ActiveRecord.*;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Map;

import javax.servlet.ServletException;

@WebServlet("/CriarAmbiente")
public class CriarAmbiente_SL extends HttpServlet {
	
	private static final long serialVersionUID = 1L;
    private AmbienteMD ambiente;


    public CriarAmbiente_SL() {
    	ambiente = new AmbienteMD();
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
    		List <ComodoMD> l = ComodoMD.listar();
	    	request.setAttribute("comodos", l);
	    	getServletContext().getRequestDispatcher("/CriarAmbiente.jsp").forward(request, response);
	}
    
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		int paredes = Integer.parseInt(request.getParameter("paredes"));
		int portas = Integer.parseInt(request.getParameter("portas"));
		float metragem = Float.parseFloat(request.getParameter("metragem"));
		ArrayList<String> idMobilias = new ArrayList<String>(Arrays.asList(request.getParameter("idMobilias").split(",")));
		ArrayList<String> quant = new ArrayList<String>(Arrays.asList(request.getParameter("qtdsHidden").split(",")));
		ArrayList<ItemVendaMD> iv = new ArrayList<>();
			Iterator<String> it = idMobilias.iterator();
			for(String s: quant){
				String id = it.next();
				iv.add(new ItemVendaMD(Integer.parseInt(s), Integer.parseInt(id)));
			}
			ItemVendaMD.criar(iv);
			ambiente.criar(paredes, portas, metragem, iv);
		getServletContext().getRequestDispatcher("/ListarAmbientesContrato").forward(request, response);
	}
	
	
}
