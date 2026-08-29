#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Default"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{}

Form::Form(const std::string& name, int gToSign, int gToExecute)
	: name(name), isSigned(false), gradeToSign(gToSign), gradeToExecute(gToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& other) : name(other.name), isSigned(other.isSigned)
	, gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
		isSigned = other.isSigned;
	return (*this);
}

Form::~Form()
{}

const std::string &Form::getName() const
{
	return (name);
}
bool Form::getIsSigned() const
{
	return (isSigned);
}
int Form::getGradeToSign() const
{
	return (gradeToSign);
}
int Form::getGradeToExecute() const
{
	return (gradeToExecute);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw GradeTooLowException();
	isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form Grade Too High");
}
const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form Grade Too Low");
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Form " << form.getName() << ", signed: " << (form.getIsSigned() ? "yes" : "no")
		<< ", grade required to sign: " << form.getGradeToSign()
		<< ", grade required to execute: " << form.getGradeToExecute();
	return (os);
}