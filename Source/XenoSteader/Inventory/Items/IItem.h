// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "XenoSteader/Inventory/IInventoryEntry.h"

/**
 * 
 */
class XENOSTEADER_API IItem : public IInventoryEntry
{
public:
	int GetXSize() { return -1; }
    int GetYSize() { return -1; }
};
