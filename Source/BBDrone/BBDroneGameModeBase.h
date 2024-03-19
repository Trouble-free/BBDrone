// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BBDroneGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class BBDRONE_API ABBDroneGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 score;
	
};
