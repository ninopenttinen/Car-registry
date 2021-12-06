#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include "CarInfo.h"

using std::string;
using std::cout;
using std::cin;
using std::getline;
using std::endl;
using std::vector;
using std::unique_ptr;
using std::shared_ptr;
using std::weak_ptr;
using std::make_unique;
using std::make_shared;
using std::move;
using std::sort;
using std::function;
using std::remove;

bool isNumeric(const string& s);