#include <iostream>
/**
 * Интерфейс Субъекта объявляет общие операции как для Реального Субъекта, так и
 * для Заместителя. Пока клиент работает с Реальным Субъектом, используя этот
 * интерфейс, вы сможете передать ему заместителя вместо реального субъекта.
 */
class Subject {
public:
    virtual void Request() const = 0;
};
/**
 * Реальный Субъект содержит некоторую базовую бизнес-логику. Как правило,
 * Реальные Субъекты способны выполнять некоторую полезную работу, которая к
 * тому же может быть очень медленной или точной – например, коррекция входных
 * данных. Заместитель может решить эти задачи без каких-либо изменений в коде
 * Реального Субъекта.
 */
class RealSubject : public Subject {
public:
    void Request() const override {
        std::cout << "RealSubject: Handling request.\n";
    }
};
/**
 * Интерфейс Заместителя идентичен интерфейсу Реального Субъекта.
 */
class Proxy : public Subject {
private:
    RealSubject* real_subject_;

    bool CheckAccess() const {
        // Некоторые реальные проверки должны проходить здесь.
        std::cout << "Proxy: Checking access prior to firing a real request.\n";
        return true;
    }
    void LogAccess() const {
        std::cout << "Proxy: Logging the time of request.\n";
    }

    /**
     * Заместитель хранит ссылку на объект класса РеальныйСубъект. Клиент может
     * либо лениво загрузить его, либо передать Заместителю.
     */
public:
    Proxy(RealSubject* real_subject) : real_subject_(new RealSubject(*real_subject)) {
    }

    ~Proxy() {
        delete real_subject_;
    }
    /**
     * Наиболее распространёнными областями применения паттерна Заместитель
     * являются ленивая загрузка, кэширование, контроль доступа, ведение журнала и
     * т.д. Заместитель может выполнить одну из этих задач, а затем, в зависимости
     * от результата, передать выполнение одноимённому методу в связанном объекте
     * класса Реального Субъект.
     */
    void Request() const override {
        if (this->CheckAccess()) {
            this->real_subject_->Request();
            this->LogAccess();
        }
    }
};
