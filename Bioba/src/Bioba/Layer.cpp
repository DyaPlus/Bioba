#include "biopch.h"
#include "Layer.h"


namespace Bioba {

	Layer::Layer(const LayerType& type, const std::string& name)
		: m_DebugName(name) , m_Type(type)
	{
	}

}