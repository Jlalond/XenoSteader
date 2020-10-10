// Fill out your copyright notice in the Description page of Project Settings.


#include "UItemGridInventory.h"
#include "XenoSteader/Inventory/IInventoryEntry.h"
#include <tuple>
#include <vector>
#include "IItem.h"

UItemGridInventory::UItemGridInventory(const FObjectInitializer& FObjectInitializer) : Super(FObjectInitializer)
{
}

UItemGridInventory::UItemGridInventory(int XSize, int YSize)
{
    this->ItemMatrix = std::vector<std::vector<IInventoryEntry*>>(XSize, std::vector<IInventoryEntry*>(YSize));
}

UItemGridInventory::~UItemGridInventory()
{
}

bool UItemGridInventory::InsertItem(IInventoryEntry* InventoryEntry)
{
    return this->CanBeInserted(InventoryEntry);
}

bool UItemGridInventory::CanBeInserted(IInventoryEntry* InventoryEntry)
{
    IItem* Item = dynamic_cast<IItem*>(InventoryEntry);
    if(Item == nullptr)
    {
        return false;
    }

    int ItemX = Item->GetXSize();
    int ItemY = Item->GetYSize();
    for(int x = 0; x < ItemMatrix.size(); x++)
    {
        for(int y = 0; y < ItemMatrix[0].size(); y++)
        {
            bool HasSpace = false;
            // check if all the spaces in the matrix are null-pointers
            for(int i = 0; i < ItemX; i++)
            {
                for(int k = 0; k < ItemY; k++)
                {
                    if(ItemMatrix[i][k] != nullptr)
                    {
                        HasSpace = false;
                        break;
                    }
                }
                if(!HasSpace)
                {
                    break;
                }
            }

            if(HasSpace)
            {
                // If we have space, reiterate over all the spaces and put them as the pointer
                for(int i = 0; i < ItemX; i++)
                {
                    for(int k = 0; k < ItemY; k++)
                    {
                        ItemMatrix[i][k] = Item;
                    }
                }

                return true;
            }
        }
    }

    // if we've iterated over ever space, return false.
    // worst case we visit ever square (Matrix Width * Item Width) (Matrix Height * Item Height)
    // so like.. 100 :D
    return false;
}

