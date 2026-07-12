Student Management System (C++)
A comprehensive, console-based Student Management System built in C++ using core Object-Oriented Programming (OOP) principles. This application streamlines administrative tasks by enabling efficient tracking, modifying, and handling of student profiles, academic courses, and grading records.

🚀 Key Features
Student Enrollment: Register new students with unique IDs and foundational information.Record Management: Search, view, update, or remove student profiles effortlessly
Academic Tracking: Monitor enrolled courses, credit allocations, and grade points.
Data Persistence: Store and retrieve student records reliably via native C++ file handling (fstream).
Input Validation: Prevent system crashes using type checking and robust error-handling safeguards

🛠️ OOP Concepts Implemented

The application architecture demonstrates production-grade Object-Oriented design patterns:
Encapsulation: Class attributes (e.g., studentID, grades) are hidden from direct outside access using private data modifiers, exposed safely through public getters and setters.
Inheritance: Derived specialized classes (such as Undergraduate or Postgraduate) inherit common functional structures from a primary abstract User or Person base class.
Polymorphism: Implemented dynamic dispatch via virtual functions to execute specialized runtime logic for disparate user roles.
Abstraction: Hidden complex file indexing systems behind simplified, clean interfaces like displayMenu().
