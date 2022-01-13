#include <vector>

// this function will sort a vector (arrays were proving difficult) with the most inneficient non-trivial method I could devise
std::vector<int> slowSort(std::vector<int> unsortedList) {

	// a new vector of the same size is made where the sorted elements will be inserted
	std::vector<int> sortedList(unsortedList.size());
	std::fill(sortedList.begin(), sortedList.end(), NULL);

	// for each element of the unsorted list, the number of elements will lower value are tallied to determine its place on the sorted list
	for (int sortElementIndex = 0; sortElementIndex < unsortedList.size(); sortElementIndex++) {
		int sortElementPosition = 0;
		for (int comparisonIndex = 0; comparisonIndex < unsortedList.size(); comparisonIndex++) {
			if (unsortedList[sortElementIndex] > unsortedList[comparisonIndex]) sortElementPosition++;
		}

		// to ensure duplicate values don't overwrite one another in the sorted list, the following check is made
		while (sortedList[sortElementPosition] != NULL) sortElementPosition++;

		// the element is inserted
		sortedList[sortElementPosition] = unsortedList[sortElementIndex];
	}

	// a now sorted copy of the list is returned
	return sortedList;
}
