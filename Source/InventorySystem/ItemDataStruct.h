#pragma once

#include "coreminimal.h"
#include "engine/datatable.h"
#include "ItemDataStruct.generated.h"

UENUM()
enum class EItemQuality : uint8
{
	Iron UMETA(DisplayName = "Iron"),
	Bronze UMETA(DisplayName = "Bronze"),
	Silver UMETA(DisplayName = "Silver"),
	Gold UMETA(DisplayName = "Gold"),
	Diamond UMETA(DisplayName = "Diamond")
};

UENUM()
enum class EItemType : uint8
{
	Armor UMETA(DisplayName = "Armor"),
	Weapon UMETA(DisplayName = "Weapon"),
	Consumable UMETA(DisplayName = "Consumable")
};

USTRUCT()
struct FItemDescription
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, Category = "Item Description")
	FText ItemName;
	UPROPERTY(EditAnywhere, Category = "Item Description")
	FText Description;
	UPROPERTY(EditAnywhere, Category = "Item Description")
	FText InteractionText;
	UPROPERTY(EditAnywhere, Category = "Item Description")
	FText UsageText;
};
USTRUCT()
struct FItemNumericData
{
	GENERATED_USTRUCT_BODY();

	UPROPERTY(EditAnywhere, Category = "Numeric Data")
	int MaxQuantity;
	UPROPERTY(EditAnywhere, Category = "Numeric Data")
	bool isStackable;
};
USTRUCT()
struct FArmorData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, Category = "Armor Data")
	float ArmorRating;
	UPROPERTY(EditAnywhere, Category = "Armor Data")
	float ArmorDamageReduction;
	UPROPERTY(EditAnywhere, Category = "Armor Data")
	float ArmorWeight;
};
USTRUCT()
struct FWeaponData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, Category = "Weapon Data")
	float WeaponRating;
	UPROPERTY(EditAnywhere, Category = "Weapon Data")
	float WeaponDamage;
	UPROPERTY(EditAnywhere, Category = "Weapon Data")
	float WeaponWeight;
};
USTRUCT()
struct FConsumableData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, Category = "Consumable Data")
	float HealthRecover;
	UPROPERTY(EditAnywhere, Category = "Consumable Data")
	float AmmoRecover;
};
USTRUCT()
struct FItemAssetData
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, Category = "VIsibility Data")
	UTexture2D* Icon;
	UPROPERTY(EditAnywhere, Category = "VIsibility Data")
	UStaticMesh* Mesh;
};


//------------------------------------------------------------------------------------------------
//								DATA TABLE VISIBLE OPTIONS START
//------------------------------------------------------------------------------------------------
USTRUCT()
struct FItemData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, Category = "Data Item")
	FName ID;

	int Quantity;

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
};
//------------------------------------------------------------------------------------------------
//								DATA TABLE VISIBLE OPTIONS END
//------------------------------------------------------------------------------------------------