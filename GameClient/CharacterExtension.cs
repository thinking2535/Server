using rso.physics;

public static class CCharacterExtension
{
    public static bool IsAlive(this SCharacter Char_)
    {
        return (Char_.BalloonCount >= 0);
    }
    public static float GetMaxVelDown(this SCharacter Char_, SCharacterMeta Meta_)
    {
        if (Char_.BalloonCount > 0)
            return -Meta_.MaxVelDown;
        else if (Char_.BalloonCount == 0)
            return -global.c_MaxVelParachuteY;
        else
            return -global.c_MaxVelDeadY;
    }
    public static void FixedUpdate(this SCharacter Char_, SCharacterMeta Meta_, float DeltaTime_)
    {
    }
    public static void Center(this SCharacter Char_) // 조이패드 중앙
    {
        Char_.Dir = 0;
        Char_.Acc.X = 0.0f;
    }
    public static void LeftRight(this SCharacter Char_, SCharacterMeta Meta_, sbyte Dir_)
    {
    }
    public static void Fly(this SCharacter Char_)
    {
    }
    public static void Land(this SCharacter Char_, SCharacterMeta Meta_)
    {
        Char_.IsGround = true;
        Char_.Acc.X = Meta_.RunAcc * Char_.Dir;
    }
    public static bool Flap(this SCharacter Char_, SCharacterMeta Meta_)
    {
        return true;
    }
    static void Die(this SCharacter Char_)
    {
    }
    public static void RecvHit(this SCharacter Char_, sbyte TargetCollisionDir_)
    {
    }
    public static SRect GetBodyRect(this SPoint Pos_)
    {
        return new SRect();
    }
}