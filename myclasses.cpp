#include "myclasses.h"

//Realization of classes and functions

MyLineEdit::MyLineEdit(QWidget* parent, QFileSystemModel& _model_, const QString& _rootPath_): QLineEdit(parent), model(_model_), rootPath(_rootPath_) {}

void MyLineEdit::onTextChanged() {
    QDir dir(rootPath);
    QStringList list = dir.entryList(ALL);

    search(this->text(), list);

    model.setNameFilterDisables(false);
    model.setNameFilters(list);
}

void search(const QString& string, QStringList& list) {
    if (string.isEmpty())
        return;

    for (int i = 0; i < list.size(); ++i) {
        if (list[i].indexOf(string) == -1) {
            QString toBeDeleted = list[i];
            list.removeOne(toBeDeleted);
            --i;
        }
    }
}

