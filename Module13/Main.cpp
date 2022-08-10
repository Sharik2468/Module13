#include "Facade.cpp"
#include "Deputy.cpp"
#include "Composite.cpp"
#include "Adapter.cpp"

int main() {
	//Facade
	Vilager1* subsystem1 = new Vilager1;
	Vilager2* subsystem2 = new Vilager2;
	Vilage* facade = new Vilage(subsystem1, subsystem2);
	std::cout << facade->Operation();

	delete facade;

	//Deputy
	std::cout << "Client: Executing the client code with a real subject:\n";
	RealSubject* real_subject = new RealSubject;
	real_subject->Request();
	std::cout << "\n";
	std::cout << "Client: Executing the same client code with a proxy:\n";
	Proxy* proxy = new Proxy(real_subject);
	proxy->Request();

	delete real_subject;
	delete proxy;

	//Composite
    Component* simple = new Leaf;
    std::cout << "Client: I've got a simple component:\n";
    ClientCode(simple);
    std::cout << "\n\n";
    /**
     * ...а также сложные контейнеры.
     */

    Component* tree = new Composite;
    Component* branch1 = new Composite;

    Component* leaf_1 = new Leaf;
    Component* leaf_2 = new Leaf;
    Component* leaf_3 = new Leaf;
    branch1->Add(leaf_1);
    branch1->Add(leaf_2);
    Component* branch2 = new Composite;
    branch2->Add(leaf_3);
    tree->Add(branch1);
    tree->Add(branch2);
    std::cout << "Client: Now I've got a composite tree:\n";
    ClientCode(tree);
    std::cout << "\n\n";

    std::cout << "Client: I don't need to check the components classes even when managing the tree:\n";
    ClientCode2(tree, simple);
    std::cout << "\n";

    delete simple;
    delete tree;
    delete branch1;
    delete branch2;
    delete leaf_1;
    delete leaf_2;
    delete leaf_3;

    //Adapter
    std::cout << "Client: I can work just fine with the Target objects:\n";
    Target* target = new Target;
    ClientCode(target);
    std::cout << "\n\n";
    Adaptee* adaptee = new Adaptee;
    std::cout << "Client: The Adaptee class has a weird interface. See, I don't understand it:\n";
    std::cout << "Adaptee: " << adaptee->SpecificRequest();
    std::cout << "\n\n";
    std::cout << "Client: But I can work with it via the Adapter:\n";
    Adapter* adapter = new Adapter(adaptee);
    ClientCode(adapter);
    std::cout << "\n";

    delete target;
    delete adaptee;
    delete adapter;

	return 0;
}