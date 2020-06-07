package servicelayer.contrato;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import entidades.Ambiente;
import entidades.Comodo;
import entidades.Contrato;
import gateway.AmbienteGTW;
import gateway.ContratoGTW;
import gateway.MobiliaGTW;
import tm.*;

import java.io.IOException;
import java.io.PrintWriter;
import java.sql.SQLException;
import java.util.List;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;

@WebServlet("/FinalizarContrato")
public class FinalizarContrato_SL extends HttpServlet {
	
	private static final long serialVersionUID = 1L;
	private Contrato_TM contrato;
	private Ambiente_TM ambiente;
    
    public FinalizarContrato_SL() {
    	ambiente= new Ambiente_TM();
    	contrato = new Contrato_TM();
    }

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		float comissao = Float.parseFloat(request.getParameter("comissao"));
		String m = request.getParameter("method"); 
		if(m.equals("cancel")){
			contrato.CancelarContrato();
			getServletContext().getRequestDispatcher("/index.jsp").forward(request, response);	
		}else{
			List<Ambiente> ambientes = ambiente.GetAmbiente();
			Contrato c = contrato.UpdateContrato(comissao, ambientes);
			request.setAttribute("ambientes", ambientes);
			request.setAttribute("contrato",c );
		}	
		getServletContext().getRequestDispatcher("/FinalizarContrato.jsp").forward(request, response);	}
}

