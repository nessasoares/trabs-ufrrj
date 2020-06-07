package servicelayer.ambiente;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import entidades.Ambiente;
import entidades.Comodo;
import entidades.ItemVenda;
import entidades.Mobilia;
import mapper.AmbienteMAPPER;
import mapper.ComodoMAPPER;
import mapper.ItemVendaMAPPER;
import mapper.MobiliaMAPPER;
import ts.ambiente.*;
import ts.comodo.*;
import ts.contrato.CriarContrato_TS;
import ts.itemVenda.CriarItemVenda_TS;
import entidades.Ambiente;
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
    
	private CriarAmbiente_TS criar; 
	private ListarComodo_TS listarComodo; 
	private CriarItemVenda_TS criarIV;


    public CriarAmbiente_SL() {
    	criar = new CriarAmbiente_TS();
    	listarComodo = new ListarComodo_TS();
    	criarIV = new CriarItemVenda_TS();
    }


    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
    		List <Comodo> l = new ArrayList<>();
	    		l = listarComodo.execute();
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
		ArrayList<ItemVenda> iv = new ArrayList<>();
			Iterator<String> it = idMobilias.iterator();
			for(String s: quant){
				String id = it.next();
				iv.add(new ItemVenda(Integer.parseInt(s), Integer.parseInt(id)));
			}
			criarIV.execute(iv);
			criar.execute(paredes, portas, metragem, iv);
		getServletContext().getRequestDispatcher("/ListarAmbientesContrato").forward(request, response);
	}
	
	
}

