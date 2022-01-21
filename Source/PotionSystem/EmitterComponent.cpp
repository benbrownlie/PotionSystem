// Fill out your copyright notice in the Description page of Project Settings.

#include "EmitterComponent.h"
#include "Projectile.h"

// Sets default values for this component's properties
UEmitterComponent::UEmitterComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	ProjectileClass = AProjectile::StaticClass();
}


// Called when the game starts
void UEmitterComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UEmitterComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UEmitterComponent::Fire()
{
	SpawnProjectile();
}

void UEmitterComponent::SpawnProjectile()
{
	//Gets the actor that the script is applied to
	AActor* owner = GetOwner();

	//Sets the variables to the current location and rotation of the component
	FVector location = GetComponentLocation();
	FRotator rotation = GetComponentRotation();
	FActorSpawnParameters spawnParameters;
	spawnParameters.Owner = owner;
	spawnParameters.Instigator = owner->GetInstigator();

	//Spawns the projectile into the world
	AProjectile* projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileClass, location, rotation);
}

