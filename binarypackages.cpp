#include "binarypackages.h"

#include <QByteArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

void operator << (altrepoapi::BinaryPackages &bp, QByteArray json){
    QJsonDocument doc = QJsonDocument::fromJson(json);
    QJsonObject root = doc.object();
    QJsonValue length = root.value("length");
    QJsonArray dat = root["packages"].toArray();
    for(int num = 0; num < length.toInt(); ++ num){
         altrepoapi::BinaryPackages::PackageInfo pi;
         QJsonObject binary = dat.at(num).toObject();
         pi.name = binary.value("name").toString().toStdString();
         pi.epoch = binary.value("epoch").toInt();
         pi.version = binary.value("version").toString().toStdString();
         pi.release = binary.value("release").toString().toStdString();
         pi.arch = binary.value("arch").toString().toStdString();
         pi.disttag = binary.value("disttag").toString().toStdString();
         pi.buildTime = binary.value("buildTime").toInt();
         pi.source = binary.value("source").toString().toStdString();
         bp << pi;
    }
}


altrepoapi::BinaryPackages::
BinaryPackages(char * jsonData, size_t size){
    *this << QByteArray::fromRawData(jsonData,size);
}

const altrepoapi::BinaryPackages::PackageInfo &altrepoapi::BinaryPackages::
at(size_t index)const{
    try{
        return m_packages.at(index);
    }catch(std::out_of_range exe){
        throw exe;
    }
}


void altrepoapi::BinaryPackages::
operator << (PackageInfo pi){
    m_packages.push_back(pi);
}






