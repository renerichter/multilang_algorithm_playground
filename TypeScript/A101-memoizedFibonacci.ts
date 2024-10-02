function measureTime<T>(func: (...args:any[])=>T): (...args:any[])=>T{
    return function(...args:any[]):T{
        const start = performance.now();
        const result= func(...args);
        const total = performance.now() - start;
        console.log(`Execution time: ${total.toFixed(3)}ms.`)
        return result
    }
}

class memoizedFibonacci{
    private fibonacci:number[]=[0,1];
    private steps: number = 0;
    constructor(preCalc?:number[]){
        if (preCalc && preCalc.length>this.fibonacci.length){
            this.fibonacci=preCalc;
        };
        console.log(this.fibonacci);
    }
    private calculateFibonacciIter(n:number):number{
        while(this.fibonacci.length<=n){
            const newFib = this.fibonacci[this.fibonacci.length-2]+this.fibonacci[this.fibonacci.length-1]
            this.fibonacci.push(newFib)
        }
        return this.fibonacci[n]
    }
    calculate(n:number):number{
        const measuredFib=measureTime<number>(this.calculateFibonacciIter.bind(this))
        return measuredFib(n)
    }
    get_fibonacci():number[]{
        return this.fibonacci
    }
}

const n=50
const memFib = new memoizedFibonacci()
memFib.calculate(n)
console.log(memFib.get_fibonacci())
