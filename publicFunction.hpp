#ifndef _PUBLIC_FUNCTION_HPP
#define _PUBLIC_FUNCTION_HPP

#include "../../StandardLibrary/public/headfile.hpp"
#include "openssl/md5.h"
using namespace std;

class CPublicFunction
{
public:
	static string datetime2string(chrono::system_clock::time_point &tp);
	static chrono::system_clock::time_point string2datetime(const string &szDatetime);
	static string Md5Crypto(const string &szSrcStr);
};

#endif // _PUBLIC_FUNCTION_HPP