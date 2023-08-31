#include <functional>
#include <iostream>
#include <unordered_map>
#include <vector>

#include "Source/WaiGameObject.h"
#include "Source/SortAlgorithms.h"
#include "Source/WaiString.h"

using namespace std;

template<typename T>
void display_catagory()
{
    using it_tag = typename iterator_traits<T>::iterator_category;
    std::cout << typeid(it_tag).name() << std::endl;
}


int* GetRandomNums(int size) {
    srand(time(NULL));
    int* nums = new int[size];
    for (int i = 0; i < size; i++) {
        nums[i] = rand();
    }
    return nums;
}


template<typename T>
void PrintTypeSize()
{
    cout<<"sizeof "<<typeid(T).name()<<" = "<<sizeof(T)<<endl;
}

void func1(WaiString s) {return;}
void func2(WaiString&& s) {return;}

int main()
{
    // //test unordered_map,reference_wrapper
    // WaiGameObject g1("Wai",666);
    // WaiGameObject g2("Wai",666);
    //
    // reference_wrapper<WaiGameObject> r1 = g1;
    // reference_wrapper<WaiGameObject> r2 = g2;
    //
    // unordered_map<
    //     std::reference_wrapper<WaiGameObject>,
    //     int,
    //     ObjectHashHelper,
    //     ObjectEqualHelper> ump_r{};
    // unordered_map<WaiGameObject*,int> ump_p{};
    //
    // vector<reference_wrapper<WaiGameObject>> vec{};
    //
    //
    // ump_r.emplace(r1,3);
    // ump_r.emplace(r2,6);
    // ump_p.emplace(&g1,3);
    // ump_p.emplace(&g2,6);
    //
    // g2.name = "WHY";


    // //test SortingAlogrithums
    // int size = 10000;
    // int* nums = GetRandomNums(size);
    // SortAlgorithms::selectionSort(nums,0,size);
    // SortAlgorithms::check(nums,0,size);
    

    //test move

    WaiString s1("s1");
    WaiString&& s2 = "s2";
    cout<<endl;
    // WaiString& s2 = s1;
    // func1(s1);
    func2(std::move(s1));
    // func1(s2);
    
    system("pause");
}
