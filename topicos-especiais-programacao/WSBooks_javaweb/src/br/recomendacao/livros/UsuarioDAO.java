package br.recomendacao.livros;

import java.util.List;

import org.hibernate.HibernateException;
import org.hibernate.Query;
import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.hibernate.Transaction;
import org.hibernate.cfg.Configuration;

public class UsuarioDAO {
	
private static SessionFactory sessionFactory;
	
	private Session getSession(){
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
	
	public void insereUsuario(String n, String e, String u, String s, String g){
		
		Session session = getSession();
		try{
			
			Transaction tx = session.beginTransaction();
			Usuario user = new Usuario();
			user.setNome(n);
			user.setEmail(e);
			user.setUsername(u);
			user.setSenha(s);
			user.setGenero(g);
			session.save(user);
			tx.commit();
			System.out.println("SALVOUUUUUUU");
		}catch(HibernateException ex){
			System.out.println(ex.getMessage());
		}finally{
			session.close();
		}
	}
	public boolean buscarLoginUsuario(String user, String pass){
		    
			Session session = getSession();
			
			Query query = session.createQuery("SELECT t FROM Usuario t where t.username = '"+ user +"' AND t.senha ='" + pass + "'");
			if(query.list().size()==0){
				return false;
			}
			session.close();
			return true;
	}
	
	public boolean verificarUsuario(String atributo, String param){
		Session session = getSession();
		List query = session.createQuery("SELECT t FROM Usuario t where t."+ param + " = '"+ atributo +"'").list();
		if(query.size()>= 1){
			return false;
		}
		return true; // retorna true se n existe usuario com msm username  adc
	}
	
    public List<Usuario> buscarUsuario(String atributo, String param){
		
		Session session = getSession();
		
		List query = session.createQuery("SELECT t FROM Usuario t where t."+ param + " = '"+ atributo +"'").list();
		
		if(query.size()==0){
			return null;
		}
		List<Usuario> buscaUsuario = query;
		
		return buscaUsuario;
    }
    
   
    
    public void updateUsuario(String email, String senha, String user){
    	
    	Session session = getSession();
    	try{
    	Transaction tx = session.beginTransaction();
    	Query query = session.createQuery("UPDATE Usuario set email = '"+ email +"', senha = '"+ senha +"' WHERE username = '"+ user +"'");
    	query.executeUpdate();
    	System.out.println("upppp");
    	tx.commit();
    	}catch(HibernateException e){
    		e.getMessage();
    	}finally{
    		session.close();
    	}
    			
    }
}

