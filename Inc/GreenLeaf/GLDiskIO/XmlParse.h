/**
 * @file XmlParse.h
 * @brief xml解析的声明文件
 * @author Wim
 * @version v1.0
 * @date 2014-12-26
 */
#ifndef XMLPARSE_H
#define XMLPARSE_H

#include <boost/noncopyable.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

namespace GreenLeaf {
namespace GLDiskIO {

/**
 * @brief xml解析类
 */
class XmlParse
{
public:
    typedef boost::property_tree::ptree Properties;

    static XmlParse& instance();

    bool loadFile(const std::string& inputFile);
    void saveFile(const char* outputFile);

    template<typename Type>
    Type get(const Properties::path_type& path, const Type& defaultValue =
            Type()) {
        return _properties.get(path, defaultValue);
    }

    template<typename Type>
    Type get(const Properties& node, const Properties::path_type& path,
            const Type& defaultValue = Type()) {
        return node.get(path, defaultValue);
    }

    template<typename Type>
    void set(const Properties::path_type& path, const Type& newValue) {
        return _properties.put(path, newValue);
    }

    template<typename Type>
    void set(const Properties& node, const Properties::path_type& path,
            const Type& newValue) {
        return node.put(path, newValue);
    }

    template<typename Type>
    void add(const Properties::path_type& path, const Type& value) {
        _properties.add(path, value);
    }

    std::size_t remove(const Properties::key_type& key);

    const Properties& getChild(const Properties::path_type& path) const;
    Properties& getChild(const Properties::path_type& path);

private:
    explicit XmlParse();

private:
    Properties _properties;     /**< 解析xml所需容器 */

};

} } // GreenLeaf::GLDiskIO

#endif // XMLPARSE_H

