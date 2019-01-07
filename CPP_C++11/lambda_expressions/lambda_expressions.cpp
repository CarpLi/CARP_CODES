#include <string>
#include <iostream>
using namespace std;

// LAMBDA FUNCTION
/*
  ����ʽ��̷�񣺾͵���������Ŀ�꺯���������󣬲���Ҫ����дһ�������������ߺ�������
  ��ࣺ����Ҫ������дһ���������ߺ������󣬱����˴������ͺ͹��ܷ�ɢ���ÿ����߸��Ӽ��о������ֱߵ�����
  ����Ҫ��ʱ��͵ص�ʵ�ֹ��ܱհ���ʹ��������

  [...]   (...)   mutable(��ѡ)   throwSpec(��ѡ) ->  retType(��ѡ) {...}

  [...]   lambda������ ��lambda�ڷ����ⲿ�Ǿ�̬����
          ����std::cout�ľ�̬����ɱ�ʹ��
          ����ָ��һ��caputureȥ����һ���ⲿ�������ݣ���������һ������
  [=]     ��ζ���ⲿ��Χ�Դ�ֵ�ķ�ʽ����lambda
  [&]     ��ζ���ⲿ��Χ�Դ����õķ�ʽ����lambda
  [=,&y]  ��ζ��y�Դ����õķ�ʽ�������Դ����õķ�ʽ 
  
  mutable �Դ�ֵ�ķ�ʽ������󣬵���lambda����ĺ��������ڲ���ӵ�ж�ֵ��������дȨ��
  retType û��ָ�����ⷵ�����͵Ķ��壬�����ӷ���ֵ�����ƶ�
*/

/*
  lambda�����ں����ͱ���ʽ�ڲ�����ĺ���ʽ����
  lambda�ɱ�����inline����ʹ��
  ��Сlambda����û�в������򵥵���һЩ����
*/

namespace SIMPLE_LAMBDA
{
  auto I = [] {
      cout << "hello world!" << endl;
  };

  void TEST(){
    I();
  }
}

int main()
{
  SIMPLE_LAMBDA::TEST();
}