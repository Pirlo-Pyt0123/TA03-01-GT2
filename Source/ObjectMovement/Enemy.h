#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemy.generated.h"


class APointActor;
class AStaticMeshActor;

UCLASS()
class OBJECTMOVEMENT_API AEnemy : public AActor
{
    GENERATED_BODY()

public:
    AEnemy();

protected:
    virtual void BeginPlay() override;

public:
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Visual")
        UStaticMeshComponent* EnemyMesh;

    UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Movement")
        TArray<APointActor*> PatrolPoints;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
        float MovementSpeed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
        TMap<UMaterialInterface*, AStaticMeshActor*> diccionario;

 

private:
    int32 CurrentPointIndex;

    // Updated to include DeltaTime since it handles the movement math
    void GoTo(APointActor* Target, float DeltaTime);
};