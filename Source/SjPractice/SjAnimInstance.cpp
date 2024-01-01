// Fill out your copyright notice in the Description page of Project Settings.


#include "SjAnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"


void USjAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	// 재정의한 함수를 사용하기 위해서 부모클래스의 원형의 함수를 호출한다.
	Super::NativeUpdateAnimation(DeltaSeconds);

	ACharacter* SjChar = Cast<ACharacter>(TryGetPawnOwner());
	if (IsValid(SjChar))
	{
		Speed = SjChar->GetCharacterMovement()->Velocity.Size();
	}

}
