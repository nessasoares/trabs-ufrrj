package br.recomendacao.livros;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.List;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

/**
 * Servlet implementation class servletDetalhaLivro
 */
@WebServlet("/servletDetalhaLivro")
public class servletDetalhaLivro extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public servletDetalhaLivro() {
        super();
        // TODO Auto-generated constructor stub
    }
	protected void processRequest(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
	    	
	    	PrintWriter out = response.getWriter();
	    	List<Livro> lista = null;
	    	RequestDispatcher rd = null;
	    	LivroDAO dao = new LivroDAO();
	    	
	    	HttpSession session = request.getSession();
	    	
	    	String idLivroAux = request.getParameter("id");
	    	String teste = request.getParameter("input-21e");

	    	int idLivro = Integer.parseInt(idLivroAux);
	    	
	    	lista = dao.buscarLivroId(idLivro);
	    	
	    	if(lista == null){
	    		rd = getServletContext().getRequestDispatcher("/404.html");
	    	}else{
	    		session.setAttribute("listaLivro",lista);
	    		rd = getServletContext().getRequestDispatcher("/livro.jsp");
	    	}
	    	rd.forward(request, response);
	
	}

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		processRequest(request, response);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		processRequest(request, response);
	}

}
