#ifndef _PmergeMe_HPP_
#define _PmergeMe_HPP_

#include <deque>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <vector>

class PmergeMe 
{
    private:
        std::vector<int> _vec;
        std::deque<int> _deque;
        double _vecTime;
        double _dequeTime;
        
        int convertToInt(const std::string& str);
        std::vector<int> generateJacobsthalSequence(int n);
        std::vector<int> generateInsertionOrder(int n);
        
        int binarySearchVec(const std::vector<int>& sorted, int value, int right);
        int binarySearchDeque(const std::deque<int>& sorted, int value, int right);
        void fordJohnsonVec(std::vector<int>& arr);
        void fordJohnsonDeque(std::deque<int>& arr);

        std::vector<std::string> splitInput(char *str);
        bool hasSpace(char *str);

    public:
        PmergeMe();
        PmergeMe(const PmergeMe &copy);
        PmergeMe &operator=(const PmergeMe &copy);
        ~PmergeMe();
        
        bool checkInput(int ac, char **av);
        void sort();
        void printBefore();
        void printResults();
};

#endif