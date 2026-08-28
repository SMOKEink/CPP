#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm
{
private:
	const std::string name;
	bool isSigned;
	const int gradeToSign;
	const int gradeToExecute;
protected:
	virtual void executeAction() const = 0;
public:
	AForm();
	AForm(const std::string &name, int gradeToSign, int gradeToExecute);
	AForm(const AForm &other);
	AForm& operator=(const AForm &other);
	virtual ~AForm();

	const std::string& getName() const;
	bool getIsSigned()	 const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	void beSigned(const Bureaucrat& bureaucrat);
	void execute(const Bureaucrat& Bureaucrat) const;

	class GradeTooHighException : public std::exception 
	{
	public:
		const char* what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const throw();
	};
	class FormNotSignedException : public std::exception
	{
	public:
		const char* what() const throw();
	};
};
std::ostream& operator<<(std::ostream &os, const AForm &form);

#endif