#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Error: Numbers Of Arguments Must Be 3 !" << std::endl;
		return (1);
	}
	std::string FileName = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];

	if (s1.empty())
	{
		std::cout << "Error: " << std::endl;
		return (1);
	}

	std::ifstream inFile(FileName.c_str());
	if (!inFile.is_open())
	{
		std::cout << "Error: Couldn't Open Input File" << std::endl;
		return (1);
	}

	std::ofstream outFile((FileName + ".replace").c_str());
	if (!outFile.is_open())
	{
		std::cout << "Error: Couldn't Create Output File" << std::endl;
		return (1);
	}

	std::string content;
	std::string line;
	while (std::getline(inFile, line))
	{
		content += line;
		if (!inFile.eof())
			content += "\n";
	}
	size_t pos = 0;
	while ((pos = content.find(s1, pos)) != std::string::npos)
	{
		content.erase(pos, s1.length());
		content.insert(pos, s2);
		pos += s2.length();
	}
	outFile << content;

	inFile.close();
	outFile.close();

	return (0);
}
