#include <string>

class MyString {
public:
  static size_t DCtor;
  static size_t Ctor;
  static size_t CCtor;
  static size_t CAsign;
  static size_t MCtor;
  static size_t MAsign;
  static size_t Dtor;

public:

  // Ĭ�Ϲ��캯��
  MyString() :_data(nullptr), _len(0) {
    ++DCtor;
  }

  // ���캯��
  MyString(char* p):_len(strlen(p)){
    ++Ctor;
    init_data(p);
  }

  // �������캯�� 
  MyString(const MyString& str) :_len(str._len) {
    ++CCtor;
    init_data(str._data);
  }

  // �ƶ����캯��
  MyString(MyString&& str) : _data(str._data), _len(str._len){
    //_data = str._data;
    //_len = str._len;
    str._data = nullptr;
    str._len = 0;
  }

  // ��ֵ������
  MyString& operator=(const MyString& str) {
    ++CAsign;
    if (this != &str) {
      _len = str._len;
      _data = new char[str._len + 1];
      memcpy(_data, str._data, str._len);
      _data[_len] = '\0';
    }
    else {
    }
    return *this;
  }

  // �ƶ���ֵ������
  MyString& operator=(MyString&& str) {
  }

private:
  void init_data(const char* s) {
    _data = new char[strlen(s) + 1];
    memcpy_s(_data, _len, s, _len);
    _data[_len] = '\0';
  }

  char* _data;
  size_t _len;
};

int main()
{

}