#include <iostream>
using namespace std;

/* 
    - PC sẽ lấy 1 vùng nhớ trên RAM để save các giá trị biến
    - Để check xem tên vùng nhớ mà nó chiếm trên RAM dùng từ khóa '&'
    - Pointer trong C++ là 1 biến đặt biệt. Nó chứa địa chỉ của 1 ô nhớ trên PC
    a. khai báo: data_type *<tên_biến>;
    b. cấp phát: <tên_biến> = new data_type; //phải cùng data type với khai báo
    c. hủy bộ nhớ: delete <tên_biến>;
    - Con trỏ void: void để trỏ tới nhiều data type, nhưng khi can thiệp đến các value cần phải ép kiểu dữ liệu về kiểu dữ liệu nó trỏ tới
    - Con trỏ null: khi chúng ta khai báo mà chưa cáp phát bộ nhớ thì sẽ gặp lỗi này
        + Đối với vs studio thì ctrinh sẽ ko chạy
*/
int main() {
    //1. 
    int nhietDo = 78;
    //xem dia chi o nho tren RAM
    cout << "dia chi o nho cua bien nhietDo la: " << &nhietDo << endl;

    //khai bao con tro
    int *a; //*a trỏ tới đâu chưa biết
    a = new int; // new tạo 1 vùng nhớ kiểu int có 4 byte với địa chỉ là ... gán cho a
    //Xuat truc tiep gia tri con tro a. Tra ve dia chi o nho ma a chiem
    cout << "dia chi a tro toi: " << a << endl;
    //gan gia tri cho bien con tro
    *a = 25; //*a chứa giá trị là 25
    cout << "gia tri nam tren o nho cua con tro a la: " << *a << endl;

    //2.
    //khai bao conTroT
    int *conTroT;
    //tro bien conTroT vao o nho cua bien nhietDo
    conTroT = &nhietDo;
    cout << "dia chi ma conTroT tro toi: " << conTroT << endl;
    cout << "gia tri nam tren o nho cua conTroT la: " << *conTroT << endl;
    //change value of conTroT
    *conTroT = 99; // nếu change *conTroT = 99 thì nhietDo = 99 luôn
    cout << "value sau khi change conTroT: " << endl;
    cout << "value conTroT sau doi la: " << *conTroT << endl;
    cout << "value of bien nhietDo: " << nhietDo << endl;

    //khai bao bien thong thuong
    int nguyenA;
    float thucB;
    //khai bao bien con tro
    int *conTroNguyen;
    float *conTroThuc;
    //gan con tro hop le;
    conTroNguyen = &nguyenA; // conTroNguyen = nguyenA; -> false
                            // gán địa chỉ của biến nguyenA cho con trỏ conTroNguyen
                            //conTroNguyen sẽ trỏ đến vùng nhớ của biến nguyenA, cho phép bạn thao tác trực tiếp với giá trị của nguyenA thông qua con trỏ.
    conTroThuc = &thucB;

    *conTroNguyen = 45;
    //khai bao invalid
    // conTroNguyen = &thucB;
    //  conTroThuc = &nguyenA;

    //3. con tro void: nếu muốn con trỏ có thể trỏ đến bất kỳ data type nào khác thì dùng 'void' thay cho data type lúc khai báo con trỏ
    //khai bao con tro void
    void *giCungDuoc;
    //gan voi cac kieu du lieu khac nhau
    giCungDuoc = &nguyenA;
    // giCungDuoc = &thucB;

    //Void hởi dở là nó dùng để trỏ tới nhiều kiểu dữ liệu, nhưng khi can thiệp đến các gtri lại phải cần ép data type về kiểu dữ liệu nó trỏ tới
    //gan value cho bien con tro kieu void
    *(int*)giCungDuoc = 65; //*giCungDuoc = 65; -> false
    //xuất địa chỉ ô nhớ
    cout << "địa chỉ nguyenA: " << &nguyenA << endl;
    cout << "địa chỉ giCungDuoc: " << giCungDuoc << endl;
    //xuat value cua NguyenA, va value nam tren o nho con tro giCungDuoc tro toi
    // biến con trỏ là trỏ tới địa chỉ ô nhớ 
    cout << "giá trị nguyenA: " << nguyenA << endl;
    cout << "giá trị giCungDuoc: " << *(int*)giCungDuoc << endl;
    //4. con trỏ null: khai báo mà chưa cấp phát bộ nhớ thì sẽ gặp lỗi
    int *conTroxyz;
    cout << "ô nhớ conTroxyz trỏ đến: " << conTroxyz << endl;
    delete conTroxyz; // Nhớ giải phóng bộ nhớ sau khi sử dụng xong
}