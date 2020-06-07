package br.recomendacao.livros;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 * Servlet implementation class servletCadastroUsuario
 */
@WebServlet("/servletCadastroUsuario")
public class servletCadastroUsuario extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public servletCadastroUsuario() {
        super();
        // TODO Auto-generated constructor stub
    }

 protected void processRequest(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
	 	
	 	String path ;
	 	RequestDispatcher rd = null;
    	String nome = request.getParameter("nome");
    	String email = request.getParameter("email");
    	String username = request.getParameter("username");
    	String senha = request.getParameter("senha");
    	String confirmaSenha = request.getParameter("confirmaSenha");
    	String genero = request.getParameter("sex");
    	
    
    	
    	if( !nome.isEmpty() && !email.isEmpty() && !username.isEmpty() && !senha.isEmpty() && !confirmaSenha.isEmpty()){
    		UsuarioDAO dao = new UsuarioDAO();
    		Usuario user = new Usuario();
    		
    		if(dao.verificarUsuario(username, "username")){

    			if(senha.length()>=6){

		    		if(senha.equals(confirmaSenha)){
		    			
		    			dao.insereUsuario(nome, email, username, user.criptografa(senha), genero);
		    			path = "/CadastroUsuario.jsp";
		    			request.setAttribute("msgsAlert",1);
		    			
		    		}else{
		    			System.out.println("SENHA INVALIDA");
		    			path = "/CadastroUsuario.jsp";
		    			request.setAttribute("msgsAlert",2);
		    		}
		    		
    			}else{
    				System.out.println("Senha com pouco digito");
        			path = "/CadastroUsuario.jsp";
        			request.setAttribute("msgsAlert",5);
    			}
	    		
    		}else{
    			System.out.println("USERNAME JÁ EXISTENTE!");
    			path = "/CadastroUsuario.jsp";
    			request.setAttribute("msgsAlert",3);
    		}
    		
    	}else{
    		System.out.println("erro!!! nome vazio!");
    		path = "/CadastroUsuario.jsp";
			request.setAttribute("msgsAlert",4);
    	}
    	
    	rd = getServletContext().getRequestDispatcher(path);
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
