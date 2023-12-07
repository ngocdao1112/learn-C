#include <iostream>
#include <math.h>
using namespace std;

//FRIEND FUNCTION
    // class EquilteralTriangle {
    // private:
    //     float a;
    //     float circumference;
    //     float area;
    // public:
    //     void setA(float length) {
    //         a = length;
    //         circumference = a*3; //cv = a+a+a
    //         area = (sqrt(3)*a*a) / 4; // s = (canh^2.can(3)) / 4
    //     }
    //     friend void PrintResults(EquilteralTriangle et); //đi với global func
    // };

    // //global func
    // void PrintResults(EquilteralTriangle et) {
    //     cout << "circumference = " << et.circumference << endl;
    //     cout << "area = " << et.area << endl;
    // }

    // int main() {
    //     EquilteralTriangle et;
    //     et.setA(3);
    //     // nếu để như vầy thì cannot access vì cả 2 đều trong private
    //     // vì vậy hãy tạo friend và tạo thêm hàm void như ở trên
    //     // cout << "circumference = " << et.circumference << endl; 
    //     // cout << "area = " << et.area << endl;
    //     PrintResults(et); // ko còn là hàm global nữa

    //     /* TẠO 1 FRIEND CLASS
    //     vậy liệu 1 class có nhiều friend func không? có nhưng phải lựa chọn
    //     nếu nhiều friend func thì sẽ mất đi tính encapsulation
    //     vì có 1 số data cần phải private và k đc public ra ngoài
    //     ko n~ có các friend func mà còn có friend class
    //     */

    //     system("pause>null");
    // }


//FRIEND CLASS (ko phải là lẫn nhau mà là trong 'EquilteralTriangle' nếu có any attribute (private or protected) nào thì 'Homework' sẽ access được nhưng ngc lại thì không)
                // cũng k phải là inheritance: có nghĩa nếu có 1 base class có friend func thì friend func theo default sẽ k phải là friend của các class dẫn xuất của base class          
    class EquilteralTriangle {
    private:
        float a;
        float circumference;
        float area;
    public:
        void setA(float length) {
            a = length;
            circumference = a*3; //cv = a+a+a
            area = (sqrt(3)*a*a) / 4; // s = (canh^2.can(3)) / 4
        }
        friend class Homework; //tạo 1 friend class và chỉ định Homework
    };
    class Homework { //create friend class
    public:
        void PrintResults(EquilteralTriangle et) { //local func -> hàm thành viên 
            cout << "circumference = " << et.circumference << endl;
            cout << "area = " << et.area << endl;
        }
    };

    int main() {
        EquilteralTriangle et;
        et.setA(3);
        // PrintResults(et); //ko còn là hàm global nữa, chỉ tồn tại ở dạng hàm thành viên của class Homework
        //chỉ đc cách gọi bằng sử dụng 1 object
        Homework h;
        h.PrintResults(et); //giờ hàm này đc gọi là thành viên của class Homework
        /*
        vậy liệu 1 class có nhiều friend func không? có nhưng phải lựa chọn
        nếu nhiều friend func thì sẽ mất đi tính encapsulation
        vì có 1 số data cần phải private và k đc public ra ngoài
        ko n~ có các friend func mà còn có friend class
        */

        system("pause>null");
    }

/*
- struct mặc định là public
- class mặc đinh là private

- nên khi operator overloading cho 1 struct thì k cần create các friend func để access các thành viên public vì chúng là public 
- nhưng khi làm việc với các class, các thành viên theo default là private, vì vậy nếu muốn access chúng bên ngoài lớp đó, bạn cần create 1 friend class cho operator overloading 
*/