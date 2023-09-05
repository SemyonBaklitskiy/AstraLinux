#ifndef MYCLASSES_H
#define MYCLASSES_H

#endif // MYCLASSES_H

#include <QApplication>
#include <QDesktopWidget>
#include <QFileSystemModel>
#include <QFileIconProvider>
#include <QTreeView>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include <unistd.h>  //
#include <QLineEdit> //including files where username() function and QLineEdit widget are defined

#define ALL QDir::Dirs |QDir::Files | QDir::Hidden

void search(const QString& string, QStringList& list); //searching substring in string (nedded to filter files)

class MyLineEdit: public QLineEdit { //creating class MyLineEdit inherited from QLineEdit with special slot
private:
    QFileSystemModel& model;
    const QString& rootPath;

public:
    MyLineEdit(QWidget* parent, QFileSystemModel& model, const QString& rootPath);

public slots:
    void onTextChanged();
};
