
#include "DeformerExample/Deformer.h"


IE_CORE_DEFINERUNTIMETYPED( DeformerExample::Deformer );

namespace DeformerExample
{

size_t Deformer::g_firstPlugIndex = 0;


Deformer::Deformer( const std::string &name , IECore::PathMatcher::Result filterDefault )
{
	storeIndexOfNextChild( g_firstPlugIndex );

	addChild( new GafferScene::ScenePlug("cageScene") );
	addChild( new Gaffer::StringPlug("cageLocation") );

	// Fast pass-throughs for things we don't modify
	outPlug()->attributesPlug()->setInput( inPlug()->attributesPlug() );
	outPlug()->transformPlug()->setInput( inPlug()->transformPlug() );
}

Deformer::~Deformer()
{
}


GafferScene::ScenePlug* Deformer::cageScenePlug()
{
	return getChild<GafferScene::ScenePlug>( g_firstPlugIndex );
}

const GafferScene::ScenePlug* Deformer::cageScenePlug() const
{
	return getChild<GafferScene::ScenePlug>( g_firstPlugIndex );
}

Gaffer::StringPlug* Deformer::cageLocationPlug()
{
	return getChild<Gaffer::StringPlug>( g_firstPlugIndex + 1);
}

const Gaffer::StringPlug* Deformer::cageLocationPlug() const
{
	return getChild<Gaffer::StringPlug>( g_firstPlugIndex + 1);
}


void Deformer::affects( const Gaffer::Plug *input, AffectedPlugsContainer &outputs ) const
{
	SceneElementProcessor::affects( input, outputs );

//	if( input == namesPlug() || input == invertNamesPlug() )
//	{
//		outputs.push_back( outPlug()->objectPlug() );
//	}

}

bool Deformer::processesBound() const
{
	return true;
}

void Deformer::hashProcessedBound( const ScenePath &path, const Gaffer::Context *context, IECore::MurmurHash &h ) const
{

}

Imath::Box3f Deformer::computeProcessedBound( const ScenePath &path, const Gaffer::Context *context, const Imath::Box3f &inputBound ) const
{

}

bool Deformer::processesObject() const
{
	return true;
}

void Deformer::hashProcessedObject( const ScenePath &path, const Gaffer::Context *context, IECore::MurmurHash &h ) const
{

}

IECore::ConstObjectPtr Deformer::computeProcessedObject( const ScenePath &path, const Gaffer::Context *context, IECore::ConstObjectPtr inputObject ) const
{

}


} // namespace DeformerExample