#include "MatlabDataArray.hpp"
#include "MatlabEngine.hpp"
#include<iostream>

int main()
{
    using namespace matlab::engine;

    // Start MATLAB engine synchronously
    std::unique_ptr<MATLABEngine> matlabPtr = startMATLAB();
    std::string s;
    system("cls");
    std::cout<<"---Welcome to MATLAB command-line version 0.1---"<<std::endl;
    std::cout<<"By: Minerva-007. Drop by if you're a MechE in UET LHR!"<<std::endl;
    std::cout<<"Type #help to dump help message."<<std::endl;
    while(1)
    {
    	try
    	{
	    	std::cout<<"> ";
	    	std::getline(std::cin, s);
	    	if(s=="#help")
	    	{
	    		std::cout<<"MATLAB CLI is intended to run as both a Command-Line interface, a server, and an ssh interface."<<std::endl;
	    		std::cout<<"This app doesn't support GUI, and it's probably for the better: GUI is slow af."<<std::endl;
	    		std::cout<<"This app is still under dev, so help will be super appreciated!"<<std::endl;
	    		std::cout<<"And again, if you're a student in UET LHR, drop by and say hi!"<<std::endl;
	    		std::cout<<"-- Minerva-007"<<std::endl;
	    		continue;
			}
			//Convert the string into C string, then a UTF-16 string, then pass to MATLAB's eval()
	    	matlabPtr->eval( matlab::engine::convertUTF8StringToUTF16String(s.c_str()));
    	}
    	catch(...)
    	{
    		//MATLAB engine shuts down by default on exceptions.
    		//This block overrides the exception handler and keeps the flow continued.
		}
	}
}