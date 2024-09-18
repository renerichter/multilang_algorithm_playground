#include <vector>
#include <iostream>
#include <algorithm>

using std::cout, std::vector;

template <typename T>
class Sorter
{
public:
    virtual vector<T> sort(const vector<T> &inputList) = 0; // abstract = purely virtual function
    virtual ~Sorter() = default;                            // destructor
};

template <typename T>
class MergeSort : public Sorter<T>
{
public:
    vector<T> sort(const vector<T> &inputList) override
    {
        if (inputList.size() <= 1)
        {
            return inputList;
        }

        size_t middle = inputList.size() / 2; // stays int
        // using iterators to create sub-slices via call by reference -> '.begin()' gives pointer to begin of inputList -> note that vector is contiguous
        vector<T> leftHalf(inputList.begin(), inputList.begin() + middle);
        // alternative: std::vector<T> left_half;left_half.assign(inputList.begin(), inputList.begin() + middle);
        vector<T> rightHalf(inputList.begin() + middle, inputList.end());

        leftHalf = sort(leftHalf);
        rightHalf = sort(rightHalf);

        return merge(leftHalf, rightHalf);
    }

private:
    vector<T> merge(const vector<T> &left, const vector<T> &right)
    {
        vector<T> merged;
        merged.reserve(left.size() + right.size());
        size_t leftIdx = 0, rightIdx = 0;

        while (leftIdx < left.size() && rightIdx < right.size())
        {
            if (left[leftIdx] <= right[rightIdx])
            {
                merged.push_back(left[leftIdx++]);
            }
            else
            {
                merged.push_back(right[rightIdx++]);
            }
        };
        // copy remaining elements
        merged.insert(merged.end(), left.begin() + leftIdx, left.end());
        merged.insert(merged.end(), right.begin() + rightIdx, right.end());
        return merged;
    }
};

template <typename T>
class SorterFactory
{
public:
    // we need to tell Compiler which datatype is behind pointer for memory management and safety
    // unique_ptr makes sure that RAII-principles are used
    // could be also named 'Scope-bound', which means that the lifetime of the object is bound to the scope of a variable, so when the variable goes out of scope then the destructor will release the resource. A very useful property of this is that it makes for greater exception-safety.
    std::unique_ptr<Sorter<T>> createSorter(const std::string& sorterType)
    {
        if (sorterType == "merge")
        {
            // Allocate a MergeSort<T> object on the heap, wrap it in a unique_ptr, and return the pointer.
            return std::make_unique<MergeSort<T>>();
        }
        else
        {
            throw std::invalid_argument("Sorter type '" + sorterType + "' not found.");
        }
    }
};

vector<int> genRandomIntList(size_t length, int min, int max)
{
    vector<int> randomList;
    randomList.reserve(length);

    for (size_t i = 0; i < length; i++)
    {
        randomList.push_back(min + rand() % (max - min + 1));
    }
    return randomList;
};

int main()
{
    /*     vector<int> hi = {1, 2, 3, 4, 5};
        size_t middle = hi.size() / 2;
        cout << "First half: ~>";
        std::copy(hi.begin(), hi.begin() + middle, std::ostream_iterator<int>(cout, "-"));
        cout << "\nSecond half: ";
        std::copy(hi.begin()+middle,hi.end(),std::ostream_iterator<int>(cout, "-"));
        cout<<"\b<~\n";
        vector<int> leftPart(hi.begin(), hi.begin() + 3);
        copy(leftPart.begin(), leftPart.end(), std::ostream_iterator<int>(cout, "-")); */

    vector<int> aList = genRandomIntList(15, -10, 20);
    cout << "Unsorted List: ";
    copy(aList.begin(), aList.end(), std::ostream_iterator<int>(cout, " "));
    cout << std::endl;

    SorterFactory<int> sorterFactory;
    auto sorter = sorterFactory.createSorter("merge");

    //'->' dereferences the pointer such that the object (here function 'sort') can be used
    vector<int> sortedAList = sorter->sort(aList);
    cout << "Sorted List: ";
    copy(sortedAList.begin(), sortedAList.end(), std::ostream_iterator<int>(cout, " "));
    return 0;
}