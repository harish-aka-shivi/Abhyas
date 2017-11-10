package com.luv2code.springdemo.mvc;

import java.util.LinkedHashMap;


public class Student {
	String firstName  = "";
	String lastName   = "";
	String country = "";
	
	String favoriteLanguage = "";
	
	String[] operatingSystems;
	
	LinkedHashMap<String, String> countryOptions;
	
	public String getFavoriteLanguage() {
		return favoriteLanguage;
	}
	
	public void setFavoriteLanguage(String favoriteLanguage) {
		this.favoriteLanguage = favoriteLanguage;
	}
	
	public LinkedHashMap<String, String> getCountryOptions() {
		return countryOptions;
	}


	public String getCountry() {
		return country;
	}
	
	
	public void setCountry(String country) {
		this.country = country;
	}
	
	public String getFirstName() {
		return firstName;
	}
	
	public String getLastName() {
		return lastName;
	}
	
	public Student() {
		countryOptions = new LinkedHashMap<String,String>();
		countryOptions.put("Br","brazil");
		
		
	}
	
	public void setFirstName(String firstName) {
		this.firstName = firstName;
	}
	
	public void setLastName(String lastName) {
		this.lastName = lastName;
	}
	
	public String[] getOperatingSystems() {
		return operatingSystems;
	}
	
	public void setOperatingSystems(String[] operatingSystem) {
		this.operatingSystems = operatingSystem;
	}
}
