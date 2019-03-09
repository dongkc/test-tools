#pragma once
#include <string>

#define NUMBER_UNCHECK_0 0X20
#define NUMBER_UNCHECK_1 0X21
#define NUMBER_UNCHECK_2 0X22
#define NUMBER_UNCHECK_3 0X23

#define NUMBER_CHECK_0 0X24
#define NUMBER_CHECK_1 0X25
#define NUMBER_CHECK_2 0X26
#define NUMBER_CHECK_3 0X27
using namespace std;

namespace Message {
	enum CommandType
	{
		ZEROING,
		CALIBRATION1,
		CALIBRATION2,
		CALIBRATION3,
		CALIBRATIONQUERY
	};

uint16_t GetCalibrationResult(uint16_t value_low, uint16_t value_high) {
	return (value_low << 8) | value_high;
}

void GetUnCheckedMessage(int index, unsigned char * outbuf, unsigned int &buflen) {
	unsigned char value_base = 0x20;

	outbuf[0] = 0X0A;
	outbuf[1] = 0x01;

	switch (index)
	{
	case ZEROING:
		outbuf[2] = value_base;
		break;
	case CALIBRATION1:
		outbuf[2] = value_base + 1;
		break;
	case CALIBRATION2:
		outbuf[2] = value_base + 2;
		break;
	case CALIBRATION3:
		outbuf[2] = value_base + 3;
		break;
	case CALIBRATIONQUERY:
		outbuf[2] = value_base + 8;
		break;
	default:
		break;
	}

	outbuf[3] = 0x00;
	outbuf[4] = 0xDD;
	outbuf[5] = 0xEE;

	buflen = 6;
}

void GetCheckedMessage(int index,uint16_t value,unsigned char * outbuf, unsigned int &buflen) {
	unsigned char value_base = 0x24;

	outbuf[0] = 0X0A;
	outbuf[1] = 0x03;
	switch (index)
	{
	case ZEROING:
		outbuf[2] = value_base;
		break;
	case CALIBRATION1:
		outbuf[2] = value_base + 1;
		break;
	case CALIBRATION2:
		outbuf[2] = value_base + 2;
		break;
	case CALIBRATION3:
		outbuf[2] = value_base + 3;
		break;
	default:
		break;
	}

	outbuf[3] = value & 0x0f;  //取低八位
	outbuf[4] = value >> 8;    //取高八位

	outbuf[5] = 0x00;
	outbuf[6] = 0xDD;
	outbuf[7] = 0xEE;

	buflen = 8;
}
inline char helper(char c)
{
	if (c < 10) {
		return c + '0';
	}

	return c - 10 + 'A';
}
void hex2ASCII(char c, char* ascii)
{
	char high = (c & 0xF0) >> 4;
	char low = c & 0x0F;
	ascii[0] = helper(high);
	ascii[1] = helper(low);
}

string format(const char* hex, int32_t len)
{
	char ascii[2];
	string content;
	for (int i = 0; i < len; ++i) {
		hex2ASCII(hex[i], (char*)&ascii);
		content = content + string(ascii, 2) + " ";
	}
	content += "\n";

	return content;
}
}
