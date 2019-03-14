#pragma once

class myexception1 : public exception
{
	virtual const char* what() const throw()
	{
		return "Wrong parameter! Wrong parameter combination.";
	}
};

class myexception2 : public exception
{
	virtual const char* what() const throw()
	{
		return "Wrong parameter! The first and last letter constraints are illegal.";
	}
};

class myexception3: public exception
{
	virtual const char* what() const throw()
	{
		return "Wrong parameter! The parameter does not meet the specifications.";
	}
};

class myexception4 : public exception
{
	virtual const char* what() const throw()
	{
		return "Error! there is no such file!";
	}
};

class myexception5 : public exception
{
	virtual const char* what() const throw()
	{
		return "sorry! I don't think there is a such long word.";
	}
};

class myexception6 : public exception
{
	virtual const char* what() const throw()
	{
		return "Error! There are more words than required.";
	}
};

class myexception7 : public exception
{
	virtual const char* what() const throw()
	{
		return "Invalid File! The words can form words ring.";
	}
};

class myexception8 : public exception
{
	virtual const char* what() const throw()
	{
		return "Invalid File! There is no word list in the file.";
	}
};