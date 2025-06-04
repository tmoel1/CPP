#include <string>
#include <iostream>
#include <fstream>
#include <sstream>


int searchAndReplace(const std::string& filename,
					 const std::string& s1,
					 const std::string& s2)
{
	std::ifstream inputFile(filename.c_str());
	if (!inputFile)
	{
		std::cerr << "Error: Can't open file" << std::endl;
		return 1;
	}

	std::ostringstream outputStream;
	outputStream << inputFile.rdbuf();
	inputFile.close();

	std::string fileContents = outputStream.str();

	if (s1.empty())
	{
		std::cerr << "Error: s1 is empty" << std::endl;
		return 1;
	}
	else
	{
		std::size_t pos = 0;
		while ((pos = fileContents.find(s1, pos)) != std::string::npos)
		{
			fileContents.erase(pos, s1.length());
			fileContents.insert(pos, s2);
			pos = (pos + s2.length());
		}
	}

	std::ofstream outputFile((filename + ".replace").c_str(), std::ios::out | std::ios::trunc);
	if (!outputFile)
	{
		std::cerr << "Error: Can't create file" << std::endl;
		return 1;
	}
	
	outputFile << fileContents;
	outputFile.close();

	return 0;	
}

int main(int ac,char** av)
{
	if (ac != 4)
	{
		std::cerr 	<< "Error: Launch the program with a filename and two strings as parameters"
					<< std::endl;
		return 1;
	}

	const std::string filename = av[1];
	const std::string s1 = av[2];
	const std::string s2 = av[3];

	if (searchAndReplace(filename, s1, s2))
		return 1;

	return 0;	
}
/*
Testing with included script:

chmod +x run_tests.sh
./run_tests.sh
*/