#pragma once
#include "Comm.h"


template <typename T>
class ZoByteArray
{

private:
	T zoarray[MAX];

public:
	ZoByteArray(){};
	~ZoByteArray(){};
};