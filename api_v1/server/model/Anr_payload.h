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
 * Anr_payload.h
 *
 * 
 */

#ifndef Anr_payload_H_
#define Anr_payload_H_


#include "Nodeb_descriptor.h"
#include <nlohmann/json.hpp>

namespace org::openapitools::server::model
{

/// <summary>
/// 
/// </summary>
class  Anr_payload
{
public:
    Anr_payload();
    virtual ~Anr_payload() = default;


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

    bool operator==(const Anr_payload& rhs) const;
    bool operator!=(const Anr_payload& rhs) const;

    /////////////////////////////////////////////
    /// Anr_payload members

    /// <summary>
    /// 
    /// </summary>
    org::openapitools::server::model::Nodeb_descriptor getNodeb() const;
    void setNodeb(org::openapitools::server::model::Nodeb_descriptor const& value);
    bool nodebIsSet() const;
    void unsetNodeb();
    /// <summary>
    /// 
    /// </summary>
    double getRSRP() const;
    void setRSRP(double const value);
    bool rSRPIsSet() const;
    void unsetRSRP();
    /// <summary>
    /// 
    /// </summary>
    double getRSRQ() const;
    void setRSRQ(double const value);
    bool rSRQIsSet() const;
    void unsetRSRQ();
    /// <summary>
    /// 
    /// </summary>
    double getSINR() const;
    void setSINR(double const value);
    bool sINRIsSet() const;
    void unsetSINR();
    /// <summary>
    /// 
    /// </summary>
    double getCQI() const;
    void setCQI(double const value);
    bool cQIIsSet() const;
    void unsetCQI();
    /// <summary>
    /// 
    /// </summary>
    double getBLER() const;
    void setBLER(double const value);
    bool bLERIsSet() const;
    void unsetBLER();

    friend  void to_json(nlohmann::json& j, const Anr_payload& o);
    friend  void from_json(const nlohmann::json& j, Anr_payload& o);
protected:
    org::openapitools::server::model::Nodeb_descriptor m_Nodeb;
    bool m_NodebIsSet;
    double m_RSRP;
    bool m_RSRPIsSet;
    double m_RSRQ;
    bool m_RSRQIsSet;
    double m_SINR;
    bool m_SINRIsSet;
    double m_CQI;
    bool m_CQIIsSet;
    double m_BLER;
    bool m_BLERIsSet;
    
};

} // namespace org::openapitools::server::model

#endif /* Anr_payload_H_ */
