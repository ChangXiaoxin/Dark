#pragma once

#include "Event.h"

namespace Dark {

	class DARK_API GamepadEvent : public Event
	{
	public:
		EVENT_CALSS_CATEGORY(EventCategoryGamepad | EventCategoryInput)
			inline int GetGamepadId() const { return m_GamepadId; }
	protected:
		GamepadEvent(int jid)
			: m_GamepadId(jid)
		{
		}
	protected:
		int m_GamepadId;
	};

	class DARK_API GamepadConnectedEvent : public GamepadEvent
	{
	public:
		GamepadConnectedEvent(int jid)
			: GamepadEvent(jid)
		{
		}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "GamepadConnectedEvent: " << m_GamepadId << " connected!";
			return ss.str();
		}
		EVENT_CLASS_TYPE(GamepadConnected)
	};

	class DARK_API GamepadDisconnectedEvent : public GamepadEvent
	{
	public:
		GamepadDisconnectedEvent(int jid)
			: GamepadEvent(jid)
		{
		}


		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "GamepadDisconnectedEvent: " << m_GamepadId << " disconnected!";
			return ss.str();
		}
		EVENT_CLASS_TYPE(GamepadDisconnected)
	};

}
