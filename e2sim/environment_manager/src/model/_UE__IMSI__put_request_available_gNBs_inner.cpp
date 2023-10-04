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


#include "_UE__IMSI__put_request_available_gNBs_inner.h"
#include "Helpers.h"

#include <sstream>

namespace org::openapitools::server::model
{

_UE__IMSI__put_request_available_gNBs_inner::_UE__IMSI__put_request_available_gNBs_inner()
{
    m_GNB_ID = "";
    m_GNB_RSRP = 0;
    m_GNB_RSSI = 0;
    m_GNB_RSSIIsSet = false;
    m_GNB_RSRQ = 0;
    m_GNB_RSRQIsSet = false;
    m_Connected = false;
    m_ConnectedIsSet = false;
    
}

void _UE__IMSI__put_request_available_gNBs_inner::validate() const
{
    std::stringstream msg;
    if (!validate(msg))
    {
        throw org::openapitools::server::helpers::ValidationException(msg.str());
    }
}

bool _UE__IMSI__put_request_available_gNBs_inner::validate(std::stringstream& msg) const
{
    return validate(msg, "");
}

bool _UE__IMSI__put_request_available_gNBs_inner::validate(std::stringstream& msg, const std::string& pathPrefix) const
{
    bool success = true;
    const std::string _pathPrefix = pathPrefix.empty() ? "_UE__IMSI__put_request_available_gNBs_inner" : pathPrefix;

                        
    return success;
}

bool _UE__IMSI__put_request_available_gNBs_inner::operator==(const _UE__IMSI__put_request_available_gNBs_inner& rhs) const
{
    return
    
    
    (getGNBID() == rhs.getGNBID())
     &&
    
    (getGNBRSRP() == rhs.getGNBRSRP())
     &&
    
    
    ((!gNBRSSIIsSet() && !rhs.gNBRSSIIsSet()) || (gNBRSSIIsSet() && rhs.gNBRSSIIsSet() && getGNBRSSI() == rhs.getGNBRSSI())) &&
    
    
    ((!gNBRSRQIsSet() && !rhs.gNBRSRQIsSet()) || (gNBRSRQIsSet() && rhs.gNBRSRQIsSet() && getGNBRSRQ() == rhs.getGNBRSRQ())) &&
    
    
    ((!connectedIsSet() && !rhs.connectedIsSet()) || (connectedIsSet() && rhs.connectedIsSet() && isConnected() == rhs.isConnected()))
    
    ;
}

bool _UE__IMSI__put_request_available_gNBs_inner::operator!=(const _UE__IMSI__put_request_available_gNBs_inner& rhs) const
{
    return !(*this == rhs);
}

void to_json(nlohmann::json& j, const _UE__IMSI__put_request_available_gNBs_inner& o)
{
    j = nlohmann::json::object();
    j["gNB_ID"] = o.m_GNB_ID;
    j["gNB_RSRP"] = o.m_GNB_RSRP;
    if(o.gNBRSSIIsSet())
        j["gNB_RSSI"] = o.m_GNB_RSSI;
    if(o.gNBRSRQIsSet())
        j["gNB_RSRQ"] = o.m_GNB_RSRQ;
    if(o.connectedIsSet())
        j["connected"] = o.m_Connected;
    
}

void from_json(const nlohmann::json& j, _UE__IMSI__put_request_available_gNBs_inner& o)
{
    j.at("gNB_ID").get_to(o.m_GNB_ID);
    j.at("gNB_RSRP").get_to(o.m_GNB_RSRP);
    if(j.find("gNB_RSSI") != j.end())
    {
        j.at("gNB_RSSI").get_to(o.m_GNB_RSSI);
        o.m_GNB_RSSIIsSet = true;
    } 
    if(j.find("gNB_RSRQ") != j.end())
    {
        j.at("gNB_RSRQ").get_to(o.m_GNB_RSRQ);
        o.m_GNB_RSRQIsSet = true;
    } 
    if(j.find("connected") != j.end())
    {
        j.at("connected").get_to(o.m_Connected);
        o.m_ConnectedIsSet = true;
    } 
    
}

std::string _UE__IMSI__put_request_available_gNBs_inner::getGNBID() const
{
    return m_GNB_ID;
}
void _UE__IMSI__put_request_available_gNBs_inner::setGNBID(std::string const& value)
{
    m_GNB_ID = value;
}
int32_t _UE__IMSI__put_request_available_gNBs_inner::getGNBRSRP() const
{
    return m_GNB_RSRP;
}
void _UE__IMSI__put_request_available_gNBs_inner::setGNBRSRP(int32_t const value)
{
    m_GNB_RSRP = value;
}
int32_t _UE__IMSI__put_request_available_gNBs_inner::getGNBRSSI() const
{
    return m_GNB_RSSI;
}
void _UE__IMSI__put_request_available_gNBs_inner::setGNBRSSI(int32_t const value)
{
    m_GNB_RSSI = value;
    m_GNB_RSSIIsSet = true;
}
bool _UE__IMSI__put_request_available_gNBs_inner::gNBRSSIIsSet() const
{
    return m_GNB_RSSIIsSet;
}
void _UE__IMSI__put_request_available_gNBs_inner::unsetGNB_RSSI()
{
    m_GNB_RSSIIsSet = false;
}
int32_t _UE__IMSI__put_request_available_gNBs_inner::getGNBRSRQ() const
{
    return m_GNB_RSRQ;
}
void _UE__IMSI__put_request_available_gNBs_inner::setGNBRSRQ(int32_t const value)
{
    m_GNB_RSRQ = value;
    m_GNB_RSRQIsSet = true;
}
bool _UE__IMSI__put_request_available_gNBs_inner::gNBRSRQIsSet() const
{
    return m_GNB_RSRQIsSet;
}
void _UE__IMSI__put_request_available_gNBs_inner::unsetGNB_RSRQ()
{
    m_GNB_RSRQIsSet = false;
}
bool _UE__IMSI__put_request_available_gNBs_inner::isConnected() const
{
    return m_Connected;
}
void _UE__IMSI__put_request_available_gNBs_inner::setConnected(bool const value)
{
    m_Connected = value;
    m_ConnectedIsSet = true;
}
bool _UE__IMSI__put_request_available_gNBs_inner::connectedIsSet() const
{
    return m_ConnectedIsSet;
}
void _UE__IMSI__put_request_available_gNBs_inner::unsetConnected()
{
    m_ConnectedIsSet = false;
}


} // namespace org::openapitools::server::model

