package com.luv2code.springdemo;

import org.springframework.context.support.ClassPathXmlApplicationContext;

public class HelloSpringApp {

	
	public static void main(String[] args) {

		// load the spring config
		ClassPathXmlApplicationContext context = new ClassPathXmlApplicationContext("applicationContext.xml");
		
		// retrieve the spring bean
		Coach theCoach = context.getBean("myCoach",Coach.class);
		
		
		System.out.print(theCoach.getDailyWorkout());
		System.out.print(theCoach.getDailyFortune());
		
		// close the context
		context.close();

		
	}

}
