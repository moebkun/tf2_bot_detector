#pragma once

#include "Clock.h"

#include <memory>
#include <vector>

namespace tf2_bot_detector
{
	class IAction;
	class ActionManager;

	class IPeriodicAction
	{
	public:
		virtual ~IPeriodicAction() = default;

		virtual duration_t GetInterval() const = 0;

		[[nodiscard]] virtual bool Execute(ActionManager& manager) = 0;
	};

	class StatusUpdateAction final : public IPeriodicAction
	{
	public:
		duration_t GetInterval() const override;
		bool Execute(ActionManager& manager) override;

	private:
		bool m_NextShort = false;
	};
}
