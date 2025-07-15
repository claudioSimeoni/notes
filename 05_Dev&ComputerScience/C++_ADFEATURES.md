
```c++
template<class type>
type max(type x, type y){ 
    return (x > y) ?  x : y;
}

// i can call the function both by making explicit the type with <>
// and without doing so or you can just mix both ways 

// the compiler builds the needed functions at compile time 
// so you should have both input parameters types equal 
```

```c++
template<class typel, class type2, class type3>
typel max(type2 x, type3 y){
    return (x>y)? x : y;
}
// here x, y should have the same type otherwise you 
// wouldn't know at compile time type1
```

---

You can also have non-type parameters, so you build a function that changes by changing the parameter, eg `template<int n, class type1>`

---

If you have static variables with the template the compiler will set a separate variable for each instance of that function 

--- 

When dealing with model classes (using template): 
1. When declaring an instance you must also make explicit the type. 
2. No more file .cpp, the header must contain both definitions and declarations 

---

```c++
Inheritance: 

class student : public/private/protected person{

}; 

// student inherits all the members specified from person, everything
// works as it should, firstly you can overload person's attribute
// but then you will need :: to access the original one. You can 
// also assign student's instances to person one but not vice versa.  

// protected is just for inheritance, outside the class is like private
```

Another interesting fact is that when you create an instance x of c3 where c3->c2->c1 the c3 will have all its personal instances of c2 and c1. 

---

The constructors are polleridge: the calls are made in this order, o1, o2, o3, ... If an ancestor class has more than one constructor you should call a specific one in the son's constructor initialization list eg `o4() : o3(x)`. 

The destruction of an object o2 destroys firstly the on attributes then the on-1 ones and so on. 

The constructors are called in the following order: o1-attributes, o1, o2-attributes, o2... 

You can have an o1 attribute into a lower level class. 

---

If you are using a pointer that points o3 and you call o3->dio where dio is an overridden function than it will call by default o1->dio because o1 is find before in memory, if you want it to call the right function every time you must mark the first class's function as virtual.

An o3 object has o1, o2, o3 inside. To a pointer o3 you can only assign a lower level class like o5 and the first area in memory when dereferencing that pointer will be an o3 object, so you can also set virtual from a lower level like 3 and from down there it will call the right functions while if you have a o1 pointer it will always use o1 function even though the pointer points to a lower level class. 

```c++
class studente {
public:
    void virtual chisei() { cout << "sono uno studente";}
};
class borsista : public studente{
public:
    void virtual chisei() { cout << "sono un borsista";}
}; // virtual puo’ mancare

```

--- 

Abstract class is a class that cannot be instanced, it is a base for other classes that must implement her original functions marked by `function() = 0`, otherwise they become abstract themselves. 

--- 

try catch e throw 

