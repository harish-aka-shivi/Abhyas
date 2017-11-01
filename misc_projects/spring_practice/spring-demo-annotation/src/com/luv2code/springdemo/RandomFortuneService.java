package com.luv2code.springdemo;

import java.util.Random;

import org.springframework.stereotype.Component;

@Component
public class RandomFortuneService implements FortuneService {

	
	private String[] data = {
			"Random Fortune 0","Random Fortune 1","Random Fortune 2","Random Fortune 3"
			
	};
	
	@Override
	public String getFortune() {
		int index = new Random(data.length); 
		return "Random Fortune";
	}

}
