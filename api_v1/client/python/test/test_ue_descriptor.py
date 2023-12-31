# coding: utf-8

"""
    E2 Node UE API

    No description provided (generated by Openapi Generator https://github.com/openapitools/openapi-generator)

    The version of the OpenAPI document: 1.0
    Generated by OpenAPI Generator (https://openapi-generator.tech)

    Do not edit the class manually.
"""  # noqa: E501


import unittest
import datetime

from openapi_client.models.ue_descriptor import UeDescriptor  # noqa: E501

class TestUeDescriptor(unittest.TestCase):
    """UeDescriptor unit test stubs"""

    def setUp(self):
        pass

    def tearDown(self):
        pass

    def make_instance(self, include_optional) -> UeDescriptor:
        """Test UeDescriptor
            include_option is a boolean, when False only required
            params are included, when True both required and
            optional params are included """
        # uncomment below to create an instance of `UeDescriptor`
        """
        model = UeDescriptor()  # noqa: E501
        if include_optional:
            return UeDescriptor(
                data_plane_flow = openapi_client.models.data_plane_flow.data_plane_flow(
                    average_throughput = 1.337, 
                    latency = 1.337, ),
                anr_payload = [
                    openapi_client.models.anr_payload.anr_payload(
                        nodeb = openapi_client.models.nodeb_descriptor.nodeb_descriptor(
                            nodeb_id = '', ), 
                        rsrp = 1.337, 
                        rsrq = 1.337, 
                        sinr = 1.337, 
                        cqi = 1.337, 
                        bler = 1.337, )
                    ]
            )
        else:
            return UeDescriptor(
        )
        """

    def testUeDescriptor(self):
        """Test UeDescriptor"""
        # inst_req_only = self.make_instance(include_optional=False)
        # inst_req_and_optional = self.make_instance(include_optional=True)

if __name__ == '__main__':
    unittest.main()
