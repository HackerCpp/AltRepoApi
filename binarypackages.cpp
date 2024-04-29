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
         bp << pi;
         //ui->textEdit->append(binary.value("version").toString());
         //ui->textEdit->append(binary.value("release").toString());
         //ui->textEdit->append(binary.value("arch").toString());
         //ui->textEdit->append(binary.value("disttag").toString());
         //ui->textEdit->append("\n");
    }
}


altrepoapi::BinaryPackages::
BinaryPackages(char * jsonData, size_t size){
    *this << QByteArray::fromRawData(jsonData,size);
}

void altrepoapi::BinaryPackages::
operator << (PackageInfo pi){
    m_packages.push_back(pi);
}






