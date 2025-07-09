# 🛒 Shopping Cart System in C++

## Overview

This project is a simple, console-based shopping system implemented in **C++** using core **Object-Oriented Programming (OOP)** concepts. It allows multiple customers to browse available products, add items to their cart, and generate a detailed bill that includes discounts and loyalty points.

---

## ✨ Features

- View a list of available products with names and prices  
- Add multiple products in custom quantities to the shopping cart  
- Generate a detailed printed bill per customer  
- Apply dynamic discount rules based on total amount  
- Award royalty points based on the final billed amount

---

## 🧠 OOP Concepts Demonstrated

- **Abstraction**  
  Defined an abstract `Item` class with pure virtual functions to enforce a common interface.

- **Encapsulation**  
  Sensitive data like product name and price are kept private and accessed via methods.

- **Inheritance**  
  `Product` class inherits from the abstract base class `Item`.

- **Polymorphism**  
  Virtual functions are overridden in the `Product` class to display and retrieve product data.

- **Modularity**  
  Business logic is clearly separated using classes like `Product`, `Item`, and `ShoppingCart`.

---

## 🧾 Billing Logic

- **Discounts:**
  - 10% discount if total > ₹5000
  - 15% discount if total > ₹10000

- **Loyalty Points:**
  - Earn 1 point per ₹100 of final billed amount

---

## 🧪 Sample Functional Flow

1. Customer enters their ID.
2. Product catalog is displayed.
3. Customer adds desired items and quantities to the cart.
4. Final bill is generated with discounts and loyalty points.
5. Repeat for up to 10 customers.

---

## 🔧 Technologies Used

- **Language:** C++  
- **Compiler:** Any standard C++11 or later  
- **Platform:** CodeBlocks

---


![image](https://github.com/user-attachments/assets/087589fc-1ac9-4be3-a073-87c0cf723024)


