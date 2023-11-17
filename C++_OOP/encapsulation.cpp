#include <iostream>
#include <list>
using namespace std;
//2. ENCAPSULATION
/*

*/
class YouTubeChannel { // định nghĩa class YouTubeChannel
    private:
        //thuộc tính (attribute)
        string Name;
        string OwerName;
        int SubscribersCount;
        list<string> PublishedVideoTitles;
    public:
    //2. Constructor cho class YouTubeChannel
        //truyền 2 tham số và truyền 2 đối số cho constructor
    YouTubeChannel(string name, string OwerName) { 
        //gán các giá trị ban đầu cho các attribute
        Name = name;
        OwerName = OwerName;
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
    //4.encapsulation
    void Subscribe() {
        SubscribersCount++;
    }
    void Unsubcribe() {
        if(SubscribersCount > 0) {
            SubscribersCount--;
        }
    }
    void PublishVideo(string title) {
        PublishedVideoTitles.push_back(title);
    }
};

int main() {
    YouTubeChannel myChannel1("CodeBeauty", "NgocDao");
/*
    myChannel1.PublishedVideoTitles.push_back("\tC++ for begineers");
    myChannel1.PublishedVideoTitles.push_back("\tHTML & CSS for begineers");
    myChannel1.PublishedVideoTitles.push_back("\tC++ OOP");
    YouTubeChannel myChannel2("CodeBeautifull", "Trieu Ho");
*/    
    myChannel1.PublishVideo("\tC++ for begineers");
    myChannel1.PublishVideo("\tHTML & CSS for begineers");
    myChannel1.PublishVideo("\tC++ OOP");
    myChannel1.Unsubcribe();

    myChannel1.GetInfo();
    
}

