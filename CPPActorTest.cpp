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
	//���L�����ʒu�̎擾
	FVector MyCharacterPosition = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	//���̃A�N�^�̈ʒu�̎擾
	FVector ActorPosition = GetActorLocation();

	FVector XYvector = MyCharacterPosition - ActorPosition;
	XYvector.Z = 0.0;
	return XYvector.Length();
}

FVector ACPPActorTest::CalcDirection()
{
	//���L�����ʒu�̎擾
	FVector MyCharacterPosition = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	//���̃A�N�^�̈ʒu�̎擾
	FVector ActorPosition = GetActorLocation();

	return ActorPosition - MyCharacterPosition;
}

// Called when the game starts or when spawned
void ACPPActorTest::BeginPlay()
{
	Super::BeginPlay();
	
	//�����ɏ��߂ɍs��������������������
}

// Called every frame
void ACPPActorTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//�����ɖ��t���[���s����������������

	//���L�����Ƃ��̃A�N�^�̋�����ϐ��Ɋi�[
	DistFromCharacter = CalcDistace();
	//���L���������̃A�N�^�����x�N�g���ix,y���ʏ�̒l�������j��1�̃T�C�Y�œ���
	VecCtoA = CalcDirection();
	VecCtoA.Z = 0.0;
	VecCtoA.Normalize();
	//��ʏ�ɋ�����\��
	UKismetSystemLibrary::PrintString(this, FString::SanitizeFloat(DistFromCharacter), true, true, FColor::Cyan, 2.f, TEXT("None"));
}

