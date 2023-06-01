// Fill out your copyright notice in the Description page of Project Settings.

#include "Sample_01.h"

// Sets default values
ASample_01::ASample_01(){
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// set up Box Collision 
	Frame_Box = CreateDefaultSubobject<UBoxComponent>("Element Box");
	RootComponent = Frame_Box;

	// add collision event functions  ( in BP , choose Box, add events on BeginOverlap and EndOverlap)
	Frame_Box->OnComponentBeginOverlap.AddDynamic(this, &ASample_01::OnCollision_Start);
	
	//////------------------ text
	///////////////////////// FObjectFinder method
	infoTextRender = CreateDefaultSubobject<UTextRenderComponent>(FName("name"));

	infoTextRender->SetRelativeLocation(FVector(.0f, -40.0f, 75.0f));
	infoTextRender->SetRelativeRotation(FRotator(.0f, 180.0f, 30.0f));
	infoTextRender->SetXScale(1.0f);
	infoTextRender->SetYScale(1.0f);
	infoTextRender->SetWorldSize(32);
	infoTextRender->AttachToComponent(Frame_Box, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void ASample_01::BeginPlay(){
	Super::BeginPlay();
	
	infoTextRender->SetText(FText::FromString(infoText));
}

// Called every frame
void ASample_01::Tick(float DeltaTime){
	Super::Tick(DeltaTime);

}

void ASample_01::OnCollision_Start(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult){
	infoTextRender->SetText(FText::FromString("Collision Detected"));
}

void ASample_01::DestroyItem(){
	//Destroy();
}


void ASample_01::setDistance() {}
void ASample_01::setName(FString name) {}
void ASample_01::setActive(bool bActive) {}


int ASample_01::getDistance() {
	return 0;
}

FString ASample_01::getName(int id) {
	return FString();
}

bool ASample_01::isActive() {
	return false;
}

bool ASample_01::isExtra() {
	return false;
}




