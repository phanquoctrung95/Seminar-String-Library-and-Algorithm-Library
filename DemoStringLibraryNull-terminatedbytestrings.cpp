//////////////////////////////////////////////////////////////////////////
/// Ten     : Phan Quoc Trung
/// MSSV    : 1412590
/// Email   : trungpq999@gmail.com
/// Lop     : Phuong Phap Lap Trinh Huong Doi Tuong 15CTT1
/// Noi Dung: demo noi dung 48 ham trong Null-terminated byte strings
/// duoc nhac den trong file bao cao
/////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<string>
#include<string.h>
#include <cctype>
#include <clocale>
#include <cinttypes>
int main(){

	//  1. Demo isalnum
	std::cout << "1. Demo isalnum" << std::endl;
	unsigned char c1 = '3';
	std::cout<<" c1: "<<c1<<"\n isalnum(c1): "<<isalnum(c1)<<std::endl;
	//  2. Demo isalpha
	std::cout << "2. Demo isalpha" << std::endl;
	std::cout << " c1: " << c1 << "\n isalpha(c1): " << isalpha(c1) << std::endl;
	//  3. Demo islower
	unsigned char c2 = 'A';
	std::cout << "3. Demo islower" << std::endl;
	std::cout << " c2: " << c2 << "\n islower(c2): " << islower(c2) << std::endl;
	//  4. Demo isupper
	std::cout << "4. Demo isupper" << std::endl;
	std::cout << " c2: " << c2 << "\n isupper(c2): " << isupper(c2) << std::endl;
	//  5. Demo isdigit
	std::cout << "5. Demo isdigit" << std::endl;
	std::cout << " c2: " << c2 << "\n isdigit(c2): " << isdigit(c2) << std::endl;
	//  6. Demo isxdigit
	std::cout << "6. Demo isxdigit " << std::endl;
	std::cout << " c2: " << c2 << "\n isxdigit(c2): " << isxdigit(c2) << std::endl;
	//  7. Demo iscntrl
	std::cout << "7. Demo iscntrl " << std::endl;
	std::cout << " c2: " << c2 << "\n iscntrl(c2): " << iscntrl(c2) << std::endl;
	//  8. Demo isgraph
	std::cout << "8. Demo isgraph " << std::endl;
	std::cout << " c2: " << c2 << "\n isgraph(c2): " << isgraph(c2) << std::endl;
	//  9. Demo isspace
	std::cout << "9. Demo isspace " << std::endl;
	std::cout << " c2: " << c2 << "\n isspace(c2): " << isspace(c2) << std::endl;
	//  10. Demo isblank
	std::cout << "10. Demo isblank " << std::endl;
	std::cout << " c2: " << c2 << "\n isblank(c2): " << isblank(c2) << std::endl;
	//  11. Demo isprint
	std::cout << "11. Demo isprint " << std::endl;
	std::cout << " c2: " << c2 << "\n isprint(c2): " << isprint(c2) << std::endl;
	//  12. Demo ispunct
	std::cout << "12. Demo ispunct " << std::endl;
	std::cout << " c2: " << c2 << "\n ispunct(c2): " << ispunct(c2) << std::endl;
	//  13. Demo tolower
	std::cout << "13. Demo tolower " << std::endl;
	tolower(c2);
	std::cout << " c2: " << c2 << "\n tolower(c2), c2: " << c2 << std::endl;
	//  14. Demo toupper
	std::cout << "14. Demo toupper " << std::endl;
	toupper(c2);
	std::cout << " c2: " << c2 << "\n toupper(c2), c2: " << c2 << std::endl;
	//  15. Demo atof
	std::cout << "15. Demo atof " << std::endl;
	std::cout << " std::atof(\"1.0000000123\"): " << std::atof("1.0000000123") << "\n";
	//  16. Demo atoi
	std::cout << "16. Demo atof " << std::endl;
	std::cout << " std::atoi(\"1.0000000123\"): " << std::atoi("1.0000000123") << "\n";
	//  17. Demo atol
	std::cout << "17. Demo atol " << std::endl;
	std::cout << " std::atol(\"1.0000000123\"): " << std::atol("1.0000000123") << "\n";
	//  18. Demo atoll
	std::cout << "18. Demo atoll " << std::endl;
	std::cout << " std::atoll(\"1.0000000123\"): " << std::atoll("1.0000000123") << "\n";
	//  19. Demo strtol
	char *c3 = "10.25";
	char *end = &c3[1];
	std::cout << "19. Demo strtol " << std::endl;
	std::cout <<" strtol(c3, &end, 10): "<< strtol(c3,&end, 10) << std::endl;
	//  20. Demo strtoll
	std::cout << "20. Demo strtoll " << std::endl;
	std::cout << " strtoll(c3, &end, 10): " << strtoll(c3, &end, 10) << std::endl;
	//  21. Demo strtoul
	std::cout << "21. Demo strtoul " << std::endl;
	std::cout << " strtoul(c3, &end, 10): " << strtoul(c3, &end, 10) << std::endl;
	//  22. Demo strtoull
	std::cout << "22. Demo strtoull " << std::endl;
	std::cout << " strtoull(c3, &end, 10): " << strtoull(c3, &end, 10) << std::endl;
	//  23. Demo strtof
	std::cout << "23. Demo strtof " << std::endl;
	std::cout << " strtof(c3, &end, 10): " << strtof(c3, &end) << std::endl;
	//  24. Demo strtod
	std::cout << "24. Demo strtod " << std::endl;
	std::cout << " strtod(c3, &end, 10): " << strtod(c3, &end) << std::endl;
	//  25. Demo strtold
	std::cout << "25. Demo strtold " << std::endl;
	std::cout << " strtold(c3, &end, 10): " << strtold(c3, &end) << std::endl;
	//  26. Demo strtoimax
	std::cout << "26. Demo strtoimax " << std::endl;
	std::cout <<" std::strtoimax(c3, &end, 10): "<< std::strtoimax(c3, &end, 10)<<std::endl;
	//  27. Demo strtoumax
	std::cout << "27. Demo strtoumax " << std::endl;
	std::cout << " std::strtoumax(c3, &end, 10): " << std::strtoumax(c3, &end, 10) << std::endl;
	//  28. Demo strcpy
	std::cout << "28. Demo strcpy " << std::endl;
	char* src = "Take the test.";
	char *src2= new char[256];
	std::strcpy(src2, src);	
	std::cout << " src: " << src << '\n' << " src2: " << src2 << '\n';
	//  29. Demo strncpy
	std::cout << "29. Demo strncpy " << std::endl;
	std::strncpy(src2, src,strlen(src2));
	std::cout << " src: " << src << '\n' << " src2: " << src2 << '\n';
	//  30. Demo strcat
	std::cout << "30.. Demo strcat " << std::endl;
	std::strcat(src2, src);
	std::cout << " src: " << src << '\n' << " src2: " << src2 << '\n';
	//  31. Demo strncat
	std::cout << "31. Demo strncat " << std::endl;
	std::strncat(src2, src, strlen(src2));
	std::cout << " src: " << src << '\n' << " src2: " << src2 << '\n';
	//  32. Demo strxfrm
	char src3[20];
	std::cout << "32. Demo strxfrm " << std::endl;
	int len= std::strxfrm(src3, src, strlen(src));
	src3[len] = 0;
	std::cout << " strxfrm(src3, src, strlen(src)), src3: " << src3<<std::endl;
	//  33. Demo strlen
	std::cout << "33. Demo strlen " << std::endl;
	std::cout << " strlen(src3): " << strlen(src3)<<std::endl;
	//  34. Demo strcmp
	std::cout << "34. Demo strcmp\n strcmp(src3,src): " << strcmp(src3, src) << std::endl;
	//  35. Demo strncmp
	std::cout << "35. Demo strncmp\n strncmp(src3,src,5): " << strncmp(src3, src,5) << std::endl;
	//  36. Demo strcoll
	std::cout << "36. Demo strcoll\n strcoll(src3,src): " << strcoll(src3, src) << std::endl;
	//  37. Demo strchr
	std::cout << "37. Demo strchr\n";
	char str[] = "This is a sample string";
	char * pch;
	pch = strchr(str, 's');
	std::cout << " str: " << str << "\n First occurence of 's' found at: " << pch - str + 1 << '\n';
	//  38. Demo strrchr
	std::cout << "38. Demo strrchr\n";
	pch = strrchr(str, 's');
	std::cout << " str: " << str << "\n Last occurence of 's' found at: " << pch - str + 1 << '\n';
	//  39. Demo strspn
	std::cout << "39. Demo strspn " << std::endl;
	std::cout << " strspn(src, src3);" << strspn(src, src3) << std::endl;
	//  40. Demo strcspn
	std::cout << "40. Demo strcspn " << std::endl;
	std::cout << " strcspn(src, src3);" << strcspn(src, src3) << std::endl;
	//  41. Demo strpbrk
	std::cout << "41. Demo strpbrk " << std::endl;
	std::cout << " strpbrk(src, \"abcdef\"): " << strpbrk(src, "abcdef") << std::endl;
	//  42. Demo strstr
	std::cout << "42. Demo strstr " << std::endl;
	std::cout << " strstr(src, \"the\"): " << strstr(src, "the") << std::endl;
	//  43. Demo strtok
	std::cout << "43. Demo strtok " << std::endl;
	char str2[] = " - This, a sample string.";
	char * pch2;
	printf(" Splitting string \"%s\"\n strtok(str2, \", . - \"): \n", str2);
	pch2 = strtok(str2, " ,.-");
	while (pch2 != NULL)
	{
		printf(" %s\n", pch2);
		pch2 = strtok(NULL, " ,.-");
	}
	std::cout << std::endl;
	//  44. Demo memchr
	std::cout << "44. Demo memchr " << std::endl;
	pch = (char*)memchr(src, 'e', strlen(src));
	std::cout << " In src, 'e' fount at position: " <<  pch- src + 1 << std::endl;
	//  45. Demo memcmp
	std::cout << "45. Demo memcmp " << std::endl;
	std::cout<<"std::memcmp(src, str2, strlen(src)): "<<std::memcmp(src, str2, strlen(src))<<std::endl;
	//  46. Demo memset
	std::cout << "46. Demo memset " << std::endl;
	std::cout << " before std::memset(str2,'1',strlen(str2)): " << str2 << '\n';
	std::memset(str2, '1', strlen(str2));
	std::cout << " std::memset(str2, '1', strlen(str2));, str2: " << str2 << std::endl;
	//  47. Demo memcpy
	std::cout << "47. Demo memcpy " << std::endl;
	std::memcpy(str2, src, strlen(str2));
	std::cout << " std::memcpy(str2, src, strlen(str2)): " << str2 << std::endl;
	//  48. Demo memmove
	std::cout << "48. Demo memmove " << std::endl;
	char str3[] = "memmove can be very useful......";
	std::cout << " str3: " << str3 << '\n';
	memmove(str3 + 20, str3 + 15, 11);
	std::cout << " memmove(str3 + 20, str3 + 15, 11), str3: " << str3 << '\n';

	delete src2;
	delete pch2;
	return 0;
}
