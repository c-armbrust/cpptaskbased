#include <iostream>
#include <future>
#include <exception>

using namespace std;

int greetings() {
	cout << "Hello World!\n";
	throw std::runtime_error("test exception"); 
	return 0;
}

int add(int a, int b){
	return a + b;
}

int main()
{
//	auto fut2 = std::async(std::launch::async, add, 3, 8);
	auto fut2 = std::async([](int a, int b){return a + b;}, 10, 20);
	auto res2 = fut2.get();	
	cout << res2 << endl;


	try
	{
		auto fut1 = std::async(std::launch::async, greetings);
		auto res1 = fut1.get();
 		cout << res1 << endl;
	}
	catch(std::exception& e)
	{
		cout << e.what() << endl;
		return 1;
	}

return 0;
}
