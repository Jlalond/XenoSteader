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
    SubContainers = TArray<UInventoryComponent*>();
}

UItemGridInventory::~UItemGridInventory()
{
}

bool UItemGridInventory::InsertItem(IInventoryEntry* InventoryEntry)
{
    return this->CanBeInserted(InventoryEntry);
}

bool UItemGridInventory::RemoveItem(IInventoryEntry* InventoryEntry)
{
    if(!InventoryManifest.Contains(InventoryEntry))
    {
        return false;
    }
}

TArray<IInventoryEntry*>::TConstIterator UItemGridInventory::GetInventory()
{
    return InventoryManifest.CreateConstIterator();
}

bool UItemGridInventory::AddSubContainer(UInventoryComponent* InventoryComponent)
{
    SubContainers.Add(InventoryComponent);
    return true;
}

bool UItemGridInventory::RemoveSubContainer(UInventoryComponent* InventoryComponent)
{
    if(SubContainers.Contains(InventoryComponent))
    {
        SubContainers.Remove(InventoryComponent);
        return true;
    }

    return false;
}

TArray<UInventoryComponent*>::TConstIterator UItemGridInventory::GetSubContainers()
{
    return SubContainers.CreateConstIterator();
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
            
        }
    }

    // if we've iterated over ever space, return false.
    // worst case we visit ever square (Matrix Width * Item Width) (Matrix Height * Item Height)
    // so like.. 100 :D
    return false;
}

bool UItemGridInventory::VerticalInsert(const int X, const int Y, IItem* Item)
{
    bool HasSpace = true;
    const int ItemX = Item->GetXSize();
    const int ItemY = Item->GetYSize();

    for(int i = X; i < ItemMatrix.size() && i - X <= ItemX; i++)
    {
        for(int k = Y; i < ItemMatrix[0].size() && k - Y <= ItemY; k++)
        {
            if(ItemMatrix[i][k] != nullptr)
            {
                HasSpace = false;
                break;
            }
        }
        
        if(i - X == ItemX && HasSpace)
        {
            Fill(X, Y, ItemX, ItemY, Item);
            return true;
        }
    }

    return false;
}



bool UItemGridInventory::HorizontalInsert(int X, int Y, IItem* Item)
{
    bool HasSpace = true;
    const int ItemX = Item->GetXSize();
    const int ItemY = Item->GetYSize();

    for(int i = Y; i < ItemMatrix[0].size() && i - Y <= ItemY; i++)
    {
        for(int k = X; i < ItemMatrix.size() && k - X <= ItemX; k++)
        {
            if(ItemMatrix[k][i] != nullptr)
            {
                HasSpace = false;
                break;
            }
        }
        
        if(i - X == ItemX && HasSpace)
        {
            Fill(X, Y, ItemY, ItemX, Item);
            return true;
        }
    }

    return false;
}

void UItemGridInventory::Fill(int X, int Y, int XLength, int YLength, IItem* Item)
{
    for(int i = X; i -XLength <= XLength; i++)
    {
        for(int k = Y; k - Y <= YLength; k++)
        {
            // TODO: throw an exception if fill will exit bounds
            // Vector doesn't do bound checks, currently the insert algo's handle this, but even a debug exception would be good
            ItemMatrix[i][k] = Item;
        }
    }
}

