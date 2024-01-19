# Factory Method

**Factory Method** is a creation design pattern that provides an interface for
creating objects in a superclass, but allows subclasses to alter the types
objects that will be created

The Factory Method pattern suggest that you replace direct object construction
calls (using the `new` operator) with calls to a special factory method. Objects
returned bt a factory are often referred to as _products_.

## Structure

1. The **Product** declares the interface, which is common to all objects that
   can be produced by the creator and its subclasses.

2. **Concrete Products** are different implementations of the product interface.

3. The **Creator** class declare the factory method that returns new product
   objects. It's important that the return type of this method matches the
   product interface.

4. **Concrete Creators** override the base factory method so it returns a
   different type of product.

## Pseudocode

```Java
// The creator class declares the factory method that must
// return an object of a product class. The creator's subclasses
// usually provide the implementation of this method.
class Dialog is
  // The creator may also provide some default implementation
  // of the factory method.
  abstract method createButton():Button

  // Note that, despite its name, the creator's primary
  // responsibility isn't creating products. It usually
  // contains some core business logic that relies on product
  // objects returned by the factory method. Subclasses can
  // indirectly change that business logic by overriding the
  // factory method and returning a different type of product
  // from it.
  method render() is
    // Call the factory method to create a product object.
    Button okButton = createButton()
    // Now use the product.
    okButton.onClick(closeDialog)
    okButton.render()


// Concrete creators override the factory method to change the
// resulting product's type.
class WindowsDialog extends Dialog is
  method createButton():Button is
    return new WindowsButton()

class WebDialog extends Dialog is
  method createButton():Button is
    return new HTMLButton()


// The product interface declares the operations that all
// concrete products must implement.
interface Button is
  method render()
  method onClick(f)

// Concrete products provide various implementations of the
// product interface.
class WindowsButton implements Button is
  method render(a, b) is
    // Render a button in Windows style.
  method onClick(f) is
    // Bind a native OS click event.

class HTMLButton implements Button is
  method render(a, b) is
    // Return an HTML representation of a button.
  method onClick(f) is
    // Bind a web browser click event.


class Application is
  field dialog: Dialog

  // The application picks a creator's type depending on the
  // current configuration or environment settings.
  method initialize() is
    config = readApplicationConfigFile()

    if (config.OS == "Windows") then
      dialog = new WindowsDialog()
    else if (config.OS == "Web") then
      dialog = new WebDialog()
    else
      throw new Exception("Error! Unknown operating system.")

  // The client code works with an instance of a concrete
  // creator, albeit through its base interface. As long as
  // the client keeps working with the creator via the base
  // interface, you can pass it any creator's subclass.
  method main() is
    this.initialize()
    dialog.render()
```

## Applicability

- Use the Factory Method when you don't know beforehand the exact types and
  dependencies of the objects your code should work with.

- Use the Factory Method when you want to provide users of your library or
  framework with a way to extend its internal components.

- Use the Factory Method when you want to save system resources by reusing
  existing objects instead of rebuilding them each time.

## How to Implement

1. Make all products follow the same interface. This interface should declare
   methods that make sense in every product.

2. Add an empty factory method inside the creator class. The return type of the
   method should match the common product interface.

3. In the creator's code find all references to product constructors. One by
   one, replace them with calls to the factory method, while extracting the
   product creation code into the factory method. You might need to add a
   temporary parameter to the factory method to control the type of returned
   product.

4. Now, create a set of creator subclasses for each product type listed in the
   factory method. Override the factory method in the subclasses and extract the
   appropriate bits of construction code from the base method.

5. If there are too many product types and it doesn't make sense to create
   subclasses for all of them, you can reuse the control parameter from the
   base class in subclasses.

6. If, after all of the extractions, the base factory method has become empty,
   you can make it abstract. If there's something left, you can make it a
   default behavior of the method.

## Pros and Cons

### Pros

- You avoid tight coupling between the creator and the concrete products.
- Single Responsibility Principle. You can move the product creation code into
  one place in the program, making the code easier to support.
- Open/Closed Principle. You can introduce new types of products into the
  program without breaking existing client code.

### Cons

- The code may become more complicated since you need to introduce a lot of new
  subclasses to implement the pattern. The best case scenario is when you're
  introducing the pattern into an existing hierarchy of creator classes.
