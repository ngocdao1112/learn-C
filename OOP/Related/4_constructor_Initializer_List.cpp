
#include <iostream>
#include <string>

// class Entity {
// private:
//     int m_Score;
//     std::string m_Name;
// public:

//     // C1:
//     // Entity() {
//     //     m_Name = "Unknow";
//     // }

//     // C2:
//     Entity()
//         : m_Score(0), m_Name("Unknow") {} //nhớ là phải viết theo thứ tự kiểu dữ liệu int trước >> string


//     Entity(const std::string& name) 
//         : m_Name(name) {}
//     // {
//     //     m_Name = name; // C1
//     // }

//     const std::string& GetName() const {
//         return m_Name;
//     }
// };
//========================
class Example {
public:
    Example() {
        std::cout << "Created Entity!" << std::endl;
    }

    Example(int x) {
        std::cout << "Created Entity with " << x << "!" << std::endl;
    }
};

class Entity {
private:
    std::string m_Name;
    // int x, y, z;
    Example m_Example;
public:
    Entity()
        // : x(0), y(0), z(0) 
        // : m_Example(Example(8)) // C2
        // : m_Example(8) // C3
    {
        m_Name = std::string("Unknow");
        m_Example = Example(8); //C1
    } 

    Entity(const std::string& name) 
        : m_Name(name) {}

    const std::string& GetName() const {
        return m_Name;
    }
};

int main() {
    Entity e0;
    // std::cout << e0.GetName() << std::endl;

    // Entity e1("Cherno");
    // std::cout << e1.GetName() << std::endl;

    // std::cin.get();
}