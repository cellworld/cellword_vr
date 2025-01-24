#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Math/UnrealMathUtility.h"
#include "CoordinateMathFLibrary.generated.h"

UCLASS()
class EXPERIMENTPLUGIN_API UCoordinateMathFLibrary : public UBlueprintFunctionLibrary {

	GENERATED_BODY()
public: 
	UFUNCTION(BlueprintCallable, 
		meta = (DisplayName = "GeneratePoints3DSphere", Keywords="Points Along 3D Points Sphere"),
		Category = CoordinateMathFLibrary)

	/* generates InNumPoints along Sphere center. Returns points along Sphere.
	 * todo: make a version of this that also includes center as first index 
	 */
	static inline TArray<FVector> GeneratePoints3DSphere(const FVector InCenterLocation, const float InRadius, const int InNumPoints) {
		
		constexpr int MIN_POINTS = 3;
		constexpr int MAX_POINTS = 15;

		if (InNumPoints < MIN_POINTS || InNumPoints > MAX_POINTS) {
			UE_LOG(LogTemp, Log, TEXT("[GeneratePoints3DSphere] InNumPoints not valid (%i). Must be between %i and %i."), InNumPoints, MIN_POINTS, MAX_POINTS);
			return {};
		}

		const float AngleStep = 2.0f * PI / InNumPoints;

		TArray<FVector> OutPoints;
		
		for (int8 i = 0; i < InNumPoints; i++) {
			const float Angle = i * AngleStep;
			FVector CurrentLocation {
				InCenterLocation.X + InRadius * FMath::Cos(Angle),
				InCenterLocation.Y + InRadius * FMath::Sin(Angle),
				InCenterLocation.Z
			};

			OutPoints.Add(CurrentLocation);
			UE_LOG(LogTemp, Log, TEXT("[GeneratePoints3DSphere] Added New Point:  (%i | %s)."),
				InNumPoints,
				*CurrentLocation.ToString());
		}

		UE_LOG(LogTemp, Log, TEXT("[GeneratePoints3DSphere] InNumPoints (%i)."),  InNumPoints);
		UE_LOG(LogTemp, Log, TEXT("[GeneratePoints3DSphere] AngleStep (%0.4f)."), AngleStep);
		
		return OutPoints; 
	}

};
