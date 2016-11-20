//////////////////////////////////////////////////////////////////////////
/// Ten     : Phan Quoc Trung
/// MSSV    : 1412590
/// Email   : trungpq999@gmail.com
/// Lop     : Phuong Phap Lap Trinh Huong Doi Tuong 15CTT1
/// Noi Dung: demo noi dung 60 ham trong std::basic_string
/// duoc nhac den trong file bao cao
/////////////////////////////////////////////////////////////////////////
#include<string>
#include<string.h>
#include<iostream>
#include<sstream>
int main(){
	std::string str = "oriented object programming";
	std::cout << "string str: " << str << '\n';
	// demo at();
	std::cout << "1. str.at(12): " << str.at(12) << std::endl;
	// demo operator[]
	std::cout << "2. str[13]: " << str[13] << std::endl;
	// demo front
	std::cout << "3. str.front(): " << str.front() << '\n'; // "exemplary"
	// demo back
	std::cout << "4. str.back(): " << str.back() << '\n'; // "Exemplars"
	// demo data
	std::cout << "5. str.data(): " << str.data() << '\n';
	// demo c_str
	std::cout << "6. str.c_str(): " << str.c_str() << '\n';
	// demo begin
	std::cout << "7. *str.begin(): " << *str.begin() << '\n';
	// demo cbegin
	std::cout << "8. *str.cbegin(): " << *str.cbegin() << '\n';
	// demo end
	std::string s1;
	std::copy(str.begin(), str.end(), std::back_inserter(s1));
	std::cout << "9.Demo str.end(): " << s1 << '\n';
	// demo cend
	std::string s2;
	std::copy(str.cbegin(), str.cend(), std::back_inserter(s2));
	std::cout << "10.Demo str.cend() == null: " << s2 << '\n';
	// demo rbegin
	std::string s3;
	std::copy(str.rbegin(), str.rend(), std::back_inserter(s3));
	std::cout << "11.Demo str.rbegin(): " << s3 << '\n';
	// demo crbegin
	std::string s4;
	std::copy(str.crbegin(), str.crend(), std::back_inserter(s4));
	std::cout << "12. Demo str.crbegin(): " << s4 << '\n';
	// demo rend
	std::string s("A man, a plan, a canal: Panama");
	{
		std::string c;
		std::copy(s.rbegin(), s.rend(), std::back_inserter(c));
		std::cout << "13. Demo s.rend(): " << c << '\n';
	}
	// demo crend
	std::string c;
	std::copy(s.crbegin(), s.crend(), std::back_inserter(c));
	std::cout << "14. Demo s.crend(): " << c << '\n';
	// demo empty
	std::cout << "15. *str.empty(): " << str.empty() << '\n';
	// demo size
	std::cout << "16. *str.size(): " << str.size() << '\n';
	// demo length
	std::cout << "17. *str.length(): " << str.length() << '\n';
	// demo max_size
	std::cout << "18. *str.max_size(): " << str.max_size() << '\n';
	// demo reserve
	//std::cout << "19. *str.reserve(): " << str.reserve() << '\n';
	// demo capacity
	std::cout << "20. *str.capacity(): " << str.capacity() << '\n';
	// demo shrink_to_fit
	std::string s5;
	s5.resize(100);
	std::cout << "21. Demo shrink_to_fit\n";
	s5.clear();
	std::cout << "   Capacity after s.clear() is " << s5.capacity() << '\n';
	s5.shrink_to_fit();
	std::cout << "   Capacity after s.shrink_to_fit(): " << s5.capacity() << '\n';
	// Demo clear
	std::cout << "22. Demo clear()\n before clear c : "<<c<<'\n';
	c.clear();
	std::cout << " after clear, is c empty ? "<< c.empty() <<std::endl;
	// Demo insert
	str.insert(str.size(), " 15CTT1");
	std::cout << "23. insert  15CTT1 to str"<<str<<std::endl;
	// Demo erase
	std::cout << "24. Demo erase()"<<std::endl;
	std::cout << " before clear s4 : " << s4 << '\n';
	s4.erase();
	std::cout << " after clear, is s4 empty ? " << s4.empty() << std::endl;
	// Demo push_back
	str.push_back('1');
	std::cout << "25. str.push_back(1) " <<str<<std::endl;
	// Demo pop_back
	str.pop_back();
	std::cout << "26. str.pop_back(), str : "<<str<<std::endl;
	// Demo append
	std::cout << "27. str.append(\"2016\") : "<<str.append(" 2016")<<std::endl;
	// Demo operator+=
	str += " DH KHTN";
	std::cout << "28. str+=\" DH KHTN\" : "<<str<<std::endl;
	// Demo compare
	std::cout << "29. str == s1 ? : "<<str.compare(s1)<<std::endl;
	// Demo replace
	str.replace(str.find_first_of("DH"), 7, "Dai Hoc Khoa Hoc Tu Nhien");
	std::cout << "30. str.replace(str.find_first_of(\"DH\"),7, \"Dai Hoc Khoa Hoc Tu Nhien\")\n str : "<<str<<std::endl;
	// Demo substr
	std::cout << "31. str.substr(0,15): "<<str.substr(0,15)<<std::endl;
	// Demo copy
	char s6[10];
	s6[9] = NULL;
	str.copy(s6, sizeof(s6)-1);
	std::cout << "32. str.copy(s6,sizeof(s6)-1), s6 : "<<s6<<std::endl;
	// Demo resize
	std::cout << "33. Demo resize()\n s4.size() = : " << s4.size();
	s4.resize(4);
	std::cout<<"\n s4.resize(4), s4.size(): " <<s4.size()<< std::endl;
	// Demo swap
	std::cout << "34. Demo swap():"<<std::endl;
	std::string a = "AAA";
	std::string b = "BBB";

	std::cout << "	before swap" << '\n';
	std::cout << "	a: " << a << '\n';
	std::cout << "	b: " << b << '\n';
	a.swap(b);
	std::cout << "	after swap" << '\n';
	std::cout << "	a: " << a << '\n';
	std::cout << "	b: " << b << '\n';
	// Demo find
	std::cout << "35. str.find(\"programming\"): "<<str.find("programming")<<std::endl;
	// Demo rfind
	std::cout << "36. str.rfind(\"o\"): "<<str.rfind("o")<<std::endl;
	// Demo find_first_of
	std::cout << "37. str.find_first_of(\"o\"): " << str.find_first_of("o") << std::endl;
	// Demo find_first_not_of
	std::cout << "38. str.find_first_not_of(\"o\"): " << str.find_first_not_of("o")<<std::endl;
	// Demo find_last_of
	std::cout << "39. str.find_last_of(\"o\"): "<<str.find_last_of("o")<<std::endl;
	// Demo find_last_not_of
	std::cout << "40. str.find_last_not_of(\"o\"): " << str.find_last_not_of("o") << std::endl;
	// Demo operator+
	std::cout << "41. Demo s1= s1 + s2\n";
	std::cout<<" s1 : "<< s1 <<std::endl;
	std::cout<<" s2 : " << s2 << std::endl;
	s1 = s1 + s2;
	std::cout << " s1 = s1 + s2, s1: " << s1 << std::endl;
	// Demo operator==
	std::cout << "42. s1 == s2 ? :"<< (s1==s2) <<std::endl;
	// Demo operator!=
	std::cout << "43. s1 != s2 ? :" << (s1 != s2) << std::endl;
	// Demo operator<
	std::cout << "44. s1 < s2 ? :" << (s1 < s2) << std::endl;
	// Demo operator>
	std::cout << "45. s1 > s2 ? :" << (s1 > s2) << std::endl;
	// Demo operator<=
	std::cout << "46. s1 <= s2 ? :" << (s1 <= s2) << std::endl;
	// Demo operator>=
	std::cout << "47. s1 >= s2 ? :" << (s1 >= s2) << std::endl;
	// Demo operator<<
	std::cout << "48. std::cout<<str :"<<str<<std::endl;
	// Demo operator>>
	std::cout << "49. Demo operator>>"<<std::endl;
	std::string greeting = "Hello, whirled!";
	std::istringstream is(greeting);
	std::string hello_comma;
	std::cout << "	std::cout<<hello_comma: " << hello_comma << '\n';
	std::cout << "	std::istringstream is(greeting);\n";
	std::cout << "	is >> hello_comma;\n";
	is >> hello_comma;
	std::cout << "	std::cout<<hello_comma: " << hello_comma << '\n';
	// Demo getline
	std::cout << "50. Demo getline"<<std::endl;
	std::cout << " Read input file line by line: \n";
	std::istringstream input;
	input.str("1\n2\n3\n4\n5\n6\n7\n");
	int sum = 0;
	for (std::string line; std::getline(input, line);) {
		std::cout <<"\t"<< line << std::endl;
	}
	// Demo stoi
	std::cout << "51. Demo stoi "<<std::endl;
	std::string str1 = "45";	
	int myint1 = std::stoi(str1);
	std::cout << "	std::stoi(\"" << str1 << "\") is " << myint1 << '\n';	
	//std::cout << "std::stoi(\"" << str4 << "\") is " << myint4 << '\n';
	// Demo stol
	std::cout << "52. Demo stol"<<std::endl;
	std::string str2 = "3.14159";
	int myint2 = std::stol(str2);
	std::cout << "	std::stol(\"" << str2 << "\") is " << myint2 << '\n';	
	// Demo stoll		std::cout << "53. Demo stoll"<<std::endl;	std::string str3 = "31337 with words";	int myint3 = std::stoll(str3);	std::cout << "	std::stoll(\"" << str3 << "\") is " << myint3 << '\n';	// Demo stoul
	std::string str3 = "31337 with words";
	std::cout << "54. Demo stoul"<<std::endl;	
	std::cout << "	std::stoul(\"" << str1 << "\") is " << std::stoul(str1) << '\n';
	// Demo stoull	std::cout << "55. Demo stoull" << std::endl;	std::cout << "	std::stoulll(\"" << str2 << "\") is " << std::stoull(str2) << '\n';	// Demo stof
	std::cout << "56. Demo stof"<<std::endl;
	std::cout << "	std::stof(\"" << str2 << "\") is " << std::stof(str2) << '\n';
	// Demo stod
	std::cout << "57. Demo stod"<<std::endl;
	std::cout << "	std::stod(\"" << str3 << "\") is " << std::stod(str3) << '\n';
	// Demo stold	std::cout << "58. Demo stold"<<std::endl;	std::cout << "	std::stold(\"" << str3 << "\") is " << std::stold(str3) << '\n';	// Demo to_string
	std::cout << "59. Demo to_string"<<std::endl;
	double f = 23.43;
	std::string f_str = std::to_string(f);
	std::cout << "	std::cout: " << f << '\n'
		<< "	to_string: " << f_str << "\n\n";
	// Demo to_wstring
	std::cout << "60. Demo to_wstring"<<std::endl;
	double f2 = 231232.12001;
	std::wstring f2_str = std::to_wstring(f2);
	std::wcout << "	std::cout: " << f2 << '\n'
		<< "	to_string: " << f2_str << "\n\n";
	return 0;
}