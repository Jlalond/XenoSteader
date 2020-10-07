// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	SetIsReplicatedByDefault(true);
	this->SubContainers = TArray<UInventoryComponent*>();
}

UInventoryComponent::UInventoryComponent(IInventoryConstraint InventoryConstraint)
{
	this->InventoryConstraint = InventoryConstraint;
	PrimaryComponentTick.bCanEverTick = false;
	SetIsReplicatedByDefault(true);
	this->SubContainers = TArray<UInventoryComponent*>();
}

// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();
}

