#include "stdafx.h"

CFlyAwayObject::CFlyAwayObject(const STransform& Transform_, int32 objectNumber, SRectCollider2D Collider_) :
    CRectCollider2D(Transform_, objectNumber, Collider_)
{
}