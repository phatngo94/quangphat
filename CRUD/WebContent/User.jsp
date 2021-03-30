<%@ page language="java" contentType="text/html; charset=ISO-8859-1"
	pageEncoding="ISO-8859-1"%>
<%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>
<%@ page import="java.util.*" import="java.io.*"%>
<!doctype html>
<html lang="en">
<head>
<!-- Required meta tags -->
<meta charset="utf-8">
<meta name="viewport"
	content="width=device-width, initial-scale=1, shrink-to-fit=no">

<!-- Bootstrap CSS -->
<link rel="stylesheet"
	href="https://cdn.jsdelivr.net/npm/bootstrap@4.6.0/dist/css/bootstrap.min.css"
	integrity="sha384-B0vP5xmATw1+K9KRQjQERJvTumQW0nPEzvF6L/Z6nronJ3oUOFUFpCjEUQouq2+l"
	crossorigin="anonymous">
<base href="/CRUD/">
<title>Hello, world!</title>
</head>
<body>
	<main class="container">
		<div class="row">
			<div class="col">
				<c:if test="${not empty message }">
					<div class="alert alert-success">${message }</div>
				</c:if>
				<c:if test="${not empty error }">
					<div class="alert alert-danger">${error }</div>
				</c:if>

			</div>
		</div>
		<div class="row">
			<div class="col">
				<form action="UserServlet" method="post">
					<div class="form-group">
						<label for="userId">UserId</label> <input type="text" id="userId"
							class="form-control" name="userId" value="${user.getUserId()}"/>
					</div>
					<div class="form-group">
						<label for="password">Password</label> <input type="text"
							id="password" class="form-control" name="password" value= "${user.getPassword() }"/>
					</div>
					<div class="from-group">
						<label for="fullname">FullName</label> <input type="text"
							class="form-control" id="fullname" name="fullname"  value="${user.getFullname() }"/>
					</div>
					<div class="form-group">
						<label for="emaill">Email Address</label> <input type="text"
							class="form-control" id="emaill" name="emaill" value ="${user.getEmaill()}"/>
					</div>
					<div class="form-check form-check-inline">
						<label for="" class="ml-2">Role: </label> <label class="ml-2">
							<input type="radio" class="form-check-input" id="admin"
							name="admin" value=""${user.getAdmin()?'checked':''} />Admin
						</label> 
						<label class="ml-2"> <input type="radio"
							class="form-check-input" id="user" name="admin"  value=""${! user.getAdmin()?'checked':'' }/>User
						</label>
					</div>
					<div class="form-group">
						<button class="btn btn-primary" formaction="UserServlet/create">Create</button>
						<button class="btn btn-warning" formaction="UserServlet/update">Update</button>
						<button class="btn btn-danger" formaction="UserServlet/delete">Delete</button>
						<button class="btn btn-info" formaction="UserServlet/reset">Reset</button>
					</div>
				</form>
			</div>
		</div>
		<div class="row">
			<div class="col">
				<table class="table table-stripe">
					<tr>
						<td>UserId</td>
						<td>FullName</td>
						<td>Email</td>
						<td>role</td>
						<td>&nbsp;</td>
					</tr>

					<c:forEach var="item" items="${users }">
						<tr>
							<td >${item.getUserId() }</td>
							<td>${item.getFullname() }</td>
							<td>${item.getEmaill() }</td>
							<td>${item.getAdmin()? "admin" : "user" }</td>
							<td><a href="edit?userId=${item.getUserId() }" >edit </a>  </td>
							<td><a href="deleteD?userId=${item.getUserId() }">delete</a></td>
						</tr>
					</c:forEach>





				</table>
			</div>
		</div>
	</main>



	<!-- Option 1: jQuery and Bootstrap Bundle (includes Popper) -->
	<script src="https://code.jquery.com/jquery-3.5.1.slim.min.js"
		integrity="sha384-DfXdz2htPH0lsSSs5nCTpuj/zy4C+OGpamoFVy38MVBnE+IbbVYUew+OrCXaRkfj"
		crossorigin="anonymous"></script>
	<script
		src="https://cdn.jsdelivr.net/npm/bootstrap@4.6.0/dist/js/bootstrap.bundle.min.js"
		integrity="sha384-Piv4xVNRyMGpqkS2by6br4gNJ7DXjqk09RmUpJ8jgGtD7zP9yug3goQfGII0yAns"
		crossorigin="anonymous"></script>


</body>
</html>