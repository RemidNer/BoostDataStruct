#include <iostream>
#include <boost/array.hpp>
#include <boost/assign.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/dynamic_bitset/dynamic_bitset.hpp>

using namespace std;
using namespace boost;
using namespace boost::assign;

void case1()
{
	//assign() & at() & c_array()
	boost::array<int, 10> arr;

	arr[0] = 999;

	cout << "arr[0]: " << arr[0] << " arr.back(): " << arr.back() << endl;

	arr.assign(666);

	for (auto tmp:arr)
	{
		cout << tmp << " ";
	}
	cout << endl;

	int *ps = arr.c_array();
	*(ps + 5) = 888;

	cout << "arr.at(6): " << arr.at(6) << " " << endl;

	sort(arr.begin(), arr.end());

	cout << "After sort: " << endl;
	for (BOOST_AUTO(pos,arr.begin());pos != arr.end();++pos)
	{
		cout << " *pos: " << *pos << std::endl;
	}
}

void case2()
{
	// boost array init method
	boost::array<string, 3> atr = { "Bruce","Neal","Alice" };
	//boost::array<string,3> atr = {"Bruce","Neal"};		//剩余的元素将调用缺省构造函数完成初始化
	int a[10] = { 0 };
	boost::array<int, 10> ait = { 0 };

	assert(std::equal(ait.begin(), ait.end(), a));

	boost::array<int, 6> ps(list_of(1)(2)(3)(4)(5)(6));
	cout << "ps array content: ";
	for (auto tmp : ps)
	{
		cout << tmp << " ";
	}
	cout << endl;

	boost::array <string, 3> ptr(list_of("Bruce")("Neal"));	//自动初始化第三个元素为NULL
	assert(ptr.at(2).empty());
	cout << "After Assert ptr.at(3).empty()" << endl;
}

void case3()
{
	dynamic_bitset<> db1;							//a NULL dynamic_bitset
	dynamic_bitset<> db2(10);						//size of dynamic_bitset is 10
	dynamic_bitset<> db3(0x16, BOOST_BINARY(10101));
	dynamic_bitset<> db4(string("0100"));			//string constructor
	dynamic_bitset<> db5(db3);						//copy constructor
	dynamic_bitset<> db6;

	db6 = db4;										//valuation constructor

	cout << hex << db5.to_ulong() << endl;
	cout << db4[0] << db4[1] << db4[2] << endl;
}

void case4()
{
	//容器操作
	dynamic_bitset<> db;				//a NULL dynamic_bitset
	db.resize(32, true);				//扩展为10个二进制位，值全为1
	cout << db << endl;

	db.resize(5);						//缩小容量为5
	cout << db << endl;
}
int main()
{
	case4();
	system("pause");
}