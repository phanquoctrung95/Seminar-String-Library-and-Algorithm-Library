///////////////////////////////////////////////////////////////////////////////////////
/// Ten     : Phan Quoc Trung
/// MSSV    : 1412590
/// Email   : trungpq999@gmail.com
/// Lop     : Phuong Phap Lap Trinh Huong Doi Tuong 15CTT1
/// Noi Dung: demo noi dung 13 ham trong so 17 ham Null-terminated Multibyte Strings
/// duoc nhac den trong file bao cao
///////////////////////////////////////////////////////////////////////////////////////
#include <clocale>
#include <string>
#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <codecvt>
#include <wchar.h>
#include <stdio.h>  
#include <mbctype.h>  
#include <string.h>  
#include <locale.h>  
#include <wchar.h> 
#include <vector>
#include <iostream>
#include <iomanip>
#include <clocale>
#include <cstring>
#include <cwchar>
#define BUF_SIZE 100  
int Sample(char* szIn, wchar_t* wcOut, int nMax);
int print_mb(const char* ptr);
void print_as_wide(const char* mbstr);
void print_wide(const wchar_t* wstr);
int main(){
	//1. Demo mblen
	std::cout << "1. Demo mblen " << std::endl;
	int      i;
	char    *pmbc = (char *)malloc(sizeof(char));
	wchar_t  wc = L'a';

	printf("Convert wide character to multibyte character:\n");
	wctomb_s(&i, pmbc, sizeof(char), wc);
	printf("  Characters converted: %u\n", i);
	printf("  Multibyte character: %x\n\n", *pmbc);

	i = mblen(pmbc, MB_CUR_MAX);
	printf("Length in bytes of multibyte character %x: %u\n", *pmbc, i);
	
	pmbc = NULL;
	i = mblen(pmbc, MB_CUR_MAX);
	printf("Length in bytes of NULL multibyte character %x: %u\n", pmbc, i);
	//2. Demo mbtowc
	std::cout << "2. Demo mbtowc " << std::endl;
	std::setlocale(LC_ALL, "en_US.utf8");
	// UTF-8 narrow multibyte encoding
	const char* str = "\x7a\xc3\x9f\xe6\xb0\xb4\xf0\x9d\x84\x8b"; // or u8"zß水𝄋"
	// or "\x7a\xc3\x9f\xe6\xb0\xb4\xf0\x9d\x84\x8b";
	print_mb(str);
	//3. Demo wctomb
	std::cout << "3. Demo wctomb " << std::endl;
	const wchar_t str2[] = L"wctomb example";
	const wchar_t* pt;
	char buffer[255];
	int length;
	pt = str2;
	while (*pt) {
		length = wctomb(buffer, *pt);
		if (length<1) break;
		for (i = 0; i<length; ++i) printf("[%c]", buffer[i]);
		++pt;
	}
	std::cout << '\n';
	//4. Demo mbstowcs
	std::cout << "4. Demo mbstowcs " << std::endl; std::setlocale(LC_ALL, "en_US.utf8");
	const char* mbstr = "\x7a\xc3\x9f\xe6\xb0\xb4\xf0\x9f\x8d\x8c";
	wchar_t wstr[5];
	std::mbstowcs(wstr, mbstr, 5);
	std::wcout << "wide string: " << wstr << '\n';
	std::cout << '\n';
	//5. Demo wcstombs
	std::cout << "5. Demo wcstombs " << std::endl;
	std::setlocale(LC_ALL, "en_US.utf8");
	// UTF-8 narrow multibyte encoding
	const wchar_t* wstr3 = L"z\u00df\u6c34\U0001d10b"; // or L"zß水𝄋"
	char mbstr2[11];
	std::wcstombs(mbstr2, wstr3, 11);
	std::cout << "multibyte string: " << mbstr2 << '\n';
	//6. Demo mbsinit
	std::cout << "6. Demo mbsinit " << std::endl;
	// allow mbrlen() to work with UTF-8 multibyte encoding
	std::setlocale(LC_ALL, "en_US.utf8");
	// UTF-8 narrow multibyte encoding
	std::string str3 = "\xe6\xb0\xb4";
	std::mbstate_t mb = std::mbstate_t();
	(void)std::mbrlen(&str3[0], 1, &mb);
	if (!std::mbsinit(&mb)) {
		std::cout << "After processing the first 1 byte of " << str3
			<< " the conversion state is not initial\n";
	}

	(void)std::mbrlen(&str3[1], str3.size() - 1, &mb);
	if (std::mbsinit(&mb)) {
		std::cout << "After processing the remaining 2 bytes of " << str3
			<< ", the conversion state is initial conversion state\n";
	}
	//7. Demo btowc
	std::cout << "7. Demo btowc " << std::endl;
	int num;
	const char mbs[] = "btowc example";
	num = 0;
	for (i = 0; i<sizeof(mbs); ++i)
	if (btowc(mbs[i]) != WEOF) ++num;
	wprintf(L"mbs contains %d single-byte characters.\n", num);
	//8. Demo wctob
	std::cout << "8. Demo wctob " << std::endl;
	const wchar_t wcs[] = L"wctob example";
	num = 0;
	for (i = 0; i<wcslen(wcs); ++i)
	if (wctob(wcs[i]) != EOF) ++num;
	wprintf(L"wcs contains %d characters that translate to single-byte characters.", num);
	std::cout << '\n';
	//9. Demo mbrlen
	std::cout << "9. Demo mbrlen " << std::endl;
	std::mbstate_t mb2 = std::mbstate_t();
	int len1 = std::mbrlen(&str[0], 1, &mb2);
	std::cout << " length: " << len1 << '\n';
	//10. Demo mbrtowc
	std::cout << "10. Demo mbrtowc " << std::endl;
	char    mbBuf[BUF_SIZE] = "AaBbCc\x9A\x8B\xE0\xEF\xF0xXyYzZ";
	wchar_t wcBuf[BUF_SIZE] = { L'' };
	Sample(mbBuf, wcBuf, BUF_SIZE);
	//11. Demo wcrtomb
	std::cout << "11. Demo wcrtomb " << std::endl;
	const wchar_t* pt3 = L"wcrtomb example";
	char buffer3[256];
	mbstate_t mbs3;
	mbrlen(NULL, 0, &mbs3);   /* initialize mbs3 */

	while (*pt3) {
		length = wcrtomb(buffer3, *pt3, &mbs3);
		if ((length == 0) || (length>256)) break;
		putchar('[');
		for (i = 0; i<length; ++i) putchar(buffer3[i]);
		putchar(']');
		++pt3;
	}
	std::cout << '\n';
	//12. Demo mbsrtowcs
	std::cout << "12. Demo mbsrtowcs " << std::endl;
	std::setlocale(LC_ALL, "en_US.utf8");
	const char* mbstr5 = "\x7a\xc3\x9f\xe6\xb0\xb4\xf0\x9d\x84\x8b";
	print_as_wide(mbstr5);
	//13. Demo wcsrtombs
	std::cout << "13. Demo wcsrtombs " << std::endl;
	const wchar_t str6[] = L"wcstombs example";
	char buffer4[32];
	int ret;
	printf("wchar_t str6ing: %ls \n", str6);

	ret = wcstombs(buffer4, str6, sizeof(buffer4));
	if (ret == 32) buffer4[31] = '\0';

	return 0;
}



int Sample(char* szIn, wchar_t* wcOut, int nMax)
{
	mbstate_t   state = { 0 }; // Initial state  
	size_t      nConvResult,
		nmbLen = 0,
		nwcLen = 0;
	wchar_t*    wcCur = wcOut;
	wchar_t*    wcEnd = wcCur + nMax;
	const char* mbCur = szIn;
	const char* mbEnd = mbCur + strlen(mbCur) + 1;
	char*       szLocal;

	// Sets all locale to French_Canada.1252  
	szLocal = setlocale(LC_ALL, "French_Canada.1252");
	if (!szLocal)
	{
		printf("The fuction setlocale(LC_ALL, \"French_Canada.1252\") failed!\n");
		return 1;
	}

	printf("Locale set to: \"%s\"\n", szLocal);

	// Sets the code page associated current locale's code page  
	// from a previous call to setlocale.  
	if (_setmbcp(_MB_CP_SBCS) == -1)
	{
		printf("The fuction _setmbcp(_MB_CP_SBCS) failed!");
		return 1;
	}

	while ((mbCur < mbEnd) && (wcCur < wcEnd))
	{
		//  
		nConvResult = mbrtowc(wcCur, mbCur, 1, &state);
		switch (nConvResult)
		{
		case 0:
		{  // done  
				  printf("Conversion succeeded!\nMultibyte String: ");
				  printf(szIn);
				  printf("\nWC String: ");
				  wprintf(wcOut);
				  printf("\n");
				  mbCur = mbEnd;
				  break;
		}

		case -1:
		{  // encoding error  
				   printf("The call to mbrtowc has detected an encoding error.\n");
				   mbCur = mbEnd;
				   break;
		}

		case -2:
		{  // incomplete character  
				   if (!mbsinit(&state))
				   {
					   printf("Currently in middle of mb conversion, state = %x\n", state);
					   // state will contain data regarding lead byte of mb character  
				   }

				   ++nmbLen;
				   ++mbCur;
				   break;
		}

		default:
		{
				   if (nConvResult > 2) // The multibyte should never be larger than 2  
				   {
					   printf("Error: The size of the converted multibyte is %d.\n", nConvResult);
				   }

				   ++nmbLen;
				   ++nwcLen;
				   ++wcCur;
				   ++mbCur;
				   break;
		}
		}
	}

	return 0;
}

int print_mb(const char* ptr)
{
	std::mbtowc(NULL, 0, 0); // reset the conversion state
	const char* end = ptr + std::strlen(ptr);
	int ret;
	std::cout << " wide string: ";
	for (wchar_t wc; (ret = std::mbtowc(&wc, ptr, end - ptr)) > 0; ptr += ret) {
		std::wcout << wc;
	}
	std::wcout << '\n';
	return ret;
}
void print_as_wide(const char* mbstr)
{
	std::mbstate_t state = std::mbstate_t();
	int len = 1 + std::mbsrtowcs(NULL, &mbstr, 0, &state);
	std::vector<wchar_t> wstr(len);
	std::mbsrtowcs(&wstr[0], &mbstr, wstr.size(), &state);
	std::cout << "Wide string: " << &wstr[0] << '\n'
		<< "The length, including '\\0': " << wstr.size() << '\n';
}
void print_wide(const wchar_t* wstr)
{
	std::mbstate_t state = std::mbstate_t();
	int len = 1 + std::wcsrtombs(nullptr, &wstr, 0, &state);
	std::vector<char> mbstr(len);
	std::wcsrtombs(&mbstr[0], &wstr, mbstr.size(), &state);
	std::cout << "multibyte string: " << &mbstr[0] << '\n'
		<< "Length, including '\\0': " << mbstr.size() << '\n';
}
