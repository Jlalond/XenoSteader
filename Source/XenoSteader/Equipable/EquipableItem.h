// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "XenoSteader/Inventory/Items/IItem.h"
#include "EquipableItem.generated.h"

UCLASS()
class XENOSTEADER_API AEquipableItem : public AActor, public IItem
{
	GENERATED_BODY()
	
public:
	UPROPERTY()
	virtual USkeletalMesh* GetSkeletalMesh() const { return ItemMesh;}

protected:
	/* 3d Model for Item */
	UPROPERTY(BlueprintReadOnly)
	USkeletalMesh* ItemMesh;
};
