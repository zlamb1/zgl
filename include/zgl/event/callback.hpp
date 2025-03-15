#pragma once

#include <functional>

#include <zgl/ref.hpp>

#include <zgl/event/event.hpp>

namespace ZG
{
    class EventHandler
    {
        public:
            virtual ~EventHandler() = default;

            virtual void OnEvent(Ref<ZG::Event> event) = 0;  
    };

    template<typename T>
    class EventCallback : public EventHandler
    {
        using CallbackFunction = std::function<void(Ref<T>)>; 

        public:
            EventCallback(CallbackFunction callback)
            {
                m_Callback = callback; 
            }

            virtual void OnEvent(Ref<ZG::Event> event) override
            {
                auto derivedEvent = std::dynamic_pointer_cast<T>(event); 
                m_Callback(derivedEvent); 
            }

        protected:
            CallbackFunction m_Callback;

    };
};