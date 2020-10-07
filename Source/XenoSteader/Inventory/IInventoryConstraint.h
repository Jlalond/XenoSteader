// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class XENOSTEADER_API IInventoryConstraint
{
public:
	virtual bool ItemPassesConstraint(class UInventoryComponent* ParentInventory, class IInventoryEntry* Entry) { return true; }
};
