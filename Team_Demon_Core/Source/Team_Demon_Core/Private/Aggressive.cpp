


#include "Aggressive.h"
#include "Math/UnrealMathUtility.h"
#include "Math/Vector.h"
#include "Math/Rotator.h"

// Sets default values
AAggressive::AAggressive()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;




}

// Called when the game starts or when spawned
void AAggressive::BeginPlay()
{
	StartLocation = GetActorLocation();
	FVector Location = GetActorLocation();
	FVector Direction = TargetLocation - Location;
	FRotator TargetRotation = Direction.Rotation();

	Super::BeginPlay();
	delay = GetWorld()->GetTimeSeconds();
	
	DefaultValue = AttackTimes;
	
		
	
}
//turns fish 180 degrees upon collision with 1 second delay to not collide multiple times per collision.
void AAggressive::OnOverlapBeg()
{
	if (CollisionTimer < GetWorld()->GetTimeSeconds())
	{
		AttackTimes -= 1;
		CollisionTimer += GetWorld()->GetTimeSeconds();

		FRotator CurrentRotation = GetActorRotation();
		FRotator NewRotation = FRotator(CurrentRotation.Pitch, CurrentRotation.Yaw + 180.0f, CurrentRotation.Roll);
		FVector NewLocation = GetActorLocation() + NewRotation.Vector() * 20.0f;
		SetActorTransform(FTransform(NewRotation, NewLocation));
	}
	
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("My Int Value: %d"), AttackTimes));
	//FVector Location = GetActorLocation();
	//FVector Direction = TargetLocation - Location;
	//Direction.Normalize();
	//Direction *= -1.0f * 10.0f;
	//FRotator TargetRotation = Direction.Rotation();
	//
	//SetActorRotation(TargetRotation);
	//Location += Direction * 10.0f;
	//SetActorLocation(Location);
	TimeBetweenAttack += GetWorld()->GetTimeSeconds();
	if (AttackTimes < 1) {
		IsAttacking = false;
		ResetAttackTimer += GetWorld()->GetTimeSeconds();
	}
}

// Called every frame
void AAggressive::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	//Player in agro range of fish -> make attack move.
	FVector Player = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	FVector Location = GetActorLocation();
	distance = FVector::Dist(Location, Player);
	if (distance < AggroDistance && AttackTimes > 0 && TimeBetweenAttack < GetWorld()->GetTimeSeconds()) {

		FVector Direction = Player - Location;
		FRotator TargetRotation = Direction.Rotation();
		FRotator NewRotation = FMath::Lerp(GetActorRotation(), TargetRotation, DeltaTime * MaxChaseDegrees / 180.0f);
		SetActorRotation(NewRotation);
		Location += GetActorForwardVector() * MaxChaseSpeed * DeltaTime;
		Patrol = false;
	}
	//finds a random location to move to, uses spawn location as starting point, scene editable time, rotation speed and movement speed.
	else if (GetWorld()->GetTimeSeconds() > delay + TimeToMove && Patrol == true)
	{
		VolumeMin += StartLocation;
		VolumeMax += StartLocation;
		TargetLocation = FMath::RandPointInBox(FBox(FVector(VolumeMin), FVector(VolumeMax)));
		delay = GetWorld()->GetTimeSeconds();
	}
	/*FVector Player = { 1.0f, 1.0f, 1.0f };*/
	
	else if(IsAttacking == false && Patrol == true) {

		FVector Direction = TargetLocation - Location;
		FRotator TargetRotation = Direction.Rotation();
		FRotator NewRotation = FMath::Lerp(GetActorRotation(), TargetRotation, DeltaTime * MaxDegreesPerSecond / 180.0f);
		SetActorRotation(NewRotation);
		Location += GetActorForwardVector() * FloatSpeed * DeltaTime;
	}
	//Increased speed between attacks.
	else if (Patrol == false)
	{
		Location += GetActorForwardVector() * SpeedBetweenAttack * DeltaTime;
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, FString::Printf(TEXT("My Float Value: %f"), SpeedBetweenAttack));
	}

	//general forward movement.
	Location += GetActorForwardVector() * FloatSpeed * DeltaTime;
	FHitResult HitResult;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);
	if (GetWorld()->LineTraceSingleByChannel(HitResult, GetActorLocation(), Location, ECC_WorldStatic, Params))
	{
		
		Location = HitResult.ImpactPoint - GetActorForwardVector() * 10.0f; 
	}
	SetActorLocation(Location);

	//full reset for attacking once all attacks are completed + X amount of time passed.
	if (ResetAttackTimer < GetWorld()->GetTimeSeconds() && IsAttacking == false)
	{
		IsAttacking = true;
		AttackTimes = DefaultValue;
		Patrol = true;
	}

	
	
}
