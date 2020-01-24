#pragma once
#include <iostream>
#include <cstring>


//опис прототипы ф-ций
//(этот файл встав в прогу, где будем подключ dll файл)

void Write(char* s);
void ProcessRun();
bool CheckFile(std::string path, std::string file_name);