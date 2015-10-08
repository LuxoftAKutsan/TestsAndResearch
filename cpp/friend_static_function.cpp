struct X {
	static void foo();
};

class A {
	void bar() {
	}
	friend void X::foo();
};

void X::foo() {
	A a;
	a.bar();
}

int main() {
	return 0;
}
