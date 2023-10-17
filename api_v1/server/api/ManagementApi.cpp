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

#include "ManagementApi.h"
#include "Helpers.h"

namespace org::openapitools::server::api
{

using namespace org::openapitools::server::helpers;
using namespace org::openapitools::server::model;

const std::string ManagementApi::base = "/v1";

ManagementApi::ManagementApi(const std::shared_ptr<Pistache::Rest::Router>& rtr)
    : ApiBase(rtr)
{
}

void ManagementApi::init() {
    setupRoutes();
}

void ManagementApi::setupRoutes() {
    using namespace Pistache::Rest;

    Routes::Delete(*router, base + "/UE/:iMSI/admission", Routes::bind(&ManagementApi::u_eimsi_admission_delete_handler, this));
    Routes::Put(*router, base + "/UE/:iMSI/admission", Routes::bind(&ManagementApi::u_eimsi_admission_put_handler, this));
    Routes::Put(*router, base + "/UE/:iMSI/anr", Routes::bind(&ManagementApi::u_eimsi_anr_put_handler, this));
    Routes::Put(*router, base + "/UE/:iMSI/flow", Routes::bind(&ManagementApi::u_eimsi_flow_put_handler, this));

    // Default handler, called when a route is not found
    router->addCustomHandler(Routes::bind(&ManagementApi::management_api_default_handler, this));
}

std::pair<Pistache::Http::Code, std::string> ManagementApi::handleParsingException(const std::exception& ex) const noexcept
{
    try {
        throw;
    } catch (nlohmann::detail::exception &e) {
        return std::make_pair(Pistache::Http::Code::Bad_Request, e.what());
    } catch (org::openapitools::server::helpers::ValidationException &e) {
        return std::make_pair(Pistache::Http::Code::Bad_Request, e.what());
    } catch (std::exception &e) {
        return std::make_pair(Pistache::Http::Code::Internal_Server_Error, e.what());
    }
}

std::pair<Pistache::Http::Code, std::string> ManagementApi::handleOperationException(const std::exception& ex) const noexcept
{
    return std::make_pair(Pistache::Http::Code::Internal_Server_Error, ex.what());
}

void ManagementApi::u_eimsi_admission_delete_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response) {
    try {

    // Getting the path params
    auto iMSI = request.param(":iMSI").as<std::string>();
    
    try {
        this->u_eimsi_admission_delete(iMSI, response);
    } catch (Pistache::Http::HttpError &e) {
        response.send(static_cast<Pistache::Http::Code>(e.code()), e.what());
        return;
    } catch (std::exception &e) {
        const std::pair<Pistache::Http::Code, std::string> errorInfo = this->handleOperationException(e);
        response.send(errorInfo.first, errorInfo.second);
        return;
    }

    } catch (std::exception &e) {
        response.send(Pistache::Http::Code::Internal_Server_Error, e.what());
    }

}
void ManagementApi::u_eimsi_admission_put_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response) {
    try {

    // Getting the path params
    auto iMSI = request.param(":iMSI").as<std::string>();
    
    // Getting the body param
    
    Ue_descriptor ueDescriptor;
    
    try {
        nlohmann::json::parse(request.body()).get_to(ueDescriptor);
        ueDescriptor.validate();
    } catch (std::exception &e) {
        const std::pair<Pistache::Http::Code, std::string> errorInfo = this->handleParsingException(e);
        response.send(errorInfo.first, errorInfo.second);
        return;
    }

    try {
        this->u_eimsi_admission_put(iMSI, ueDescriptor, response);
    } catch (Pistache::Http::HttpError &e) {
        response.send(static_cast<Pistache::Http::Code>(e.code()), e.what());
        return;
    } catch (std::exception &e) {
        const std::pair<Pistache::Http::Code, std::string> errorInfo = this->handleOperationException(e);
        response.send(errorInfo.first, errorInfo.second);
        return;
    }

    } catch (std::exception &e) {
        response.send(Pistache::Http::Code::Internal_Server_Error, e.what());
    }

}
void ManagementApi::u_eimsi_anr_put_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response) {
    try {

    // Getting the path params
    auto iMSI = request.param(":iMSI").as<std::string>();
    
    // Getting the body param
    
    _UE__iMSI__anr_put_request uEIMSIAnrPutRequest;
    
    try {
        nlohmann::json::parse(request.body()).get_to(uEIMSIAnrPutRequest);
        uEIMSIAnrPutRequest.validate();
    } catch (std::exception &e) {
        const std::pair<Pistache::Http::Code, std::string> errorInfo = this->handleParsingException(e);
        response.send(errorInfo.first, errorInfo.second);
        return;
    }

    try {
        this->u_eimsi_anr_put(iMSI, uEIMSIAnrPutRequest, response);
    } catch (Pistache::Http::HttpError &e) {
        response.send(static_cast<Pistache::Http::Code>(e.code()), e.what());
        return;
    } catch (std::exception &e) {
        const std::pair<Pistache::Http::Code, std::string> errorInfo = this->handleOperationException(e);
        response.send(errorInfo.first, errorInfo.second);
        return;
    }

    } catch (std::exception &e) {
        response.send(Pistache::Http::Code::Internal_Server_Error, e.what());
    }

}
void ManagementApi::u_eimsi_flow_put_handler(const Pistache::Rest::Request &request, Pistache::Http::ResponseWriter response) {
    try {

    // Getting the path params
    auto iMSI = request.param(":iMSI").as<std::string>();
    
    // Getting the body param
    
    _UE__iMSI__flow_put_request uEIMSIFlowPutRequest;
    
    try {
        nlohmann::json::parse(request.body()).get_to(uEIMSIFlowPutRequest);
        uEIMSIFlowPutRequest.validate();
    } catch (std::exception &e) {
        const std::pair<Pistache::Http::Code, std::string> errorInfo = this->handleParsingException(e);
        response.send(errorInfo.first, errorInfo.second);
        return;
    }

    try {
        this->u_eimsi_flow_put(iMSI, uEIMSIFlowPutRequest, response);
    } catch (Pistache::Http::HttpError &e) {
        response.send(static_cast<Pistache::Http::Code>(e.code()), e.what());
        return;
    } catch (std::exception &e) {
        const std::pair<Pistache::Http::Code, std::string> errorInfo = this->handleOperationException(e);
        response.send(errorInfo.first, errorInfo.second);
        return;
    }

    } catch (std::exception &e) {
        response.send(Pistache::Http::Code::Internal_Server_Error, e.what());
    }

}

void ManagementApi::management_api_default_handler(const Pistache::Rest::Request &, Pistache::Http::ResponseWriter response) {
    response.send(Pistache::Http::Code::Not_Found, "The requested method does not exist");
}

} // namespace org::openapitools::server::api

