// Fill out your copyright notice in the Description page of Project Settings.

#include "LightTrigger_01.h"


// Sets default values
ALightTrigger_01::ALightTrigger_01(){
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// set up Box Collision ( in BP -> creat, drag and drop to root)
	Frame_Box = CreateDefaultSubobject<UBoxComponent>("Element Box");
	RootComponent = Frame_Box;

	// add collision event functions  ( in BP , choose Box, add events on BeginOverlap and EndOverlap)
	Frame_Box->OnComponentBeginOverlap.AddDynamic(this, &ALightTrigger_01::OnEntering);
	Frame_Box->OnComponentEndOverlap.AddDynamic(this, &ALightTrigger_01::OnLeaving);
}

// Called when the game starts or when spawned
void ALightTrigger_01::BeginPlay(){
	Super::BeginPlay();
	
}

// Called every frame
void ALightTrigger_01::Tick(float DeltaTime){
	Super::Tick(DeltaTime);

}

// on collision with ANY visitor object
void ALightTrigger_01::OnEntering(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult){
	UE_LOG(LogTemp, Warning, TEXT(" - iekt --- %s"), *(OtherActor->GetName()));
	LightOperator();

	/*
	LOG in Unreal Engine
	https://unrealcpp.com/debug-logging/
	*/


}

// on leaving with ANY visitor object
void ALightTrigger_01::OnLeaving(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex){
	UE_LOG(LogTemp, Warning, TEXT(" - dakt --- %s"), *(OtherActor->GetName()));
	LightOperator();
}

void ALightTrigger_01::LightOperator(){
	for (ASpotLight* LightObject : Lights){	
		LightObject->SpotLightComponent->SetVisibility(LightsVisibility);
	}
	UE_LOG(LogTemp, Warning, TEXT(" - light checked ---"));
	LightsVisibility = !LightsVisibility; // change light visibility flag at the end
}

