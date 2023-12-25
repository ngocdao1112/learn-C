/*
1. Encapsulation - introduction:
    - Encap refers to building data with methods that can operate on that data within a class
    - Essentially, it is the idea of hiding data within a class, preventing anything outside that class from directly interacting with it
    - This does not mean that members of other classes cannot interact at all with the attributes of another object
    - Members of other classes can interact with the attributes of another object through its methods
    - Remember, methods are the functions defined within the class
    - Encapsulation - Methods:
        (1)Getting methods:
            + Retrieving information
        (2)Setting methods:
            + Changing information
    - (1)Getting methods:
        - Setting methods also allow the programmer to easily keep track of attributes that depend on one another
            + Method 1 -> Method 2
        - The setting method allows both attributes to be changed as they should, rather than requiring you to individually change them
        - You may also want some attributes to be "read only" from the outside
        - To do this, you would define a getter method BUT NOT A SETTER METHOD
        - The variable could only be referenced, not changed
    ===> It's generally best to not allow external classes to directly edit an object's attributes
    ===> This is very important when working on large and complex programs
    ===> Each piece should not have access to or rely on the inner workings of other sections of code
    ===> Information hiding, or keeping the data of one class hidden from external classes, helps you keep control of your program and prevent it from becoming too complicated
        - Encapsulation is a vital principle in OOP
        - Keep the programmer in control of access to data
        - Prevents the program from ending up in any strange or unwanted states
2. Abstraction - Introduction
    - Abstraction refers to only showing essential details and keeping everything else hidden
    - The classes you create should act like your car. Users of your classes should not worry about the inner details of those classes
    - Classes should not directly interact with other classes data
    - Modern programs are very complex to the point where multiple programmers tend to work on one program
    - In this case, it's best if the section that you work on is able to function without knowledge of the inner workings of your colleague's section
    - Abstraction - Interface & Implementation
        + The interface refers to the way sections of code can communicate with one another
        + This typically is done through methods that each class is able to access
        + The implementation of these methods, or how these methods are coded, should be hidden
        + If classes are entangled, then one change creates a ripple effect that causes many more changes
        + Creating an interface through which classes can interact ensures that each piece can be individually developed
        + Abstraction allows the program to be worked on incrementally and prevents it from becoming entangled and complex
        + Determine specific points of contact that can act as an interface between classes, and only worry about the implementation when coding it
3. Inheritance - Introduction
    - This segment we will be looking at the next of the four main principles of OOP programming: Inheritance
    - Inheritance is the principle that allows classes to derive from other classes
*/