#include "boost/python.hpp"

#include "DeformerExample/Deformer.h"

#include "GafferBindings/DependencyNodeBinding.h"

using namespace boost::python;
using namespace GafferScene;

BOOST_PYTHON_MODULE( _deformerExample )
{
	GafferBindings::DependencyNodeClass<DeformerExample::Deformer>();
}
