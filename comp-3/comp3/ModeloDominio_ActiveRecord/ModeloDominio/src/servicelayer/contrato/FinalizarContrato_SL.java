package servicelayer.contrato;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import DomainModel_ActiveRecord.*;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.SQLException;
import java.util.List;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;

@WebServlet("/FinalizarContrato")
public class FinalizarContrato_SL extends HttpServlet {
	
	private static final long serialVersionUID = 1L;
	private ContratoMD contrato;
	private AmbienteMD ambiente;
    
    public FinalizarContrato_SL() {
    	contrato = new ContratoMD();
    	ambiente = new AmbienteMD();
    }

	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		float comissao = Float.parseFloat(request.getParameter("comissao"));
		String m = request.getParameter("method"); 
		if(m.equals("cancel")){
			    contrato.cancelar();
				getServletContext().getRequestDispatcher("/index.jsp").forward(request, response);	
		}else{
			List<AmbienteMD> ambientes = ambiente.get();
			ContratoMD c = contrato.update(comissao, ambientes);
			request.setAttribute("ambientes", ambientes);
			request.setAttribute("contrato",c );
		}	
		getServletContext().getRequestDispatcher("/FinalizarContrato.jsp").forward(request, response);	}
}

