// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemySpawner.h"
#include "Components/BoxComponent.h"
#include "Enemy.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/Actor.h"
#include "Engine.h"

// Sets default values
AEnemySpawner::AEnemySpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpawnArea = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawnArea"));
	RootComponent = SpawnArea;
	SpawnArea->SetBoxExtent(FVector(10000.0f, 10000.0f, 100.0f));

}

void AEnemySpawner::SpawnEnemy()
{
	FVector Origin;
	FVector Extends;
	GetActorBounds(false, Origin, Extends);
	FVector RandomLoc = UKismetMathLibrary::RandomPointInBoundingBox(Origin, Extends);

	GetWorld()->SpawnActor<AEnemy>(Enemies, RandomLoc, FRotator::ZeroRotator);
}

// Called when the game starts or when spawned
void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(SpawnHandle, this, &AEnemySpawner::SpawnEnemy, SpawnSpan, true);
	//GetWorldTimerManager().SetTimer(SpawnHandle, this, &AEnemySpawner::SpawnEnemy, SpawnSpan, true);
	
}

// Called every frame
void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

