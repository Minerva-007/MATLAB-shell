

#include"iostream"

int main()
{
	system("cls");
	std::cout<<"===MATLAB CLI Version 0.1 installer==="<<std::endl;
	std::cout<<"By: Minerva-007."<<std::endl;
	std::cout<<"Enter matlabroot: ";
	std::string matlabroot;
	std::getline(std::cin, matlabroot);
	
	//Shell execution
	system("mex -client engine server.cpp");
	std::string command1="copy server.exe "+matlabroot+"\\extern\\bin\\win64\\";
	system(command1.c_str());
	std::string command2="echo "+matlabroot+"\\extern\\bin\\win64\\server.exe > start_matlab.bat";
	system(command2.c_str());
	system("pause");
	return 0;
}