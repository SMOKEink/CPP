#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), target(other.target)
{}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
		AForm::operator=(other);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void ShrubberyCreationForm::executeAction() const
{
	std::ofstream file((target + "_shrubbery").c_str());
	if (file)
	{
		file << "       /\\\n";
		file << "      /  \\\n";
		file << "     /____\\\n";
		file << "       ||\n";
		file << "       ||\n";
		file << "\n";
		file << "        /\\\n";
		file << "       /  \\\n";
		file << "      /____\\\n";
		file << "        ||\n";
		file << "        ||\n";
		return;
	}
	std::cerr << "Can't Create Shrubbery File" << std::endl;
}
