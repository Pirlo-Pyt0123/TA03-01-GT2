// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TopDownMover.h"
#include "TopDownMover2.generated.h"




UCLASS()
class OBJECTMOVEMENT_API ATopDownMover2 : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATopDownMover2();

protected:

	// A visual mesh so we can actually see the object in the editor
	UPROPERTY(VisibleAnywhere, Category = "Components")
		class UStaticMeshComponent* MeshComponent;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    // 2. Variables exposed to the Visual Editor
    UPROPERTY(EditAnywhere, Category = "Movement Settings")
        float Velocity;

    UPROPERTY(EditAnywhere, Category = "Movement Settings")
        EMoveDirection MoveDirection;
    UPROPERTY(EditAnywhere, Category = "Movement Settings")
        bool bIsMoving;

private:
    // 3. Boolean to control the action state
    //bool bIsMoving;

    // Function to listen to the Spacebar
    void ToggleMovement();

};
