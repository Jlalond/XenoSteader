// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "XenoSteader/Inventory/InventoryComponent.h"
#include <vector>
#include "UItemGridInventory.generated.h"

class IItem;

/**
 * Inventory to fit items in a gird format
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class XENOSTEADER_API UItemGridInventory : public UInventoryComponent
{
	GENERATED_BODY()
	UItemGridInventory(const FObjectInitializer& FObjectInitializer);
public:
	/* Dimensions for grid */
	UItemGridInventory(int XSize, int YSize);
	~UItemGridInventory();

	virtual bool InsertItem(IInventoryEntry* InventoryEntry) override;
	virtual bool RemoveItem(IInventoryEntry* InventoryEntry) override;
	virtual TArray<IInventoryEntry*>::TConstIterator GetInventory() override;
	virtual bool AddSubContainer(UInventoryComponent* InventoryComponent) override;
	virtual bool RemoveSubContainer(UInventoryComponent* InventoryComponent) override;
	virtual TArray<UInventoryComponent*>::TConstIterator GetSubContainers() override;

protected:
	/* Heap based matrix for how items are laid out in 2d for players */
	std::vector<std::vector<IInventoryEntry*>> ItemMatrix;
	virtual bool CanBeInserted(IInventoryEntry* InventoryEntry) override;
	bool VerticalInsert(int X, int Y, IItem* Item);
	bool HorizontalInsert(int X, int Y, IItem* Item);
	void Fill(int X, int Y, int XLength, int YLength, IItem* Item);
	/* Linear list of all items in the matrix */
	TArray<IInventoryEntry*> InventoryManifest;
};
