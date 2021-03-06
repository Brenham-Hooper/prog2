#include <cstdlib>
using namespace std;
// Integer class 

class Integer{
	public:
		Integer(int);
		int get();
		void set(int);
		int fib();
		int fibb(int);
	private:
		int val;

	};
 
Integer::Integer(int n){
	val = n;
	}
 
int Integer::get(){
	return val;
	}

int Integer::fibb(int n){
	if((n<=1)){
		return(n);     // these are the fib base cases, returns x with x=0 or x=1
	}
	else{
		return(fibb(n-1)+fibb(n-2));
	}
}
int Integer::fib(){
	if((val<=1)){
		return(val);     // these are the fib base cases, returns x with x=0 or x=1
	}
	else{
		return(fibb(val-1)+fibb(val-2));
	}
}


void Integer::set(int n){
	val = n;
	}


extern "C"{
	Integer* Integer_new(int n) {return new Integer(n);}
	int Integer_get(Integer* integer) {return integer->get();}
	int Integer_fib(Integer* integer) {return integer->fib();}
	void Integer_set(Integer* integer, int n) {integer->set(n);}
	void Integer_delete(Integer* integer){
		if (integer){
			delete integer;
			integer = nullptr;
			}
		}
	}
