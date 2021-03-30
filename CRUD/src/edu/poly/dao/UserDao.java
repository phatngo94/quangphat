package edu.poly.dao;

import java.util.ArrayList;
import java.util.List;

import javax.management.Query;
import javax.persistence.EntityManager;
import javax.persistence.EntityTransaction;
import javax.persistence.TypedQuery;

import edu.poly.model.User;
import edu.poly.utils.jpaUtils;

public class UserDao extends jpaUtils {
	public void insert(User user) {

		jpaUtils jpa = new jpaUtils();

		jpa.getEntityManager();
		try {
			trans.begin();

			em.persist(user);

			trans.commit();
		} catch (Exception e) {
			// System.out.println("khong thanh cong");
			e.printStackTrace();
			trans.rollback();
			throw e;
		} finally {
			trans=null;
			em.close();

		}
	}

	public void delete(String Userad) throws Exception {
		//jpaUtils.getEntityManager();
		jpaUtils jpa = new jpaUtils();

		jpa.getEntityManager();
//
//		EntityManager em=jpa.getEntityManager();
//		EntityTransaction trans=em.getTransaction();
		try {
			trans.begin();
			
			User user= em.find(User.class, Userad);
			
			if(user!=null) {
				em.remove(user);
			}else {
				throw new Exception("Users can not found !") ;
				
			}
			
			
			trans.commit();
		} catch (Exception e) {
			
			e.printStackTrace();
			trans.rollback();
			throw e;
		} finally {
			em.close();
			
			

		}
	}
	
	
	public void update(User user) {

		jpaUtils jpa = new jpaUtils();
		jpa.getEntityManager();
		
		
		try {
			trans.begin();
			
			em.merge(user);
			trans.commit();
		} catch (Exception e) {
			
			e.printStackTrace();
			trans.rollback();
			throw e;
		} finally {
			trans=null;
			em.close();

		}
	}
	
	public User findById(String userid) {

		jpaUtils jpa = new jpaUtils();
		jpa.getEntityManager();
		
		
		try {
//			trans.begin();
//			
//			em.merge(user);
//			trans.commit();
			
			User user=em.find(User.class, userid);
			
			if(user!=null) {
//				String sql="select u form Users u where u.UserId=:userid";
//				em.createNamedQuery(sql);
				return user;
				
			}
			
		} catch (Exception e) {
			
			e.printStackTrace();
			trans.rollback();
			throw e;
		} finally {
			trans=null;
			em.close();

		}
		return null;
		
	}
	
	
	public List<User> findAll(){
		
		//jpaUtils jpa=new jpaUtils();
		jpaUtils.getEntityManager();
		
		try {
//			User user= new User();
//			List<User> list=new ArrayList();
//			
//			String sql="SELECT u FROM User u";
//			//List<User> list=new List<User>();
//			list.addAll(em.createQuery(sql, User.class).getResultList());
			
			TypedQuery<User> query= em.createNamedQuery("User.findAll",User.class);
			
			
			
			//list.addAll(em.createNamedQuery(sql).getFlushMode());
//			if(list!=null) {
//				System.out.println("list khong rong ");
//
//			}
			
			return query.getResultList();
			
			
		}catch(Exception e){
			System.out.println("list rong");
		}finally {
			em.close();
		}
		return null;
	}
	
public List<User> findAll(int page, int pageSize){
		
		//jpaUtils jpa=new jpaUtils();
		jpaUtils.getEntityManager();
		
		try {
			
			
			TypedQuery<User> query= em.createNamedQuery("User.findAll",User.class);
			
			
			query.setFirstResult(page*pageSize);
			query.setMaxResults(pageSize);
			return query.getResultList();
			
			
		}catch(Exception e){
			System.out.println("list rong");
		}finally {
			em.close();
		}
		return null;
	}
	


	public User checkLogin(String userId, String passWord){
		
		jpaUtils.getEntityManager();
		String sql="select u from User u where u.Userid=;userId and u.Password=:password";
		
		TypedQuery query= em.createQuery(sql, User.class);
		
		query.setParameter("userId", userId);
		query.setParameter("password", passWord);
		
		return (User) query.getSingleResult();
	
	}

	public List<User> findFullName(String fullname){
		jpaUtils.getEntityManager();
		
		String sql="select u from User u where u.Fullname like :fullname";
		
		TypedQuery query=em.createNamedQuery(sql, User.class);
		
		query.setParameter("fullname","%" + fullname + "%");
		
		return (List<User>) query.getResultList();
		
	}
	
	public int count() {
		jpaUtils.getEntityManager();
		
		String sql="select count(u) from User u ";
		
		javax.persistence.Query query=   em.createQuery(sql);
		return ((Long)query.getSingleResult()).intValue();
	}
	
	
	public void Update1() {
		jpaUtils.getEntityManager();
		User user=new User();
		String pass=user.getPassword();
		String name=user.getFullname();
		String mail=user.getEmaill();
		boolean ad=user.getAdmin();
		String id=user.getUserId();
		
		
		String sql="update u from user u set u.Password=pass ,u.Fullname=name, u.Emaill=mail, u.Admin=ad  where u.UserId=id";
		em.createQuery(sql);
		
		
		
	}
}
