import IECore

import Gaffer
import DeformerExample



Gaffer.Metadata.registerNode(

    DeformerExample.Deformer,

    "description",
    """
    Describe what the node does
    """,

    plugs = {

        "cageScene" : [

            "description",
            """
            Scene which contains the low res geometry.
            """,

            "plugValueWidget:type", "",

        ],

        "cageLocaiton" : [

            "description",
            """
            Location in the cage scene which contains the cage geometry
            """,
        ],

    },

)