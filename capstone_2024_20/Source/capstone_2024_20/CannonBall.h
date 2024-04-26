// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "CannonBall.generated.h"

UCLASS()
class CAPSTONE_2024_20_API ACannonBall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACannonBall();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	float destroyDelayTime = 1.0f;
	int32 damage = 1;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void DestroyDelay();

	// 발사체의 컴포넌트들을 선언합니다.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* ProjectileMesh;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UProjectileMovementComponent* ProjectileMovement;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Effects")
	UParticleSystem* WaterSplashEffect;


	int32 GetDamage();
	void SetDamage(int32 dmg);
	
	// 충돌 시 호출될 함수
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	
};
