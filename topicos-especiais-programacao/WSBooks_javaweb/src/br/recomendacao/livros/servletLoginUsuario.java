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
 * Servlet implementation class servletLoginUsuario
 */
@WebServlet("/servletLoginUsuario")
public class servletLoginUsuario extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public servletLoginUsuario() {
        super();
    }

    protected void processRequest(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
    	String path ;
    	RequestDispatcher rd = null;
    	List<Usuario> lista = null;
    	List<Livro>carroselUm = null;
    	List<Livro>carroselDois = null;
    	List<Livro>maisVistos = null;
    	String username = request.getParameter("username");
    	String senha = request.getParameter("senha");
    	Usuario user = new Usuario();
    	
    	if(!username.isEmpty() && !senha.isEmpty()){
    		
    		UsuarioDAO dao = new UsuarioDAO();
    		LivroDAO daoLivro = new LivroDAO();
    		boolean achou = dao.buscarLoginUsuario(username, user.criptografa(senha));
    		
    		if(achou){
    			System.out.println("ACHOU");
    			HttpSession session = request.getSession();
    			session.setAttribute("usuarioLogado",request.getParameter("username"));
    			
    			
    			//detalhar do usurio e alteraçao de dados:
    		    lista = dao.buscarUsuario(username, "username");
    		    session.setAttribute("profileUsuario",lista);
    			
    		    carroselUm = daoLivro.ultimasAtualizacoesLivroCarrosselUm();
    		    session.setAttribute("atualizacaoLivroCarrossel1",carroselUm);
    		    
    		    carroselDois = daoLivro.ultimasAtualizacoesLivroCarrosselDois();
    		    session.setAttribute("atualizacaoLivroCarrossel2",carroselDois);
    		    
    		    maisVistos = daoLivro.maisVistos();
    		    session.setAttribute("livrosMaisVistos",maisVistos);	
    		    
    		    path = "/homeUsuario.jsp";
    			
    			//rd = getServletContext().getRequestDispatcher("/homeUsuario.jsp");
    		}else{
    			System.out.println("NAO ACHOUU");
    			path = "/login.jsp";
    			request.setAttribute("msgsAlert",1);
    		}
    		
    	}else{
    		System.out.println("erro!!! algum nome vazio");
    		path = "/login.jsp";
			request.setAttribute("msgsAlert",2);
    	}
    	rd = getServletContext().getRequestDispatcher(path);
    	rd.forward(request, response);
	}
    
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		processRequest(request, response);
	}

	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		processRequest(request, response);
	}

}
