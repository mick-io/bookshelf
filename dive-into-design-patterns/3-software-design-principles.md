# Software Design Principles

## Features of Good Design

#### Code Reuse

Reusing code is one of the most common ways of reducing development cost.

While great in theory, making existing code work in a new context usually
takes extra effort. Tight coupling, dependencies on concrete classes, and
hardcoded operations all reduce flexibility of the code, making it harder to
reuse.

## Design Principles

### Encapsulate What Varies

Identify the aspects of your application that vary and separate them from what
stays the same.

#### Encapsulation on a method

Tax rates changes depending on region and laws. This code would have to be
updated often:

```python
class OrderCalculator:
    def get_order_total(self, order):
        total = 0
        for item in order.line_items:
            total += item.price * item.quantity

        country = order.country
        if country == "US":
            total += total * 0.07  # US sales tax
        elif country == "EU":
            total += total * 0.20  # European VAT

        return total
```

Extracting the tax calculation into a separate method:

```python
class OrderCalculator:

    def get_order_total(self, order):
        total = 0
        for item in order.line_items:
            total += item.price * item.quantity

        return total + (total * self._get_tax_rate(order.country))

    def _get_tax_rate(self, country):
        if country == "US":
            return 0.07  # US sales tax
        elif country == "EU":
            return 0.20  # European VAT
        else:
            return 0
```

The tax logic is now encapsulated in a separate method. This makes it easier
to change the tax calculation logic without affecting the rest of the code.

### Program to an Interface, not an Implementation

Program to an interface, not an implementation. Depend on abstracts, not on
concrete classes.

You can tell that the design is flexible enough if you can easily extend it
without breaking existing code.

Setup flexible collaboration between objects:

1. Determine what exactly one object needs from the other.
2. Describe these methods in a new interface or abstract class.
3. Make the class that is a dependency implement the interface.
4. Now make the second class dependent on the interface rather than the
   concrete class.

### Favor Composition Over Inheritance

Inheritances comes with caveats that can make your code inflexible:

- **A subclass can't reduce the interface of the superclass.** You have to
  implement all abstract method of the parent class, even if they're not used.

- **When overriding methods you need to make sure that the new behavior is**
  **compatible with the base.** It's important because objects of the subclass
  may be passed to any code that expect objects of the superclass and you don't
  want that code to break.

- **Inheritances breaks encapsulation of the superclass.** Because the internal
  details of the parent class become available to the subclass. There might be
  an opposite situation where a program makes a superclass aware of some of the
  details of the subclasses for the sake of making further extensions easier.

- **Subclasses are tightly coupled to superclasses.** Any changes in a
  superclass may break the functionality of subclasses.

- **Trying to reuse code thought inheritance can lead to creating parallel**
  **inheritance hierarchies.** Inheritance usually takes place in a single
  dimension. But whenever there are two or more dimensions, you have to create
  lots of class combinations, bloating the class hierarchy to a ridicules size.

There's an alternative to inheritance called _composition_. Inheritances
represents the "is a" relationship (a car is a transport), composition
represents the "has a" relationship (a car has an engine).

An added benefits is that you can replace a behavior at runtime as. For
instances, you cna replace an engine object linked to a car object just by
assigning a different engine object to the car.

## SOLID Principles

### Single Responsibility Principle

**A class should have just one reason to change.**

Try to make every class responsible for a single part of the functionality
provided by the software, and make that responsibility entirely encapsulated by
the class.

If a class does too many things, you have to change it every time one of these
things changes. While doing that, you're risking breaking other parts of the
class which you didn't even intend to change.

### Open-Closed Principle

**Classes should be open for extension but closed for modification.**

The main idea of this principle is to keep existing code from breaking when you
implement new features.

A class is _open_ when you can extend it, produce a subclass and add new
methods or fields, override base behavior, etc...

A class is _closed_ when it's 100% ready to be used. It's interface is clearly
defined and won't be changed in the future.

### Liskov Substitution Principle

**When extending a class, remember that you should be able to pass objects of**
**the subclass in place of objects of the parent class without breaking the**
**client code.**

Subclasses should remain compatible with the behavior of the superclass. When
overriding a method, extend the base behavior rather than replacing it with
something else entirely.

The substitution principle has a set of forma requirements for subclasses:

- **Parameter types in a method of a subclass should match of be more abstract**
  **than parameter types in the method of the superclass.**

- **The return type in a method of a subclass should match or be a subtype of**
  **the return type in the method of a superclass.** return type requirements
  are inverse to parameter type requirements.

- **A method in a subclass shouldn't throw types of exceptions which the base**
  **method isn't expected to throw.** In other words, types of exceptions
  should match or be subtype of the exceptions that the base method is already
  able to throw. `try-catch` blocks in client code target specific exception
  typesa that which the base method is likely to throw.

- **A subclass shouldn't strengthen preconditions.** For example, the base
  method has a parameter with type `int`. If a subclass overrides this method and
  requires that the value of an argument passed to the method should be positive,
  this strengths the pre-conditions.

- **A subclass shouldn't weaken post-conditions** If a method of the class is
  suppose to always close all opened database connections upon returning a
  value, creating a subclass and changing it so the connections remain open
  could pollute a system with ghost connection.

- **Invariants of a superclass must be preserved.** Invariants are conditions
  in which an object makes sense. For example, invariants of a cat are having
  four legs,a tail, ability to meow, etc...

-**A subclass shouldn't change values of private fields of the superclass.**
some languages allow access to private members of a class via reflection
mechanism. Other's, like Python don't have protection for private members at
all.

### Interface Segregation Principle

**Clients shouldn't be forced to depend on methods they do not use.**

Make your interfaces narrow enough that client classes don't have to implement
behavior they don't need.

### Dependency Inversion Principle

High-level classes shouldn't depend on low-level classes. Both should depend on
abstractions. Abstractions shouldn't depend on details. Details should depend on abstractions.

When designing software you can make a distinction between two levels of
classes:

- **Low-level classes** implement basic operations such as working with disk,
  transferring data over a network, connection to a database etc.
- **High-level classes** contain complex business logic that directs low-level
  classes to do something

The dependency inversion principle often goes along with the _open/closed_
_principle_. You can extend lower-level classes to use with different business
logic classes without breaking existing classes.
