// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "XenoSteader/Inventory/InventoryComponent.h"

class IInventoryEntry;
/**
 * Inventory to fit items in a gird format
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class XENOSTEADER_API UItemInventory : public UInventoryComponent
{
public:
	/* Dimensions for grid */
	UItemInventory(int XSize, int YSize);
	~UItemInventory();

	virtual bool InsertItem(IInventoryEntry* InventoryEntry) override;

protected:
	IInventoryEntry** ItemMatrix;

private:
	void InsertIntoGrid(IInventoryEntry* InventoryEntry);
};
