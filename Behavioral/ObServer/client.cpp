#include <iostream>
#include "ObServer.h"


int main() {
    TestEvent event;
    event.update("事件一");//更新事件，当前没有观察者，所以没有输出

    TestObServer ob1("观察者1");
    TestObServer ob2("观察者2");


    event.add_observer(&ob1);//增加一个观察者
    event.update("事件二");//所以 [观察者1]       观察到事件      [事件二]

    event.add_observer(&ob2);//又增加一个观察者
    event.update("事件三");//所以 观察者1和观察者2 都 观察到了 事件三


    event.remove_observer(&ob1);//删除了观察者1
    event.update("事件四");//所以只有 观察者2 观察到了 事件四
    return 0;
}
