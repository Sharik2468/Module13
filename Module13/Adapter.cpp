#include <iostream>
#include <string>

/**
 * ������� ����� ��������� ���������, � ������� ����� �������� ���������� ���.
 */
class Target {
public:
    virtual ~Target() = default;

    virtual std::string Request() const {
        return "Target: The default target's behavior.";
    }
};

/**
 * ������������ ����� �������� ��������� �������� ���������, �� ��� ���������
 * ����������� � ������������ ���������� �����. ������������ ����� ��������� �
 * ��������� ���������, ������ ��� ���������� ��� ������ ��� ������������.
 */
class Adaptee {
public:
    std::string SpecificRequest() const {
        return ".eetpadA eht fo roivaheb laicepS";
    }
};

/**
 * ������� ������ ��������� ������������� ������ ����������� � �������
 * �����������.
 */
class Adapter : public Target {
private:
    Adaptee* adaptee_;

public:
    Adapter(Adaptee* adaptee) : adaptee_(adaptee) {}
    std::string Request() const override {
        std::string to_reverse = this->adaptee_->SpecificRequest();
        std::reverse(to_reverse.begin(), to_reverse.end());
        return "Adapter: (TRANSLATED) " + to_reverse;
    }
};

/**
 * ���������� ��� ������������ ��� ������, ������������ ������� ���������.
 */
inline void ClientCode(const Target* target) {
    std::cout << target->Request();
}

