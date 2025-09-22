// Fill out your copyright notice in the Description page of Project Settings.


#include "Asteroides.h"

#include "space_ship.h"
#include "Components/BoxComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AAsteroides::AAsteroides()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	// Create BoxComponent and set as RootComponent for the Actor
	BoxCollision = CreateDefaultSubobject<UBoxComponent>("BoxCollision");
	// ne marche pas BoxCollision->SetBoxExtent(FVector(FMath::RandRange(2.0f,5.0f), FMath::RandRange(2.0f,5.0f), 1.0f));
	RootComponent = BoxCollision;

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	ProjectileMovementComponent->SetUpdatedComponent(BoxCollision);
	ProjectileMovementComponent->InitialSpeed = FMath::RandRange(100.0f,300.0f) ;
	ProjectileMovementComponent->MaxSpeed = ProjectileMovementComponent->InitialSpeed;
	ProjectileMovementComponent->ProjectileGravityScale = 0.0f;
	ProjectileMovementComponent->bRotationFollowsVelocity = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(RootComponent);

	InitialLifeSpan = 20.0f;
	
}

// Called when the game starts or when spawned
void AAsteroides::BeginPlay()
{
	Super::BeginPlay();
	this->OnActorBeginOverlap.AddDynamic(this, &AAsteroides::OnOverlapBegin);

}

// Called every frame
void AAsteroides::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AAsteroides::GoInDirection(const FVector& Direction)
{
	ProjectileMovementComponent->Velocity = Direction * ProjectileMovementComponent->InitialSpeed;
}

void AAsteroides::OnOverlapBegin(AActor* MyActor, AActor* OtherActor)
{

	if (OtherActor && OtherActor != this)
	{
		Aspace_ship* SpaceShip = Cast<Aspace_ship>(OtherActor);

		if (SpaceShip)
		{
			SpaceShip->Hit();
			Destroy();
		}
	}
}

void AAsteroides::Hit()
{
	HealthPoint --;
	if (HealthPoint <= 0)
	{
		TArray<AActor*> FoundActors;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), Aspace_ship::StaticClass(), FoundActors);
		if (FoundActors.Num() > 0)
		{
			AActor* Actor = FoundActors[0];
			Aspace_ship* SpaceShip = Cast<Aspace_ship>(Actor);
			SpaceShip->AddScore();
		}
		Destroy();
	}
}