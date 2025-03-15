#pragma once

#include <string>

#include <zgl/image/image.hpp>

class STBImage : public Image
{
    public:
        STBImage(const std::string& imagePath); 
        virtual ~STBImage() override;

    protected:
        int m_Channels;

};