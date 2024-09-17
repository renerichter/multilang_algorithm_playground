from abc import abstractmethod
from typing import Any, List


class Searcher:
    @abstractmethod
    def search(self,inputList:List[Any],searchElement:int|float|str)->int|None:
        pass

class BinarySearch(Searcher):
    def search(self, inputList: List[Any],searchElement:int|float|str) -> int:
        iL = inputList
        sE = searchElement
        if len(iL)>1:
            print(len(iL),iL)
            middleElementIdx = len(iL)//2
            middleElement=iL[middleElementIdx]
            if middleElement == sE:
                return middleElementIdx
            elif middleElement < sE:
                return middleElementIdx + self.search(iL[middleElementIdx:],sE)
            return self.search(iL[:middleElementIdx],sE)
        return -len(iL)-1

class SearchFactory:
    def __init__(self,searcher_history:List[Searcher]=[]):
        self._searcher_history = searcher_history
    def create_searcher(self,searcher:str):
        match searcher:
            case "binary": 
                new_searcher = BinarySearch()
                self._searcher_history.append(new_searcher)
                return new_searcher
            case _:
                raise ValueError("No proper Searcher selected.")

alist = [3, 8, 12, 15, 22, 31, 50]
aEl = 9

search_factory = SearchFactory()
searcher = search_factory.create_searcher("binary")
print(searcher.search(alist,aEl))
print("nice")
