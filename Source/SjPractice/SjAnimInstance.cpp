// Fill out your copyright notice in the Description page of Project Settings.


#include "SjAnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"


void USjAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	// �������� �Լ��� ����ϱ� ���ؼ� �θ�Ŭ������ ������ �Լ��� ȣ���Ѵ�.
	Super::NativeUpdateAnimation(DeltaSeconds);

	ACharacter* SjChar = Cast<ACharacter>(TryGetPawnOwner());
	if (IsValid(SjChar))
	{
		Speed = SjChar->GetCharacterMovement()->Velocity.Size();
	}

}
