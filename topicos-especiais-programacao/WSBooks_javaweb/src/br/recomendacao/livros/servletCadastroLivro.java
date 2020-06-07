package br.recomendacao.livros;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;
import java.util.List;

import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.ServletRequest;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import javax.servlet.http.Part;

import org.apache.commons.fileupload.FileItemFactory;
import org.apache.commons.io.FilenameUtils;
import org.apache.tomcat.util.http.fileupload.FileItem;
import org.apache.tomcat.util.http.fileupload.FileUploadException;
import org.apache.tomcat.util.http.fileupload.RequestContext;
import org.apache.tomcat.util.http.fileupload.disk.DiskFileItemFactory;
import org.apache.tomcat.util.http.fileupload.servlet.ServletFileUpload;
import org.apache.tomcat.util.http.fileupload.servlet.ServletRequestContext;



/**
 * Servlet implementation class servletCadastroLivro
 */
@WebServlet("/servletCadastroLivro")
public class servletCadastroLivro extends HttpServlet {
	private static final long serialVersionUID = 1L;
	private FileItem fileItem;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public servletCadastroLivro() {
        super();
        // TODO Auto-generated constructor stub
    }
  
    protected void processRequest(HttpServletRequest request, HttpServletResponse response) throws Exception, ServletException, IOException{
		
    	
    	RequestDispatcher rd = null;
    	String path; 
    	int messageAlert=0;
    	PrintWriter out = response.getWriter();
    	HttpSession session = request.getSession();
    	DiskFileItemFactory factory = new DiskFileItemFactory();
    	ServletFileUpload upload = new ServletFileUpload(factory);
    	List<FileItem>formItens = upload.parseRequest(new ServletRequestContext(request));
    	String fieldvalue = "";
    	List<String>livros = new ArrayList<String>();
    	
    	for (FileItem item : formItens) {
    		if (item.isFormField()) {
    	       fieldvalue = item.getString();
    	    } else {

    	       fieldvalue = FilenameUtils.getName(item.getName());
    	    }
    		livros.add(fieldvalue);
    	}
    	
    	String titulo = livros.get(0);
		String autor = livros.get(1);
		String editora = livros.get(2);
		String ano = livros.get(3);
		String sinopse = livros.get(4);
		String arquivo = livros.get(5);
		messageAlert = 1; 
		if(!titulo.isEmpty() && !autor.isEmpty() && !editora.isEmpty() && !ano.isEmpty()){
    		
			LivroDAO dao = new LivroDAO();
    		if(dao.verificarLivro(titulo, "titulo")){
    			
				int anoAux = Integer.parseInt(ano);
	    		if(anoAux >= 1900 && anoAux <= 2015){
	    			if(dao.verificarLivro(arquivo, "arquivo")){
    					dao.insereLivro(titulo, autor,editora, ano, sinopse,arquivo);
	    				FileItem file = formItens.get(5);
		    			if(!file.isFormField()){
		    				System.out.println("é imagemmmmmm");
		    				StringBuffer bn = new StringBuffer();
		    				String dirName = "/home/patricia/Documentos/UFRRJ/6º Periodo/top.Esp.Braida/workspaceTopicosBraida/RecomendacaoLivros/WebContent/multicolor-4/images/books//";
		    				bn.append(dirName); // caminho
		    				bn.append(arquivo);
		    				File uploadedFile = new File(bn.toString());
		    				file.write(uploadedFile);
		    			}
			    			
		    			System.out.println("SUCESSOOOOOOOOOOlivro inserido");
		    			path = "/CadastroLivro.jsp";
		    			request.setAttribute("msgsAlert",1);
		    			
	    			}else{
	    				System.out.println("Arquivo já inserido");
	    				path = "/CadastroLivro.jsp";
	    				request.setAttribute("msgsAlert", 2);
	    				
	    			}
		    			
	    			System.out.println("SUCESSOOOOOOOOOOlivro inserido");
	    			path = "/CadastroLivro.jsp";
	    			messageAlert = 0; 
	    			//out.write("SUCESSOOOOOOOOOOlivro inserido");
	    			session.setAttribute("msgsAlert",0);

		    			
	    		}else{
	    			System.out.println("ANO INVALIDO");
	    			path = "/CadastroLivro.jsp";
	    			session.setAttribute("msgsAlert",5);
	    		}
    		}else{

    			System.out.println("LIVRO COM MESMO TITULO JA EXISTE");
    			path = "/CadastroLivro.jsp";
    			//session.setAttribute("msgsAlert",3);
    			session.setAttribute("msgsAlert",3);
    		}
    		
		}else{

			System.out.println("CAMPOS VAZIOS");
			path = "/CadastroLivro.jsp";
			session.setAttribute("msgsAlert",4);


		}
		rd = getServletContext().getRequestDispatcher(path);
		rd.forward(request, response);

	}

	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		try {
			processRequest(request, response);
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
	
			try {
				processRequest(request, response);
			} catch (Exception e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		
	}

}
