// Fill out your copyright notice in the Description page of Project Settings.


#include "RandomMove.h"

// Sets default values
ARandomMove::ARandomMove()
{
	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = RootScene;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);

	Speed = 50.0f;
	MoveCnt = 0;
	eventCnt = 0;
	TotalDistance = 0;
	MoveEvent = false;

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ARandomMove::BeginPlay()
{
	Super::BeginPlay();
	
	Move();
}

// Called every frame
void ARandomMove::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (MoveEvent) {
		if (CurrentDistance < MoveDistance) {
			FVector Location = GetActorLocation();

			Location += Direction * Speed * DeltaTime;

			SetActorLocation(Location);

			CurrentDistance = (Location - Start).Size();
		}
		else {
			MoveEvent = false;
			
			if (MoveCnt == 10) {
				UE_LOG(LogTemp, Warning, TEXT("TotalDistance = %f"), TotalDistance);
				UE_LOG(LogTemp, Warning, TEXT("EventCount = %d"), eventCnt);

				TotalDistance = 0;
				eventCnt = 0;
				MoveCnt = 0;
			}

			Move();
		}
	}
}

void ARandomMove::Move()
{
	MoveCnt++;

	Start = GetActorLocation();

	int32 RandomValueX = FMath::RandRange(-1, 1);
	int32 RandomValueY = FMath::RandRange(-1, 1);
	int32 RandomEvent = FMath::RandRange(0, 1);

	if (RandomEvent)
		eventCnt++;

	FVector NewPoint(Start.X + RandomValueX * 10, Start.Y + RandomValueY * 10, Start.Z);
	
	Direction = NewPoint - Start;
	MoveDistance = Direction.Size();
	TotalDistance += Direction.Size();
	
	Direction = Direction.GetSafeNormal();
	CurrentDistance = 0.0f;

	MoveEvent = true;
}

