# Package Management

## 1) **C++**
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

### **`Conan` (Cross-Platform Package Manager)**

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

### Comparison of C++ Package Managers

| **Feature**       | **vcpkg**                      | **Conan**                      | **Hunter**                      |
|-------------------|--------------------------------|--------------------------------|---------------------------------|
| **Platform**      | Cross-platform (Windows/Linux/macOS) | Cross-platform (Windows/Linux/macOS) | Cross-platform (Linux/macOS)    |
| **CMake Integration** | Easy, built-in              | Requires some setup            | Directly integrates with CMake  |
| **Community Support** | Strong, maintained by Microsoft | Large community, many packages | Smaller, CMake-focused         |
| **Package Availability** | Large library of popular packages | Very large repository of packages | Moderate repository size       |

For most C++ projects, **Conan** or **vcpkg** would be the recommended choice for managing dependencies efficiently.

## GoLang -> GVM

`gvm` is a tool that allows you to easily install, manage, and switch between different versions of Go on your system. It’s especially useful if you need to work with multiple Go versions across different projects, similar to how **`conda`** manages Python environments.

Key Features:

- Install specific versions of Go.
- Switch between installed versions.
- Set a default Go version.
- Create and manage Go environments for different projects.

### Installing and using `gvm`

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