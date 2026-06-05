// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TopDownMover.generated.h"

// UENUM(BlueprintType) makes it visible in the Editor dropdowns
UENUM(BlueprintType)
enum class EMoveDirection : uint8
{
    Up         UMETA(DisplayName = "Arriba"),
    Down       UMETA(DisplayName = "Abajo"),
    Left       UMETA(DisplayName = "Izquierda"),
    Right      UMETA(DisplayName = "Derecha"),
    UpRights   UMETA(DisplayName = "Diagonal Derecha Arriba"),
    UpLeft     UMETA(DisplayName = "Diagonal Izquierda Arriba"),
    DownRight  UMETA(DisplayName = "Diagonal Derecha Abajo"),
    DownLeft   UMETA(DisplayName = "Diagonal Izquierda Abajo")
};

UCLASS()
class OBJECTMOVEMENT_API ATopDownMover : public APawn
{
    GENERATED_BODY()

public:
    ATopDownMover();

protected:
    virtual void BeginPlay() override;

    // A visual mesh so we can actually see the object in the editor
    UPROPERTY(VisibleAnywhere, Category = "Components")
        class UStaticMeshComponent* MeshComponent;

public:
    virtual void Tick(float DeltaTime) override;
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    // 2. Variables exposed to the Visual Editor
    UPROPERTY(EditAnywhere, Category = "Configuracion de Movimiento")
        float Velocity;

    UPROPERTY(EditAnywhere, Category = "Configuracion de Movimiento")
        EMoveDirection MoveDirection;
    UPROPERTY(EditAnywhere, Category = "Configuracion de Movimiento")
        bool bIsMoving;

private:
    // 3. Boolean to control the action state
    //bool bIsMoving;

    // Function to listen to the Spacebar
    void ToggleMovement();

};
