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
        auto func  = m_requests.at(reinterpret_cast<size_t>(reply));
        func(data.data(),data.size());
        m_requests.erase(reinterpret_cast<size_t>(reply));
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
    m_requests.insert(std::make_pair(reinterpret_cast<size_t>(m_mng->get(*m_request)), callback));
}
