
# 🧑‍💻 User Management System in C

A basic terminal-based **User Management System** written in C, simulating user creation, modification, deletion, and system export features. Designed as a simple practice project to work with structures, enums, pointers, file I/O, and dynamic memory in C.

---

## 📂 Features

- Create and store user profiles with:
  - Name, Age, ID, and up to 4 Group memberships
- Modify an existing user's name
- Delete a user from the system
- Add a new group to an existing user (up to 4 max)
- Print user information
- Export all user data to a text file
- Cleanly delete/free all users from memory
- Count the total number of users

---

## ⚙️ Technologies Used

- C programming language
- Standard libraries: `stdio.h`, `stdlib.h`, `string.h`
- Linked list data structure for user storage

---

## 🧾 Example User Groups

```c
enum Group {
    root_user = 0,
    system_user = 200,
    operator_user = 1001,
    observer_user
};

```
## 🖥️ How to Compile

Using GCC:
```c
gcc main.c UserManagementSystem.c -o user_mgmt
./user_mgmt
```

