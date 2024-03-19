// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemySpawner.generated.h"

UCLASS()
class BBDRONE_API AEnemySpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemySpawner();

	UPROPERTY(VisibleAnywhere)
	class UBoxComponent* SpawnArea;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class AEnemy> Enemies;

	UPROPERTY(EditAnywhere)
	float SpawnSpan = 1.0f;

	UFUNCTION()
	void SpawnEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	FTimerHandle SpawnHandle;

};
