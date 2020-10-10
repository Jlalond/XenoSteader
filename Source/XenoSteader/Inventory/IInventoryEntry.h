// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <vector>


class XENOSTEADER_API IInventoryEntry
{
public:
    FString Name;
    // virtual destructor to mark this as polymorphic type
    virtual ~IInventoryEntry() = default; 
};
