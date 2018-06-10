#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Jun 10 16:30:01 2018

@author: azizc
"""

import json

"""
    The ``json_wrapper`` module
    ==========================

    Use it to serialize your object to json

"""

    
class JsonObject():
    """
        JsonObject class
        ---------------
        This mother class allow your object to be serialized into json

    """
    def __init__(self):
        pass
    
    def __str__(self):
        """
            Serialize the class into json object
        """
        return json.dumps(self, default=lambda o: o.__dict__, 
            sort_keys=True, indent=4)
        
