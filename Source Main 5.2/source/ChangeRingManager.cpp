﻿// ChangeRingManager.cpp: implementation of the CChangeRingManager class.
//////////////////////////////////////////////////////////////////////

// common
#include "stdafx.h"
#include "ZzzTexture.h"
#include "ZzzOpenData.h"
#include "ZzzBMD.h"
#include "ZzzCharacter.h"
#include "ChangeRingManager.h"
#include "LoadData.h"
#include "CharacterManager.h"

CChangeRingManager::CChangeRingManager()
{
}

CChangeRingManager::~CChangeRingManager()
{
}

void CChangeRingManager::LoadItemModel()
{
    gLoadData.AccessModel(MODEL_TRANSFORMATION_RING, L"Data\\Item\\", L"Ring", 1);
    gLoadData.AccessModel(MODEL_ELITE_TRANSFER_SKELETON_RING, L"Data\\Item\\", L"Ring", 1);
    gLoadData.AccessModel(MODEL_JACK_OLANTERN_TRANSFORMATION_RING, L"Data\\Item\\", L"Ring", 1);
    gLoadData.AccessModel(MODEL_CHRISTMAS_TRANSFORMATION_RING, L"Data\\Item\\", L"Ring", 1);
    gLoadData.AccessModel(MODEL_GAME_MASTER_TRANSFORMATION_RING, L"Data\\Item\\", L"Ring", 1);
    gLoadData.AccessModel(MODEL_SNOWMAN_TRANSFORMATION_RING, L"Data\\Item\\xmas\\", L"xmasring");
    gLoadData.AccessModel(MODEL_PANDA_TRANSFORMATION_RING, L"Data\\Item\\", L"PandaPetRing");
    gLoadData.AccessModel(MODEL_SKELETON_TRANSFORMATION_RING, L"Data\\Item\\", L"SkeletonRing");
}

void CChangeRingManager::LoadItemTexture()
{
    gLoadData.OpenTexture(MODEL_ELITE_TRANSFER_SKELETON_RING, L"Item\\");
    gLoadData.OpenTexture(MODEL_CHRISTMAS_TRANSFORMATION_RING, L"Item\\");
    gLoadData.OpenTexture(MODEL_JACK_OLANTERN_TRANSFORMATION_RING, L"Item\\");
    gLoadData.OpenTexture(MODEL_GAME_MASTER_TRANSFORMATION_RING, L"Item\\");
    gLoadData.OpenTexture(MODEL_SNOWMAN_TRANSFORMATION_RING, L"Item\\xmas\\");
    gLoadData.OpenTexture(MODEL_PANDA_TRANSFORMATION_RING, L"Item\\");
    gLoadData.OpenTexture(MODEL_SKELETON_TRANSFORMATION_RING, L"Item\\");
}

bool CChangeRingManager::CheckDarkLordHair(int iType)
{
    if ((iType >= MODEL_SKELETON1 && iType <= MODEL_SKELETON3) || iType == MODEL_SKELETON_PCBANG)
    {
        return true;
    }
    if (iType == MODEL_HALLOWEEN)
    {
        return true;
    }
    if (iType == MODEL_XMAS_EVENT_CHANGE_GIRL)
    {
        return true;
    }
    if (iType == MODEL_GM_CHARACTER)
    {
        return true;
    }
    if (iType == MODEL_CURSEDTEMPLE_ALLIED_PLAYER || iType == MODEL_CURSEDTEMPLE_ILLUSION_PLAYER)
    {
        return true;
    }
    if (iType == MODEL_XMAS2008_SNOWMAN)
    {
        return true;
    }
    if (iType == MODEL_PANDA)
    {
        return true;
    }
    if (iType == MODEL_SKELETON_CHANGED)
    {
        return true;
    }
    return false;
}

bool CChangeRingManager::CheckDarkCloak(int iClass, int iType)
{
    if (gCharacterManager.GetCharacterClass(iClass) == CLASS_DARK)
    {
        if (iType == MODEL_HALLOWEEN)
        {
            return true;
        }

        if (iType == MODEL_XMAS_EVENT_CHANGE_GIRL)
        {
            return true;
        }

        if (iType == MODEL_GM_CHARACTER)
        {
            return true;
        }

        if (iType == MODEL_XMAS2008_SNOWMAN)
        {
            return true;
        }

        if (iType == MODEL_PANDA)
        {
            return true;
        }

        if (iType == MODEL_SKELETON_CHANGED)
        {
            return true;
        }
    }

    return false;
}

bool CChangeRingManager::CheckChangeRing(short RingType)
{
    if (RingType == ITEM_HELPER + 10)
    {
        return true;
    }
    if (RingType == ITEM_HELPER + 39)
    {
        return true;
    }
    if (RingType == ITEM_HELPER + 40)
    {
        return true;
    }
    if (RingType == ITEM_HELPER + 41)
    {
        return true;
    }
    if (RingType == ITEM_HELPER + 42)
    {
        return true;
    }

    if (RingType == ITEM_HELPER + 68)
    {
        return true;
    }

    if (RingType == ITEM_HELPER + 76)
    {
        return true;
    }

    if (RingType == ITEM_HELPER + 122)
    {
        return true;
    }
    return false;
}

bool CChangeRingManager::CheckRepair(int iType)
{
    if (iType == ITEM_HELPER + 10)
    {
        return true;
    }

    if (iType == ITEM_HELPER + 39)
    {
        return true;
    }

    if (iType == ITEM_HELPER + 40)
    {
        return true;
    }

    if (iType == ITEM_HELPER + 41)
    {
        return true;
    }

    if (iType == ITEM_HELPER + 42)
    {
        return true;
    }

    if (iType == ITEM_HELPER + 68)
    {
        return true;
    }

    if (iType == ITEM_HELPER + 76)
    {
        return true;
    }

    if (iType == ITEM_HELPER + 122)
    {
        return true;
    }
    return false;
}

bool CChangeRingManager::CheckMoveMap(short sLeftRingType, short sRightRingType)
{
    if (sLeftRingType == ITEM_HELPER + 10 || sRightRingType == ITEM_HELPER + 10)
    {
        return true;
    }
    if (sLeftRingType == ITEM_HELPER + 39 || sRightRingType == ITEM_HELPER + 39)
    {
        return true;
    }
    if (sLeftRingType == ITEM_HELPER + 40 || sRightRingType == ITEM_HELPER + 40)
    {
        return true;
    }
    if (sLeftRingType == ITEM_HELPER + 41 || sRightRingType == ITEM_HELPER + 41)
    {
        return true;
    }
    if (sLeftRingType == ITEM_HELPER + 42 || sRightRingType == ITEM_HELPER + 42)
    {
        return true;
    }
    if (sLeftRingType == ITEM_HELPER + 68 || sRightRingType == ITEM_HELPER + 68)
    {
        return true;
    }
    if (sLeftRingType == ITEM_HELPER + 76 || sRightRingType == ITEM_HELPER + 76)
    {
        return true;
    }
    if (sLeftRingType == ITEM_HELPER + 122 || sRightRingType == ITEM_HELPER + 122)
    {
        return true;
    }
    return false;
}

bool CChangeRingManager::CheckBanMoveIcarusMap(short sLeftRingType, short sRightRingType)
{
    if (sLeftRingType == ITEM_HELPER + 10 || sRightRingType == ITEM_HELPER + 10)
    {
        return true;
    }
    if (sLeftRingType == ITEM_HELPER + 39 || sRightRingType == ITEM_HELPER + 39)
    {
        return true;
    }
    if (sLeftRingType == ITEM_HELPER + 40 || sRightRingType == ITEM_HELPER + 40)
    {
        return true;
    }
    if (sLeftRingType == ITEM_HELPER + 41 || sRightRingType == ITEM_HELPER + 41)
    {
        return true;
    }
    if (sLeftRingType == ITEM_HELPER + 42 || sRightRingType == ITEM_HELPER + 42)
    {
        return true;
    }
    if (sLeftRingType == ITEM_HELPER + 68 || sRightRingType == ITEM_HELPER + 68)
    {
        return true;
    }
    return false;
}