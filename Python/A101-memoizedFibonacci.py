from functools import wraps
from time import perf_counter
from typing import Any, Callable, List


def measure_time(func:Callable[...,Any]):
    @wraps(func)
    def wrapper(*args:Any,**kwargs:Any):
        start_time = perf_counter()
        result = func(*args,**kwargs)
        end_time = perf_counter()-start_time
        print(f"{func.__name__}---Calculation took: {end_time:2e}s.")
        return result
    return wrapper


class memoizedfibonacci:
    def __init__(self,pre_calc:List[int]=[]):
        self.fibonacci:List[int] = pre_calc if pre_calc else [0,1]
        self.steps = 0
    
    
    def calculate_fibonacci_recursive(self,n:int)->int:
        if n<len(self.fibonacci):
            return self.fibonacci[n]
        else:
            self.steps+=1
            new_fibonacci = self.calculate_fibonacci_recursive(n-1) + self.calculate_fibonacci_recursive(n-2)
            self.fibonacci.append(new_fibonacci)
            return new_fibonacci
    
    def calculate_fibonacci_iterative(self,n:int)->int:
        while len(self.fibonacci)<=n:
            new_fib = self.fibonacci[-2]+self.fibonacci[-1]
            self.fibonacci.append(new_fib)
        return self.fibonacci[n]
    @measure_time
    def get_fibonacci(self,n:int,method:int=0):
        self.steps = 0
        func = [self.calculate_fibonacci_iterative,self.calculate_fibonacci_recursive][method]
        res:int = func(n)
        return res,self.steps
        
            
        
    
    def get_stored_fibonacci(self):
        return self.fibonacci

if __name__ == '__main__':
    recfib = memoizedfibonacci()
    iterfib = memoizedfibonacci()
    k=50
    rec_nbr = recfib.get_fibonacci(k,1)
    iter_nbr = iterfib.get_fibonacci(k,0)
    
    #print(iterfib.get_stored_fibonacci())
    #print(recfib.get_stored_fibonacci())
    print("nice")
    