#include "ItemBase.h"

UItemBase::UItemBase()
{
}

UItemBase* UItemBase::CreateItemCopy() const
{
	UItemBase* ItemCopy = NewObject<UItemBase>(StaticClass());

	ItemCopy->ID = this->ID;
	ItemCopy->Quality = this->Quality;
	ItemCopy->ItemVisibilityData = this->ItemVisibilityData;
	ItemCopy->ItemType = this->ItemType;
	ItemCopy->ItemNumData = this->ItemNumData;
	ItemCopy->ItemDesc = this->ItemDesc;
	ItemCopy->ArmorStats = this->ArmorStats;
	ItemCopy->WeaponStats = this->WeaponStats;
	ItemCopy->ConsumableStats = this->ConsumableStats;

	return ItemCopy;
}

void UItemBase::SetQuantity(const int NewQuantity)
{
	if (NewQuantity != Quantity)
	{
		Quantity = FMath::Clamp(NewQuantity, 0, ItemNumData.isStackable ? ItemNumData.MaxQuantity : 1);

		//if (OwningInventory != nullptr)
		//{
		//	if (Quantity <= 0)
		//	{
		//		OwningInventory->RemoveItem(this);
		//	}
		//}
	}
}

void UItemBase::Use(AInventorySystemCharacter* Character)
{
}
