// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BallScaler.generated.h"

UCLASS()
class OBJECTMOVEMENT_API ABallScaler : public AActor
{
    GENERATED_BODY()

public:
    ABallScaler();

protected:
    virtual void BeginPlay() override;

    // The visual mesh component
    UPROPERTY(VisibleAnywhere, Category = "Components")
        class UStaticMeshComponent* MeshComponent;

public:
    virtual void Tick(float DeltaTime) override;

    // How fast the ball scales up per second
    UPROPERTY(EditAnywhere, Category = "Scaling Settings")
        FVector ScaleRate;

    // Boolean to control the action
    UPROPERTY(EditAnywhere, Category = "Scaling Settings")
    bool bIsScaling;

private:
    
    // Function to trigger when 'I' is pressed
    void ToggleScaling();

    // Function to trigger when the object is clicked with the mouse
    UFUNCTION()
    void OnObjectClicked(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed);
};