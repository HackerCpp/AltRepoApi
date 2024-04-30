#ifndef JSONHTTPLOADER_H
#define JSONHTTPLOADER_H
#include <memory>
#include <functional>

class QNetworkAccessManager;
class QNetworkRequest;
namespace altrepoapi{
    class JsonHttpLoader {

        QNetworkAccessManager *m_mng;
        QNetworkRequest *m_request;
        std::function<void(char * data, size_t size)> m_callback = nullptr;
    public:
        JsonHttpLoader();
        ~JsonHttpLoader();
        void load_async(std::string url, std::function<void(char * data, size_t size)> callback);
    };
}

#endif // JSONHTTPLOADER_H
