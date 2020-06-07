package controladores.mobilia;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

import dao.MobiliaDAO;
import dao.CozinhaDAO;
import entidades.Mobilia;
import singleton.Singleton;

import java.io.IOException;
import java.sql.SQLException;

import javax.servlet.ServletException;

@WebServlet("/CrAlterarMobilia")
public class CrAlterarMobilia extends HttpServlet {
	
	private static final long serialVersionUID = 1L;
    
    /**
     * @see HttpServlet#HttpServlet()
     */
    public CrAlterarMobilia() {
        super();
        // TODO Auto-generated constructor stub
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
    	String id = request.getParameter("descHidden");
		String m = request.getParameter("method"); 
		String desc = request.getParameter("desc");
		Float custo = Float.valueOf(request.getParameter("custo"));
		int tempoEntrega = Integer.parseInt(request.getParameter("tempoEntrega"));
		if(m.equals("delete")){
			try {
				MobiliaDAO.deleteMobilia(id);
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}else{
			try {
				MobiliaDAO.alterMobilia(id, desc, custo, tempoEntrega);
			} catch (SQLException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}

		}
		getServletContext().getRequestDispatcher("/ListarMobilia.jsp").forward(request, response);
	}
	

}

