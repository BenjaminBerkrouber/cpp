#include "PmergeMe.hpp"
#include <sstream>
#include <algorithm>

// ================== CONSTRUCTORS ================== //

PmergeMe::PmergeMe() {
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

// ================= Insert First Min ================= //

void PmergeMe::findMinOfPairs() {
    if (_sorted_number.empty()) return;

    int min_element = _sorted_number[0];

    for (std::vector<std::pair<int, int> >::iterator it = _pairs.begin(); it != _pairs.end(); ++it) {
        if (it->first == min_element) {
            _sorted_number.insert(_sorted_number.begin(), it->second);
            _pairs.erase(it);
            return;
        } else if (it->second == min_element) {
            _sorted_number.insert(_sorted_number.begin(), it->first);
            _pairs.erase(it);
            return;
        }
    }
}

// ================= Insert Min part ================= //

void PmergeMe::insertMin() {
    std::vector<size_t> jacobsthal_seq;
    _size_min_vector = 2;

	printPairs();
    generateJacobsthalSeq(jacobsthal_seq, _pairs.size());
    while (!_pairs.empty()) {
        if (static_cast<size_t>(_size_min_vector) < jacobsthal_seq.size() && static_cast<size_t>(_size_min_vector) == jacobsthal_seq[_size_min_vector]) {
            insertInSortedOrder(_pairs[0].first);
            _pairs.erase(_pairs.begin());
        } else {
            insertInSortedOrder(_pairs[0].second);
            _pairs.erase(_pairs.begin());
        }
    }
}

void	PmergeMe::insertInSortedOrder(int value) {
	if (_sorted_number.empty()) {
		_sorted_number.push_back(value);
		return;
	}

	for (std::vector<int>::iterator it = _sorted_number.begin(); it != _sorted_number.end(); ++it) {
		if (value < *it) {
			_sorted_number.insert(it, value);
			return;
		}
	}
	_sorted_number.push_back(value);
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

void PmergeMe::sort(const std::string &str) {
    if (!parsInput(str))
        return;

    std::cout << "Input:" << std::endl;
    std::cout << "  " << _str << std::endl << std::endl;
        
    std::cout << "Pairs:" << std::endl;
    makePair();
    printPairs();

    std::cout << "Max insert:" << std::endl;
    findMaxOfPairs();
    printNumbers();
    
    std::cout << "Sorted max insert:" << std::endl;
    sortMaxOfPairs();
    printNumbers();

    std::cout << "findMinOfPairs Min insert:" << std::endl;
    findMinOfPairs();
    printNumbers();

    std::cout << "Sorted min insert:" << std::endl;
    insertMin();
    printNumbers();
}

// ================================================================================= //
// ===================================== Utils ===================================== //
// ================================================================================= //

void PmergeMe::printPairs() {
    for (size_t i = 0; i < _pairs.size(); i++) {
        std::cout << "  " << _pairs[i].first << " " << _pairs[i].second << std::endl;
    }
    if (_nb != -1)
        std::cout << "nb: " << _nb << std::endl << std::endl;
    else
        std::cout << std::endl;
}

void PmergeMe::printNumbers() {
    std::cout << "  ";
    for (size_t i = 0; i < _sorted_number.size(); i++) {
        std::cout << "" << _sorted_number[i] << " ";
    }
    std::cout << std::endl << std::endl;
}
