#include <iostream>
#include <string>

/**
 * Подсистема может принимать запросы либо от фасада, либо от клиента напрямую.
 * В любом случае для Подсистемы Фасад – это еще один клиент, и он не является
 * частью Подсистемы.
 */
class Vilager1 {
public:
	std::string Operation1() const {
		return "Subsystem1: Ready!\n";
	}
	// ...
	std::string OperationN() const {
		return "Subsystem1: Go!\n";
	}
};
/**
 * Некоторые фасады могут работать с разными подсистемами одновременно.
 */
class Vilager2 {
public:
	std::string Operation1() const {
		return "Subsystem2: Get ready!\n";
	}
	// ...
	std::string OperationZ() const {
		return "Subsystem2: Fire!\n";
	}
};

/**
 * Класс Фасада предоставляет простой интерфейс для сложной логики одной или
 * нескольких подсистем. Фасад делегирует запросы клиентов соответствующим
 * объектам внутри подсистемы. Фасад также отвечает за управление их жизненным
 * циклом. Все это защищает клиента от нежелательной сложности подсистемы.
 */
class Vilage {
protected:
	Vilager1* subsystem1_;
	Vilager2* subsystem2_;
	/**
	 * В зависимости от потребностей вашего приложения вы можете предоставить
	 * Фасаду существующие объекты подсистемы или заставить Фасад создать их
	 * самостоятельно.
	 */
public:
	/**
	 * В этому случае мы делегируем владение памятью классу Facade
	 */
	Vilage(Vilager1* subsystem1 = nullptr,Vilager2* subsystem2 = nullptr) {
		this->subsystem1_ = subsystem1 ? new Vilager1 : NULL;
		this->subsystem2_ = subsystem2 ? new Vilager2 : NULL;
	}
	~Vilage() {
		delete subsystem1_;
		delete subsystem2_;
	}
	/**
	 * Методы Фасада удобны для быстрого доступа к сложной функциональности
	 * подсистем. Однако клиенты получают только часть возможностей подсистемы.
	 */
	std::string Operation() {
		std::string result = "Facade initializes subsystems:\n";
		result += this->subsystem1_->Operation1();
		result += this->subsystem2_->Operation1();
		result += "Facade orders subsystems to perform the action:\n";
		result += this->subsystem1_->OperationN();
		result += this->subsystem2_->OperationZ();
		return result;
	}
};