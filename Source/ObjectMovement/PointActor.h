#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PointActor.generated.h"

// Forward declaration
class UArrowComponent;
class AStaticMeshActor;
UCLASS()
class OBJECTMOVEMENT_API APointActor : public AActor
{
    GENERATED_BODY()

public:
    APointActor();

    // The visual handle that makes it clickable in the Editor
    UPROPERTY(VisibleAnywhere, Category = "Reference")
        UArrowComponent* PointHandle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Point Logic")
        AStaticMeshActor* LinkedCube;
};