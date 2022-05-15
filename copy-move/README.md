# Copy Move Semantics

## Copy Semantics

The copy semantics is used when you want to duplicate a object, without affecting the original object. After copy operation, you would have two objects with identical content (by content we mean the meaning of data instead the memory value. For example, a copy of two string would give you two pointer pointing to identical string, instead of identical pointer address).

There are two ways to do copy: copy constructor and copy operator. Copy constructor is a special constructor that allows you to construct an identical object given an existing object, and a copy operator allows you to make an existing object identical to another object.

### Copy Constructor

```c++
class T {
  T(const T &src) { /* Write code to copy */ }
};
```

The copy constructor constructs an identical object given the other object. If there are non-trivial data fields in this class, initialize them in the initialization list, as they need to be constructed instead of be copied in most cases. The argument has type <code>const T&</code>, as in copy tasks, the original object would not be modified, and the object would not be passed in by reference (pass by reference requires copy, and we are implementing the copy).

```c++
Copyable a();
Copyable b(a); // This is copy constructor
Copyable c = b; // This is also copy constructor!
```

One thing to keep in mind is that copy constructor is used even if the notation is assignment.

### Copy Operator

```c++
class T {
  T& operator=(const T &src) {
    // Do the copy operation

    return *this; // Always do this at the end
  }
};
```

The copy operator works when the object is already constructed, and we only need to copy the value (in some cases heavy memory allocation is needed on construction, but not on assignment).

The signature shows copy operator method returns a reference of the same type. Always return a reference to itself, as the assignment operator is also an expression, and would be evaluated to the assignee.

## Move Semantics


