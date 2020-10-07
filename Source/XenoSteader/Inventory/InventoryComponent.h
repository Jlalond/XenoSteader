// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IInventoryConstraint.h"
#include "Android/AndroidPlatformMath.h"
#include "Android/AndroidPlatformMath.h"
#include "Android/AndroidPlatformMath.h"
#include "Android/AndroidPlatformMath.h"
#include "Chaos/AABB.h"
#include "Chaos/AABB.h"
#include "Chaos/AABB.h"
#include "Chaos/AABB.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

class UInventoryComponent;
class IInventoryEntry;

/* A system that contains items, implementations express behavior upon this,
 * Has a constraint, or an item that determines rules, and exposes an iterator of the whole set */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class XENOSTEADER_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();
	explicit UInventoryComponent(IInventoryConstraint InventoryConstraint);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

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

private:
	UPROPERTY()
	TArray<UInventoryComponent*> SubContainers;
	IInventoryConstraint InventoryConstraint;
};
