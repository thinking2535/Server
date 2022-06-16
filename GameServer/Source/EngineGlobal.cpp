#include "stdafx.h"

float CEngineGlobal::BalloonWidth(int8 BalloonCount_)
{
    if (BalloonCount_ > c_BalloonCountForRegen)
        BalloonCount_ = 2;
    else if (BalloonCount_ < 0)
        BalloonCount_ = 0;

    return c_BalloonWidth * BalloonCount_;
}

