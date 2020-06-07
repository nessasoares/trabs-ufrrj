package singleton;

import java.util.ArrayList;
import java.util.Collection;

import entidades.Cozinha;
import entidades.Sala;

public class Singleton {

	private static Singleton instance = null;
	
	private Collection<Cozinha> kitchen = new ArrayList<>();
	private Collection<Sala> room = new ArrayList<>();

	private Singleton(){
	}
	
	public static Singleton getInstance(){
		
		if(instance == null){
			instance = new Singleton();
		}
		return instance;
	}
	
	public void insereCozinha(Cozinha u){
		kitchen.add(u);
	}
	
	public void removeCozinha(Cozinha c){
		kitchen.remove(c);
	}
	
	public Collection<Cozinha> getCozinha(){
		return this.kitchen;
	}
	
	 /*public Cozinha findCozinha(String desc){
		Cozinha r = new Cozinha("");
		for(Cozinha c : this.kitchen){
				r = c;
			}
		return r;
	}*/
	
	public void insereSala(Sala u){
		room.add(u);
	}
	
	public void removeSala(Sala c){
		room.remove(c);
	}
	
	public Collection<Sala> getSala(){
		return this.room;
	}
	
	public Sala findSala(String desc){
		Sala r = new Sala("");
		for(Sala c : this.room){
				r = c;
			}
		return r;
	}
}
