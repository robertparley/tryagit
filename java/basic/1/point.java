class choose{
	public static paper point(int flag){
		paper p = null;
		if(flag == 0)
			p = new book();
		else if(flag == 1)
			p = new album();
		return p;
	}
}
