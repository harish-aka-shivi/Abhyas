package com.luv2code.springdemo;

import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class JavaConfigDemoApp {

	
	public static void main(String[] args) {
		
		// read spring config file
//		ClassPathXmlApplicationContext context = new ClassPathXmlApplicationContext("applicationContext.xml");
		AnnotationConfigApplicationContext context = 
			new AnnotationConfigApplicationContext(SportConfig.class);

		
		// get the bean from spring container
		Coach theCoach = context.getBean("tennisCoach",Coach.class);

	   
		// call the method on bean
		System.out.println(theCoach.getDailyWorkout());
		System.out.println(theCoach.getDailyFortune());
		System.out.println(((TennisCoach)theCoach).getEmail());
	
		
		// close the context
		context.close();
		
	}

}
