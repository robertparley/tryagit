class CountyB implements People{
	private People people;
	CountyB(People p){people = p;}
	public void doSomeWork(){
		System.out.println("hello,why people always go to County A?");
		people.doSomework();
	}
}
