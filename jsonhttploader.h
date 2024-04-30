#ifndef JSONHTTPLOADER_H
#define JSONHTTPLOADER_H
#include <memory>
#include <functional>
#include <map>

class QNetworkAccessManager;
class QNetworkRequest;
namespace altrepoapi{    

    class JsonHttpLoader {
        QNetworkAccessManager *m_mng;
        QNetworkRequest *m_request;
        std::map<size_t, std::function<void(char * data, size_t size)>> m_requests;
    public:
        JsonHttpLoader();
        ~JsonHttpLoader();
        void load_async(std::string url, std::function<void(char * data, size_t size)> callback);
    };
}

#endif // JSONHTTPLOADER_H
