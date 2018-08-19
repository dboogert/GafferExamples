import GafferUI
import DeformerExample

nodeMenu = GafferUI.NodeMenu.acquire( application )
nodeMenu.append( "/DeformerExample/Deformer", DeformerExample.Deformer, searchText = "ExampleDeformer.Deformer" )
