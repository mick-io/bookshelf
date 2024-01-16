# Intro to Object Oriented Programming

## Pillars of OOP

### Abstraction

Abstraction is a model of real-world objects or phenomenon, limited to a
specific context, which represents all details relevant to this context with
high accuracy and omits all the rest.

### Encapsulation

Encapsulation is the ability of an object to hide parts of its state and
behavior from other objects, exposing only a limited interface to the rest of
the program.

### Inheritance

Inheritance is the ability to build a new class on top of an existing one.

The consequence of using inheritance is that subclasses have the same interface
as their parent class. You can't hide a method in a subclass if it was declared
in the superclass.

### Polymorphism

Polymorphism is the ability of a program to detect the real class of an object
and call it's implementation even when its real type is unknown in the current
context.

You can also think of polymorphism as the ability of an object to pretend to be
something else, usually a class it extends of an interface it implements.

## Relations Between Object

### Dependency

**Class A can be affected by changes in class B.**

Dependency is the most basic type of relations between classes. There is a
dependency between two classes if some changes to the definition of one class
might results in modifications to another class.

Dependency is made weaker if you make your code dependent on interfaces or
abstract classes instead of concrete classes.

### Association

**Object A knowns about object B. Class A depends on B.**

Association is a relationship in which one object uses or interacts with
another.

Association can seen as a specialized kind of dependency, where an object
always has access to the objects with which it interacts.

```java
/**
 * If some­one changes the sig­na­ture of the getKnowledge method our code will
 * break. That’s why we can say that the Professor class depends on the Course
 * class.
 *
 * if the sig­na­ture of the method remember changes, the Professor’s code will
 * break. How­ev­er, since the student field is always acces­si­ble to any method
 * of the Professor, the Student class is not mere­ly a depen­den­cy, but also an
 * association.
 * */
class Professor {
    public final Student student;

    public void teach(Course c) {
        this.student.remember(c.getKnowledge());
    }
}
```

### Aggregation

**Object A knowns about object B, and consists of B. Class A depends on B**

Aggregation is a specialized type of association that represents _one-to-many_,
_many-to-many_, or _whole_part_ relations between multiple objects.

Under aggregation, an object has a set of other objects and serves as a
container or collection.

### Composition

**Object A knows about object B, consists of B, and manages B's life cycle.**
**Class A depends on B.**

Composition is a specific kind of aggregation where one object is composed of
one or more instances of the other. The distinction between this relation and
others is that that the component can only exist as a part of the container.
