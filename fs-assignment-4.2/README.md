Delimeter와 가변, 고정길이 버퍼를 통한 파일 읽기 쓰기 test 내용이다. \n
testpack.cpp 파일은 pack과 unpack을 통해 버퍼에 어떻게 가져오고 flush하는지를 확인한다. \n
test.cpp에서는 pack을 통해 버퍼에 가져온 데이터를 파일에 쓰고, 파일에서 버퍼로 읽어와서 버퍼에서
Student 객체로 unpack하는 동작을 확인할 수 있다.\n
\n
Student 데이터를 저장할 때에는 벡터를 사용하면 되지 않았다.
Student* stable[10]; 이런식으로 선언하고 수동으로 메모리를 할당하는 방식으로 진행했다.
stable = new Student(st);
