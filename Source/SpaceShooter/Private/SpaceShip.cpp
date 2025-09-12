// Fill out your copyright notice in the Description page of Project Settings.


#include "SpaceShip.h"
#include "Components/BoxComponent.h"
// Sets default values
ASpaceShip::ASpaceShip()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
   // Create BoxComponent and set as RootComponent for the Actor
   BoxCollision = CreateDefaultSubobject<UBoxComponent>("BoxCollision");
   RootComponent = BoxCollision;

   // Create StaticMeshComponent and Attach to BoxComponent
   StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
   StaticMesh->SetupAttachment(BoxCollision);
}

// Called when the game starts or when spawned
void ASpaceShip::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpaceShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASpaceShip::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

