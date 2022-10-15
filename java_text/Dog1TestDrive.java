class Dog1 {

	void bark(int numOfBarks) {
		while (numOfBarks > 0) {
			System.out.println("ruff");
			numOfBarks -= 1;
		}
	}
}

class Dog1TestDrive {
	public static void main(String[] args) {
		Dog1 d = new Dog1();
		d.bark(3);
	}
}