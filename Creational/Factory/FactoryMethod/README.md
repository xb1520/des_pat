# 工厂方法模式（Factory Method Pattern）

属于**创建型模式（Creational Patterns）**的一种

## 优点：

- 符合开放-封闭原则（扩展时只需要添加响应的产品和工厂的代码就行，不需要修改现有代码）
- 符合单一职责原则（每个工厂类和产品类的职责单一）

## 缺点：

- 增加了类的数量，增加了代码的复杂度
- 客户端代码变得复杂（客户端需要选择自己要使用的工厂），需要添加额外的逻辑。（或许可以在客户端实现个简单工厂？）
