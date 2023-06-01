// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "Runtime/Engine/Classes/Components/TextRenderComponent.h"
#include "Engine/World.h"
#include "Sample_01.generated.h"

UCLASS()
class BPANDCPP_API ASample_01 : public AActor{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	ASample_01();
	
	UPROPERTY(EditAnywhere)
		UBoxComponent* Frame_Box;			// BoxCollision in BP
	
	UPROPERTY(EditAnywhere)
		UTextRenderComponent* infoTextRender;		// TextRender in BP

	UPROPERTY(EditAnywhere)
		FString infoText;

	/* UPROPERTY - Declaration, Description(s) and usage
	https://unrealcommunity.wiki/revisions/61799c5c65f766208636d1d3
	https://docs.unrealengine.com/en-us/Programming/UnrealArchitecture/Reference/Properties
	*/

	UFUNCTION()
		void OnCollision_Start(
			UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult & SweepResult
		);

	/* UFUNCTION - Declaration for Blueprint, Description(s) and example
	https://docs.unrealengine.com/4.26/en-US/ProgrammingAndScripting/GameplayArchitecture/Functions/
	https://docs.unrealengine.com/en-US/Programming/UnrealArchitecture/Reference/Functions
	https://answers.unrealengine.com/questions/543285/global-blueprint-callable-c-functions.html // bp function libraries 
	*/


	// .. your comment for Value_01
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ASample integer")
		int Value_01;

	//.. your comment for Value_02
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "ASample Float")
		float Value_02;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "ASample Bool")
		bool Flag_01;

	UPROPERTY(BlueprintReadWrite, EditInstanceOnly, Category = "ASample Actor")
		AActor* Object_01;

	// --

	UPROPERTY(BlueprintReadWrite, Category = "ASample A")
		int Value_A;

	UPROPERTY(BlueprintReadOnly, Category = "ASample B")
		int Value_B;

	// https://docs.unrealengine.com/en-US/Programming/UnrealArchitecture/Reference/Properties/Specifiers/index.html  Property Specifiers
	// ---------------------------------------------------------------------------

	// identity of player in level 2 
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ASample C", meta = (DisplayName = "Identity in System"))
		int Value_C_01;

	// range of skils on indentity in level 2
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "ASample C", meta = (ClampMin = "1", ClampMax = "120"))
		int Value_C_02;

	// https://docs.unrealengine.com/en-US/Programming/UnrealArchitecture/Reference/Metadata/index.html  Metadata Specifiers



	/*
	 collision -base
	https://www.youtube.com/watch?v=zZPyMjEWpF8&t=1262s

	collision -c++ example
	https://www.youtube.com/watch?v=LACvuJgQU5c

	answer hub -search
	https://answers.unrealengine.com/questions/320852/collision-detection-in-c.html

	check collision on Hit
	https://www.youtube.com/watch?v=1oiOi5peMCg
	*/
	
	void DestroyItem();


	// void
	void setDistance();
	void setName(FString name);
	void setActive(bool bActive = true);
	//void setActive(bool bActive = true, int value); //	<-- ERROR --------------- !
	//void setActive(int value, bool bActive = true); //	<-- OK
	//void setActive(bool bActive = true, int value = 4); //<-- OK
	//void setActive(int value, bool bActive = true, int set = 4, bool bExtra = false); //	<-- OK

	// return
	int getDistance();
	FString getName(int id);

	// blueprint

	// check activation
	UFUNCTION(BlueprintCallable, Category = "ASample Functions")
		bool isActive();
	// check extra 
	UFUNCTION(BlueprintPure, Category = "ASample Functions")
		bool isExtra();





protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
};
