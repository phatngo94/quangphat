package edu.poly.utils;

import javax.persistence.EntityManager;
import javax.persistence.EntityManagerFactory;
import javax.persistence.EntityTransaction;
import javax.persistence.Persistence;

public class jpaUtils {
	
	public static EntityManager em ;
	public static EntityTransaction trans;
	public static void getEntityManager() {
		EntityManagerFactory factory=Persistence.createEntityManagerFactory("CRUD");
		EntityManager entity=factory.createEntityManager();
		em=factory.createEntityManager();
		trans=em.getTransaction();
		//return entity;
		
	}
	
//	public static void getEntity() {
//		jpaUtils jpa=new jpaUtils ();
//		em=jpa.getEntityManager();
//		
//	}
//	
//	public static void getTrans() {
//		trans=em.getTransaction();
//		
//	}
	
	

}
