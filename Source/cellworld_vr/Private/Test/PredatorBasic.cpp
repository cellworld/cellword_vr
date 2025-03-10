#include "PredatorBasic.h"
#include "cellworld_vr/cellworld_vr.h"

APredatorBasic::APredatorBasic() : Super() {
	UE_LOG(LogExperiment, Log, TEXT("[APredatorBasic::APredatorBasic()]"));
	// Set this actor to call Tick() every frame. You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	SetActorEnableCollision(false);
	SetActorRotation(FRotator::ZeroRotator);
	
	// Create a sphere component
	SphereMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RootComponent"));
	SphereMeshComponent->SetCollisionEnabled(ECollisionEnabled::Type::NoCollision);
	SphereMeshComponent->SetRelativeLocation(FVector(0.0f,0.0f, 182.0f)); // 182cm-> ~6ft
	SphereMeshComponent->SetRelativeScale3D(FVector(3.0f, 3.0f,3.0f));
	RootComponent = SphereMeshComponent;

	UStaticMesh* StaticMesh = CreateDefaultSubobject<UStaticMesh>(TEXT("StaticMesh"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SphereMeshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Sphere.Sphere'"));
	if (SphereMeshAsset.Succeeded()) {
		UE_LOG(LogExperiment, Log,TEXT("[APredatorBasic::APredatorBasic()] Set Skeletal mesh: OK"))
		SphereMeshComponent->SetStaticMesh(SphereMeshAsset.Object);
	} else {
		UE_LOG(LogExperiment,Error,TEXT("[APredatorBasic::APredatorBasic()] Set Skeletal mesh: Failed"));
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> SphereMaterialAsset(TEXT("/Script/Engine.Material'/Engine/BasicShapes/BasicShapeMaterial.BasicShapeMaterial'"));
	if (SphereMaterialAsset.Succeeded()) {
		UE_LOG(LogExperiment,Log,TEXT("[APredatorBasic::APredatorBasic()] Set Material: OK"))
		SphereMeshComponent->SetMaterial(0, SphereMaterialAsset.Object);
	}else {
		UE_LOG(LogExperiment, Error,TEXT("[APredatorBasic::APredatorBasic()] Set Material: Failed"));
	}

}
