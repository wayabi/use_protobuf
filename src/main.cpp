#include "a.pb.h"

#include <iostream>
#include <string>

using namespace message;
using namespace std;

int main(int argc, const char** argv)
{
	Person p;
	p.set_name("hoge");
	p.set_email("cc");
	cout << "byte size:" << p.ByteSize() << endl;
	p.set_email("aaacc");
	cout << "byte size:" << p.ByteSize() << endl;
	string s;
	p.SerializeToString(&s);
	cout << "serialized size:" << s.size() << endl;
	cout << s << endl;
	Person_Pos* pos = p.add_pos();
	pos->set_x(123);
	pos->set_y(222);
	pos = p.add_pos();
	pos->set_x(333);
	pos->set_y(444);
	cout << "num pos:" << p.pos_size() << endl;

	for(int i=0;i<p.pos_size();++i){
		cout << p.pos(i).DebugString() << endl;
	}


	cout << "IsInitialized:" << p.IsInitialized() << endl;//Quickly check if all required fields have values set.
	cout << p.DebugString() << endl;
	cout << p.ShortDebugString() << endl;

	Person p2;
	p2.ParseFromString(s);
	cout << "p2 name:" << p2.name() << endl;

	return 0;
}
