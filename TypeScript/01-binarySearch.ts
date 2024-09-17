abstract class Searcher {
    abstract search(inputList: (number | string)[], searchElement: number | string): number | null;
}

class BinarySearch extends Searcher {
    search(inputList: (number | string)[], searchElement: number | string): number | null {
        const iL = inputList;
        const sE = searchElement;
        if (iL.length > 1) {
            console.log(iL.length, iL);
            const middleElementIdx = Math.floor(iL.length / 2);
            const middleElement = iL[middleElementIdx]

            if (middleElement == sE) {
                return middleElementIdx;
            } else if (middleElement < sE) {
                const result = this.search(iL.slice(middleElementIdx),sE)
                return result !== null ? middleElementIdx + result : null
            } else {
                return this.search(iL.slice(0, middleElementIdx),sE)
            }
        }
        return null
    }
}

class SearchFactory {
    private _searchHistory: Searcher[] = [];

    createSearcher(searcherType: string): Searcher {
        switch (searcherType) {
            case 'binary':
                const newSearcher = new BinarySearch();
                this._searchHistory.push(newSearcher);
                return newSearcher;
            default:
                throw new Error("No proper Searcher selected")
        }
    }
}

const alist = [3, 8, 12, 15, 22, 31, 50];
const aEl = 50;

const searchFactory = new SearchFactory();
const searcher = searchFactory.createSearcher("binary");
console.log(searcher.search(alist, aEl));
console.log("nice");


