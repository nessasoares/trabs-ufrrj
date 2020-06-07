package br.recomendacao.livros;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

/**
 * Servlet implementation class servletBuscaLivro
 */
@WebServlet("/servletBuscaLivro")
public class servletBuscaLivro extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public servletBuscaLivro() {
        super();
    }

    protected void processRequest(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
    	
    	List<Livro> lista = null;
    	request.setCharacterEncoding("UTF8");  
    	String titulo = request.getParameter("titulo");
    	RequestDispatcher rd = null;
    	String autor = request.getParameter("autor");
    	String editora = request.getParameter("editora");
    	String ano = request.getParameter("ano");
    	HttpSession session = request.getSession();
    	
    	System.out.println("anoo " + ano);
    	
    	if(titulo != null){
    		LivroDAO dao = new LivroDAO();
    		String auxParam = "titulo";
    		lista = dao.buscarLivro(titulo, auxParam);
    		session.setAttribute("listaLivroTitulo",lista);
    		//session.setAttribute("listaLivro",lista);
    		rd = getServletContext().getRequestDispatcher("/buscarLivro.jsp");
    	}else if (titulo == null){
    		session.setAttribute("listaLivroTitulo",null);
    	}
    		
    	if(autor != null){
    		LivroDAO dao = new LivroDAO();
    		String auxParam = "autor";
    		lista = dao.buscarLivro(autor, auxParam);
    		session.setAttribute("listaLivroAutor",lista);
    		//session.setAttribute("listaLivro",lista);
    		rd = getServletContext().getRequestDispatcher("/buscarLivro.jsp");
    	}else if(autor == null){
    		session.setAttribute("listaLivroAutor",null);
    	}
    	
    	if(editora != null){
    		LivroDAO dao = new LivroDAO();
    		String auxParam = "editora";
    		lista = dao.buscarLivro(editora, auxParam);
    		session.setAttribute("listaLivroEditora",lista);
    		//session.setAttribute("listaLivro",lista);
    		rd = getServletContext().getRequestDispatcher("/buscarLivro.jsp");
    	}else if(editora == null){
    		session.setAttribute("listaLivroEditora",null);
    	}
    		
    		
    	if(ano != null && !ano.isEmpty()){
    		int anoAux = Integer.parseInt(ano);
    		if(anoAux >= 1900 && anoAux <= 2015){
    			LivroDAO dao = new LivroDAO();
        		String auxParam = "ano";
        		lista = dao.buscarLivro(ano, auxParam);
        		session.setAttribute("listaLivroAno",lista);
        		//session.setAttribute("listaLivro",lista);
        		
    		}else{
    			request.setAttribute("msgsAlert",1);
        		
    		}
    		rd = getServletContext().getRequestDispatcher("/buscarLivro.jsp");
    	}else {
    		session.setAttribute("listaLivroAno",null);
    		rd = getServletContext().getRequestDispatcher("/buscarLivro.jsp");
    	}
    	
    	rd.forward(request, response);
	}
    
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		processRequest(request, response);
	}

	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		processRequest(request, response);
	}

}
