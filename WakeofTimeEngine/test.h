//
// Created by alexander on 14/06/19.
//

#ifndef WAKEOFTIMEENGINE_TEST_H
#define WAKEOFTIMEENGINE_TEST_H


class Test {
public:
    Test():m_a(0),m_b('0'){
        std::cout<<"Construct default Test"<<*this<<"\n";
    }
    Test(const Test& orig): m_a(orig.m_a),m_b(orig.m_b) {
        std::cout<<"Construct cpy Test"<<*this<<"\n";
    }
    ~Test() {
        std::cout<<"Delete Test"<<*this<<"\n";
    }

    friend std::ostream& operator<<(std::ostream& ostream, const Test& test) {
        ostream<<"["<<test.m_a<<",'"<<test.m_b<<"']";
        return ostream;
    }

    void change(int New) {
        m_a = New;
    }

private:
    int m_a;
    char m_b;
};

struct Initialiser {
    void operator() (Test* element) {
        std::cout<<"Initialising Test"<<*element<<"\n";
    }
};

struct Releaser {
    void operator() (Test* element) {
        std::cout<<"Releasing Test"<<*element<<"\n";
    }
};

#endif //WAKEOFTIMEENGINE_TEST_H
