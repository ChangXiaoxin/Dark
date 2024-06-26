#pragma once

#include "Event.h"

namespace Dark {

	class DARK_API WindowResizedEvent : public Event
	{
	public:
		WindowResizedEvent(unsigned int width, unsigned int height)
			: m_Width(width), m_Height(height)
		{
		}

		inline unsigned int GetWidth() const { return m_Width; }
		inline unsigned int GetHeight() const { return m_Height; }
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizedEvent: " << m_Width << ", " << m_Height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CALSS_CATEGORY(EventCategoryInput)

	private:
		unsigned int m_Width, m_Height;
	};

	class DARK_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowClose)
	    EVENT_CALSS_CATEGORY(EventCategoryApplication)
	};

	class DARK_API AppTickEvent : public Event
	{
	public:
		AppTickEvent() {}

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CALSS_CATEGORY(EventCategoryApplication)
	};

	class DARK_API AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() {}

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CALSS_CATEGORY(EventCategoryApplication)
	};
	
	class DARK_API AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() {}

		EVENT_CLASS_TYPE(AppRender)
        EVENT_CALSS_CATEGORY(EventCategoryApplication)
	};
}
