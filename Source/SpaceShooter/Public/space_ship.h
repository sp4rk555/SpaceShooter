// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "space_ship.generated.h"

class UInputComponent;
class UIInputAction;
class UInputMappingContext;

UCLASS()
class SPACESHOOTER_API Aspace_ship : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	Aspace_ship();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Input")
	TObjectPtr<UInputMappingContext> InputMappingContext;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Input")
	TObjectPtr<UInputAction> LookAction;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Input")
	TObjectPtr<UInputAction> FireAction;

	UPROPERTY(EditDefaultsOnly, Category = Projectile)
	TSubclassOf<class AProjectile> Projectile;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	UFUNCTION()
	void Move (const FInputActionValue& Value);
		
	UFUNCTION()
	void Look (const FInputActionValue& Value);

	
	UFUNCTION()
	void Fire();
};
