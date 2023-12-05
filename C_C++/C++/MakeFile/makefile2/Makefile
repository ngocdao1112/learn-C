#phụ thuộc trực tiếp vào các file nguồn (main.cpp và message.cpp). nếu ko viết dependencies main.o message.o
output: main.o message.o # nếu main.o hoặc message.o có bất kỳ thay đổi nào, target output sẽ được cập nhật tự động
	g++ main.o message.o -o output

output2: 
	g++ main.cpp message.cpp -o output2222
# o: object, liên kết các file object 'main.o' và 'message.o')
bao1: 
	g++ Bao.cpp -o bao456

main.o: main.cpp
	g++ -c main.cpp
# c: complie 'main.cpp' to 'main.o'

message.o: message.cpp message.h
	g++ -c message.cpp

clean:
	del *.o output *.exe

# cấu trúc:
# target: dependencies
# 	action

# >>> change thành .o bởi vì sau khi run lần 1 nó tạo 2 file .o nhưng sau đó chúng ta change file 'message.cpp' thì run lần 2 nó chỉ tạo
# 1 file 'message.o', còn 'main.o' vẫn giữ nguyên vì chúng ta k change 'main.cpp', giúp ctrinh run nhanh hơn