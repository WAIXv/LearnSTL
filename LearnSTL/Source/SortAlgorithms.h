#pragma once

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
        std::cout<<"Time_selectionSort: "<<endTime - startTime<<std::endl;
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

        std::cout<<(sorted ? "sorted!" : "ERROR!")<<std::endl;
    }

    static int* getNums(int size)
    {
        srand(time(NULL));
        int* nums = new int[size];
        for (int i = 0; i < size; i++)
        {
            nums[i] = rand();
        }
        
        return nums;
    }
};