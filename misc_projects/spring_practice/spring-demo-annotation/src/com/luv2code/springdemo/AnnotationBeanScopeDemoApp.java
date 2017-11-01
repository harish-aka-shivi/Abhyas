package com.luv2code.springdemo;

import org.springframework.context.support.ClassPathXmlApplicationContext;

public class AnnotationBeanScopeDemoApp {
	
	public static void main(String[] args) {
	
		ClassPathXmlApplicationContext context = new ClassPathXmlApplicationContext("applicationContext.xml");
		
		// get the bean from spring container
		Coach theCoach = context.getBean("tennisCoach",Coach.class);
		
		
		// get the bean from spring container
		Coach Coach2 = context.getBean("tennisCoach",Coach.class);

		boolean result = (theCoach == Coach2);
		
		System.out.println("same pointing -> " +  result);
		System.out.println("the coach location -> " +  theCoach);
		System.out.println("Coach 2 loaction -> " +  Coach2);
		
	
	}

}
