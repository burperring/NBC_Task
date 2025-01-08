// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RandomMove.generated.h"

UCLASS()
class NBC_TASK_5_API ARandomMove : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARandomMove();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MoveActor")
	class USceneComponent* RootScene;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "MoveActor")
	class UStaticMeshComponent* Mesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Move();
    void createEvent();

protected:
	FVector Start;
	FVector Direction;

	float Speed;
	float TotalDistance;
	float MoveDistance;
	float CurrentDistance;
	
	int32 eventCnt;
	int32 MoveCnt;

	bool MoveEvent;
};
