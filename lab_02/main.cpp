#include <iostream>
#include <chrono>
#include <list>
#include "List.h"
#include "DoubleLinkedList.h"
#include "RingBuffer.h"




int main()
{
	using namespace std;
	try
	{
		using ns = std::chrono::nanoseconds;

		List<int> userlist;
		std::list<int> stllist;
		
		cout << endl;
		cout << "\t\t\tPerformance comparison results" << endl;
		cout << "\t\t\t  (all results in nanoseconds)\n" << endl;
		cout << "type\t\t" << "push\t\t\t" << "pop\t\t\t" << "qsort\t\t\t" << "msort\t\t" << endl;
		cout << "My list\t\t";

		////////// LINKED LIST CHECK /////////////

		auto start = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < 10000; i++)
		{
			userlist.push_back(i);
		}
		auto end = std::chrono::high_resolution_clock::now();
		auto res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t";

		start = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < 10000; i++)
		{
			userlist.pop_back();
		}
		end = std::chrono::high_resolution_clock::now();
		res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t";

		userlist.push_back(-32);
		userlist.push_back(54);
		userlist.push_back(12);
		userlist.push_back(76);
		userlist.push_back(31);

		start = std::chrono::high_resolution_clock::now();
		userlist.quicksort(0, userlist.count());
		end = std::chrono::high_resolution_clock::now();
		res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t\t";

		userlist.push_back(99);
		userlist.push_back(15);
		userlist.push_back(21);
		userlist.push_back(43);
		userlist.push_back(-122);

		start = std::chrono::high_resolution_clock::now();
		userlist.mergesort(0, userlist.count()-1);
		end = std::chrono::high_resolution_clock::now();
		res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t\n";


		cout << "STL list\t";

		start = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < 10000; i++)
		{
			stllist.push_back(i);
		}
		end = std::chrono::high_resolution_clock::now();
		res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t\t";

		start = std::chrono::high_resolution_clock::now();
		for (int i = 0; i < 10000; i++)
		{
			stllist.pop_back();
		}
		end = std::chrono::high_resolution_clock::now();
		res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t\t";

		stllist.push_back(-32);
		stllist.push_back(54);
		stllist.push_back(12);
		stllist.push_back(76);
		stllist.push_back(31);

		start = std::chrono::high_resolution_clock::now();
		stllist.sort();
		end = std::chrono::high_resolution_clock::now();
		res = std::chrono::duration_cast<ns>(end - start).count();
		cout << res << "\t\t\t";
		cout << "----" << endl;
	}
	catch (const std::exception& exp)
	{
		cout << exp.what() << endl;
	}
	
	return 0;
}