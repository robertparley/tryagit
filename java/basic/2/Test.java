class Test{
	public static void main(String args []){
		People people = null;
		Teacher teacher = new Teacher();
		CountyA county = new CountyA(teacher);
		CountyA county2 = new CountyA(new Doctor());
		people = county;
		people.doSomeWork();
		people = county2;
		people.doSomeWork();
		}
}
