/**
* E2 Node API
* No description provided (generated by Openapi Generator https://github.com/openapitools/openapi-generator)
*
* The version of the OpenAPI document: 1.0
* 
*
* NOTE: This class is auto generated by OpenAPI Generator (https://openapi-generator.tech).
* https://openapi-generator.tech
* Do not edit the class manually.
*/


#include "_endpoints_get_200_response.h"
#include "Helpers.h"

#include <sstream>

namespace org::openapitools::server::model
{

_endpoints_get_200_response::_endpoints_get_200_response()
{
    m_EndpointsIsSet = false;
    
}

void _endpoints_get_200_response::validate() const
{
    std::stringstream msg;
    if (!validate(msg))
    {
        throw org::openapitools::server::helpers::ValidationException(msg.str());
    }
}

bool _endpoints_get_200_response::validate(std::stringstream& msg) const
{
    return validate(msg, "");
}

bool _endpoints_get_200_response::validate(std::stringstream& msg, const std::string& pathPrefix) const
{
    bool success = true;
    const std::string _pathPrefix = pathPrefix.empty() ? "_endpoints_get_200_response" : pathPrefix;

         
    if (endpointsIsSet())
    {
        const std::vector<org::openapitools::server::model::_endpoints_get_200_response_endpoints_inner>& value = m_Endpoints;
        const std::string currentValuePath = _pathPrefix + ".endpoints";
                
        
        { // Recursive validation of array elements
            const std::string oldValuePath = currentValuePath;
            int i = 0;
            for (const org::openapitools::server::model::_endpoints_get_200_response_endpoints_inner& value : value)
            { 
                const std::string currentValuePath = oldValuePath + "[" + std::to_string(i) + "]";
                        
        success = value.validate(msg, currentValuePath + ".endpoints") && success;
 
                i++;
            }
        }

    }
    
    return success;
}

bool _endpoints_get_200_response::operator==(const _endpoints_get_200_response& rhs) const
{
    return
    
    
    
    ((!endpointsIsSet() && !rhs.endpointsIsSet()) || (endpointsIsSet() && rhs.endpointsIsSet() && getEndpoints() == rhs.getEndpoints()))
    
    ;
}

bool _endpoints_get_200_response::operator!=(const _endpoints_get_200_response& rhs) const
{
    return !(*this == rhs);
}

void to_json(nlohmann::json& j, const _endpoints_get_200_response& o)
{
    j = nlohmann::json::object();
    if(o.endpointsIsSet() || !o.m_Endpoints.empty())
        j["endpoints"] = o.m_Endpoints;
    
}

void from_json(const nlohmann::json& j, _endpoints_get_200_response& o)
{
    if(j.find("endpoints") != j.end())
    {
        j.at("endpoints").get_to(o.m_Endpoints);
        o.m_EndpointsIsSet = true;
    } 
    
}

std::vector<org::openapitools::server::model::_endpoints_get_200_response_endpoints_inner> _endpoints_get_200_response::getEndpoints() const
{
    return m_Endpoints;
}
void _endpoints_get_200_response::setEndpoints(std::vector<org::openapitools::server::model::_endpoints_get_200_response_endpoints_inner> const& value)
{
    m_Endpoints = value;
    m_EndpointsIsSet = true;
}
bool _endpoints_get_200_response::endpointsIsSet() const
{
    return m_EndpointsIsSet;
}
void _endpoints_get_200_response::unsetEndpoints()
{
    m_EndpointsIsSet = false;
}


} // namespace org::openapitools::server::model

