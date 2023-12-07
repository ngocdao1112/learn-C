#include <iostream>
#include <string.h>
#include <list>
using namespace std;

//struct: default là public
//class: default là private
struct YouTubeChannel {
    string Name;
    int SubscribersCount;

    YouTubeChannel(string name, int subscribersCount) {
        Name = name; // khởi tạo
        SubscribersCount = subscribersCount;
    }
    bool operator == (const YouTubeChannel& channel) {
        return this->Name == channel.Name;
    }
};
// void operator << (ostream& COUT, YouTubeChannel& ytChannel) {
ostream& operator << (ostream& COUT, YouTubeChannel& ytChannel) { // hàm global và có 2 tham số
    COUT << "Name: " << ytChannel.Name << endl;
    COUT << "Subscribers: " << ytChannel.SubscribersCount << endl;
    return COUT;
}


struct MyCollection { // hàm thành viên và chỉ nhận 1 tham số sử dụng trong trường hợp bị quá tải
    list<YouTubeChannel>myChannels;

    void operator+=(YouTubeChannel& channel) {
        this->myChannels.push_back(channel);    
    }

    void operator-=(YouTubeChannel& channel) {
        this->myChannels.remove(channel);    
    }
};
ostream& operator << (ostream& COUT, MyCollection& myCollection) {
    for(YouTubeChannel ytChannel : myCollection.myChannels)
        COUT << ytChannel << endl;
    return COUT;
}

int main() {
    YouTubeChannel yt1 = YouTubeChannel ("CodeBeauty", 75000);
    YouTubeChannel yt2 = YouTubeChannel ("My second channel", 80000);
    // cout << 5; // sẽ hiểu
    // cout << yt1; // sẽ error vì k biết cách in dữ liệu do người dùng xác định và bayh hãy xem như 'cout' & 'yt1' là 2 toán tử
    
    // cout << yt1 << yt2;

    // cout << yt1;
    // operator << (cout, yt1); // Name: CodeBeauty  
    //                             // Subscribers: 75000

    MyCollection myCollection;
    myCollection += yt1;
    myCollection += yt2;
    myCollection -= yt2;
    cout << myCollection;

    cin.get();

}

