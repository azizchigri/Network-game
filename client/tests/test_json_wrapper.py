#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Jun 10 16:51:40 2018

@author: azizc
"""

import unittest
from ia.json_wrapper import JsonObject

class Human(JsonObject):
    """Human test class"""
    def __init__(self):
        self.age = 19
        self.name = "Jean"
        self.surname = "Dupont"

class SerializerTest(unittest.TestCase):
    """Test case for testing JsonObject module"""
    def test_serializer(self):
        result = str(Human())
        expected = '{\n    "age": 19,\n    "name": "Jean",'
        expected += '\n    "surname": "Dupont"\n}'
        self.assertEqual(result, expected)
        
        

