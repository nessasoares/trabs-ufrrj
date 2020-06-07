<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@page import="br.recomendacao.livros.LivroDAO"%>
<%@ page import="org.json.JSONObject" %>  

	<%
	LivroDAO db = new LivroDAO();
    String [] results = null;
    int j = 0;
    String param = "autor";
    String query = request.getParameter("term");

    results = db.pegaDadosAutocomplete(query, param);
    JSONObject json = new JSONObject();  
   	for(j = 0 ; j < results.length; j++){
   		
   		if(results[j].toUpperCase().startsWith(query.toUpperCase())){
	  		json.put("nome"+j, results[j]);
   		}
  
	}
    out.println(json.toString());
	System.out.println(json.toString());
   	%>