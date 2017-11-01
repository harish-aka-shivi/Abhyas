package com.luv2code.springdemo;

public class RestFortuneService implements FortuneService {

	@Override
	public String getFortune() {
		return "Rest Api Service";
	}

}
