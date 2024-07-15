#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InteractionInterface.generated.h"

UENUM()
enum class EInteractableType : uint8
{
	Pickup UMETA(DisplayName = "Pickup"),
	NonPlayerCharacter UMETA(DisplayName = "NPC"),
	Device UMETA(DisplayName = "Device"),
	Toggle UMETA(DisplayName = "Toggle"),
	Container UMETA(DisplayName = "Container")
};

USTRUCT()
struct FInteractableData
{
	GENERATED_USTRUCT_BODY();

	FInteractableData() :
	InteractableType(EInteractableType::Pickup),
	Name(FText::GetEmpty()),
	Action(FText::GetEmpty()),
	Quantity(0),
	InteractionDuration(0.0f)
	{

	}

	UPROPERTY(EditInstanceOnly)
	EInteractableType InteractableType;

	UPROPERTY(EditInstanceOnly)
	FText Name;
	UPROPERTY(EditInstanceOnly)
	FText Action;
	// Quantity if only for pickup
	UPROPERTY(EditInstanceOnly)
	int Quantity;
	// InteractionDuration will only be used to do hold task like turning a valve, etc
	UPROPERTY(EditInstanceOnly)
	float InteractionDuration;
};

UINTERFACE(MinimalAPI)
class UInteractionInterface : public UInterface
{
	GENERATED_BODY()
};

class INVENTORYSYSTEM_API IInteractionInterface
{
	GENERATED_BODY()

public:
	virtual void BeginFocus();
	virtual void EndFocus();

	virtual void BeginInteract();
	virtual void EndInteract();

	virtual void Interact();

	FInteractableData InteractableData;
};
