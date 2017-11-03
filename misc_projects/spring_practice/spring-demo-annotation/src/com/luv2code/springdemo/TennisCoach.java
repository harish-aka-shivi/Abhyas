package com.luv2code.springdemo;

import javax.annotation.PostConstruct;
import javax.annotation.PreDestroy;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.context.annotation.Scope;
import org.springframework.stereotype.Component;


@Component
public class TennisCoach implements Coach {
	// auto wired injection
	@Autowired
	@Qualifier("happyFortuneService")
	private FortuneService fortuneService;
	
    @Value("${foo.email}")
    private String email;
        
    @Value("${foo.team}")
    private String team;
	
	public TennisCoach()  {
		System.out.println("inside def constructor");

	}
	
	// defining the init method
	@PostConstruct
	public void doMyStartUpStuff() {
		System.out.println("inside do my startup stuff, init");

	}
	
	@PreDestroy
	public void doMyCleaningStuff() {
		System.out.println("inside do my cleaning stuff, destroy");

	}
//	@Autowired
//	public TennisCoach(FortuneService fortuneService) {
//		this.fortuneService = fortuneService;
//	}
//	
	// method injection
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

	public String getEmail() {
		return email;
	}

	public void setEmail(String email) {
		this.email = email;
	}

	public String getTeam() {
		return team;
	}

	public void setTeam(String team) {
		this.team = team;
	}
	

	
	
//	public void doSomeCrazyStuff() {
//		
//	}

	
	
}
