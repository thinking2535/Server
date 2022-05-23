using rso.core;
using rso.game;
using rso.gameutil;
using System;

public static class NetProtocolExtension
{
    public static STimeBoost ZeroTimeBoost = new STimeBoost();
    public static TimePoint ZeroTimePoint = new TimePoint(0);
    public static int[] ZeroResources = new int[(int)EResource.Max];

    public static bool IsSame(this int[] lhs_, int[] rhs_)
    {
        if (lhs_.Length != rhs_.Length)
            throw new Exception("Invalid Resources Size");

        for (int i = 0; i < lhs_.Length; ++i)
            if (lhs_[i] != rhs_[i])
                return false;

        return true;
    }
    public static int[] Copy(this int[] lhs_)
    {
        int[] ret = new int[lhs_.Length];

        for (int i = 0; i < lhs_.Length; ++i)
            ret[i] = lhs_[i];

        return ret;
    }
    public static int[] Clear(this int[] lhs_)
    {
        for (int i = 0; i < lhs_.Length; ++i)
            lhs_[i] = 0;

        return lhs_;
    }
    public static int[] Set(this int[] lhs_, int[] rhs_)
    {
        for (int i = 0; i < lhs_.Length; ++i)
            lhs_[i] = rhs_[i];

        return lhs_;
    }
    public static int[] Limit(this int[] lhs_, int[] rhs_)
    {
        for (int i = 0; i < lhs_.Length; ++i)
        {
            if (lhs_[i] < 0)
                lhs_[i] = 0;
            else if (lhs_[i] > rhs_[i])
                lhs_[i] = rhs_[i];
        }

        return lhs_;
    }
    public static int[] Add(this int[] lhs_, int[] rhs_)
    {
        for (int i = 0; i < lhs_.Length; ++i)
            lhs_[i] += rhs_[i];

        return lhs_;
    }
    public static int[] GetAdd(this int[] lhs_, int[] rhs_)
    {
        return lhs_.Copy().Add(rhs_);
    }
    public static int[] Sub(this int[] lhs_, int[] rhs_)
    {
        for (int i = 0; i < lhs_.Length; ++i)
            lhs_[i] -= rhs_[i];

        return lhs_;
    }
    public static int[] GetSub(this int[] lhs_, int[] rhs_)
    {
        return lhs_.Copy().Sub(rhs_);
    }
    public static int[] Multi(this int[] lhs_, int[] rhs_)
    {
        for (int i = 0; i < lhs_.Length; ++i)
            lhs_[i] *= rhs_[i];

        return lhs_;
    }
    public static int[] GetMulti(this int[] lhs_, int[] rhs_)
    {
        return lhs_.Copy().Multi(rhs_);
    }
    public static int[] Multi(this int[] lhs_, int rhs_)
    {
        for (int i = 0; i < lhs_.Length; ++i)
            lhs_[i] *= rhs_;

        return lhs_;
    }
    public static int[] GetMulti(this int[] lhs_, int rhs_)
    {
        return lhs_.Copy().Multi(rhs_);
    }
    public static int[] Div(this int[] lhs_, int[] rhs_)
    {
        for (int i = 0; i < lhs_.Length; ++i)
        {
            if (rhs_[i] == 0)
                continue;

            lhs_[i] /= rhs_[i];
        }

        return lhs_;
    }
    public static int[] GetDiv(this int[] lhs_, int[] rhs_)
    {
        return lhs_.Copy().Div(rhs_);
    }
    public static int[] Div(this int[] lhs_, int rhs_)
    {
        for (int i = 0; i < lhs_.Length; ++i)
        {
            if (rhs_ == 0)
                continue;

            lhs_[i] /= rhs_;
        }

        return lhs_;
    }
    public static int[] GetDiv(this int[] lhs_, int rhs_)
    {
        return lhs_.Copy().Div(rhs_);
    }
    public static bool GreaterThan(this int[] lhs_, int[] rhs_)
    {
        bool HaveGreater = false;
        for (int i = 0; i < lhs_.Length; ++i)
        {
            if (lhs_[i] < rhs_[i])
                return false;

            if (lhs_[i] > rhs_[i])
                HaveGreater = true;
        }

        return HaveGreater;
    }
    public static bool GreaterThanEqual(this int[] lhs_, int[] rhs_)
    {
        for (int i = 0; i < lhs_.Length; ++i)
            if (lhs_[i] < rhs_[i])
                return false;

        return true;
    }
    public static string ToArrayString(this int[] lhs_)
    {
        string ret = "[";

        if (lhs_.Length > 0)
            ret += lhs_[0].ToString();

        for (int i = 1; i < lhs_.Length; ++i)
        {
            ret += ", ";
            ret += lhs_[i].ToString();
        }

        ret += ']';

        return ret;
    }
    public static int[] MakeResources()
    {
        return new int[(int)EResource.Max];
    }
    public static int[] MakeResources(EResource Type_, int Value_)
    {
        var Resources = MakeResources();
        Resources[(int)Type_] = Value_;
        return Resources;
    }
    public static int[] MakeResources(this SResourceTypeData ResourceTypeData_)
    {
        return MakeResources(ResourceTypeData_.Type, ResourceTypeData_.Data);
    }
    public static int GetResources(this int[] resources, EResource eResource)
    {
        return resources[(int)eResource];
    }

    public static Int64 c_TicksPerHour = 36000000000;

    public static bool IsEqual(this SVersion Lhs_, SVersion Rhs_)
    {
        return (Lhs_.Main == Rhs_.Main && Lhs_.Data == Rhs_.Data);
    }
    public static bool IsAlive(this SBattlePlayer Player_)
    {
        return true;
    }

    public static void AddResources(this int[] Resources_, int[] Added_)
    {
        for (int i = 0; i < Resources_.Length; ++i)
        {
            if (Resources_[i] + Added_[i] < 0)
            {
                if (Added_[i] > 0)
                    Resources_[i] = int.MaxValue;
                else
                    Resources_[i] = 0;
            }
            else
            {
                Resources_[i] += Added_[i];
            }
        }
    }
    public static void AddResource(this int[] Resources_, EResource Resource_, int Data_)
    {
        if (Resources_[(int)Resource_] + Data_ < 0)
        {
            if (Data_ > 0)
                Resources_[(int)Resource_] = int.MaxValue;
            else
                Resources_[(int)Resource_] = 0;
        }
        else
        {
            Resources_[(int)Resource_] += Data_;
        }
    }

}
