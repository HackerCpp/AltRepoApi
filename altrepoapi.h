#ifndef ALTREPOAPI_H
#define ALTREPOAPI_H

#include "AltRepoApi_global.h"
#include "jsonhttploader.h"
#include "binarypackages.h"
#include <map>

namespace altrepoapi{
    class ALTREPOAPI_EXPORT AltRepoApi
    {
        size_t m_currentId = 1;
        JsonHttpLoader m_jsonLoader;
        std::map<size_t, std::function<void(BinaryPackages)>> m_binaryPackagesRequests;

        void binaryPackagesHandler(const size_t id, char *data, size_t size);
    public:
        enum Repos{P9,P10,SISYPHUS};

        AltRepoApi();

        void exportBinaryPackages_async(Repos branch,std::function<void(BinaryPackages)> callback,
                                  std::function<void(std::string)> exe = nullptr);
    private:
        const std::vector<std::string> m_repos{"p9","p10","sisyphus"};
    };
}

#endif // ALTREPOAPI_H
