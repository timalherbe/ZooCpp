#include "zoomessage.h"
#include <QMessageBox>


ZooErrorLevel ZooMessage::getErrorLevel() const
{
    return errorLevel;
}

QString ZooMessage::getMessage() const
{
    return message;
}

ZooObject *ZooMessage::getFrom() const
{
    return from;
}

QString ZooMessage::getEmittorName()
{
    return typeid (from).name();
}

ZooMessage::ZooMessage(ZooErrorLevel errorLevel, QString message, ZooObject* from)
    :ZooObject("message"),
      errorLevel(errorLevel),
      message(message),
      from(from)
{

    QMessageBox msgBox;
    msgBox.setText(message);
    if (errorLevel==ERROR){
        msgBox.setIcon(QMessageBox::Critical);
        QMessageBox::critical(NULL, QMessageBox::tr(QString("Level ").append(errorLevel).append(" message error").toStdString().c_str()), QMessageBox::tr(message.toStdString().c_str()), QMessageBox::Ok);
    }if (errorLevel==WARNING){
        msgBox.setIcon(QMessageBox::Warning);
        QMessageBox::warning(NULL, QMessageBox::tr(QString("Level ").append(errorLevel).append(" message error").toStdString().c_str()), QMessageBox::tr(message.toStdString().c_str()), QMessageBox::Ok);
    }if (errorLevel==INFO){
        msgBox.setIcon(QMessageBox::Information);
        QMessageBox::information(NULL, QMessageBox::tr(QString("Level ").append(errorLevel).append(" message error").toStdString().c_str()), QMessageBox::tr(message.toStdString().c_str()), QMessageBox::Ok);
    }
    msgBox.exec();
}
