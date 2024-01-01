// Fill out your copyright notice in the Description page of Project Settings.


#include "SjCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "EnhancedInputComponent.h"
#include "Kismet/KismetMathLibrary.h"


// Sets default values
ASjCharacter::ASjCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);//OK

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
	
	GetMesh()->SetRelativeRotation(FRotator(0, -90.0f, 0));
	GetMesh()->SetRelativeLocation(FVector(0, 0, -GetCapsuleComponent()->GetScaledCapsuleHalfHeight()));

}

void ASjCharacter::Move(const FInputActionValue& Value)
{
	//¿Ü¿ö
	FVector2D Dir = Value.Get<FVector2D>();
	
	FRotator CameraRot = GetControlRotation();
	FRotator DirRot = FRotator(0, CameraRot.Yaw, 0);

	FVector ForwardVector = UKismetMathLibrary::GetForwardVector(DirRot);
	FVector RightVector = UKismetMathLibrary::GetRightVector(DirRot);

	AddMovementInput(ForwardVector, Dir.Y);
	AddMovementInput(RightVector, Dir.X);
	
}

void ASjCharacter::Look(const FInputActionValue& Value)
{
	FVector2D Dir = Value.Get<FVector2D>();

	AddControllerYawInput(Dir.X);
	AddControllerPitchInput(Dir.Y);

}

// Called when the game starts or when spawned
void ASjCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASjCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASjCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UEnhancedInputComponent* UEIC = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (IsValid(UEIC))
	{
		UEIC->BindAction(IA_Jump, ETriggerEvent::Started, this, &ASjCharacter::Jump);
		UEIC->BindAction(IA_Jump, ETriggerEvent::Completed, this, &ASjCharacter::StopJumping);

		UEIC->BindAction(IA_Look, ETriggerEvent::Triggered, this, &ASjCharacter::Look);
		UEIC->BindAction(IA_Move, ETriggerEvent::Triggered, this, &ASjCharacter::Move);
	}
}

