// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "XenoSteader/Inventory/InventoryComponent.h"
#include <vector>

/**
 * Inventory to fit items in a gird format
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class XENOSTEADER_API UItemGridInventory : public UInventoryComponent
{
	GENERATED_BODY()
public:
	/* Dimensions for grid */
	UItemGridInventory(int XSize, int YSize);
	~UItemGridInventory();

	virtual bool InsertItem(IInventoryEntry* InventoryEntry) override;

protected:
	std::vector<std::vector<IInventoryEntry*>> ItemMatrix;
	virtual bool CanBeInserted(IInventoryEntry* InventoryEntry) override;
};
