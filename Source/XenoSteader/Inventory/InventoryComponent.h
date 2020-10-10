// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

class UInventoryComponent;
class IInventoryEntry;

/* A system that contains items, implementations express behavior upon this,
 * Has a constraint, or an item that determines rules, and exposes an iterator of the whole set */
UCLASS( ClassGroup=(Custom) )
class XENOSTEADER_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	/* Returns true if item can be inserted */
	virtual bool InsertItem(IInventoryEntry* InventoryEntry) { return false; }

	/* Try to remove an item */
	virtual bool RemoveItem(IInventoryEntry* InventoryEntry) { return false; }

	/* Get the entire inventory, including sub inventories */
	virtual TArray<IInventoryEntry*>::TConstIterator GetInventory() { return TArray<IInventoryEntry*>().CreateConstIterator(); }

	/* Add an inventory to an inventory, like a bag in the bag */
	virtual bool AddSubContainer(UInventoryComponent* InventoryComponent) { return false; }

	virtual bool RemoveSubContainer(UInventoryComponent* InventoryComponent) { return false; }

	virtual TArray<UInventoryComponent*>::TConstIterator GetSubContainers() { return TArray<UInventoryComponent*>().CreateConstIterator(); }

protected:
	virtual bool CanBeInserted(IInventoryEntry* InventoryEntry) { return false; }

private:
	TArray<UInventoryComponent*> SubContainers;
};
