# 第五章-语句
### 一.简单语句
1. 空语句，`while(cin>>s) ;`有意空语句
2. 不要多加分号，多余的空语句并非总是无害的
### 二.语句作用域
1. if,switch,while,for控制结构内定义的变量，只有在内部可见，跳出语句块不可见
### 三.条件语句
1. 就近匹配消除二义性
2. switch语句中，case必须是整形**常量**表达式
3. 漏写break容易引发缺陷
4. default如果什么也不做的话，最好加一个空语句
3. switch内部如果需要定义并且初始化，写在语句块{}内，否则不合法。并且其他case不可以访问该语句块内定义并初始化的变量。
### 四.迭代语句
1. 不确定迭代多少次，用while循环，如输入`while(cin>>i)`
2. do while语句先执行语句块，后判断条件
3. break语句负责中止离它最近的break,while,do while,for,switch
### 五.跳转语句
1. 四类，break,continue,goto,return
1. continue语句中止最近的循环中当前迭代并开始下一次迭代
2. goto语句
```
goto end;
end:
...
//注意end中不要包含goto与end之间声明的变量
```
### 六.try语句块和异常处理
1. throw表达式，try语句块
2. `throw 标准库异常类型("Data must refer to same ISBN");`
3. runtime_error定义在stdexcept中，提供一个string 或C风格字符串，输出辅助信息
4. try语句块内声明在catch内也无法访问
5. catch语句块
```
try{
    //正常语句
    }catch(runtimr_error err){
        cout<<err.what();
    }
    //err.what返回初始化error时对象的副本
```
6. 异常头文件：
- `exception`头文件，只报告异常发生，不提供额外信息，只能默认初始化
- `stdexcept`几种通用异常类，P176，其他异常类不能默认初始化，给提供string类型或C风格字符串类型
- new,type_info头文件放在后面介绍
### 小结
本章介绍了我写C++只会用的几类语句T T,goto语句要有label，异常处理的几个头文件，在以后写大型项目时要注意。
