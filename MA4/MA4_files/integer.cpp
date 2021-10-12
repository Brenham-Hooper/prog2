#include <cstdlib>
// Integer class 

class Integer{
	public:
		Integer(int);
		int get();
		void set(int);
		int fib(int);
	private:
		int val;
	};
 
Integer::Integer(int n){
	val = n;
	}
 
int Integer::get(){
	return val;
	}

int Integer::fib(int n){
	if((n==0||n==1)){
		return(n);     // these are the fib base cases, returns x with x=0 or x=1
	}
	else{
		return(fib(n-1)+fib(n-2));
	}
}


void Integer::set(int n){
	val = n;
	}


extern "C"{
	Integer* Integer_new(int n) {return new Integer(n);}
	int Integer_get(Integer* integer) {return integer->get();}
	int Integer_fib(Integer* integer, int n) {return integer->fib(n);}
	void Integer_set(Integer* integer, int n) {integer->set(n);}
	void Integer_delete(Integer* integer){
		if (integer){
			delete integer;
			integer = nullptr;
			}
		}
	}
