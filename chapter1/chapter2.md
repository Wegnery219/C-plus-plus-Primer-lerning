# 第二章-变量和基本内置类型
### 一. 基本内置类型
1. char在不同的机器上可能不同，有的是unsigned char，有的是signed char
2. 浮点数尽量选用double运算
3. 非布尔转换成布尔，0是false其他是true
4. 浮点->整数，只保留小数之前
5. int,short,long long..都是带符号的。一个算术表达式既有unsigned又有int，则会自动把有符号的int转为无符号的，从而引起结果错误。
```
unsigned u=10;
int i=-42;
std::cout<<i+i<<std::endl;//输出-84
std::cout<<i+u<<std::endl;//int占32位，输出4294967264
```
无符号整数相减也不能是负数
```
//错误,无符号整数永远不会小于0
for(unsigned i=10;i>=0;--i){
    std::cout<<i;
}
//改正,打印出来从10到0
unsigned u=11;
while(u>0){
    --u;
    std::cout<<u;
}
```
6. 八位转义\1233，只用前三个数字，十六位全用
### 二.变量
1. 列表初始化，拒绝可能丢失信息的初始化，如float->int
```
int units_sold={0};
int units_sold{0};
```
2. 尽量初始化变量，避免不必要的错误
3. extern关键字，声明而非定义变量，而且不需要显式初始化
4. ```::i```访问全局变量i
### 三.复合类型
1. 引用必须被初始化，是为一个已经存在的对象所起的另外一个名字
2. 对引用操作就是对对象本身操作，引用是多少，对象就是多少
3. ```double *pd=&dval```正确
   ```double *pd2=pd```正确
   指针的赋值后面要么是地址要么是指针，且类型一定要匹配。
4. #include cstdlib 使指针初始化为NULL，
5. <font color="pink">使用未经初始化的指针是引发错误的一大原因</font>
6. pi=&val 改变的是指针的引用对象
   *pi 改变的是指针指向的对象
7. 不能直接操作void*所指向的对象
8. **指向指针的指针
```
int ival=1024;
int *pi=&ival;
int **pi=&pi;
```
9. ```int *&r=p;``` &r意思是r是个引用，前面加个*意思是int *，这个引用是个指针类型的。
10. ```int *ip=0;```意思是空指针
### 四.const限定符
1. const 对象必须初始化
2. ```const int &r=i;```i允许是非常量，即普通对象。表达式的意思是不允许通过r来改变i，但是如果i不是常量的话，可以通过其他方式来改变i

<font color="red">允许把非常量的变量加一个常量引用，但是不允许给常量加一个非常量的引用</font>

3. 指针与常量的两种类型
- 指向常量的指针```const double *cptr=&pi```
同引用一样，允许指向非常量，但是不允许通过这个指针改变pi
- 常量指针```int* const  err```err 是个常量，类型是指针，意思是指针指向的地址不能变。
4. constexpr 常量表达式是指值不会改变而且在编译过程中就能确定计算结果的
### 五.处理类型
1. 类型别名的两种方式
- 使用typedef,尽量避免复合类型，恢复的时候不能简单把typedef的代入表达式，尤其是当涉及指针的时候，所以尽量避免。
     ```
    typedef double wages;//wages是double 的别名
    typedef wages base,*p;//base 是double的同义词，p是double*的同义词
    ```
- 使用别名声明
```using SI=Sales_item;```
2. auto让编译器去替我们分析表达式所属于的类型，auto i=0,*p=&i;但是写在一个句子里的必须是同一个类型的。
3. decltype(ci) x; ci是什么类型，x就是什么类型。注意如果是引用的话必须初始化。
### 六.自定义数据结构
1. 类的定义后记得加分号
```
struct Sales_data{
    std::string bookNo;
    unsigned units_sold=0;
    double revenue=0.0;
};
Sales_data accum,trans,*salesptr;
```
<font color="red">不加分号的报错信息</font>
```
[Error] multiple types in one declaration
```
2. 只能被定义一次的实体，类，const,constexpr
3. <font color="yellow">头文件保护符</font>
```
#ifndef A_H     //#ifndef表示如果A.H没定义才往下执行
                //#ifdef相反
#define A_H     //把A_H设定为预处理变量
#include<string>
struct Sales_data{
    ...
};
#endif
```
## **小结**
本章先介绍了基本内置类型，相互转换，有符号和无符号相加减可能出现的问题，再介绍了变量的初始化，声明（extern），作用域的问题,接着介绍了两种复合类型：引用和指针，引用必须定义的时候初始化，指针可以不用 ，但是不初始化的指针容易引起问题。第四小节介绍了const，在const的引用和const的指针（两种类型）中需要注意的问题，介绍了常量表达式constexpr，第五小节讲了typedef给类型起别名，在给指针起别名的时候容易出错，并不是简单的代入求解关系，auto可以让编译器去分析表达式的类型，decltype()选择并返回操作数的数据类型。struct可以自定义数据结构，要加分号，以及之前在编写符号表中犯过的错误，头文件保护符，避免重复include头文件。


