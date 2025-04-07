
# 🛍️ Mall Customer Billing System (C Language)

This project is a simple console-based **Mall Customer Billing System**, written in C. It allows you to:

- Register customer details (name, age, contact, address)
- Calculate the total bill based on selected items
- Display current and total expenditure
- View stored customer data

---

## 📌 Features

- Struct-based customer information management
- Multiple item-based billing system
- Date integration using system time
- Handles optional inputs (like middle name)
- Prevents invalid data (e.g. age range, max customer size)
- Supports multiple customers (up to 100)

---

## 🧾 Functions Overview

### `user_register()`
Takes user inputs like name, contact number, age, and address. Stores them in a struct.

### `generate_bill()`
Lets the user choose items and calculates the total bill.

### `get_date(char *store_date)`
Fetches and stores the current system date in the format `dd Month yyyy`.

### `show_current_previous_bill()`
Displays the current and total budget of a customer using their stored data.

### `show_customer_details()`
Prints all customer records stored in the system.

---


