<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page import="java.io.PrintWriter"%>
<%@page import="java.util.Iterator"%>
<%@page import="java.util.List"%>
<%@page import="br.recomendacao.livros.LivroDAO"%>
<%@page import="org.hibernate.*"%>
<%@ page import="org.json.JSONObject" %>  
<%@page import="org.hibernate.Session.*"%>
<%@page import="org.hibernate.Query"%> 
<%@page import="java.util.Enumeration"%> 

<%--
	//PrintWriter out =response.getWriter();
    LivroDAO db = new LivroDAO();
    String [] countries = null;
    int j = 0;
    String query = request.getParameter("q");
    System.out.println("AIIII " + query);
   	countries = db.pegaDadosAutocomplete(query);
   	for(j = 0 ; j < countries.length; j++){
   		
   		if(countries[j].toUpperCase().startsWith(query.toUpperCase())){
	  		 System.out.println("AIIII " + countries[j]);
	   		 out.print(countries[j]+"ee\n");
   		}
	   
	}
    
--%>

 <%-- LivroDAO db = new LivroDAO();
    String [] countries = null;
    int j = 0;
    String query = request.getParameter("term");
    System.out.println("AIIII " + query);
   	countries = db.pegaDadosAutocomplete(query);
    JSONObject json = new JSONObject();  
   	for(j = 0 ; j < countries.length; j++){
   		
   		if(countries[j].toUpperCase().startsWith(query.toUpperCase())){
	  		System.out.println("AIIII " + countries[j]);
	  		json.put("nome", countries[j]);
	   		
   		}
   
	   
	}
    out.println(json.toString());
   	--%>
	
	
	<%--
	LivroDAO dao = new LivroDAO();
	int i = 0;
	Session s;
	s = dao.getSession();
	 List query = s.createQuery("SELECT t.titulo FROM Livro t").list();
     
		String [] valores = new String[query.size()];
		Iterator it = query.iterator();
		while(it.hasNext()){
			String v = (String)it.next();
			valores[i] = v;
			i++;
		}
		 int j = 0;
		    String query2 = request.getParameter("term");
		    System.out.println("AIIII " + query2);
		    JSONObject json = new JSONObject();  
		   	for(j = 0 ; j < valores.length; j++){
		   		
		   		if(valores[j].toUpperCase().startsWith(query2.toUpperCase())){
			  		System.out.println("AIIII " + valores[j]);
			  		json.put("nome"+j, valores[j]);
			   		
		   		}
		   		
			   
			}
		   	System.out.println("AIIIIpapapii " + json.toString());
		    out.println(json.toString());
		    s.close();
		    
	--%>
	
	
	<%
	LivroDAO db = new LivroDAO();
    String [] results = null;
    int j = 0;
    String param = "titulo";
    String query = request.getParameter("term");
    
    System.out.println("AIIII " + query);
    results = db.pegaDadosAutocomplete(query, param);
    JSONObject json = new JSONObject();  
   	for(j = 0 ; j < results.length; j++){
   		
   		if(results[j].toUpperCase().startsWith(query.toUpperCase())){
	  		System.out.println("AIIII caceteee" + results[j]);
	  		json.put("nome"+j, results[j]);
	   		
   		}
  
	}
    out.println(json.toString());
	System.out.println(json.toString());
   	%>