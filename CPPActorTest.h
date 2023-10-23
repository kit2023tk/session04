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

	//���L�����Ƃ̋����ix,y���ʏ�ł́j���i�[����ϐ�
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ForRunAway")
	float DistFromCharacter;

	//���L���������̃A�N�^�����̃x�N�g���ix,y���ʂ̒l�������j���i�[����ϐ�
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ForRunAway")
	FVector VecCtoA;
	
	//�������v�Z����֐�
	UFUNCTION(BlueprintCallable, Category = "ForRunAway")
	float CalcDistace();
	
	//�������v�Z����֐�
	UFUNCTION(BlueprintCallable, Category = "ForRunAway")
	FVector CalcDirection();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
