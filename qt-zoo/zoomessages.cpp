#include "zoomessages.h"
#include <QDebug>


ZooMessages::ZooMessages()
    :ZooObject("messages")
{

}

void ZooMessages::addMessage(ZooMessage *message)
{
    messages.push_back(message);
}

ZooMessages::MessagesList ZooMessages::getMessages() const
{
    return messages;
}

ZooMessages::MessagesList ZooMessages::getMessagesByErrorLevel(ZooErrorLevel lvl)
{
    MessagesList messageList;
    for(int i=0; messages.size() - 1; i++){
        if(messages.at(i)->getErrorLevel() == lvl){
            messageList.push_back(messages.at(i));
        }
    }
    return messageList;
}
ZooMessages::MessagesList ZooMessages::getMessagesByEmittor(ZooObject* emetteur)
{
    MessagesList messageList;
    for(int i=0; messages.size() - 1; i++){
        if(messages.at(i)->getEmittorName() == typeid(emetteur).name()){
            messageList.push_back(messages.at(i));
        }
    }
    return messageList;
}

ZooMessage *ZooMessages::getLastUnreadMessage()
{
    if(messages.size()==0){
        return NULL;
    }
    for(int i= messages.size() - 1; i == 0; i--){
        if(messages.at(i)->isUnread()){
            messages.at(i)->markAsRead();
            return messages.at(i);
        }
    }
}

QString ZooMessages::getLastUnreadMessageAsHtml()
{
    QString html = QString("Error level ")
            .append(getLastUnreadMessage()->getErrorLevel())
            .append(" From : "+getLastUnreadMessage()->getEmittorName()
                    +" Message : "+getLastUnreadMessage()->getMessage());
    return html;
}


