# Training

## Preparation of environments

### [Python](./Python/)

1. **Create python environment**
   ```bash
   mamba create -n multi_algo python
   mamba activate multi_algo
   ```
2. **run file**
   ```bash
   python myfile.py 
   ```

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

1. **Compile**:  
   ```bash
   g++ yourfile.cpp -o output
   ```
2. (Optional: **Clang**:)
   ```bash
   sudo apt-get install clang
   clang++ -std=c++17 yourfile.cpp -o output
   ```
3. **Run**:  
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

## Further Reads to get started

- Learn about the differences in the languages [idiomics](./documentation/IdiomaticComparison.md)
- learn which [package managers](./documentation/PackageManagers.md) to use

