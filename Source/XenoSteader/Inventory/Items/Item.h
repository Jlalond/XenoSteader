// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "XenoSteader/Inventory/IInventoryEntry.h"

/**
 * 
 */
class XENOSTEADER_API Item : public IInventoryEntry
{
public:
	Item();
	~Item();

	FName ItemName;
};
