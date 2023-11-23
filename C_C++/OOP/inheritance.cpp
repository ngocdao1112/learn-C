#include <iostream>
#include <list>
using namespace std;

class YouTubeChannel { // định nghĩa class YouTubeChannel
    private:
        //thuộc tính (attribute)
        string Name;
        // string OwerName;
        int SubscribersCount;
        list<string> PublishedVideoTitles;
    protected:
        string OwnerName;
    public:
    //2. Constructor cho class YouTubeChannel (method constructor)
        //truyền 2 tham số và truyền 2 đối số cho constructor
        YouTubeChannel(string name, string owerName) { 
        //gán các giá trị ban đầu cho các attributes
            Name = name;
            OwnerName = owerName;
            SubscribersCount = 0;
        }
        //3. Class methods
        void GetInfo() {
            cout << "Name: " << Name << endl;
            cout << "OwerName: " << OwnerName << endl;
            cout << "SubscribersCount: " << SubscribersCount << endl;
            cout << "List Videos: " << endl;
            for (string videoTitle : PublishedVideoTitles) {
                cout << videoTitle << endl;
            }
        }
        //4. Encapsulation
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
//5. INHERITANCE
class CookingYoutubeChannel:public YouTubeChannel { //'inheritance' public from class 'YouTubeChannel'
    public:
        //passes 'name' & 'ownerName' to the base class constructor 'YouTubeChannel'.
        CookingYoutubeChannel(string name, string ownerName):YouTubeChannel(name, ownerName) {
        
        }
        void Practice() { //method bổ sung
            // cout << "practicing cooking, learning new recipes, experimenting with spices..." << endl;
            // OwnerName đã access được vì có protected (lớp con CookingYoutubeChannel có thê gọi được class )
            cout << OwnerName << " is practicing cooking, learning new recipes, experimenting with spices..." << endl;
        }
};

int main() {
    CookingYoutubeChannel cookingMyChannel1("Ngoc Kitchen", "Ngoc");
    CookingYoutubeChannel cookingMyChannel2("Trieu Kitchen", "Trieu");
/*  
    cookingMyChannel1.PublishVideo("Apple pie");
    cookingMyChannel1.PublishVideo("Chocolate cake");
    cookingMyChannel1.Subscribe();
    cookingMyChannel1.Subscribe();
    cookingMyChannel1.GetInfo();

    YouTubeChannel myChannel("aaa", "bbbbb");
    myChannel.OwerName(); => cannot access vì OwerName đang nằm trong private
*/
    cookingMyChannel1.Practice();
    cookingMyChannel2.Practice();

    system("pause > 0");
}

