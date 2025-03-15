#pragma once

#include <zgl/event/event.hpp>
#include <zgl/event/window.hpp>

#include <zgl/window/kb.hpp>

namespace ZG
{
    class KeyPressEvent : public ZG::WindowEvent
    {
        public:
            KeyPressEvent(Ref<Window> window, KeyAction keyAction, KeyCode keyCode) : WindowEvent(window)
            {
                m_KeyAction = keyAction;
                m_KeyCode = keyCode;
            }

            virtual EventType GetEventType() const override { return EventType::KeyPress; }

            virtual KeyAction GetKeyAction() const { return m_KeyAction; }
            virtual KeyCode GetKeyCode() const { return m_KeyCode; }

        protected:
            KeyAction m_KeyAction;
            KeyCode m_KeyCode;

    };
};