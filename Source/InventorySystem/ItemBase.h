#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ItemDataStruct.h"
#include "ItemBase.generated.h"

UCLASS()
class INVENTORYSYSTEM_API UItemBase : public UObject
{
	GENERATED_BODY()
	
//------------------------------------------------------------------------------------------------
//										DATA MEMBERS START
//------------------------------------------------------------------------------------------------
public:
	//UPROPERTY()
	//UInventoryComponent* OwningInventory;

	UPROPERTY(VisibleAnywhere, Category = "Data Item", meta = (UIMin = 1, UIMax = 100))
	int Quantity;

	UPROPERTY(EditAnywhere, Category = "Data Item")
	FName ID;

	UPROPERTY(EditAnywhere, Category = "Data Item")
	EItemQuality Quality;
	UPROPERTY(EditAnywhere, Category = "Data Item")
	FItemAssetData ItemVisibilityData;
	UPROPERTY(EditAnywhere, Category = "Data Item")
	EItemType ItemType;

	UPROPERTY(EditAnywhere, Category = "Data Item")
	FItemDescription ItemDesc;
	UPROPERTY(EditAnywhere, Category = "Data Item")
	FItemNumericData ItemNumData;
	UPROPERTY(EditAnywhere, Category = "Data Item")
	FWeaponData ArmorStats;
	UPROPERTY(EditAnywhere, Category = "Data Item")
	FWeaponData WeaponStats;
	UPROPERTY(EditAnywhere, Category = "Data Item")
	FConsumableData ConsumableStats;
//------------------------------------------------------------------------------------------------
//										 DATA MEMBERS END
//------------------------------------------------------------------------------------------------



//------------------------------------------------------------------------------------------------
//										DATA FUNCTIONS START
//------------------------------------------------------------------------------------------------
public:
	UItemBase();
	UItemBase* CreateItemCopy() const;
	FORCEINLINE int IsFullItemStack() const { return Quantity == ItemNumData.MaxQuantity; };
	void SetQuantity(const int NewQuantity);
	virtual void Use(class AInventorySystemCharacter* Character);
//------------------------------------------------------------------------------------------------
//										 DATA FUNCTIONS END
//------------------------------------------------------------------------------------------------


//------------------------------------------------------------------------------------------------
//									OPERATOR OVERLOADING START
//------------------------------------------------------------------------------------------------
protected:
	bool operator == (const FName& OtherID) const
	{
		return ID == OtherID;
	}
//------------------------------------------------------------------------------------------------
//									 OPERATOR OVERLOADING END
//------------------------------------------------------------------------------------------------
};
