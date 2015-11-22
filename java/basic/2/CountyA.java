class CountyA implements People{
	private People people = null;
	CountyA(People p){people = p;}
	public void doSomeWork(){
		System.out.println("A company special service.");
		people.doSomeWork();
	}
}
