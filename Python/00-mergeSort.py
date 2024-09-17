from abc import abstractmethod
from typing import Any, List, Tuple


class Sorter:
    @abstractmethod
    def sort(self,input_list:List[Any]|Tuple[Any])->List[Any]|Tuple[Any]:
        pass

class MergeSort(Sorter):
    def sort(self, input_list: List[Any] | Tuple[Any])->List[Any]|Tuple[Any]:
        iL=input_list
        sorted_List:List[Any]=[]
        #print(len(iL),iL)
        if len(iL)>1:
            middle_element=len(iL)//2
            left_half = self.sort(iL[:middle_element])
            right_half = self.sort(iL[middle_element:])
            counter_l = 0
            counter_r = 0
            while counter_l<len(left_half) and counter_r<len(right_half):
                if left_half[counter_l]<=right_half[counter_r]:
                    sorted_List.append(left_half[counter_l])
                    counter_l+=1
                else: 
                    sorted_List.append(right_half[counter_r])
                    counter_r+=1
            if counter_l<len(left_half):
                sorted_List+=left_half[counter_l:]
            elif counter_r<len(right_half):
                sorted_List+=right_half[counter_r:]        
        else:
            sorted_List.append(iL[0])
        return sorted_List
    
class SorterFactory:
    def __init__(self,sorter_history:List[Sorter]=[]):
        self._sorter_history=sorter_history
    
    def createSorter(self,sorter:str)->Sorter:
        match sorter:
            case "merge":
                self._sorter_history.append(MergeSort())
                return self._sorter_history[-1]
            case _:
                raise ValueError("This sorting method is not implemented")


aList=list(range(7,-5,-1))#[5, 2, 9, 1, 6]
sorter_factory = SorterFactory()
sorter = sorter_factory.createSorter("merge")
print(sorter.sort(aList))
print("nice")