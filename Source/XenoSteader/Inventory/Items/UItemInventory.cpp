// Fill out your copyright notice in the Description page of Project Settings.


#include "UItemInventory.h"


UItemInventory::UItemInventory(int XSize, int YSize)
{
    
}

UItemInventory::~UItemInventory()
{
}

bool UItemInventory::InsertItem(IInventoryEntry* InventoryEntry)
{
    if(!this->InventoryConstraint.ItemPassesConstraint(this, InventoryEntry))
    {
        return false;
    }

    
}

