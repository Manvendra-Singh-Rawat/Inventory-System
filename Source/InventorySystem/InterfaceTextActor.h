#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InterfaceTextActor.generated.h"

UCLASS()
class INVENTORYSYSTEM_API AInterfaceTextActor : public AActor
{
	GENERATED_BODY()
	
public:
	AInterfaceTextActor();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
