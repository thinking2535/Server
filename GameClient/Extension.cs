using rso.physics;
using UnityEngine;

public static class Extension
{
    public static Vector2 ToVector2(this SPoint Point_)
    {
        return new Vector2((float)Point_.X, (float)Point_.Y);
    }
    public static void Set(this SPoint Point_, Vector2 Vec_)
    {
        Point_.X = Vec_.x;
        Point_.Y = Vec_.y;
    }
    public static void Collide(this SCharacter Char_, Rigidbody2D Rigidbody_)
    {
    }
    public static void FixedUpdate(this SCharacter Char_, SCharacterMeta Meta_)
    {
    }
}