package com.luv2code.springdemo;

import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class SwimJavaConfigDemoApp {

	
	public static void main(String[] args) {
		
		// read spring Config file
//		ClassPathXmlApplicationContext context = new ClassPathXmlApplicationContext("applicationContext.xml");
		AnnotationConfigApplicationContext context = 
			new AnnotationConfigApplicationContext(SportConfig.class);

		
		// get the bean from spring container
//		Coach theCoach = context.getBean("swimCoach",Coach.class);
		SwimCoach theCoach = context.getBean("swimCoach",SwimCoach.class);
	   
		// call the method on bean
		System.out.println(theCoach.getDailyWorkout());
		System.out.println(theCoach.getDailyFortune());
	
		System.out.println("email => " +theCoach.getEmail());
		System.out.println("team ==> " + theCoach.getTeam());
		
		// close the context
		context.close();
		
	}

}
