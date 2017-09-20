package com.luv2code.springdemo;

import org.springframework.context.support.ClassPathXmlApplicationContext;

public class SetterDemoApp {
	
	public static void main(String[] args) {
		// load the spring config
		ClassPathXmlApplicationContext context = new ClassPathXmlApplicationContext("applicationContext.xml");
		
		// retrieve the spring bean
		CricketCoach theCoach = context.getBean("myCricCoach",CricketCoach.class);
		
		
		System.out.println(theCoach.getDailyWorkout());
		System.out.println(theCoach.getDailyFortune());
		System.out.println(theCoach.getEmailAddress());
		System.out.println(theCoach.getTeam());

		// close the context
		context.close();

	}

}
