+++
title = "C++ Template - Class Template"
date = 2022-03-28T16:19:00+08:00
lastmod = 2022-03-28T16:20:42+08:00
tags = ["cpp"]
categories = ["cpp"]
draft = false
toc = true
+++

## Class Templates {#class-templates}

**Class Templates** provide a way to generate generic class declarations.Templates provide _parameterized_ types--that is, they are capable of passing a type name as an argument to a recipe for building a class or a function.


### Define a Class Template {#define-a-class-template}

The keyword **template** informs the compiler that you\`re about to define a template. The part in angle brackets is analogous to an argument list to a function. You can think of the keyword **class** as serving as a type name for a variable that accept a type as value,and of **Type** is representing a name for this variable.

Using class here doesn\`t mean that type must be a class; it just means that Type serves as a generic type specifier for which a real type will be substituted when the template is used.

```c++
template <class Type>;// old
```

Newer c++ implementations allow you to use the less confusing keyword typename instead of class in this context;

```c++
template <typename Type>;//Newer c++ implementations
```

Newer c++ implementations allow you to use the less confusing keyword typename instead of class in this context;

You can use your choice of generic type name in the Type position; The name rules are the same as those for any other identifier. Popular choices include **T** and **Type** ;
Let\`s use the Stack class as a model to build a template.

```c++
typedef unsigned long Item;
class Stack{
private:
    enum {MAX = 10};
    Item items[MAX];
    int top;
public:
    Stack();
    bool isempty() const;
    bool isfull() const;
    bool push(const Item &item);
    bool pop(Item & item);
}
```

When a template is invoked, Type will be replaced with a specific type value,such as int or string. Within the template definition. You can use the generic type name to identify the type to be stored in the stack.

```c++
Item item[MAX]; // original way
Type item[MAX]; // template way
```

You can replace the class methods of the original class with template member functions. Each function heading will be prefaced with the same template announcemenmt;

```c++
templace <typename Type>
bool Stack<Type>::push(const Type & item){

}
```

if you define a method within the class declarations(an inline definition),you can omit the templace preface and the class qualifier.For some reason you should place all the templace in a header file and to include the header file in the file that will use the templaces;

```c++
// stackp.h -- a stack templace
#ifndef STACKTP_H_
#define STACKTP_H_

templace <class Type>
class Stack{
private:
    enum{MAX = 10};
    Type items[MAX];
    int top;
public:
    Stack();
    bool isempty();
    bool isfull();
    bool push(const Type & item);
    bool pop(Type & item);
};

template<typename Type>
Stack<Type>::Stack(){
    top = 0;
}

template<typename Type>
bool Stack<Type>::isempty(){
    return top == 0;
}
template<typename Type>
bool Stack<Type>::isfull(){
    return top == MAX;
}

template<typename Type>
bool Stack<Type>::push(const Type & item){
    if(top < MAX){
        items[top++] = item;
        return true;
    }else{
        return false;
    }
}
template<typename Type>
bool Stack<Type> :: pop(Type & item){
    if(top > 0){
        item = items[--top];
        return true;
    }else{
        return false
            }
}

#endif
```


### Using a Template Class {#using-a-template-class}

To declare an object of the template class type,replacing the generic type name with the particular type you want.For example,here\`s how you would create two stacks, one for stacking ints and one for stacking string objects;

```c++
Stack<int> kernels;
Stack<string> colonels;
```
