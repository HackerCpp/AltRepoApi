#include "jsonhttploader.h"

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>


altrepoapi::JsonHttpLoader::
JsonHttpLoader(){
    m_mng = new QNetworkAccessManager();
    m_request = new QNetworkRequest();
    m_request->setRawHeader("Accept", "application/json");

    QObject::connect(m_mng, &QNetworkAccessManager::finished,[&](QNetworkReply * reply){
        QByteArray data = reply->readAll();
        if(m_callback)
            m_callback(data.data(),data.size());
    });
}

altrepoapi::JsonHttpLoader::
~JsonHttpLoader(){
    if(m_mng){
        delete m_mng;
        m_mng = nullptr;
    }
    if(m_request){
        delete m_request;
        m_request = nullptr;
    }
}

void altrepoapi::JsonHttpLoader::
load_async(std::string url, std::function<void(char * data, size_t size)> callback){
    m_request->setUrl(QUrl{QString::fromStdString(url)});
    m_mng->get(*m_request);
    m_callback = callback;
}
