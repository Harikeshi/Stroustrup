#include <string>

using namespace std;

template<typename T>
class Disk_Ptr
{
	string identifier;
	T* in_core_address;



public:
	Disk_Ptr(const string& s) :identifier{ s }, in_core_address{ nullptr } {}
	~Disk_Ptr() {
		write_to_disk(identifier, in_core_address);
	}

	T* operator->() {
		if (in_core_address == nullptr) {
			in_core_address = read_from_disk(identifier);
		}

		return in_core_address;
	}

	T* read_from_disk(string id) { return nullptr; }

	void write_to_disk(string s, T* t) {/*some code*/ }
};

// Example
struct Rec {
	string name;
};

void update(const string& s) {
	Disk_Ptr<Rec> p{ s };

	p->name = "Hello";
}

