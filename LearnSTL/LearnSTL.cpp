#include <algorithm>
#include <deque>
#include <forward_list>
#include <functional>
#include <iostream>
#include <list>
#include <unordered_map>
#include <utility>
#include <vector>

#include "LazySingleton.h"

using namespace std;

template<typename T>
void display_catagory()
{
    using it_tag = typename iterator_traits<T>::iterator_category;
    std::cout << typeid(it_tag).name() << std::endl;
}

class m_GameObject
{
public:
    string name;
    int guid;

    m_GameObject(string name,int guid):name(name),guid(guid)
    {}
    
    bool operator== (const m_GameObject& other) const
    {
        return &other == this;
    }

};

struct ObjectHashHelper
{
    std::size_t operator() (const m_GameObject& go) const
    {
        return std::hash<m_GameObject const*>{}(&go);
    }
};

struct ObjectEqualHelper
{
    bool operator() (const m_GameObject& g1, const m_GameObject& g2) const
    {
        return &g1 == &g2;
    }
};

struct SortAlgorithms
{
    //时间复杂度：O(n^2)，移动操作复杂度：O(n)
    static void selectionSort(int* nums, int left, int right)
    {
        auto startTime = clock();
        
        for(int i = left; i < right; ++i)
        {
            //找出未排序部分的最小值
            int minIndex{i};
            for(int j = i; j < right; ++j)
            {
                if(nums[j] < nums[minIndex])
                {
                    minIndex = j;
                }
            }
            //和最小值位置交换
            if(minIndex != i)
            {
                std::swap(nums[i],nums[minIndex]);
            }
        }

        auto endTime = clock();
        cout<<"Time_selectionSort: "<<endTime - startTime<<endl;
    }
    
    static void quickSort(int* nums, int left, int right)
    {
        
    }

    static void shellSort(int* nums, int left, int right)
    {
        
    }

    static void mergeSort(int* nums, int left, int mid, int right)
    {
        
    }

    static void check(int* nums, int left, int right)
    {
        bool sorted = true;
        int prev = nums[left];
        for(int i = 0; i < right; ++i)
        {
            if(prev > nums[i])
            {
                sorted = false;
                break;
            }
            prev = nums[i];
        }

        cout<<(sorted ? "sorted!" : "ERROR!")<<endl;
    }
};

int* getNums(int size) {
    srand(time(NULL));
    int* nums = new int[size];
    for (int i = 0; i < size; i++) {
        nums[i] = rand();
    }
    return nums;
}

struct playerController
{
    playerController()
    {
        cout<<"playerController Construct"<<endl;
    }
};


template<typename T>
void printSize()
{
    cout<<"sizeof "<<typeid(T).name()<<" = "<<sizeof(T)<<endl;
}

int main()
{
    m_GameObject g1("Wai",666);
    m_GameObject g2("Wai",666);

    reference_wrapper<m_GameObject> r1 = g1;
    reference_wrapper<m_GameObject> r2 = g2;

    unordered_map<
        std::reference_wrapper<m_GameObject>,
        int,
        ObjectHashHelper,
        ObjectEqualHelper> ump_r{};
    unordered_map<m_GameObject*,int> ump_p{};
    
    vector<reference_wrapper<m_GameObject>> vec{};
    
    
    ump_r.emplace(r1,3);
    ump_r.emplace(r2,6);
    ump_p.emplace(&g1,3);
    ump_p.emplace(&g2,6);
    
    g2.name = "WHY";

    int size = 10000;
    int* nums = getNums(size);
    SortAlgorithms::selectionSort(nums,0,size);
    SortAlgorithms::check(nums,0,size);
    
    system("pause");
}
