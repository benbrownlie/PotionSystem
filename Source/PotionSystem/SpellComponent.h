// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Projectile.h"
#include "Components/ActorComponent.h"
#include "SpellComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class POTIONSYSTEM_API USpellComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USpellComponent();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	TSubclassOf<AProjectile> ProjectileClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
