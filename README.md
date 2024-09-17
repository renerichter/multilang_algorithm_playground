# Training

## Preparation of environments

### [Python](./Python/)

Just using a base environment.


### [TypeScript](./TypeScript/)

1. **Install Node.js and TypeScript**:  
   Ensure Node.js is installed, then install TypeScript globally:
   ```bash
   npm install -g typescript
   ```

2. **Initialize `tsconfig.json`**:  
   In your project directory, run:
   ```bash
   tsc --init
   ```

3. **Compile the TypeScript file**:  
   Use `tsc` to compile your `.ts` file:
   ```bash
   tsc yourfile.ts
   ```

4. if config-files exist **Compile using `tsc`**:  
   ```bash
   npx tsc
   ```

> *"The way is in training."* — Miyamoto Musashi

### [C++](./Cpp/)

### a) **C++ Code**

1. **Compile**:  
   ```bash
   g++ yourfile.cpp -o output
   ```

1. (Optional: **Clang**:)
   ```bash
   sudo apt-get install clang
   clang++ -std=c++17 yourfile.cpp -o output
   ```

2. **Run**:  
   ```bash
   ./output
   ```

> *"Mastery is often simplicity."* — Zen Proverb

### [GoLang](./GoLang/)

1. **Run directly**:  
   ```bash
   go run yourfile.go
   ```

2. **Compile and run**:  
   ```bash
   go build yourfile.go
   ./yourfile
   ```

> *"Act without doing."* — Lao Tzu

## Idiomic comparison of the languages

| **Idiom**                     | **Python**                           | **TypeScript**                     | **C++**                                     | **Go**                                      |
|-------------------------------|---------------------------------------|------------------------------------|---------------------------------------------|---------------------------------------------|
| **1. Variable Declaration**    | Implicit typing, dynamic (`x = 5`)    | Implicit with `let`, `const` (`let x = 5`) | Explicit type declaration (`int x = 5;`)   | Explicit type inference (`x := 5`)         |
| **2. Function Definition**     | `def func(a, b): return a + b`        | `function func(a: number, b: number): number { return a + b }` | `int func(int a, int b) { return a + b; }` | `func func(a, b int) int { return a + b }` |
| **3. List/Array Creation**     | `my_list = [1, 2, 3]`                | `let myList: number[] = [1, 2, 3]` | `std::vector<int> myList = {1, 2, 3};`      | `myList := []int{1, 2, 3}`                 |
| **4. Object-Oriented Design**  | Class-based, inheritance (`class MyClass:`) | Class-based, inheritance (`class MyClass {}`) | Class-based, inheritance with `private`, `public` | Structs with composition (`type MyStruct struct {}`) |
| **5. Error Handling**          | Exceptions (`try: ... except: ...`)   | `try { ... } catch { ... }`        | Exceptions (`try { ... } catch(...) { ... }`) | Error return values (`if err != nil {...}`) |
| **6. Iterating Over Elements** | `for x in list:`                      | `list.forEach(x => ...)`           | `for (int x : list)` (range-based for loop) | `for _, x := range list { ... }`           |
| **7. List Comprehension**      | `[x**2 for x in list if x > 0]`       | `list.filter(x => x > 0).map(x => x ** 2)` | No direct equivalent (use `std::transform` or loops) | No direct equivalent (use loops)           |
| **8. Memory Management**       | Automatic with garbage collection     | Automatic with garbage collection  | Manual memory management (`new`/`delete`, RAII) | Automatic with garbage collection          |
| **9. Lambda Functions**        | `lambda x: x * 2`                     | `(x: number) => x * 2`             | `[](int x) { return x * 2; }`               | `func(x int) int { return x * 2 }`         |
| **10. Concurrency Model**      | Threading, async (`import threading`) | Promises and async/await           | Threading (`std::thread`)                   | Goroutines (`go func() { ... }`)           |


### Explanation of Idioms:

1. **Variable Declaration**:
   - **Python**: Variables are dynamically typed and assigned without specifying a type.
   - **TypeScript**: Variables can be declared using `let` or `const`, with or without explicit types.
   - **C++**: Variables are explicitly typed, though C++11 introduced `auto` for type inference.
   - **Go**: Variables can be declared with `var` or inferred using `:=`, but types are explicit where needed.
2. **Function Definition**:
   - **Python**: Uses `def`, with no explicit type annotations (though optional with `typing` module).
   - **TypeScript**: Functions are explicitly typed, including both parameters and return types.
   - **C++**: Strongly typed functions, with the return type declared before the function name.
   - **Go**: Functions require explicit parameter and return types, with type inference used in function calls.
3. **List/Array Creation**:
   - **Python**: Lists are dynamic and can contain mixed types.
   - **TypeScript**: Arrays are typed, and can be constrained to specific types.
   - **C++**: Uses `std::vector` for dynamic arrays, with the type specified explicitly.
   - **Go**: Slices are used for dynamic arrays, with clear type declarations.
4. **Object-Oriented Design**:
   - **Python**: Uses classes, supports inheritance and multiple inheritance.
   - **TypeScript**: Uses classes and interfaces, with inheritance and access modifiers (`public`, `private`).
   - **C++**: Full OOP support with inheritance, polymorphism, and access specifiers.
   - **Go**: Favors composition over inheritance using structs and interfaces. No classes or inheritance.
5. **Error Handling**:
   - **Python**: Uses exceptions, `try` and `except` blocks for error handling.
   - **TypeScript**: Same as JavaScript, uses `try/catch` with support for `Promise`-based async handling.
   - **C++**: Uses exceptions for error handling, though many prefer error codes.
   - **Go**: Avoids exceptions, preferring to return errors explicitly from functions (`if err != nil`).
6. **Iterating Over Elements**:
   - **Python**: `for` loops work directly over lists, ranges, and iterables.
   - **TypeScript**: Uses `forEach` for array iteration or `for..of` loops.
   - **C++**: Supports range-based for loops (`for (auto x : list)`) for iterating over containers.
   - **Go**: Uses `range` for iterating over slices, arrays, maps, and strings.
7. **List Comprehension**:
   - **Python**: Supports concise list comprehensions for filtering and transforming lists.
   - **TypeScript**: No direct support; instead, `map()` and `filter()` are used for transformations.
   - **C++**: Does not have a direct equivalent; uses `std::transform` or explicit loops.
   - **Go**: No list comprehension support; loops are used for transformations.
8. **Memory Management**:
   - **Python/TypeScript/Go**: Memory is managed by garbage collection, reducing the need for manual intervention.
   - **C++**: Manual memory management is common, but modern C++ uses smart pointers and RAII to manage resources.
9. **Lambda Functions**:
   - **Python**: Uses `lambda` for inline anonymous functions.
   - **TypeScript**: Uses arrow functions (`=>`) for concise anonymous functions.
   - **C++**: Introduced in C++11 with the `[]` capture syntax for inline anonymous functions.
   - **Go**: Functions are first-class citizens, and anonymous functions are defined using `func`.
10. **Concurrency Model**:
   - **Python**: Threads and async I/O with `asyncio` and `threading` modules.
   - **TypeScript**: Uses promises and `async/await` for handling asynchronous operations.
   - **C++**: Threads are supported natively with `std::thread` and `std::async`.
   - **Go**: Goroutines (`go func()`) are a lightweight, core part of Go's concurrency model, enabling highly concurrent applications.

### Conclusion:
Each language has its own strengths and idiomatic styles:

- **Python**: Emphasizes simplicity and flexibility, with dynamic typing and ease of use.
- **TypeScript**: Focuses on adding type safety to JavaScript’s dynamic nature, promoting scalability in large projects.
- **C++**: Offers fine-grained control over performance and memory, with full OOP and advanced templates.
- **Go**: Prioritizes simplicity, concurrency, and fast execution, making it ideal for modern cloud and distributed systems.

## Package Management

### 1) **C++**
C++ doesn't have a universal version manager like Go's `gvm` or Python's `pyenv` because compilers (e.g., GCC, Clang, MSVC) are platform-specific and behave differently. However, you can manage different versions of C++ compilers manually using:

- **Homebrew (macOS/Linux)**: You can install multiple versions of GCC or Clang and switch between them.
  ```bash
  brew install gcc@9
  brew install gcc@10
  ```

  To use a specific version:
  ```bash
  export CC=gcc-9
  export CXX=g++-9
  ```

#### **`Conan` (Cross-Platform Package Manager)**

`Conan` is another popular package manager for C++ that is cross-platform and highly configurable.

1. **Install `Conan`**:
   ```bash
   pip install conan   # via Python's pip
   ```

2. **Create a Conan configuration** (`conanfile.txt` or `conanfile.py`):
   ```txt
   [requires]
   fmt/8.0.1  # Specify the library and version

   [generators]
   cmake
   ```

3. **Install dependencies**:
   From the root of your project, run:
   ```bash
   conan install . --build=missing
   ```

4. **Integrate with CMake**:
   Use the generated `conanbuildinfo.cmake` file in your CMake project:
   ```cmake
   include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
   conan_basic_setup()
   ```

5. **Build and link your project**:
   After `conan install`, you can proceed with the usual CMake build process:
   ```bash
   cmake .
   cmake --build .
   ```

#### Comparison of C++ Package Managers

| **Feature**       | **vcpkg**                      | **Conan**                      | **Hunter**                      |
|-------------------|--------------------------------|--------------------------------|---------------------------------|
| **Platform**      | Cross-platform (Windows/Linux/macOS) | Cross-platform (Windows/Linux/macOS) | Cross-platform (Linux/macOS)    |
| **CMake Integration** | Easy, built-in              | Requires some setup            | Directly integrates with CMake  |
| **Community Support** | Strong, maintained by Microsoft | Large community, many packages | Smaller, CMake-focused         |
| **Package Availability** | Large library of popular packages | Very large repository of packages | Moderate repository size       |

For most C++ projects, **Conan** or **vcpkg** would be the recommended choice for managing dependencies efficiently.

### GoLang -> GVM

`gvm` is a tool that allows you to easily install, manage, and switch between different versions of Go on your system. It’s especially useful if you need to work with multiple Go versions across different projects, similar to how **`conda`** manages Python environments.

Key Features:

- Install specific versions of Go.
- Switch between installed versions.
- Set a default Go version.
- Create and manage Go environments for different projects.

#### Installing and using `gvm`

1. **Install prerequisites** (on Ubuntu, for example):
   ```bash
   sudo apt-get install curl git mercurial make binutils bison gcc
   ```
2. **Install `gvm`**:
   ```bash
   bash < <(curl -sSL https://raw.githubusercontent.com/moovweb/gvm/master/binscripts/gvm-installer)
   ```
3. **Source `gvm`** (to make it available in your shell):
   ```bash
   source ~/.gvm/scripts/gvm
   ```
4. **Install a Go version**:
   ```bash
   gvm install go1.20
   ```
5. **List installed versions**:
   ```bash
   gvm list
   ```
6. **Switch to a specific version**:
   ```bash
   gvm use go1.20
   ```
7. **Set a default version**:
   ```bash
   gvm use go1.20 --default
   ```
8. **Check current Go version**:
   ```bash
   go version
   ```
9. **Uninstall a Go version**:
   ```bash
   gvm uninstall go1.20
   ```