#include "altrepoapi.h"

altrepoapi::
AltRepoApi::AltRepoApi()
{
}

void altrepoapi::AltRepoApi::
binaryPackagesHandler(const size_t id, char *data, size_t size){
    try{
        auto func  = m_binaryPackagesRequests.at(id);
        func(BinaryPackages{data, size});
        m_binaryPackagesRequests.erase(id);

    }catch(...){

    }
}

void altrepoapi::AltRepoApi::
exportBinaryPackages_async(Repos branch,std::function<void(BinaryPackages)> callback,std::function<void(std::string)> exe)
{
    if(m_binaryPackagesRequests.size() >= std::numeric_limits<size_t>::max() - 2){
        if(exe)
            exe(std::string{"ERROR : please try again later"});
        return;
    }
    ++m_currentId;
    m_binaryPackagesRequests.insert(std::make_pair(m_currentId, callback));
    std::string url = "https://rdb.altlinux.org/api/export/branch_binary_packages/" + m_repos.at(branch);
    auto f = std::bind(&altrepoapi::AltRepoApi::binaryPackagesHandler,this,m_currentId,std::placeholders::_1,std::placeholders::_2);
    m_jsonLoader.load_async(url, f);
}
