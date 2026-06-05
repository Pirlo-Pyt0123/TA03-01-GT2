#include "PointActor.h"
#include "Components/ArrowComponent.h" // Required for the Arrow Component
#include "Engine/StaticMeshActor.h"
APointActor::APointActor()
{
    PrimaryActorTick.bCanEverTick = false;

    // Create the Arrow Component
    PointHandle = CreateDefaultSubobject<UArrowComponent>(TEXT("PointHandle"));

    // Set the Arrow as the Root Component
    // Now, clicking the arrow in the viewport lets you move the entire Actor!
    RootComponent = PointHandle;
}