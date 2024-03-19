// Fill out your copyright notice in the Description page of Project Settings.


#include "Missile.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Enemy.h"
#include "BBDroneGameModeBase.h"
#include "Engine/Engine.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AMissile::AMissile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;
	Mesh->SetGenerateOverlapEvents(true);

	MovementComp = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("MoveComp"));
	MovementComp->InitialSpeed = 500.0f;

	InitialLifeSpan = 8.0f;

}

void AMissile::OverlapHandler(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->IsA<AEnemy>())
	{
		//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("OnCollision"));
		OtherActor->Destroy();
		ABBDroneGameModeBase* gm = Cast<ABBDroneGameModeBase>(GetWorld()->GetAuthGameMode());
		if (gm != nullptr)
		{
			gm->score++;
		}
		this->Destroy();
	}
}

// Called when the game starts or when spawned
void AMissile::BeginPlay()
{
	Super::BeginPlay();

	Mesh->OnComponentBeginOverlap.AddDynamic(this, &AMissile::OverlapHandler);

	UGameplayStatics::PlaySound2D(this, MissileSound, 0.2f);
	
}

// Called every frame
void AMissile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

