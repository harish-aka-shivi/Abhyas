package com.luv2code.springdemo;

public class CricketCoach implements Coach {
	private FortuneService fortuneService;
	
	private String emailAddress;
	private String team;
	
	public CricketCoach() {}

	public void setFortuneService(FortuneService fortuneService) {
		System.out.println("setting fortune service");
		this.fortuneService = fortuneService;
	}


	public String getDailyWorkout() {
		return "bowl daily";
	}

	public String getDailyFortune() {
		return fortuneService.getFortune();
	}

	public String getEmailAddress() {
		return emailAddress;
	}

	public void setEmailAddress(String emailAddress) {
		System.out.println("setting email address service");
		this.emailAddress = emailAddress;
	}

	public String getTeam() {
		return team;
	}

	public void setTeam(String team) {
		System.out.println("setting team");
		this.team = team;
	}
	
	

}
