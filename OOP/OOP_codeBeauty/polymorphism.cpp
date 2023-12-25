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
        int ContentQuality;
    public:
    //2. Constructor cho class YouTubeChannel (method constructor)
        //truyền 2 tham số và truyền 2 đối số cho constructor
        YouTubeChannel(string name, string owerName) { 
        //gán các giá trị ban đầu cho các attributes
            Name = name;
            OwnerName = owerName;
            SubscribersCount = 0;
            ContentQuality = 0;
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
        void CheckAnalytics() {
            if (ContentQuality < 5) {
                cout << Name << " has bad quality content." << endl;
            }
            else
                cout << Name << " has great content." << endl;
            
        }
};
//5. INHERITANCE
class CookingYoutubeChannel:public YouTubeChannel { //'inheritance' public from class 'YouTubeChannel'
    public:
        //passes 'name' & 'ownerName' to the base class constructor 'YouTubeChannel'.
        CookingYoutubeChannel(string name, string ownerName):YouTubeChannel(name, ownerName) {
        
        }
        void Practice() { //method bổ sung
            cout << OwnerName << " is practicing cooking, learning new recipes, experimenting with spices..." << endl;
            ContentQuality++;
        }
};
class SingersYoutubeChannel:public YouTubeChannel { //'inheritance' public from class 'YouTubeChannel'
    public:
        //passes 'name' & 'ownerName' to the base class constructor 'YouTubeChannel'.
        SingersYoutubeChannel(string name, string ownerName):YouTubeChannel(name, ownerName) {
        
        }
        void Practice() { //method bổ sung
            cout << OwnerName << " is taking singing classes, learning new songs, learning how to dance..." << endl;
            ContentQuality++;
        }

};

int main() {
    CookingYoutubeChannel cookingMyChannel1("Ngoc Kitchen", "Ngoc");
    SingersYoutubeChannel singersMyChannel1("Bao singers", "Bao");

    cookingMyChannel1.Practice();
    singersMyChannel1.Practice();
    singersMyChannel1.Practice();
    singersMyChannel1.Practice();
    singersMyChannel1.Practice();
    singersMyChannel1.Practice();
    singersMyChannel1.Practice();

    YouTubeChannel* yt1 = &cookingMyChannel1;
    YouTubeChannel* yt2 = &singersMyChannel1;

    yt1->CheckAnalytics();
    yt2->CheckAnalytics();

    system("pause > 0");
}

