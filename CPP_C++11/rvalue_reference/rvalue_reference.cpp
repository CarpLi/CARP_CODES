
#include <type_traits>
#include <iostream>
#include <string>
using namespace std;

/*
move����  
  ͨ��move����������ֵת��Ϊ��ֵ
  move�ǽ������״̬��������Ȩ��һ������ת�Ƶ���һ������ֻ��ת�ƣ�û���ڴ濽��
  ����ֵ��Ϊһ����ֵ���ã�Ȼ��Ӧ��move������ù��캯���������˿���������˳�������
  c++������������ʵ����move����

perfect forwarding
  ������Ҫһ�ַ����ܰ��ղ���ԭ��������ת������һ������������ת����������ת��
  �ں���ģ���У���ȫ����ģ��Ĳ��������ͣ������ֲ�������ֵ����ֵ�����������������ݸ�����ģ���е��õ�����һ��������

forward
  Ϊת�������ģ����ܲ�����T&&����δ�������û�����ȷ����ֵ���û�����ֵ���ã����ᰴ�ղ�������������ת����
*/

namespace UNPERFECT_FORWARDING {

  void process(int& i) {
    cout << "process(int& i) " << i << endl;
  }

  void process(int&& i) {
    cout << "process(int&& i) " << i << endl;
  }

  void forward(int&& i) {
    cout << "forward(int&& i) " << i << endl;
    process(i);
  }

  void Test() {
    int a = 0;

    cout << "TEST PROCEESS ..." << endl;
    process(a);
    process(1);
    process(move(a));

    cout << "TEST FORWARD..." << endl;
    forward(2);
    forward(move(a));
  }
}

namespace PERFECT_FORWARDING {
  template<typename T>
  void print(T& t) {
    cout << "print lvaue: " << t << endl;
  }

  template<typename T>
  void print(T&& t) {
    cout << "print rvaue: " << t << endl;
  }

  template<typename T>
  void  TEST_FORWARD(T&& v) {
    print(v);     // v�ֱ����һ����ֵ����Ϊ�������Ѿ������һ�������ı���
    print(forward<T>(v));
    print(move(v));
  }

  /*
    TEST PROCEESS ...
    process(int& i) 0
    process(int&& i) 1
    process(int&& i) 0
    TEST FORWARD...
    forward(int&& i) 2
    process(int& i) 2
    forward(int&& i) 0
    process(int& i) 0
    print lvaue: 1
    print rvaue: 1
    print rvaue: 1
    print lvaue: 1
    print lvaue: 1
    print rvaue: 1
    print lvaue: 1
    print rvaue: 1
    print rvaue: 1
    print lvaue: 1
    print rvaue: 1
    print rvaue: 1
  */

  void TEST() {

    TEST_FORWARD(1);

    int x = 1;
    TEST_FORWARD(x);
    TEST_FORWARD(forward<decltype(x)>(x));
    TEST_FORWARD(move(x));
  }
}
namespace FUNCTION_WRAPPER
{

  template <class Function, class... Args>
  inline auto FunctionWrapper(Function&& f, Args&&... args)->decltype(f(forward<Args>(args)...)) {
    return f((forward<Args>(args))...);
  }

  void test0() {
    cout << "test0(): void" << endl;
  }

  int test1() {
    return 1;
  }

  int test2(int x) {
    return x;
  }

  string test3(string s1, string s2) {
    return s1 + s2;
  }

  void TEST() {
    FunctionWrapper(test0);

  }
}

int main()
{
  UNPERFECT_FORWARDING::Test();

  PERFECT_FORWARDING::TEST();

  FUNCTION_WRAPPER::TEST();
}