package com.luv2code.springdemo.mvc;

import org.springframework.stereotype.Component;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.RequestMapping;

@Controller
@RequestMapping("/student")
public class StudentController {

	@RequestMapping("/showForm")
	public String showForm(Model theModel) {
		Student student = new Student();
		
		theModel.addAttribute("student",student);
		
		
		return "student-form";
	}
	
	@RequestMapping("/processForm")
	public String processForm(@ModelAttribute("student") Student theStudent) {
		
		//log the inout data
		System.out.print("the student : " + theStudent.getFirstName() 
				+  "  " + theStudent.getLastName());
		
		return "student-confirmation";
	}
}
