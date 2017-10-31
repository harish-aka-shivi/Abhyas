package com.luv2code.springdemo;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

@Component
public class TennisCoach implements Coach {
	// auto wired injection
	@Autowired
	private FortuneService fortuneService;
	
	public TennisCoach()  {
		System.out.println("inside def constructor");

	}
//	@Autowired
//	public TennisCoach(FortuneService fortuneService) {
//		this.fortuneService = fortuneService;
//	}
//	
	// mthdod injection
//	@Autowired
//	public void doSomeCrazyStuff(FortuneService fortuneService) {
//		System.out.println("inside do some crazy constructor");
//
//		this.fortuneService = fortuneService;
//	}
	
	public String getDailyWorkout() {
		return "Dont get tennis elbow";
	}

	@Override
	public String getDailyFortune() {
		return fortuneService.getFortune();
	}
	
//	public void doSomeCrazyStuff() {
//		
//	}

	
	
}
