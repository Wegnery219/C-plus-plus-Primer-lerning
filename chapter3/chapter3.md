# 第三章-字符串、向量和数组
### 一.命名空间的using声明
1. 头文件不应包含using声明
### 二.标准库类型string
1. 初始化的几种方式
```
string s2(s1);
string s2=s1;

string s3("value");
string s2="value";

string s4(10,'c');
string temp(10,'c');
string s8=temp;
```
2. 读写string</br>
```cin>>s1>>s2```是把第一个输入读到s1中，第二个读到s2中</br>
```getline(cin,line)```换行符也被读进来，存的时候不存换行符
- ```while(cin>>word)```和```while(getline(cin,word))```有区别，第一个是输入enter后才打印出来全部，然后直接结束，第二个是输入enter后打印出当前的，并且最后用ctrl+Z才能结束输入
3. empty和size操作</br>empty判断是否是空，size返回字符个数
- string.size()返回的类型不是int,也不是unsigned int 而是string::size_type类型，定义的时候可以定义成**auto，decltype(str.size())**类型，但是要注意避免和有符号数的使用，因为长度肯定是无符号的，如果和有符号数使用，会自动把有符号的转为无符号的，引起错误。
4. 字面值和string相加</br>
确保每个加法运算符的两侧至少有一个是string，字面值不能直接相加```string s6=s1+","+"world"```正确，因为```s6=(s1+",")+"world"```</br>
```string s6=","+"hello"+s1```不正确，因为```(","+"hello")```不合法
5. 处理string对象中的字符</br>
在cctype头文件中有函数，P82</br>
<font size=4>关于头文件</br></font>
**在C语言中，头文件的形式为name.h,C++继承了C语言的一些头文件，但是形式为cname，代表是从C语言继承过来的。举个例子：C语言：```#include<ctype.h>```而在C++中```#include<cctype>```使用C++语言尽量使用C++的形式**
6. for循环语句处理每个字符```for(auto c:str){c;}```，可以和cctype头文件中的函数结合起来循环处理每个字符串中的值，但这里的c只是相当于一个表面形式，只能用来判断，改变c并不会对原字符串造成任何影响。如果想要改变内容，则c需要定义成引用类型，示例如下：</br>
```
for(auto &c:str){c=toupper(c);}                     //str中的每个字符都被改成大写
//根据上面的描述，如果定义成如下形式，则不会有任何改动
for(auto c:str){c=toupper(c);}
```
7. 只处理一部分字符</br>
两种方式：1.下标 2. 迭代器（本节未介绍）</br>
索引：索引下标的类型应该为string::size_type,避免负值可用auto或decltype,使用索引之前，好的习惯是首先检查字符串是否为空。用下标也可以进行随机访问，总结使用索引容易出错的两点</br>
- 1. 下标越界，可通过将下标定义为string::size_type类型，并且检查是否小于str.size()来避免
  2. 字符串为空，使用下标之前最好检查一下

8. 课后习题
    ```
    const string s="Keep out!";
    for(auto &c:s){}        //c是引用常量，不能通过c修改s

### 三.标准库类型vector
1. vector是标准库容器(容纳着其他对象)，vector是一个类模板，定义初始化vector（用=叫拷贝初始化）
```
vector<T> v1;
vector<T> v2(v1);
vector<T> v2=v1;

vector<T> v3(n,val);
vector<T> v3(n);    //初始化成有n个元素的

vector<T> v4{a,b,c};
vector<T> v5={a,b,c};   //记住用花括号初始化
```
2. 向vector添加元素push_back,范围for循环尽量不要与vector的push_back使用，因为下界不确定
3. vector的操作和string差不多，empty返回是否为空，size返回类型为vector<T>::size_type,只有当元素的值可比较时，对应vector才可以比较
4. **vector不能通过下标形式来添加元素**</br>通过下标形式去访问一个不存在的元素将引发很多错误，不会被编译器发现，而是在运行时产生错误，尽量使用范围for语句确保下标合法
### 四.迭代器介绍
1. 有迭代器的类型同时拥有返回迭代器的成员（容器和string有迭代器类型，它们的成员函数begin(),end()返回类型是迭代器），这些类型都有begin,end成员
2. ```*iter```返回迭代器iter所指元素的引用,迭代器的递增++it,向前移动一个位置
[个人有个推断就是迭代器也不能用范围for语句]
3. 迭代器两种类型 1. iterator 2. const_iterator</br>begin和and返回的具体类型由对象是否是常量决定</br>
```auto it3=v.cbegin()```不论vector本身是否是常量，返回值都是const_iterator。只是读取并未改变的情况下，用cbegin和cend
4. (*it).mem和it->mem表达含义相同
5. **凡是使用了迭代器的循环体，都不要向迭代器所属的容器添加元素**
6. vector和string迭代器支持的运算P99，两个迭代器相减得到的是different_type类型，是个有符号类型
7. 练习3.24</br>
```
//在奇数情况下也可以输出，最后一个元素就是最后一个元素
//大概是因为h.end()是个空
for(auto it=h.begin();it<h.end();it=it+2){
		auto sum=*it+*(it+1);
		cout<<sum<<' ';
	}
//下面这种奇数会输出乱七八糟的东西，因为它还会继续往下加
for(auto it=h.begin();it！=h.end();it=it+2){
		auto sum=*it+*(it+1);
		cout<<sum<<' ';
```
### 五.数组
1. 数组的大小确定不变，同vector一样，不存在引用的数组，因为引用不是个对象
2. a[d],d必须是个常量表达式，字符数组初始化：注意空字符！！
3. 不允许拷贝和赋值 
```
int a={0,1,2};
int a2[]=a;   //错误
```
4. 复杂数组的说明
```
int *ptr[10];   //含有十个整形指针的数组
int &refs[10];  //错误
int (*Parray)[10]=&arr  //Parray指向含有十个整形元素的数组
int (&arr)[10]=arr      //arr引用一个含有十个整数的数组
```
3. 数组也可以使用范围for语句打印
4. 练习3.33，如果数组没初始化，没有被赋值的地方将出现不可预料的值，详见代码3.33.cpp
5. 用到数组名字的地方，编译器会自动转化为指针```string *p2=nums```等价于```string *p=&nums[0]```</br>
```auto ia2(ia)```实际ia2是个指针，但是用decltype可以返回数组类型，如```decltype(ia2) ia3```ia3是个含有十个整数的数组。
6. `int *p=arr;++p;`可以移动指针到下一个，尾元素的获得`int *e=&arr[10]`,也是指向一个并不存在的元素，另外一种方式`int *p=begin(a) int *e=end(a)`尾后指针不能执行解引用和递增操作
7. 指针运算`int *p=arr+3`编译器自动将arr转换成指向arr中首元素的指针，还可以解引用
8. 下标和指针
```
int *p=&ia[2];
int j=p[1];
int k=p[-2];  //这是与vector和string不同的点，支持负数
```
9. C风格字符串是指用一个个字符组成的数组，如char ca[]={'C','a'},需要注意的是需要显式包含空字符以结束，C的标准库函数string.h(在C++中化为cstring)即为处理C风格字符串的头文件，有strlen,strcmp,strcat,ctrcpy等函数，在此不做赘述，需要的时候回头查阅。
10. 将string转为C风格字符串：`const char *str=s.c_str();`</br>

### 六.多维数组
1. 严格来说是没有多维数组的，只是数组的元素也是数组。
2. 可以使用范围for循环来处理多维数组，只是除了最内层的循环外，其他所有循环的控制变量都应该是引用类型。
```
for(const auto &row:ia){
  for(const auto col:row){
    cout<<col;
  }
}
```
如果外层循环row不是引用类型，循环初始化的时候会将row中的元素转换成指针形式，这样无法进行内循环。
3. 指针和多维数组，下面这个循环同上面使用范围for循环的一样
```
for(auto p=ia;p!=ia+3;++p){
  for(auto q=*p;q!=*p+4;++q){
    cout<<*q;
  }
}
//下面使用数组的begin,end函数
for(auto p=begin(ia);p!=end(ia);++p){
  for(auto q=begin(*p);q!=end(*p);++q){
    cout<<*q;
  }
}
```
### 小结
本章介绍了string,vector的使用和含有的成员函数，接着介绍了迭代器，有些地方还是不好理解，要多加练习.C++也有内置数组，但是和vector相比，灵活性差一些，不能动态添加数据,注意区分数组中begin,end函数的使用和容器，string类型的begin,end成员函数，返回类型不同，前者返回指针，后者返回迭代器。多维数组是指元素是数组的数组，注意指针和多维数组的使用。

