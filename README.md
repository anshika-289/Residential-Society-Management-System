# 🏢 Residential Society Management System

This project is a **C++ application** designed to manage and maintain records for a residential society. It uses **MySQL C API** for database connectivity and operations, making it a powerful tool for handling residential data such as owners, tenants, apartments, complaints, staff, and visitors.

## 💡 Features

- 📋 Create and populate multiple MySQL tables:
  - `Society`, `Owner`, `Apartment`, `Tenant`, `Complaint`
  - `Electrical`, `Carpentry`, `Plumbing`, `Visitor`, `Visits`
- 🔐 Enforces data integrity using:
  - Primary and foreign key constraints
  - Validation through `CHECK`, `UNIQUE`, and `REGEXP`
- 💾 Inserts sample data into each table for testing and demonstration
- 🖥️ Built using **Code::Blocks** with GCC compiler and MySQL development libraries

## 🛠️ Technologies Used

- **Language**: C++
- **Database**: MySQL (via `mysql.h`)
- **IDE**: Code::Blocks
- **Compiler**: GCC (Debug & Release modes)

## 🚀 Setup Instructions

### ✅ Prerequisites
- Code::Blocks IDE with GCC Compiler
- MySQL Server (Running on port `3307`)
- MySQL development libraries (`mysql.h`)

### 📦 Installation
1. Clone this repository or download the ZIP.
2. Open `Residential Society.cbp` in Code::Blocks.
3. Ensure MySQL is running and the database `Residential Society Management System` exists (or adjust the code).
4. Build and run the project.

## 📁 Project Structure

| File                         | Description                               |
|------------------------------|-------------------------------------------|
| `main.cpp`                  | Main source code, handles DB connection   |
| `Residential Society.cbp`   | Code::Blocks project file                 |
| `Residential Society.layout`| IDE layout configuration                  |
| `Residential Society.depend`| Auto-generated dependency file            |
| `main.o`                    | Compiled object file                      |
| `Residential Society.exe`   | Compiled executable (Windows only)        |

## 🧠 Database Schema Overview

- **Society**: Society name, manager, sector, city, etc.
- **Owner**: Personal info and contact of property owners
- **Apartment**: Apartment type, maintenance, tower, cost
- **Tenant**: Renter info linked to owners and apartments
- **Complaint**: Records of complaints and their statuses
- **Electrical, Carpentry, Plumbing**: Service staff details
- **Visitor & Visits**: Tracking of visits and guests

## ⚠️ Note
- Ensure your MySQL port and credentials match those in `main.cpp`
- Some MySQL versions may require tweaking CHECK constraints or REGEXP usage

---

© 2025 Residential Society Management System Project

