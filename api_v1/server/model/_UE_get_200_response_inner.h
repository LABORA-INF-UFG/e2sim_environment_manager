/**
* E2 Node UE API
* No description provided (generated by Openapi Generator https://github.com/openapitools/openapi-generator)
*
* The version of the OpenAPI document: 1.0
* 
*
* NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
* https://openapi-generator.tech
* Do not edit the class manually.
*/
/*
 * _UE_get_200_response_inner.h
 *
 * 
 */

#ifndef _UE_get_200_response_inner_H_
#define _UE_get_200_response_inner_H_


#include <string>
#include <nlohmann/json.hpp>

namespace org::openapitools::server::model
{

/// <summary>
/// 
/// </summary>
class  _UE_get_200_response_inner
{
public:
    _UE_get_200_response_inner();
    virtual ~_UE_get_200_response_inner() = default;


    /// <summary>
    /// Validate the current data in the model. Throws a ValidationException on failure.
    /// </summary>
    void validate() const;

    /// <summary>
    /// Validate the current data in the model. Returns false on error and writes an error
    /// message into the given stringstream.
    /// </summary>
    bool validate(std::stringstream& msg) const;

    /// <summary>
    /// Helper overload for validate. Used when one model stores another model and calls it's validate.
    /// Not meant to be called outside that case.
    /// </summary>
    bool validate(std::stringstream& msg, const std::string& pathPrefix) const;

    bool operator==(const _UE_get_200_response_inner& rhs) const;
    bool operator!=(const _UE_get_200_response_inner& rhs) const;

    /////////////////////////////////////////////
    /// _UE_get_200_response_inner members

    /// <summary>
    /// 
    /// </summary>
    std::string getIMSI() const;
    void setIMSI(std::string const& value);
    bool iMSIIsSet() const;
    void unsetIMSI();

    friend  void to_json(nlohmann::json& j, const _UE_get_200_response_inner& o);
    friend  void from_json(const nlohmann::json& j, _UE_get_200_response_inner& o);
protected:
    std::string m_IMSI;
    bool m_IMSIIsSet;
    
};

} // namespace org::openapitools::server::model

#endif /* _UE_get_200_response_inner_H_ */