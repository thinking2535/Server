#pragma once

struct ResourceTypeData : public SResourceTypeData
{
	ResourceTypeData()
	{
	}
	ResourceTypeData(const SResourceTypeData& super) :
		SResourceTypeData(super)
	{
	}
	ResourceTypeData(const EResource& type, const TResource& data) :
		SResourceTypeData(type, data)
	{
	}
	ResourceTypeData operator - (const SResourceTypeData& value) const
	{
		auto ret = *this;
		ret.Data -= value.Data;
		return ret;
	}
	ResourceTypeData operator - () const
	{
		auto ret = *this;
		ret.Data = -ret.Data;
		return ret;
	}
};