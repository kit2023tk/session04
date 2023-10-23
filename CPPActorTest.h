// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPPActorTest.generated.h"

UCLASS()
class THIRDPERSONCPP_API ACPPActorTest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACPPActorTest();

	//自キャラとの距離（x,y平面上での）を格納する変数
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ForRunAway")
	float DistFromCharacter;

	//自キャラ→このアクタ方向のベクトル（x,y平面の値だけ持つ）を格納する変数
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ForRunAway")
	FVector VecCtoA;
	
	//距離を計算する関数
	UFUNCTION(BlueprintCallable, Category = "ForRunAway")
	float CalcDistace();
	
	//方向を計算する関数
	UFUNCTION(BlueprintCallable, Category = "ForRunAway")
	FVector CalcDirection();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
