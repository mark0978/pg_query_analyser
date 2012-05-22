#include <QFileInfo>
#include "arg.h"

Arg::Arg(const char *name, QVariant(*callback)(QString), const QVariant default_, const QString help){
    this->_name = name;
    this->setDefault(default_);
    this->setCallback(callback);
    this->setHelp(help);
    this->setRequired(false);
}

Arg::Arg(const char *name, QVariant(*callback)(QString), const QString help){
    this->_name = name;
    this->setCallback(callback);
    this->setHelp(help);
    this->setRequired(true);
}

Arg::Arg(const Arg &arg) : QObject(){
    _name = arg._name;
    _callback = arg._callback;
    _default = arg._default;
    _help = arg._help;
    _required = arg._required;
}

QVariant Arg::writableFile(QString filename){
    if(QFileInfo(filename).isWritable()){
        return QVariant(filename);
    }
    return QVariant();;
}

QVariant Arg::readableFile(QString filename){
    if(QFileInfo(filename).isReadable()){
        return QVariant(filename);
    }
    return QVariant();;
}

