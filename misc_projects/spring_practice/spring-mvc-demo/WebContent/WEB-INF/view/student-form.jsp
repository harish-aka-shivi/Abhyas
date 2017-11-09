<%@ taglib uri="http://www.springframework.org/tags/form" prefix="form"%>
<!DOCTYPE html>

<html>

<head>
	<title>Student Registration Form</title>
</head>

<body>
	<!-- student is the attribute key as -->
	<form:form action="processForm" modelAttribute = "student">
	
	<!-- attribute of first name  -->
	First name : <form:input path="firstName"/>
	
	
	<br></br>
	<!--  -->
	Last name:<form:input path ="lastName"/>
	
	<br></br>
	
		<br></br>
	
	<form:select path = "country">
	
    <%-- <form:option value="brazil" label="brazil"/>
	<form:option value="india" label="India"/>
	<form:option value="spain" label="Spain"/>	 --%>
	 
	 <form:options items="${student.countryOptions}"/>
	</form:select>
	
	
	<input type = "submit" value = "Submit">
	
	
	</form:form>

</body>


</html>