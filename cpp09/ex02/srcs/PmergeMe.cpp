#include "PmergeMe.hpp"
#include <sstream>
#include <algorithm>

// ================== CONSTRUCTORS ================== //

PmergeMe::PmergeMe() {
    _nb = -1;
    _size_min_vector = 0;
    _time_vector = 0;
    _time_deque = 0;
}

PmergeMe::PmergeMe(const PmergeMe &other) {
    *this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        // CODE HERE
    }
    return *this;
}

// ================== DESTRUCTOR ================== //

PmergeMe::~PmergeMe() {
}

// ================================================================================= //
// ==================================== METHODS ==================================== //
// ================================================================================= //

// ================= Parting part ================= //

bool PmergeMe::containsOnlyDigits(const std::string &str) {
    for (size_t i = 0; i < str.size(); i++) {
        if (!isdigit(str[i]) && str[i] != ' ')
            return false;
    }
    return true;
}

bool PmergeMe::parsInput(const std::string &str) {
    if (str.empty()) {
        std::cerr << RED << "Error: Empty input" << RESET << std::endl;
        return false;
    }
    if (!containsOnlyDigits(str)) {
        std::cerr << RED << "Error: Invalid input" << RESET << std::endl;
        return false;
    }
    _str = str;
    return true;
}

// ================= Pair part ================= //

void PmergeMe::makePair() {
    std::string tmp;
    int first, second;
    std::istringstream iss(_str);

    _nb = -1;
    while (iss >> first) {
        if (!(iss >> second)) {
            _nb = first;
            break;
        }
        _pairs.push_back(std::make_pair(first, second));
    }
}

// ================= Finding max part ================= //

void PmergeMe::findMaxOfPairs() {
    for (size_t i = 0; i < _pairs.size(); i++) {
        if (_pairs[i].first > _pairs[i].second)
            _sorted_number.push_back(_pairs[i].first);
        else
            _sorted_number.push_back(_pairs[i].second);
    }
    if (_nb != -1)
        _sorted_number.push_back(_nb);
}

// ================= Insert Max part ================= //

void PmergeMe::sortMaxOfPairs() {
    if (!_sorted_number.empty()) {
        recursiveSort(_sorted_number, 0, _sorted_number.size() - 1);
        std::sort(_sorted_number.begin(), _sorted_number.end());
    }
}

void PmergeMe::recursiveSort(std::vector<int> &arr, int left, int right) {
    if (left < right) {
        int pivot = partition(arr, left, right);
        recursiveSort(arr, left, pivot - 1);
        recursiveSort(arr, pivot + 1, right);
    }
}

int PmergeMe::partition(std::vector<int> &arr, int left, int right) {
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j <= right - 1; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[right]);
    return i + 1;
}

// ================= Insert Min part ================= //

void PmergeMe::insertMin() {
    std::vector<size_t> jacobsthal_seq;
    _size_min_vector = 2;

    generateJacobsthalSeq(jacobsthal_seq, _pairs.size());

    size_t jacobsthal_index = 0;
    std::vector<std::pair<int, int> >::iterator it = _pairs.begin();
    while (it != _pairs.end() && jacobsthal_index < jacobsthal_seq.size()) {
        int min_value = std::min(it->first, it->second);
        insertInSortedOrder(min_value);
        ++jacobsthal_index;
        it = _pairs.erase(it);
    }
    if (_pairs.size() > 0) {
        insertMin();
    }
}



void PmergeMe::insertInSortedOrder(int value) {
    std::vector<int>::iterator it = _sorted_number.begin();
    while (it != _sorted_number.end() && *it < value) {
        ++it;
    }
    _sorted_number.insert(it, value);
}


void PmergeMe::generateJacobsthalSeq(std::vector<size_t> &seq, size_t size) {
    seq.push_back(0);
    seq.push_back(1);
    size_t idx = 2;
    while (true) {
        size_t next = seq[idx - 1] + 2 * seq[idx - 2];
        if (next >= size) break;
        seq.push_back(next);
        idx++;
    }
}

// ================= sort manager ================= //

void PmergeMe::sortWithVector(const std::string &str) {
    clock_t startTime = clock();
    if (!parsInput(str))
        return;
    makePair();
    findMaxOfPairs();
    sortMaxOfPairs();
    insertMin();
    clock_t endTime = clock();
    
    _time_vector = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC * 1000;
}

void PmergeMe::sortWithDeque(const std::string &str) {
    clock_t startTime = clock();
    if (!parsInput(str))
        return;
    makePair();
    findMaxOfPairs();
    sortMaxOfPairs();
    insertMin();
    clock_t endTime = clock();
    
    _time_deque = static_cast<double>(endTime - startTime) / CLOCKS_PER_SEC * 1000;
}


void PmergeMe::sort(const std::string &str) {
    sortWithVector(str);
    sortWithDeque(str);
    std::cout << GREEN << "Before [ " RESET;
    std::cout << _str << GREEN << " ]" << RESET << std::endl << std::endl;
    if (isSorted()) {
        std::cout << BLUE << "After [ " RESET;
        printNumbers();
        std::cout << BLUE << " ]" << RESET << std::endl << std::endl;
    }
    else
        std::cout << RED << "Not sorted!" << RESET << std::endl;
    std::cout << "Total time to process " << _sorted_number.size() << " elements with std::vector : " << _time_vector << " us" << std::endl;
    std::cout << "Total time to process " << _sorted_number.size() << " elements with std::deque : " << _time_deque << " us" << std::endl;

}

// ================================================================================= //
// ===================================== Utils ===================================== //
// ================================================================================= //

void PmergeMe::printNumbers() {
    for (size_t i = 0; i < _sorted_number.size(); i++) {
        std::cout << "" << _sorted_number[i] << " ";
    }
}

bool PmergeMe::isSorted() {
    if (_sorted_number.empty()) {
        return true;
    }

    std::vector<int>::iterator it = _sorted_number.begin();
    std::vector<int>::iterator prev = it;
    ++it;

    while (it != _sorted_number.end()) {
        if (*prev > *it) {
            return false;
        }
        ++prev;
        ++it;
    }

    return true;
}
