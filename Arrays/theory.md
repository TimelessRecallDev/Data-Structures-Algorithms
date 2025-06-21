# 📘Theory of Array Representation 

---

## 📌 What is an Array?

An array is a **linear data structure** that stores elements of the **same data type** in **contiguous memory locations**. It allows **random access** to elements using index-based addressing.

---

## ⚙️ Declaration and Memory Representation

### In C/C++:

```cpp
int arr[5]; // Declaration
int arr[] = {1, 2, 3, 4, 5}; // Initialization
```

### Memory Mapping:

* Suppose `int arr[] = {10, 20, 30}`
* If `arr` starts at memory location `1000` and `int` size = 4 bytes:

| Index | Value | Address |
| ----- | ----- | ------- |
| 0     | 10    | 1000    |
| 1     | 20    | 1004    |
| 2     | 30    | 1008    |

### Address Calculation Formula:

```text
Address of arr[i] = base_address + i * size_of_element
```

This allows constant time access: `O(1)`.

---

## 📌 Characteristics of Array Representation

* **Contiguous Memory Allocation**: All elements are stored next to each other.
* **Fixed Size (in static arrays)**: Size must be known at compile time.
* **Homogeneous Data Type**: All elements are of the same type.
* **Index-Based Access**: Enables fast lookup.

---

## 🧠 Memory Layout Visualization

Let’s assume:

```cpp
int arr[4] = {5, 10, 15, 20};
```

If the base address is `2000` and `sizeof(int) = 4 bytes`:

| Index (i) | Element | Address (2000 + i\*4) |
| --------- | ------- | --------------------- |
| 0         | 5       | 2000                  |
| 1         | 10      | 2004                  |
| 2         | 15      | 2008                  |
| 3         | 20      | 2012                  |

This layout enables pointer arithmetic in C/C++.

---

## 🔁 Static vs Dynamic Arrays (Representation-wise)

| Type          | Representation                                  |
| ------------- | ----------------------------------------------- |
| Static Array  | Memory allocated at compile-time (Stack/Global) |
| Dynamic Array | Memory allocated at runtime using `new/malloc`  |

Example:

```cpp
int* arr = new int[n]; // dynamic array
```

---

## 📚 Multidimensional Array Representation

### 2D Arrays (Row-major):

```cpp
int mat[2][3] = {
  {1, 2, 3},
  {4, 5, 6}
};
```

### Memory Storage:

* Stored in **row-major** order:

```text
mat[0][0], mat[0][1], mat[0][2], mat[1][0], mat[1][1], mat[1][2]
```

### Address Formula (Row Major):

```text
Address = base + ((i * number_of_columns) + j) * size_of_element
```

---

## 📍 Pointer Representation

```cpp
int arr[5] = {10, 20, 30, 40, 50};
int* ptr = arr;
```

Then:

* `*(ptr + 0)` → 10
* `*(ptr + 1)` → 20
* ...

This works because of the contiguous layout.

---

## 🚫 Pitfalls in Representation

* Going out of bounds (undefined behavior)
* Variable Length Arrays (non-standard in C++)
* Forgetting dynamic array deallocation (leaks)

---

## 🔍 Summary

* Arrays are stored in contiguous memory
* Direct access via address calculation
* Row-major order for multidimensional arrays
* Efficient for fast reads but limited in flexibility

---


