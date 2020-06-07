package br.recomendacao.livros;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;
import java.util.List;

import org.hibernate.HibernateException;
import org.hibernate.Query;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.Transaction;
import org.hibernate.cfg.Configuration;
import org.hibernate.criterion.MatchMode;
import org.hibernate.criterion.Restrictions;


public class LivroDAO {
	
private static SessionFactory sessionFactory;

	
	public Session getSession(){
		Session s = null;
		try{
			sessionFactory = new Configuration().configure(
					"br/xml/hibernate.cfg.xml").buildSessionFactory();
			s = sessionFactory.openSession();
		}catch(HibernateException e){
			System.out.println(e.getMessage());
		}
		return s;
	}
	
	public void insereLivro(String t, String nAutor, String e, String a, String s, String arq){
		
		Session s1 = getSession();
		try{
			
			Transaction tx = s1.beginTransaction();
			Livro livro = new Livro();
			livro.setTitulo(t);
			livro.setAutor(nAutor);
			livro.setEditora(e);
			livro.setAno(a);
			livro.setSinopse(s);
			livro.setArquivo(arq);
			livro.setVisita(0);
			livro.setCurtida(0);
			s1.save(livro);
			tx.commit();
			System.out.println("SALVOUUUUUUU");
		}catch(HibernateException ex){
			System.out.println(ex.getMessage());
			System.out.println("DEU RUIM");
		}finally{
			s1.close();
		}
	}
	
	public boolean verificarLivro(String atributo, String param){
		Session session = getSession();
		List query = session.createQuery("SELECT t FROM Livro t where t."+ param + " = '"+ atributo +"'").list();
		if(query.size()>= 1){
			return false;
		}
		return true; // retorna true se n existe livro com msm titulo adc
	}
	
	
	public List<Livro> buscarLivro(String atributo, String param){
		
		/*Session session = getSession();
		
		List query = session.createQuery("SELECT t FROM Livro t where t."+ param + " = '"+ atributo +"'").list();
		
		if(query.size()==0){
			return null;
		}
		List<Livro> buscaLivro = query;
		
		return buscaLivro;*/
		
		Session session = getSession();
		try{
			Transaction tx = session.beginTransaction();
			List buscas = session.createCriteria(Livro.class).add(Restrictions.like(param, atributo, MatchMode.START).ignoreCase()).list();
			tx.commit();
			session.close();
			session.clear();
			return buscas;
		}catch(HibernateException e){
			System.out.println("NAO BUSCOU");
		}
		return null;
		
	}
	
	public List<Livro> buscarLivroId(int id){
		
		Session session = getSession();
		
		List query = session.createQuery("SELECT t FROM Livro t where t.id = "+ id ).list();
		
		if(query.size()==0){
			return null;
		}
		List<Livro> livrosId = query;
		updateVisitaLivro(livrosId);
		
		return livrosId;
	}
	
	public void updateVisitaLivro(List<Livro> lista){
		Session session = getSession();
		Transaction tx = session.beginTransaction();
    	
		int soma  = 0;
		for(Livro aux : lista){
			soma = aux.getVisita() + 1;
			Query query = session.createQuery("UPDATE Livro set visita = "+ soma +" WHERE id = "+ aux.getId()+"");
	    	query.executeUpdate();
	    	tx.commit();
	    	session.close();
	    	System.out.println("atualizou a pag corretamente!!!");
		}
		
	}
	

	/*public void updateLikeLivro(String id){
		Session session = getSession();
		Transaction tx = session.beginTransaction();
    	
		List query = session.createQuery("SELECT t FROM Livro t where t.id = "+ id ).list();
	
		List<Livro> lista = query;
		int soma  = 0;

		for(Livro aux : lista){
			soma = aux.getVisita() + 1;
			Query query2 = session.createQuery("UPDATE Livro set curtida = "+ soma +" WHERE id = "+ aux.getId()+"");
	    	query2.executeUpdate();
	    	tx.commit();
	    	session.close();
	    	System.out.println("atualizou a pag corretamente!!!");
		
		}
	}*/

	
	public List<Livro> ultimasAtualizacoesLivroCarrosselUm(){
		
        Session session = getSession();
		
		//List query = session.createQuery("SELECT t FROM Livro t WHERE t.id > 6 order by t.id desc").list();
        Query query = session.createQuery("SELECT t FROM Livro t ORDER BY t.id DESC");
        query.setFirstResult(0);
        query.setMaxResults(4);
        List results = query.list();
       
		if(results.size()==0){
			return null;
		}
		List<Livro> livrosId = results;
		
		return livrosId;
		
	}
	
	public List<Livro> ultimasAtualizacoesLivroCarrosselDois(){
		
        Session session = getSession();
		
		//List query = session.createQuery("SELECT t FROM Livro t WHERE t.id > 6 order by t.id desc").list();
        Query query = session.createQuery("SELECT t FROM Livro t ORDER BY t.id DESC");
        query.setFirstResult(4);
        query.setMaxResults(4);
        List results = query.list();
       
        if(results.size()==0){
			return null;
		}
		List<Livro> livrosId = results;
		
		return livrosId;
		
	}
	
	public List<Livro> maisVistos(){
		
        Session session = getSession();
		
        Query query = session.createQuery("SELECT t FROM Livro t ORDER BY t.visita DESC");
        query.setFirstResult(0);
        query.setMaxResults(6);
        List results = query.list();
       
        if(results.size()==0){
			return null;
		}
		List<Livro> livrosVistos = results;
		
		return livrosVistos;
		
	}
	
	public String [] pegaDadosAutocomplete(String nome, String param){
		String var =null;
		int i = 0;
		Session session = getSession();
        List query = session.createQuery("SELECT distinct t."+param+" FROM Livro t").list();
        System.out.println("PARAM " + param);
		String [] valores = new String[query.size()];
		/*for(i = 0; i < query.size() ; i++){
			var = (String) query.get(i);
			if(var.startsWith(nome)){
				//valores.add(var);
				valores[i] = var;
				System.out.println("achouuu");
			}else{
			System.out.println("naoooo achouuu");
			}
		}*/
		
		Iterator it = query.iterator();
		while(it.hasNext()){
			String v = (String)it.next();
			valores[i] = v;
			i++;
		}
		return valores;
	}
	
	
}
