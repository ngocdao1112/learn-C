#include <iostream>
#include <string>

struct YouTubeChannel {
    std::string Name;
    int SubscribersCount;

    YouTubeChannel(std::string name, int subscribersCount) {
        Name = name;
        SubscribersCount = subscribersCount;
    }

    bool operator == (const YouTubeChannel& channel) {
        return this->Name == channel.Name;
    }

    void operator << (std::ostream& COUT) {
        COUT << "Name: " << this->Name << std::endl;
        COUT << "Subscribers: " << this->SubscribersCount << std::endl;
    }
};

int main() {
    YouTubeChannel ytChannel("ExampleChannel", 1000);

    // Sử dụng hàm thành viên operator<<
    ytChannel.operator<<(std::cout);

    return 0;
}
