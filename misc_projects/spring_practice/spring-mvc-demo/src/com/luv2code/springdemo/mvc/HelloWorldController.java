package com.luv2code.springdemo.mvc;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;

@Controller
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
		return "helloWorld";
	
	}
	
	
	
}
