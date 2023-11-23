#include <iostream>
#include <list>
using namespace std;
//2. CONSTRUCTOR
/*
    - Constructor là 1 specefic method của class được gọi tự động khi 1 object của class đó được tạo
    - Constructor có tên giống với tên class và không có kiểu trả về (void)
    - Có 2 loại Constructor:
        + Default Constructor: Nếu không định nghĩa sẽ tự động tạo một constructor mặc định, 
                               Constructor mặc định không có tham số và thường được sử dụng để khởi tạo các thành viên của lớp.
        + Parameterized Constructor: có thể tự định nghĩa constructor với các tham số để khởi tạo đối tượng với các giá trị cụ thể
*/
class YouTubeChannel { // định nghĩa class YouTubeChannel
    public:
        //thuộc tính (attributes)
        string Name;
        string OwerName;
        int SubscribersCount;
        list<string> PublishedVideoTitles;

    //2. Constructor cho class YouTubeChannel
    // Constructor đc sd để khởi tạo các attributes của object YouTubeChannel khi nó được tạo ra.
    YouTubeChannel(string name, string owerName) { //truyền 2 tham số cho constructor
        //gán các giá trị cho các attributes
        Name = name;
        OwerName = owerName;
        SubscribersCount = 0;
    }
    //3. Class methods
    void GetInfo() {
        cout << "Name: " << Name << endl;
        cout << "OwerName: " << OwerName << endl;
        cout << "SubscribersCount: " << SubscribersCount << endl;
        cout << "List Videos: " << endl;
        for (string videoTitle : PublishedVideoTitles) {
            cout << videoTitle << endl;
        }
    }
};

int main() {
    YouTubeChannel myChannel1("CodeBeauty", "NgocDao");
    myChannel1.PublishedVideoTitles.push_back("\tC++ for begineers");
    myChannel1.PublishedVideoTitles.push_back("\tHTML & CSS for begineers");
    myChannel1.PublishedVideoTitles.push_back("\tC++ OOP");

    YouTubeChannel myChannel2("CodeBeautifull", "Trieu Ho");
/*
    cout << "Name: " << myChannel1.Name << endl;
    cout << "OwerName: " << myChannel1.OwerName << endl;
    cout << "SubscribersCount: " << myChannel1.SubscribersCount << endl;
    cout << "List Videos: " << endl;
    for (string videoTitle : myChannel1.PublishedVideoTitles) {
        cout << videoTitle << endl;
    }
    ...
    ...
    ...
*/

//3. CLASS METHODS
    /*  
        - class methods là các hàm (functions) được định nghĩa trong phạm vi của class 
        - với cout quá nhiều sẽ sinh ra class methods
    */
    myChannel1.GetInfo();
    myChannel2.GetInfo();
    
}

