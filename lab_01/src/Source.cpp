#include <iostream>
#include "Structs.h"
#include <chrono>
#include <stack>
#include <queue>
#include <vector>

int main()
{
	try {

		using ns = std::chrono::nanoseconds;

		Stack stack1(5);
		std::stack<int> stack2;
		Queue queue1(5);
		std::queue<int> queue2;
		Vector vector1(5);
		std::vector<int> vector2;

		cout << endl;
		cout << "\t\t\tPerformance comparison results" << endl;
		cout << "\t\t\t  (all results in nanoseconds)" << endl << endl;
		cout << "type\t\t" << "push\t\t" << "pop\t\t" << "peek\t\t" << "count\t\t" << "at" << endl;
		cout << "My stack\t";

	////////// STACK CHECK /////////////

		auto start = std::chrono::high_resolution_clock::now();
		stack1.StackPush(99);
		auto end = std::chrono::high_resolution_clock::now();
		auto res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t";

		start = std::chrono::high_resolution_clock::now();
		stack1.StackPop();
		end = std::chrono::high_resolution_clock::now();
		res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t";

		stack1.StackPush(23);
	
		start = std::chrono::high_resolution_clock::now();
		stack1.Peek();
		end = std::chrono::high_resolution_clock::now();
		res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t";

		start = std::chrono::high_resolution_clock::now();
		stack1.Count();
		end = std::chrono::high_resolution_clock::now();
		res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t";
		cout << "----" << endl;

		cout << "STL stack\t";

		start = std::chrono::high_resolution_clock::now();
		stack2.push(99);
		end = std::chrono::high_resolution_clock::now();
		res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t";

		start = std::chrono::high_resolution_clock::now();
		stack2.pop();
		end = std::chrono::high_resolution_clock::now();
		res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t";

		stack2.push(23);

		start = std::chrono::high_resolution_clock::now();
		stack2.top();
		end = std::chrono::high_resolution_clock::now();
		res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t";

		stack2.push(23);

		start = std::chrono::high_resolution_clock::now();
		stack2.size();
		end = std::chrono::high_resolution_clock::now();
		res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t";
		cout << "----" << endl;

	////////// QUEUE CHECK /////////////

		cout << endl << "my_queue\t";
		start = std::chrono::high_resolution_clock::now();
		queue1.QueuePush(3);
		end = std::chrono::high_resolution_clock::now();
		res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t";

		start = std::chrono::high_resolution_clock::now();
		queue1.QueuePop();
		end = std::chrono::high_resolution_clock::now();
		res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t";

		start = std::chrono::high_resolution_clock::now();
		queue1.QueuePeek();
		end = std::chrono::high_resolution_clock::now();
		res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t";

		start = std::chrono::high_resolution_clock::now();
		queue1.Count();
		end = std::chrono::high_resolution_clock::now();
		res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t";
		cout << "----" << endl;

		cout << "STL queue\t";

		start = std::chrono::high_resolution_clock::now();
		queue2.push(2);
		end = std::chrono::high_resolution_clock::now();
		res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t";

		start = std::chrono::high_resolution_clock::now();
		queue2.pop();
		end = std::chrono::high_resolution_clock::now();
		res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t";

		queue2.push(22);

		start = std::chrono::high_resolution_clock::now();
		queue2.front();
		end = std::chrono::high_resolution_clock::now();
		res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t";

		start = std::chrono::high_resolution_clock::now();
		queue2.size();
		end = std::chrono::high_resolution_clock::now();
		res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t";
		cout << "----" << endl;

	////////// VECTOR CHECK /////////////

		cout << endl << "my_vector\t";

		start = std::chrono::high_resolution_clock::now();
		vector1.VectorPush(22);
		end = std::chrono::high_resolution_clock::now();
		res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t";

		start = std::chrono::high_resolution_clock::now();
		vector1.VectorPop();
		end = std::chrono::high_resolution_clock::now();
		res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t";

		start = std::chrono::high_resolution_clock::now();
		vector1.Peek();
		end = std::chrono::high_resolution_clock::now();
		res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t";

		vector1.VectorPush(22);

		start = std::chrono::high_resolution_clock::now();
		vector1.Count();
		end = std::chrono::high_resolution_clock::now();
		res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t";

		start = std::chrono::high_resolution_clock::now();
		vector1.VectorAt(0) = 1;
		end = std::chrono::high_resolution_clock::now();
		res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t" << endl;

		cout << "STL vector\t";

		start = std::chrono::high_resolution_clock::now();
		vector2.push_back(22);
		end = std::chrono::high_resolution_clock::now();
		res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t";

		start = std::chrono::high_resolution_clock::now();
		vector2.pop_back();
		end = std::chrono::high_resolution_clock::now();
		res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t";
		cout << "----" << "\t\t";


		vector2.push_back(22);

		start = std::chrono::high_resolution_clock::now();
		vector2.size();
		end = std::chrono::high_resolution_clock::now();
		res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t";

		start = std::chrono::high_resolution_clock::now();
		vector2.at(0) = 1;
		end = std::chrono::high_resolution_clock::now();
		res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t";
		cout << endl;

	}
	catch (const std::exception & exp) 
	{
		cout << exp.what() << endl;
	}

return 0;
}