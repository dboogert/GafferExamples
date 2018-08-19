#include "GafferScene/SceneElementProcessor.h"
#include "GafferScene/ScenePlug.h"

#include "Gaffer/ValuePlug.h"
#include "Gaffer/StringPlug.h"

namespace DeformerExample
{

	enum DeformerTypeId
	{
		DeformerTypeId = 120000,
	};

	class Deformer : public GafferScene::SceneElementProcessor
	{
	public:
		Deformer(const std::string &name = defaultName<Deformer>(),
				 IECore::PathMatcher::Result filterDefault = IECore::PathMatcher::EveryMatch);

		~Deformer();

		IE_CORE_DECLARERUNTIMETYPEDEXTENSION(DeformerExample::Deformer, DeformerTypeId,
											 GafferScene::SceneElementProcessor);

		GafferScene::ScenePlug *cageScenePlug();

		const GafferScene::ScenePlug *cageScenePlug() const;

		Gaffer::StringPlug *cageLocationPlug();

		const Gaffer::StringPlug *cageLocationPlug() const;

		void affects(const Gaffer::Plug *input, AffectedPlugsContainer &outputs) const override;

		bool processesBound() const override;

		void
		hashProcessedBound(const ScenePath &path, const Gaffer::Context *context, IECore::MurmurHash &h) const override;

		Imath::Box3f computeProcessedBound(const ScenePath &path, const Gaffer::Context *context,
										   const Imath::Box3f &inputBound) const override;

		bool processesObject() const override;

		void hashProcessedObject(const ScenePath &path, const Gaffer::Context *context,
								 IECore::MurmurHash &h) const override;

		IECore::ConstObjectPtr computeProcessedObject(const ScenePath &path, const Gaffer::Context *context,
													  IECore::ConstObjectPtr inputObject) const override;

	private :

		static size_t g_firstPlugIndex;

	};
}