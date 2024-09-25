#include <vector>
#include <iostream>
#include <chrono>

using std::vector,std::cout,std::chrono::high_resolution_clock,std::chrono::duration;

template<typename Func, typename... Args>
auto measureTime(Func&& func, Args&&... args){
    auto start = high_resolution_clock::now();
    auto result = std::forward<Func>(func)(std::forward<Args>(args)...);
    auto end = high_resolution_clock::now();
    duration<double,std::milli> duration = end - start;

    cout << "Execution time: " << duration.count() << " ms." << std::endl;

    return result;
};


class MemoizedFibonacci{
private:
    vector<long long> fibonacci;
    int steps;

    long long calculateFibonacciIter(int n){
        while(fibonacci.size()<=n){
            long long newFib = fibonacci[fibonacci.size()-2] + fibonacci[fibonacci.size()-1];
            fibonacci.push_back(newFib);
        };
        return fibonacci[n];
    };

public:
    MemoizedFibonacci(const vector<long long>& preCalc = {0,1}): fibonacci(preCalc),steps(0){
        cout << "Initial fibonacci Sequence:";
        for (const auto& num: fibonacci){
            cout << num << " ";
        }
        cout << std::endl;
    }
    // auto constructor
    long long calculate(int n){
        return measureTime([this,n](){return calculateFibonacciIter(n);});
    }
    vector<long long> getFibonacci(){
        return fibonacci;
    }
};

int main(){
    const int k=10;
    MemoizedFibonacci memFib = MemoizedFibonacci();
    memFib.calculate(k);
    for(auto num:memFib.getFibonacci()){
        cout << num << ",";
    };
    cout << std::endl;
}