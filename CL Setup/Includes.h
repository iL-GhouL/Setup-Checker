#pragma once
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

#include <WinSock2.h>
#include <Windows.h>
#include <winhttp.h>
#include <iphlpapi.h>
#include <ws2tcpip.h>
#include <iostream>
#include <filesystem>
#include <map>
#include <thread>
#include <vector>
#include <string>
#include <chrono>
#include <cctype>
#include <sstream>
#include <algorithm>
#include <process.h>
#include <atomic>
#include <fstream>
#include <mutex>
#include <functional>
#include <future>
#include "Functions.h"

#pragma comment(lib, "urlmon.lib")
#pragma comment(lib, "winhttp.lib")
#pragma comment(lib, "iphlpapi.lib")
