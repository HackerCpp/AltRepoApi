#ifndef BINARYPACKAGES_H
#define BINARYPACKAGES_H

#include "AltRepoApi_global.h"
#include <string>
#include <vector>

namespace altrepoapi{
    class ALTREPOAPI_EXPORT BinaryPackages
    {
    public:
        struct PackageInfo{
            std::string name;
            int epoch;
            std::string version;
            std::string release;
            std::string arch;
            std::string disttag;
            int buildTime;
            std::string source;
        };

        BinaryPackages(){}
        BinaryPackages(char * jsonData, size_t size);

        void operator << (PackageInfo pi);

        size_t size()const{return m_packages.size();}
        const PackageInfo &at(size_t index)const;

    private:

        std::vector<altrepoapi::BinaryPackages::PackageInfo> m_packages;
    };
}
#endif // BINARYPACKAGES_H
