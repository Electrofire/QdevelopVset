#ifndef __EXCEPTION_H__
#define __EXCEPTION_H__
/*
 *Cesar Chacon
 * Exception class that abstracts a simple alert
 * window. 
 * 
 */
#include <QMessageBox>
#include <string.h>
using namespace std;
/** From the Qt API
QMessageBox::NoIcon	0	the message box does not have any icon.
QMessageBox::Question	4	an icon indicating that the message is asking a question.
QMessageBox::Information	1	an icon indicating that the message is nothing out of the ordinary.
QMessageBox::Warning	2	an icon indicating that the message is a warning, but can be dealt with.
QMessageBox::Critical	3	an icon indicating that the message represents a critical problem.
*/
class Exception
{
	private:
		//Attributes
		string message;
		string exceptionTitle;
		int icon;
	QMessageBox mbox;
	public:
		//Constructors and destructors
		Exception();
		Exception(string message, string title, int iconType);
		virtual ~Exception();

		void setMessage(string msg);
		void setTitle(string title);
		void setIcon (int iconType);
		void show();
		
};

#endif // __EXCEPTION_H__
