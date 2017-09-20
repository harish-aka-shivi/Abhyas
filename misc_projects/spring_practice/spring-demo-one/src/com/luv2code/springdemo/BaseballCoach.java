package com.luv2code.springdemo;

public class BaseballCoach implements Coach {
	private FortuneService fortuneService;
	
	
	public BaseballCoach(FortuneService fortuneService) {
		this.fortuneService = fortuneService;
	}
	
	
	public String getDailyWorkout() {
		return "work";
	}

	public String getDailyFortune() {
		return fortuneService.getFortune() ;
	}

}
