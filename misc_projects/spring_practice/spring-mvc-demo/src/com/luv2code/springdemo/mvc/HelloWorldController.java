package com.luv2code.springdemo.mvc;

import javax.servlet.http.HttpServletRequest;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;

@Controller
@RequestMapping("/hello")
public class HelloWorldController {
	
	// controller method to show the form
	@RequestMapping("/showForm")
	public String showForm() {
		return "helloworld-form";
	}
	
	// method to show the form
	@RequestMapping("/processForm")
	public String processForm() {
		return "helloWorld";
	}
	
	
	// add a controller method to read form data and make it caps
	@RequestMapping("/processFormVersionTwo")
	public String letsShoutDude(HttpServletRequest request, Model model) {
		
		//read the request parameter from html forms
		String  name  = request.getParameter("studentName");
		name = name.toUpperCase();
		String result = "Yo " + name;
		
		model.addAttribute("message",result);
	
		return "helloWorld";
	
	}
	
	// add a controller method to read form data and make it caps
	@RequestMapping("/processFormVersionThree")
	public String processFormVersionThree(@RequestParam("studentName") String name,
			Model model) {
		

		name = name.toUpperCase();
		String result = "Yo " + name;
		
		model.addAttribute("message",result);
	
		return "helloWorld";
	
	}
	
	
	
}
