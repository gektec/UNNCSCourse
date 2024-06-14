package com.COMP2013;

public class ZooApp {

	public static void main(String[] args) {
		System.out.println("numZoos:"+Zoo.numZoos); // initialised by JVM; class variable; does not require object instantiation
		Zoo zoo0=new Zoo();
		Zoo zoo1=new Zoo("London",20);
		Zoo zoo2=new Zoo("Tokyo",15);
		Zoo zoo3=new Zoo("New York",26);
		Zoo zoo4=new Zoo("Paris",18);
		Zoo zoo5=new Zoo("Beeston",5);
		System.out.println(zoo0.printInfo());
		System.out.println(zoo1.printInfo());
		Compound compound1=zoo1.getCompound(10);
		compound1.addAnimal(new Animal());
		compound1.printInfo();
		System.out.println(zoo2.printInfo());
		System.out.println(zoo3.printInfo());
		System.out.println(zoo4.printInfo());
		System.out.println(zoo5.printInfo());
		System.out.println("numZoos:"+Zoo.numZoos);
	}
}
