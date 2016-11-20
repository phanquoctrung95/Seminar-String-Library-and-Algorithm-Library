///////////////////////////////////////////////////////////////////////////
/// Ten     : Phan Quoc Trung
/// MSSV    : 1412590
/// Email   : trungpq999@gmail.com
/// Lop     : Phuong Phap Lap Trinh Huong Doi Tuong 15CTT1
/// Noi Dung: demo noi dung 95 ham trong so 102 ham Algorithm STL
/// duoc nhac den trong file bao cao
///////////////////////////////////////////////////////////////////////////

#include<iostream>
#include <algorithm>    // std::all_of
#include <array>        // std::array
#include <vector>       // std::vector
#include <utility>      // std::pair
#include<string>
#include <functional>
#include <numeric>      // std::accumulate
#include <memory>
int current = 0;
inline int isBetter(const void * a, const void * b){return (*(int*)a - *(int*)b);}
inline int UniqueNumber() { return ++current; }
inline int op_increase(int i) { return ++i; }
inline int RandomNumber() { return (std::rand() % 100); }
inline bool compareLessThan(int i, int j) { return (i < j); }
void myfunction(int i) {  // function:
	std::cout << ' ' << i;
}
bool IsOdd(int i) {
	return (abs(i % 2) == 1);
}
bool myCompare(int i, int j) {
	return (i == j);
}

int main(){

	// 1. Demo all_of
	std::cout << "1. Demo all_of" << std::endl;
	std::vector<int> foo = { -3, 5, 7, 11, 13,13, 17, 19, 23, 7, 30 };
	if (std::all_of(foo.begin(), foo.end(), [](int i){return i % 2; }))
		std::cout << "All the elements are odd numbers.\n";
	// 2. Demo any_of
	std::cout << "2. Demo any_of" << std::endl;
	if (std::any_of(foo.begin(), foo.end(), [](int i){return i < 0; }))
		std::cout << "There are negative elements in the range.\n";
	// 3. Demo none_of
	std::cout << "3. Demo none_of" << std::endl;
	if (std::none_of(foo.begin(), foo.end(), [](int i){return i % 2 == 0; }))
		std::cout << "There are no even elements in the range.\n";
	// 4. Demo for_each	
	std::cout << "4. Demo for_each" << std::endl;
	std::cout << " foo contains:";
	for_each(foo.begin(), foo.end(), myfunction);
	std::cout << '\n';
	// 5. Demo for_each_n

	// 6. Demo count
	std::cout << "6. Demo count " << std::endl;
	std::cout << " number: 7, count: " << std::count(foo.begin(), foo.end(), 7) << '\n';
	// 7. Demo count_if
	std::cout << "7. Demo count_if " << std::endl;
	std::cout << "number divisible by five: "
		<< std::count_if(foo.begin(), foo.end(), [](int i){return i % 5 == 0; })
		<< '\n';
	//	// 8. Demo mismatch
	//std::cout << "8. Demo mismatch " << std::endl;
	//std::pair<std::vector<int>::iterator, int*> mypair;
	//int myints[] = { -3, 5, 7, 11, 13, 15, 20,0,0,0 };
	// std::mismatch(foo.begin(), foo.end(), myints);
	//std::cout << "First mismatching elements: " << *mypair.first;
	//std::cout << " and " << *mypair.second << '\n';

	// 9. Demo equal
	std::cout << "9. Demo equal " << std::endl;
	int foo2[10] = { -3, 5, 7, 11, 13, 17, 19, 23, 7, 29 };
	if (std::equal(foo.begin(), foo.end(), foo2))
		std::cout << " The contents of both sequences are equal.\n";
	else
		std::cout << " The contents of both sequences differ.\n";
	//10. Demo find
	std::cout << "10. Demo find " << std::endl;
	int *p = std::find(foo2, foo2 + 10, 11);
	if (*p != 10)
		std::cout << " fount element 11 in foo2";
	else
		std::cout << " not fount element 11 in foo2";
	//11. Demo find_if find_if_not
	std::cout << "Demo find_if find_if_not " << std::endl;
	std::vector<int>::iterator it = std::find_if(foo.begin(), foo.end(), IsOdd);
	std::cout << " The first odd value is " << *it << '\n';
	it = std::find_if_not(foo.begin(), foo.end(), IsOdd);
	std::cout << " The first even value is " << *it << '\n';
	//12. Demo find_end
	std::cout << "12. Demo find_end " << std::endl;
	int tmp[3] = { 17, 19, 23 };
	it = std::find_end(foo.begin(), foo.end(), tmp,tmp+2);
	if (it != foo.end())
		std::cout << "tmp last found at position " << (it - foo.begin()) << '\n';
		//13. Demo find_first_of
	std::cout << "13. Demo find_first_of " << std::endl;
	it = std::find_first_of(foo.begin(), foo.end(), tmp, tmp + 2);
	if (it != foo.end())
		std::cout << "tmp first found at position " << (it - foo.begin()) << '\n';
		//14. Demo adjacent_find
	std::cout << "14. Demo adjacent_find " << std::endl;
	auto i1 = std::adjacent_find(foo.begin(), foo.end());

	if (i1 == foo.end()) {
		std::cout << "no matching adjacent elements\n";
	}
	else {
		std::cout << "the first adjacent pair of equal elements at: "
			<< std::distance(foo.begin(), i1) << '\n';
	}
		//15. Demo search
	std::cout << "15. Demo search " << std::endl;
	it = std::search(foo.begin(), foo.end(), tmp, tmp + 2);
	if (it != foo.end())
		std::cout << "tmp found at position " << (it - foo.begin()) << '\n';
		//16. Demo search_n
	std::cout << "16. Demo search_n " << std::endl;
	std::cout << "Has 4 consecutive zeros: "
		<< (std::search_n(foo.begin(), foo.end(), 4, 0) != foo.end()) << '\n';
		//17. Demo copy
	std::cout << "17. Demo copy " << std::endl;
	std::copy(foo2, foo2 + 7, foo.begin());
	std::cout << "foo contains:";
	for (std::vector<int>::iterator it = foo.begin(); it != foo.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
		//18. Demo copy_if
	std::cout << "18. Demo copy_if " << std::endl;
	std::vector<int> foo3 = { 25, 15, 5, -5, -15 };
	std::vector<int> bar(foo3.size());
	// copy only positive numbers:
	it = std::copy_if(foo3.begin(), foo3.end(), bar.begin(), [](int i){return !(i<0); });
	bar.resize(std::distance(bar.begin(), it));  // shrink container to new size
	std::cout << "bar contains:";
	for (int& x : bar) std::cout << ' ' << x;
	std::cout << '\n';
		//19. Demo copy_n
	std::cout << "19. Demo copy_n " << std::endl;
	std::vector<int> myvector; 
	myvector.resize(10);
	std::copy_n(foo2, 10, myvector.begin());
	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it3 = myvector.begin(); it3 != myvector.end(); ++it3)
		std::cout << ' ' << *it3;
	std::cout << '\n';

		//20. Demo copy_backward
	std::cout << "20. Demo copy_backward " << std::endl;
	myvector.resize(13);
	std::copy_backward(myvector.begin(), myvector.begin() + 5, myvector.end());
	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
		//21. Demo move
	std::cout << "21. Demo move " << std::endl;
	std::vector<int> tmp2(10);
	std::move(myvector.begin(), myvector.begin() + 10, tmp2.begin());
	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it4 = tmp2.begin(); it4 != tmp2.end(); ++it4)
		std::cout << ' ' << *it4;
	std::cout << '\n';
		//22. Demo move_backward
	std::cout << "22. Demo move_backward " << std::endl;
	std::string elems[10] = { "air", "water", "fire", "earth" };
	// insert new element at the beginning:
	std::move_backward(elems, elems + 4, elems + 5);
	elems[0] = "ether";
	std::cout << "elems contains:";
	for (int i = 0; i<10;  ++i)
		std::cout << " ["<< elems[i] << "]";
	std::cout << '\n';
		//23. Demo fill
	std::cout << "23. Demo fill " << std::endl;
	std::fill(myvector.begin(), myvector.begin() + 4, 5);
	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
		//24. Demo fill_n
	std::cout << "24. Demo fill_n " << std::endl;
	std::fill_n(myvector.begin(), 4, 20);
	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
		//25. Demo transform
	std::cout << "25. Demo transform " << std::endl;
	myvector.resize(foo.size());
	std::transform(foo.begin(), foo.end(), myvector.begin(), op_increase);
	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
		//26. Demo generate
	std::cout << "26. Demo generate " << std::endl;
	std::generate(myvector.begin(), myvector.end(), RandomNumber);

	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
		//27. Demo generate_n
	std::cout << "27. Demo generate_n " << std::endl;
	int myarray[9];
	std::generate_n(myarray, 9, UniqueNumber);
	std::cout << "myarray contains:";
	for (int i = 0; i<9; ++i)
		std::cout << ' ' << myarray[i];
	std::cout << '\n';
		//28. Demo remove remove_if
	std::cout << "28. Demo remove remove_if " << std::endl;
	int* pbegin = foo2;                          
	int* pend = foo2 + sizeof(foo2) / sizeof(int);
	pend = std::remove(pbegin, pend, 7);         
	std::cout << "range contains:";
	for (int* p = pbegin; p != pend; ++p)
		std::cout << ' ' << *p;
	std::cout << '\n';
		//29. Demo remove_copy remove_copy_if
	std::cout << "29. Demo remove_copy " << std::endl;
	std::remove_copy(foo2, foo2 + 8, myvector.begin(), 7);
	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
		//30. Demo replace replace_if
	std::cout << "30. Demo replace replace_if " << std::endl;
	std::replace(myvector.begin(), myvector.end(), 5, -999);
	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
		//31. Demo replace_copy replace_copy_if
	std::cout << "31. Demo replace_copy replace_copy_if " << std::endl;
	std::replace_copy(foo2, foo2 + 8, myvector.begin(), 5, 9999);
	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
		//32. Demo swap
	std::cout << "32. Demo swap " << std::endl;
	int x = 3, y = 9;
	std::cout << " before swap: x= " << x << ", y= " << y << std::endl;
	std::swap(x, y);
	std::cout << " after swap: x= " << x << ", y= " << y << std::endl;
		//33. Demo swap_ranges
	std::cout << "33. Demo swap_ranges " << std::endl;
	std::swap_ranges(foo.begin() + 1, foo.end() - 1, myvector.begin());
	std::cout << "foo contains:";
	for (std::vector<int>::iterator it = foo.begin(); it != foo.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
		//34. Demo iter_swap
	std::cout << "34. Demo iter_swap " << std::endl;
	std::iter_swap(foo2, myvector.begin());
	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
		//35. Demo reverse
	std::cout << "35. Demo reverse " << std::endl;
	std::reverse(myvector.begin(), myvector.end());
	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
		//36. Demo reverse_copy
	std::cout << "36. Demo reverse_copy " << std::endl;
	std::reverse_copy(foo2, foo2 + 9, myvector.begin());
	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
		//37. Demo rotate
	std::cout << "37. Demo rotate " << std::endl;
	std::rotate(myvector.begin(), myvector.begin() + 3, myvector.end());
	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
		//38. Demo rotate_copy
	std::cout << "38. Demo rotate_copy " << std::endl;
	std::rotate_copy(foo2, foo2 + 3, foo2 + 7, myvector.begin());
	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
		//39. Demo random_shuffle shuffle
	std::cout << "39. Demo random_shuffle shuffle " << std::endl;
	// using built-in random generator:
	std::random_shuffle(myvector.begin(), myvector.end());
	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
		//40. Demo sample

		//41. Demo unique
	std::cout << "41. Demo unique " << std::endl;
	std::unique(myvector.begin(), myvector.end());
	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
		//42. Demo unique_copy
	std::cout << "42. Demo unique_copy " << std::endl;
	int myints[] = { 10, 20, 20, 20, 30, 30, 20, 20, 10 };
	std::vector<int> myvector2(9);
	std::vector<int>::iterator it4;
	it4 = std::unique_copy(myints, myints + 9, myvector2.begin());
	std::sort(myvector2.begin(), it4);
	it4 = std::unique_copy(myvector2.begin(), it4, myvector2.begin(), myCompare);
	myvector2.resize(std::distance(myvector2.begin(), it4));
	std::cout << "myvector2 contains:";
	for (it4 = myvector2.begin(); it4 != myvector2.end(); ++it4)
		std::cout << ' ' << *it4;
	std::cout << '\n';

		//43. Demo is_partitioned
	std::cout << "43. Demo is_partitioned " << std::endl;
	// print contents:
	std::cout << "foo:"; for (int& x : foo) std::cout << ' ' << x;
	if (std::is_partitioned(foo.begin(), foo.end(), IsOdd))
		std::cout << " (partitioned)\n";
	else
		std::cout << " (not partitioned)\n";
		//44. Demo partition
	std::cout << "44. Demo partition " << std::endl;
	std::vector<int>::iterator bound;
	bound = std::partition(myvector.begin(), myvector.end(), IsOdd);
	// print out content:
	std::cout << "odd elements:";
	for (std::vector<int>::iterator it = myvector.begin(); it != bound; ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "even elements:";
	for (std::vector<int>::iterator it = bound; it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
		//45. Demo partition_copy
	std::cout << "45. Demo partition_copy " << std::endl;
	std::vector<int> odd, even;
	// resize vectors to proper size:
	unsigned n = std::count_if(foo.begin(), foo.end(), IsOdd);
	odd.resize(n); even.resize(foo.size() - n);
	// partition:
	std::partition_copy(foo.begin(), foo.end(), odd.begin(), even.begin(), IsOdd);
	// print contents:
	std::cout << "odd: ";  for (int& x : odd)  std::cout << ' ' << x; std::cout << '\n';
	std::cout << "even: "; for (int& x : even) std::cout << ' ' << x; std::cout << '\n';
		//46. Demo stable_partition
	std::cout << "46. Demo stable_partition " << std::endl;
	std::vector<int>::iterator bound2;
	bound2 = std::stable_partition(myvector.begin(), myvector.end(), IsOdd);
	// print out content:
	std::cout << "odd elements:";
	for (std::vector<int>::iterator it = myvector.begin(); it != bound2; ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "even elements:";
	for (std::vector<int>::iterator it = bound2; it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
		//47. Demo partition_point
	std::cout << "47. Demo partition_point " << std::endl;
	std::vector<int> odd2;
	std::partition(foo.begin(), foo.end(), IsOdd);
	auto it5 = std::partition_point(foo.begin(), foo.end(), IsOdd);
	odd2.assign(foo.begin(), it5);
	// print contents of odd:
	std::cout << "odd:";
	for (int& x : odd2) std::cout << ' ' << x;
	std::cout << '\n';
		//48. Demo is_sorted
	std::cout << "48. Demo is_sorted " << std::endl;
	std::cout << " Is foo sorted ? " << std::is_sorted(foo.begin(), foo.end())<<std::endl;
		//49. Demo is_sorted_until
	std::cout << "49. Demo is_sorted_until " << std::endl;
	std::array<int, 4> foo6={ 2, 4, 1, 3 };
	std::array<int, 4>::iterator it6;
	it6 = std::is_sorted_until(foo6.begin(), foo6.end());
	std::cout << " " << (it6 - foo6.begin()) << " elements sorted\n";
		//50. Demo sort
	std::cout << "50. Demo sort " << std::endl;
	std::sort(foo.begin(), foo.end());
	std::cout << "foo contains:";
	for (it4 = foo.begin(); it4 != foo.end(); ++it4)
		std::cout << ' ' << *it4;
	std::cout << '\n';
		//51. Demo partial_sort
	std::cout << "51. Demo partial_sort " << std::endl;
	// using default comparison (operator <):
	std::partial_sort(myvector.begin(), myvector.end(), myvector.end());
	// print out content:
	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
		//52. Demo partial_sort_copy
	std::cout << "52. Demo partial_sort_cop " << std::endl;
	// using function as comp
	std::partial_sort_copy(myints, myints + 9, myvector.begin(), myvector.end(), compareLessThan);
	// print out content:
	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
		//53. Demo stable_sort
	std::cout << "53. Demo stable_sort " << std::endl;
	double mydoubles[] = { 3.14, 1.41, 2.72, 4.67, 1.73, 1.32, 1.62, 2.58 };
	std::vector<double> myvector3;
	myvector3.assign(mydoubles, mydoubles + 8);
	std::cout << "myvector3 contains:";
	std::stable_sort(myvector3.begin(), myvector3.end());
	for (std::vector<double>::iterator it = myvector3.begin(); it != myvector3.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
		//54. Demo nth_element
	std::cout << "54. Demo nth_element " << std::endl;
	std::nth_element(myvector.begin(), myvector.begin() + 5, myvector.end());
	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
		//55. Demo lower_bound
	std::cout << "55. Demo lower_bound " << std::endl;
	std::vector<int>::iterator low, up;
	low = std::lower_bound(myvector.begin(), myvector.end(), 20);
	std::cout << "lower_bound at position " << (low - myvector.begin()) << '\n';
		//56. Demo upper_bound
	std::cout << "56. Demo upper_bound " << std::endl;
	up = std::upper_bound(myvector.begin(), myvector.end(), 20);
	std::cout << "upper_bound at position " << (up - myvector.begin()) << '\n';
		//57. Demo binary_search
	std::cout << "57. Demo binary_search " << std::endl;
	std::cout << "looking for a 11 in foo... ";
	if (std::binary_search(foo.begin(), foo.end(), 11))
		std::cout << "found!\n"; else std::cout << "not found.\n";
		//58. Demo equal_range
	std::cout << "58. Demo equal_range " << std::endl;
	std::vector<int> v(myints, myints + 8); 
	std::pair<std::vector<int>::iterator, std::vector<int>::iterator> bounds;
	// using default comparison:
	std::sort(v.begin(), v.end());                              
	bounds = std::equal_range(v.begin(), v.end(), 20);  
	std::cout << "bounds at positions " << (bounds.first - v.begin());
	std::cout << " and " << (bounds.second - v.begin()) << '\n';
		//59. Demo merge
	std::cout << "59. Demo merge " << std::endl;
	std::merge(tmp, tmp + 2, foo2, foo2 + 5, myvector.begin());
	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
		//60. Demo inplace_merge
	std::cout << "60. Demo inplace_merge " << std::endl;
	std::inplace_merge(myvector.begin(), myvector.begin() + 5, myvector.end());
	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it7 = myvector.begin(); it7 != myvector.end(); ++it7)
		std::cout << ' ' << *it7;
	std::cout << '\n';
		//61. Demo includes
	std::cout << "61. Demo includes " << std::endl;
	// using default comparison:
	if (std::includes(tmp, tmp + 2, foo2, foo2 + 4))
		std::cout << "tmp includes foo2!\n";
	else
		std::cout << "tmp doesn't includes foo2!\n";
		//62. Demo set_difference
	std::cout << "62. Demo set_difference " << std::endl;
	it = std::set_difference(tmp, tmp + 2, foo2, foo2 + 5, v.begin());
	v.resize(it - v.begin());
	std::cout << "The difference has " << (v.size()) << " elements:\n";
	for (it = v.begin(); it != v.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
		//63. Demo set_intersection
	std::cout << "63. Demo set_intersection " << std::endl;
	it = std::set_difference(tmp, tmp + 2, foo2, foo2 + 5, v.begin());
	v.resize(it - v.begin());
	std::cout << "The intersection has " << (v.size()) << " elements:\n";
	for (it = v.begin(); it != v.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
		//64. Demo set_symmetric_difference
	std::cout << "64. Demo set_symmetric_difference " << std::endl;
	it = std::set_difference(tmp, tmp + 2, foo2, foo2 + 5, v.begin());
	v.resize(it - v.begin());
	std::cout << "The symmetric difference has " << (v.size()) << " elements:\n";
	for (it = v.begin(); it != v.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
		//65. Demo set_union
	std::cout << "65. Demo set_union " << std::endl;
	it = std::set_difference(tmp, tmp + 2, foo2, foo2 + 5, v.begin());
	v.resize(it - v.begin());
	std::cout << "The union has " << (v.size()) << " elements:\n";
	for (it = v.begin(); it != v.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
		//67. Demo is_heap
	std::cout << "67. Demo is_heap " << std::endl;
	std::cout << " Is foo heap? " << std::is_heap(foo.begin(), foo.end()) << '\n';
		//68. Demo is_heap_until
	std::cout << "68. Demo is_heap_until " << std::endl;
	auto last = std::is_heap_until(foo.begin(), foo.end());
	std::cout << "The " << (last - foo.begin()) << " first elements are a valid heap:";
		//69. Demo make_heap
	std::cout << "69. Demo make_heap " << std::endl;
	if (!std::is_heap(foo.begin(), foo.end()))
		std::make_heap(foo.begin(), foo.end());
	std::cout << "foo contains:";
	for (std::vector<int>::iterator it7 = foo.begin(); it7 != foo.end(); ++it7)
		std::cout << ' ' << *it7;
	std::cout << '\n';
		//70. Demo push_heap
	std::cout << "70. Demo push_heap " << std::endl;
	foo.push_back(99); std::push_heap(foo.begin(), foo.end());
	std::cout << "max heap after push: " << foo.front() << '\n';
		//71. Demo pop_heap
	std::cout << "71. Demo pop_heap " << std::endl;
	std::pop_heap(foo.begin(), foo.end()); foo.pop_back();
	std::cout << "max heap after pop : " << foo.front() << '\n';
		//72. Demo sort_heap
	std::cout << "72. Demo sort_heap " << std::endl;
	std::sort_heap(foo.begin(), foo.end());
	std::cout << "final sorted range :";
	for (unsigned i = 0; i<foo.size(); i++)
		std::cout << ' ' << foo[i];
	std::cout << '\n';
		//73. Demo max
	std::cout << "73. Demo max " << std::endl;
	std::cout << " max(1,2)==" << std::max(1, 2) << '\n';
		//74. Demo max_element
	std::cout << "74. Demo max_element " << std::endl;
	std::cout << "The largest myints's element is " << *std::max_element(myints, myints + 7) << '\n';
		//75. Demo min
	std::cout << "75. Demo min " << std::endl;
	std::cout << " min(1,2)==" << std::min(1, 2) << '\n';
		//76. Demo min_element
	std::cout << "76. Demo min_element " << std::endl;
	std::cout << "The smallest myints's element is " << *std::min_element(myints, myints + 7) << '\n';
		//77. Demo minmax
	std::cout << "77. Demo minmax " << std::endl;
	auto result = std::minmax({ 1, 2, 3, 4, 5 });
	std::cout << "minmax({1,2,3,4,5}): ";
	std::cout << result.first << ' ' << result.second << '\n';
		//78. Demo minmax_element
	std::cout << "78. Demo minmax_element " << std::endl;
	std::array<int, 7> foo4 = { 3, 7, 2, 9, 5, 8, 6 };
	auto result2 = std::minmax_element(foo4.begin(), foo4.end());
	// print result:
	std::cout << "min is " << *result2.first;
	std::cout << ", at position " << (result2.first - foo4.begin()) << '\n';
	std::cout << "max is " << *result2.second;
	std::cout << ", at position " << (result2.second - foo4.begin()) << '\n';
		//79. Demo clamp
	
		//80. Demo lexicographical_compare
	std::cout << "80. Demo lexicographical_compare " << std::endl;
	std::cout << std::boolalpha;
	std::cout << "Comparing foo2 and tmp lexicographically (foo2<tmp):\n";
	std::cout << "Using default comparison (operator<): ";
	std::cout << std::lexicographical_compare(foo2, foo2 + 5, tmp, tmp + 2);
	std::cout << '\n';
		//81. Demo is_permutation
	std::cout << "81. Demo is_permutation " << std::endl;
	if (!std::is_permutation(foo.begin(), foo.end(), foo3.begin()))
		std::cout << "foo and bar don't contain the same elements.\n";
	else
		std::cout << "foo and bar contain the same elements.\n";
		//82. Demo next_permutation
	std::cout << "82. Demo next_permutation " << std::endl;	
	if (!std::next_permutation(foo2, foo2 + 3))
		std::cout << "foo2 isn next_permutation.\n";
	else
		std::cout << "foo2 is next_permutation.\n";
		//83. Demo prev_permutation
	std::cout << "83. Demo prev_permutation " << std::endl;
	if (!std::prev_permutation(foo2, foo2 + 3))
		std::cout << "foo2 isn prev_permutation.\n";
	else
		std::cout << "foo2 is prev_permutation.\n";
		//84. Demo iota
	std::cout << "84. Demo iota " << std::endl;
	char buffer[33];
	int i = 50123;
	_itoa(i, buffer, 10);
	printf("decimal: %s\n", buffer);
		//85. Demo accumulate
	std::cout << "85. Demo accumulate " << std::endl;
	int numbers[] = { 10, 20, 30 };
	std::cout << " accumulate: ";
	std::cout << std::accumulate(numbers, numbers + 3, 100);
		//86. Demo inner_product
	std::cout << "86. Demo inner_product " << std::endl;
	int series1[] = { 10, 20, 30 };
	int series2[] = { 1, 2, 3 };
	std::cout << " inner_product: ";
	std::cout << std::inner_product(series1, series1 + 3, series2, 100);
	std::cout << '\n';
		//87. Demo adjacent_difference
	std::cout << "87. Demo adjacent_difference " << std::endl;
	int val[] = { 1, 2, 3, 5, 9, 11, 12 };
	int result8[7];
	std::adjacent_difference(val, val + 7, result8);
	std::cout << "using default adjacent_difference: ";
	for (int i = 0; i<7; i++) std::cout << result8[i] << ' ';
	std::cout << '\n';
		//88. Demo partial_sum
	std::cout << "88. Demo partial_sum " << std::endl;
	std::partial_sum(val, val + 5, result8);
	std::cout << "using default partial_sum: ";
	for (int i = 0; i<5; i++) std::cout << result8[i] << ' ';
	std::cout << '\n';
		//89. Demo reduce
	std::cout << "89. Demo reduce " << std::endl;
		//90. Demo exclusive_scan
	std::cout << "90. Demo exclusive_scan " << std::endl;
		//91. Demo inclusive_scan
	std::cout << "91. Demo inclusive_scan " << std::endl;
		//92. Demo transform_reduce
	std::cout << "92. Demo transform_reduce " << std::endl;

		//93. Demo transform_exclusive_scan
	std::cout << "93. Demo transform_exclusive_scan " << std::endl;
		//94. Demo transform_inclusive_scan
	std::cout << "94. Demo transform_inclusive_scan " << std::endl;
		//95. Demo uninitialized_copy
	std::cout << "95. Demo uninitialized_copy " << std::endl;
	std::string numbers2[] = { "one", "two", "three" };
	// get block of uninitialized memory:
	std::pair <std::string*, std::ptrdiff_t> result9 = std::get_temporary_buffer<std::string>(3);

	if (result9.second>0) {
		std::uninitialized_copy(numbers2, numbers2 + result9.second, result9.first);
		for (int i = 0; i<result9.second; i++)
			std::cout << result9.first[i] << " ";
		std::cout << '\n';
		std::return_temporary_buffer(result9.first);
	}
		//96. Demo uninitialized_copy_n
	std::cout << "96. Demo uninitialized_copy_n " << std::endl;
	std::pair <std::string*, std::ptrdiff_t> result12 = std::get_temporary_buffer<std::string>(3);

	if (result12.second>0) {
		std::uninitialized_copy_n(numbers2, result12.second, result12.first);
		for (int i = 0; i<result12.second; i++)
			std::cout << result12.first[i] << ' ';
		std::cout << '\n';
		std::return_temporary_buffer(result12.first);
	}
	//97. Demo uninitialized_fill
	std::cout << "97. Demo uninitialized_fill " << std::endl;
	// get block of uninitialized memory:
	std::pair <std::string*, std::ptrdiff_t>
		result10 = std::get_temporary_buffer<std::string>(3);

	if (result10.second>0) {
		std::uninitialized_fill(result10.first, result10.first + result10.second, "c++ rocks!");
		for (int i = 0; i<result10.second; i++)
			std::cout << result10.first[i] << '\n';
		std::return_temporary_buffer(result10.first);
	}
		//98. Demo uninitialized_fill_n
	std::cout << "98. Demo uninitialized_fill_n " << std::endl;
	std::pair <std::string*, std::ptrdiff_t>
		result11 = std::get_temporary_buffer<std::string>(3);
	if (result.second>0) {
		std::uninitialized_fill_n(result11.first, result11.second, "c++ rocks!");
		for (int i = 0; i<result11.second; i++)
			std::cout << result11.first[i] << '\n';
		std::return_temporary_buffer(result11.first);
	}
		//99. Demo uninitialized_move
	std::cout << "99.. Demo uninitialized_move " << std::endl;
		//100. Demo uninitialized_move_n
	std::cout << "100. Demo uninitialized_move_n " << std::endl;
		//101. Demo qsort
	std::cout << "101. Demo qsort " << std::endl;
	int values[] = { 40, 10, 100, 90, 20, 25 };
	qsort(values, 6, sizeof(int), isBetter);
	for (n = 0; n<6; n++)
		printf("%d ", values[n]);
		//102. Demo bsearch
	std::cout << "102. Demo bsearch " << std::endl;
	int * pItem;
	int key = 40;
	qsort(values, 6, sizeof (int), isBetter);
	pItem = (int*)bsearch(&key, values, 6, sizeof (int), isBetter);
	if (pItem != NULL)
		printf("%d is in the array.\n", *pItem);
	else
		printf("%d is not in the array.\n", key);


	return 0;
}