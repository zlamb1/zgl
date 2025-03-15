#pragma once

#include <zgl/camera.hpp>
#include <zgl/ref.hpp>
#include <zgl/time.hpp>

#include <zgl/event/callback.hpp>
#include <zgl/event/mouse.hpp>
#include <zgl/event/window.hpp>

#include <zgl/render/render.hpp>
#include <zgl/render/shader.hpp>

#include <zgl/window/window.hpp>

class Application
{
    public:
        Application(ZG::RenderCore& renderCore) : m_RenderCore(renderCore) {};
        virtual ~Application() = default;

        virtual void RunApp() = 0;

        virtual bool IsInitialized() { return m_Initialized; }
        virtual bool IsRunning() { return m_Running; }

    protected:
        ZG::RenderCore& m_RenderCore; 

        bool m_Initialized = true;
        bool m_Running = true;

};