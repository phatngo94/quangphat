package edu.poly.servlet;

import java.io.IOException;
import java.lang.reflect.InvocationTargetException;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;

import javax.management.Query;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.apache.commons.beanutils.BeanUtils;

import edu.poly.dao.UserDao;
import edu.poly.model.User;

/**
 * Servlet implementation class UserServlet
 */
@WebServlet({"/UserServlet","/UserServlet/create","/UserServlet/update","/UserServlet/delete","/UserServlet/reset","/edit","/deleteD"})
public class UserServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
   
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
//		
//		User user=new User();
//		request.setAttribute("user", user);
		
		String url=request.getRequestURL().toString();
		
		if(url.contains("edit")) {
			findById(request,response);
			System.out.println("thanh cong nenenene");
		}else if(url.contains("deleteD")) {
			deleteedit(request,response);
		}
		
		
		findAll(request,response);
		request.getRequestDispatcher("/User.jsp").forward(request, response);
		
	}

	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
		String url=request.getRequestURL().toString();
		try{
			
			if(url.contains("create")) {
				insert(request,response);
				
			}else if(url.contains("update")) {
				update(request,response);
			}else if(url.contains("reset")) {
				reset(request,response);
			}else if(url.contains("delete")) {
				delete(request,response);
			}
		}catch(Exception e) {
			e.getStackTrace();
		}
		
		findAll(request,response);
		
		request.getRequestDispatcher("/User.jsp").forward(request, response);
		
	}
	
	
	
	protected void insert(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException{
		try {
			UserDao dao=new UserDao();
			User user=new User();
			BeanUtils.populate(user, request.getParameterMap());
			dao.insert(user);
			System.out.println("success insert" + user.getFullname());
			
		}catch(Exception e) {
			e.printStackTrace();
			System.out.println("fails");
		}
		
	}
	
	protected void delete(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException{
		
		//UserDao dao=new UserDao();
		try {
			UserDao dao=new UserDao();
			User user=new User();
			BeanUtils.populate(user, request.getParameterMap());
			
			dao.delete(user.getUserId());
			System.out.println("success");
		}catch(Exception e) {
			e.printStackTrace();
			System.out.println("fails");
		}
	}

	
	protected void update(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException{
		try {
			UserDao dao=new UserDao();
			
			User user=new User();
//			
			BeanUtils.populate(user, request.getParameterMap());
			dao.update(user);
			request.setAttribute("user", user);
			System.out.println("success");
		}catch(Exception e) 
		{
			e.printStackTrace();
			System.out.println("fails");
		}
	}
	
	protected void findById(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException{
		try {
			UserDao dao=new UserDao();
			User user=new User();
			
			
			String id=	request.getParameter("userId");
			//String id=(String) request.getServletContext().getAttribute("userId");
			System.out.println(id+ "dang can ne");
			request.setAttribute("user", dao.findById(id));
			//System.out.println(user.getFullname());
			
			
			System.out.println("success");
		}catch(Exception e) {
			e.printStackTrace();
			System.out.println("fails");
		}
	}
	
	protected void findAll(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException{
		
		try {
			UserDao dao=new UserDao();
			
			//User user=new User();
			//BeanUtils.populate(user, request.getParameterMap());
			List <User> list= new ArrayList<User>();
			list.addAll(dao.findAll());
			
			
			
			request.setAttribute("users", list);

			
		}catch(Exception e) {
			e.printStackTrace();
			System.out.println("fails");
		}
		
	}
	
	protected void count(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException{
		try {
			UserDao dao=new UserDao();
			
			System.out.println(dao.count());
			
			
			System.out.println("success");
		}catch(Exception e) {
			e.printStackTrace();
			System.out.println("fails");
		}
		
	}
	
	protected void UpD(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException{
		
		try {
			UserDao dao=new UserDao();
			User user=new User();
			BeanUtils.populate(user, request.getParameterMap());
			dao.Update1();
			
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
	protected void reset(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException{
		UserDao dao=new UserDao();
		User user=new User();
		dao.insert(user);
	}
	protected void deleteedit(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException{
		try {
			UserDao dao=new UserDao();
			
			User user=new User();
//			
			//BeanUtils.populate(user, request.getParameterMap());
			
			dao.delete(request.getParameter("userId"));
			//request.setAttribute("user", user);
			System.out.println("success");
		}catch(Exception e) 
		{
			e.printStackTrace();
			System.out.println("fails");
		}
	}
	
}
