#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{}

AForm::AForm(const std::string& name, int gToSign, int gToExecute)
	: name(name), isSigned(false), gradeToSign(gToSign), gradeToExecute(gToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other) : name(other.name), isSigned(other.isSigned)
	, gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
		isSigned = other.isSigned;
	return (*this);
}

AForm::~AForm()
{}

const std::string &AForm::getName() const
{
	return (name);
}
bool AForm::getIsSigned() const
{
	return (isSigned);
}
int AForm::getGradeToSign() const
{
	return (gradeToSign);
}
int AForm::getGradeToExecute() const
{
	return (gradeToExecute);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw GradeTooLowException();
	isSigned = true;
}

void AForm::execute(const Bureaucrat& bureaucrat) const
{
	if (!isSigned)
		throw FormNotSignedException();
	if (bureaucrat.getGrade() > gradeToExecute)
		throw GradeTooLowException();
	executeAction();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("AForm Grade Too High");
}
const char* AForm::GradeTooLowException::what() const throw()
{
	return ("AForm Grade Too Low");
}
const char* AForm::FormNotSignedException::what() const throw()
{
	return ("Form Not Signed");
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	os << "AForm " << form.getName() << ", signed: " << (form.getIsSigned() ? "yes" : "no")
		<< ", grade required to sign: " << form.getGradeToSign()
		<< ", grade required to execute: " << form.getGradeToExecute() << ".";
	return (os);
}
