#include "PawnMainMovementComponent.h"
#include "PawnMain.h"



UPawnMainMovementComponent::UPawnMainMovementComponent()
{

}

void UPawnMainMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    // Make sure that everything is still valid, and that we are allowed to move.
    if (!PawnOwner || !UpdatedComponent || ShouldSkipUpdate(DeltaTime))
    {
        return;
    }
    // Get (and then clear) the movement vector that we set in ACollidingPawn::Tick
    FVector DesiredMovementThisFrame = ConsumeInputVector().GetClampedToMaxSize(1.0f) * DeltaTime * 150.0f;
    if (!DesiredMovementThisFrame.IsNearlyZero())
    {
        FHitResult Hit;
        SafeMoveUpdatedComponent(DesiredMovementThisFrame, UpdatedComponent->GetComponentRotation(), true, Hit);

        // If we bumped into something, try to slide along it
        if (Hit.IsValidBlockingHit())
        {
            SlideAlongSurface(DesiredMovementThisFrame, 1.f - Hit.Time, Hit.Normal, Hit);
        }
    }

}

void UPawnMainMovementComponent::SetComponentOwner(APawnMain* Owner)
{
    PawnOwner = Owner;
}

void UPawnMainMovementComponent::OnMovementUpdated(float DeltaSeconds, const FVector& OldLocation, const FVector& OldVelocity)
{
    UE_LOG(LogTemp, Warning, TEXT("UPawnMainMovementComponent::OnMovementUpdated"));
}