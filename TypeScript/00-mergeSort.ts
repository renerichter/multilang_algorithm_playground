abstract class Sorter<T>{
    abstract sort(inputList: T[]): T[]
} 

class MergeSort<T> extends Sorter<T>{
    sort(inputList: T[]):T[]{
        if(inputList.length <= 1){
            return inputList
        }
        const middle = Math.floor(inputList.length / 2)
        const leftHalf = this.sort(inputList.slice(0,middle))
        const rightHalf = this.sort(inputList.slice(middle))
        

        return this.merge(leftHalf,rightHalf)
    }
    private merge(left: T[], right: T[]):T[]{
        var merged = [];
        let leftIdx = 0
        let rightIdx = 0
        while(leftIdx < left.length && rightIdx < right.length){
            if(left[leftIdx] <= right[rightIdx]){
                merged.push(left[leftIdx++])
            }else{
                merged.push(right[rightIdx++])
            }
        }
        return merged.concat(left.slice(leftIdx)).concat(right.slice(rightIdx))
    }
}

class SorterFactory{
    createSorter(sorterType: string):Sorter<any>{
        switch(sorterType){
            case "merge": 
                return new MergeSort<any>()
            default: 
                throw new Error(`Sorter of kind ${sorterType} not found.`)
        }
    }
}

function genRandomIntList(length: number, min: number, max:number): number[]{
    return Array.from({length},()=>Math.floor(Math.random()*(max-min+1))+min)
}


// run
const aList = genRandomIntList(15,-10,20)
console.log(aList)
const sorterFactory = new SorterFactory();
const sorter = sorterFactory.createSorter("merge");
const sortedAList = sorter.sort(aList)
console.log(sortedAList);
console.log("nice");