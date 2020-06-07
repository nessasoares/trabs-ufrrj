package br.recomendacao.livros;

import java.io.IOException;
import java.util.List;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

/**
 * Servlet implementation class servletProfileUsuario
 */
@WebServlet("/servletProfileUsuario")
public class servletProfileUsuario extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public servletProfileUsuario() {
        super();
        // TODO Auto-generated constructor stub
    }

    protected void processRequest(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
    	
    	HttpSession session = request.getSession();
    	RequestDispatcher rd = null;
    	Usuario user = new Usuario();
    	String nome = (String) session.getAttribute("usuarioLogado");
    	String email = request.getParameter("email");
    	String senha = request.getParameter("senha");
    	String confirmaSenha = request.getParameter("confirmaSenha");
    	
	    if(!email.isEmpty() && !senha.isEmpty() && !confirmaSenha.isEmpty()){
	    	if(senha.equals(confirmaSenha)){
	    		UsuarioDAO dao = new UsuarioDAO();
	    		dao.updateUsuario(email,user.criptografa(senha),nome);
	    		rd = getServletContext().getRequestDispatcher("/homeUsuario.jsp");
	    	}else{
	    		System.out.println("senhas nao conferem!!");
	    	}
	    }else{
	    	System.out.println("campos vazios n da p atualizar!!");
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
