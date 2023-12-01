#include <iostream>
#include <list>
using namespace std;
//1. CLASS & OBJECT
/*
    - OPP cho phép biểu diễn các đối tượng trong lập trình và các đối tượng đó sẽ được biểu diễn cùng với các thuộc tính và sau đó là hành vi của chúng 
    - class and object:
        + class đại diện cho 1 mẫu nghĩa là 1 bản thiết kế
            + trái cây
            + car
            + class car có attributes và sau đó có 1 số hành vi
        + object đại diện cho 1 ví dụ về class đó, thể hiện của lớp đó 
            + chuối, táo
            + ford, mescedes, bmw
        
*/
class YouTubeChannel { // định nghĩa class YouTubeChannel
    public:
        //thuộc tính (attribute)
        string Name;
        string OwerName;
        int SubscribersCount;
        list<string> PublishedVideoTitles;
};
int main() {
    YouTubeChannel myChannel; //khởi tạo object myChannel thuộc class YouTubeChannel
    //gán giá trị cho các attribute của object myChannel 
    myChannel.Name = "CodeBeauty";
    myChannel.OwerName = "NgocDao";
    myChannel.SubscribersCount = 1800;
    myChannel.PublishedVideoTitles = {"\tC++ for beginners video 1", "\tHTML & CSS video 1", "\tC++ OOP video 1"};

    cout << "Name: " << myChannel.Name << endl;
    cout << "OwerName: " << myChannel.OwerName << endl;
    cout << "SubscribersCount: " << myChannel.SubscribersCount << endl;
    cout << "List Videos: " << endl;
    //khai báo biến có kiểu dữ liệu là string(chuỗi ký tự) với tên biến là videoTitle
    for (string videoTitle : myChannel.PublishedVideoTitles) {
        cout << videoTitle << endl;
    }
    //tạo 1 object khác thuộc class YouTubeChannel ?
    /*
        bad solution:
            - create 1 object mới với myChannel_1
            - copy chỗ gán giá trị của myChannel và change thành myChannel2
            - sau đó đổi các thông tin của giá trị gán
            - và phần cout cũng phải change thành myChannel1
        ===========>>>>>>>>>>> Constructor được ra đời
    */
    
}

