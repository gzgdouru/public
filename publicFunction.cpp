#include "publicFunction.hpp"

chrono::system_clock::time_point CPublicFunction::string2datetime(const string &szDatetime)
{
	tm t;
	int year, month, day, hour, minute, second;
	sscanf(szDatetime.c_str(), "%d-%d-%d %d:%d:%d", &year, &month, &day, &hour, &minute, &second);
	t.tm_year = year - 1900;
	t.tm_mon = month - 1;
	t.tm_mday = day;
	t.tm_hour = hour;
	t.tm_min = minute;
	t.tm_sec = second;
	t.tm_isdst = 0;

	std::get_time(&t, "%b %d %Y %H:%M:%S");
	return chrono::system_clock::from_time_t(mktime(&t));
}

string CPublicFunction::datetime2string(chrono::system_clock::time_point &tp)
{
	time_t tt = chrono::system_clock::to_time_t(tp);
	stringstream ss;
	ss << put_time(localtime(&tt), "%Y-%m-%d %H:%M:%S");
	return ss.str();
}

string CPublicFunction::Md5Crypto(const string &szSrcStr)
{
	MD5_CTX ctx;
	unsigned char ottmd[16] = { 0 };

	MD5_Init(&ctx);
	MD5_Update(&ctx, szSrcStr.c_str(), szSrcStr.length());
	MD5_Final(ottmd, &ctx);

	string szMd5;
	for_each(begin(ottmd), end(ottmd), [&szMd5](unsigned char &ucOtt) {
		char cTemp[3] = { 0 };
		sprintf(cTemp, "%02X", static_cast<int>(ucOtt));
		szMd5 += cTemp;
	});

	return szMd5;
}