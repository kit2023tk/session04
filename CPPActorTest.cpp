// Fill out your copyright notice in the Description page of Project Settings.


#include "CPPActorTest.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
ACPPActorTest::ACPPActorTest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	DistFromCharacter = 10000;
}

float ACPPActorTest::CalcDistace()
{
	//自キャラ位置の取得
	FVector MyCharacterPosition = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	//このアクタの位置の取得
	FVector ActorPosition = GetActorLocation();

	FVector XYvector = MyCharacterPosition - ActorPosition;
	XYvector.Z = 0.0;
	return XYvector.Length();
}

FVector ACPPActorTest::CalcDirection()
{
	//自キャラ位置の取得
	FVector MyCharacterPosition = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	//このアクタの位置の取得
	FVector ActorPosition = GetActorLocation();

	return ActorPosition - MyCharacterPosition;
}

// Called when the game starts or when spawned
void ACPPActorTest::BeginPlay()
{
	Super::BeginPlay();
	
	//ここに初めに行いたい処理を書き込む
}

// Called every frame
void ACPPActorTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//ここに毎フレーム行う処理を書き込む

	//自キャラとこのアクタの距離を変数に格納
	DistFromCharacter = CalcDistace();
	//自キャラ→このアクタ方向ベクトル（x,y平面上の値だけ持つ）を1のサイズで得る
	VecCtoA = CalcDirection();
	VecCtoA.Z = 0.0;
	VecCtoA.Normalize();
	//画面上に距離を表示
	UKismetSystemLibrary::PrintString(this, FString::SanitizeFloat(DistFromCharacter), true, true, FColor::Cyan, 2.f, TEXT("None"));
}

