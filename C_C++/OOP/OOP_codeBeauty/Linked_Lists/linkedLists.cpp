/*- không cần phải cấp phát một lượng bộ nhớ cố định từ trước như mảng
- Linked list thường được triển khai thông qua các lớp (classes) như Node và LinkedList. Mỗi 
 node trong danh sách liên kết chứa dữ liệu và một con trỏ đến node tiếp theo trong danh sách.
- ưu điểm: array có size cố định đồng thời không thể thêm/ xóa các ptu, linked lists có size động & có thể thêm/xóa các ptu
- nhược điểm: ko đc access to random elements in linked lists
- nhưng nếu muốn access các ptu thì cần biết ptu đầu tiên và sau đó dần theo pointer sẽ tìm đc
- linked lists cần nhiều bộ nhớ hơn array
    + vì memory cần lưu trữ 2 thứ giá trị đó là giá trị của ptu và pointer to pointer ptu tiếp theo

Thường dùng:
    - Khi kích thước của dãy số thay đổi thường xuyên.
    - Khi cần thêm/xóa phần tử ở giữa danh sách một cách hiệu quả.
    - Khi không biết trước kích thước tối đa của dãy số hoặc khi cần thêm phần tử mà không cần cấp phát một lượng bộ nhớ lớn từ trước.
*/
#include <iostream>
using namespace std;
class Node {
public: //tốn memory vì lưu trữ 2 giá trị trong cùng 1 ô nhớ
    int value;
    Node* Next;
};
//linked lists to function
void printList(Node*n) {
    while(n != NULL) {
        cout << n->value << endl;
        n = n->Next;
    }
}
int main() {
    Node* head = new Node();
    Node* second = new Node();
    Node* third = new Node();

    head -> value = 1;
    head -> Next = second;
    second -> value = 2;
    second -> Next = third;
    third -> value = 3;
    third -> Next = NULL;

    printList(head);
    
    return 0;
}