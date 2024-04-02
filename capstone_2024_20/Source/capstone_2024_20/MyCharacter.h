
#pragma once

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "CoreMinimal.h"
#include "MyObject.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "UObject/ObjectRename.h"
#include "MyCharacter.generated.h"


class USpringArmComponent;

UCLASS()
class CAPSTONE_2024_20_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(Category=Character, VisibleAnywhere)
	USpringArmComponent* M_SpringArmComponent;
	
	UPROPERTY(Category=Character, VisibleAnywhere)
	UCameraComponent* M_CameraComponent;
	
	UPROPERTY(Category=Character, VisibleAnywhere)
	UStaticMeshComponent* M_MeshComponent;


public:
	UPROPERTY(Category=UI, VisibleAnywhere)
	class UWidgetComponent* TextWidget;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UUserWidget> ClearPopUpWidgetClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	TSubclassOf<UUserWidget> GameOverPopUpWidgetClass;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<AActor> BP_CannonBallClass;
	
protected:

	unsigned int PlayerMaxHP = 10;
	unsigned int PlayerHP = PlayerMaxHP;
	
	bool bIsChanging=false;
	float TargetArmLength;
	FRotator TargetRotation;
	float ChangeSpeed = 5.0f;
	bool bIsOverlap = false;

	AMyObject* CurrentHitObject;
	FString CurrentHitObjectName;
	AActor* SpawnedCannonBall;
	
	UFUNCTION()
	virtual void BeginOverlap(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	virtual void EndOverlap(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);


	

	
public:

	TArray<FString> ObjectList = {
		TEXT("Cannon"), 
		TEXT("SteelWheel"), 
		TEXT("CannonBallBox"), 
		TEXT("Telescope")
	};

	enum class PlayerState
	{
		NONE,
		CARRYING,
		DRAGGING
	};
	PlayerState CurrentPlayerState = PlayerState::NONE;
	void SetPlayerState(PlayerState NewPlayerState);
	
	UFUNCTION()
	bool GetIsOverLap();

	UFUNCTION()
	void SetTextWidgetVisible(bool b);

	UFUNCTION()
	bool GetTextWidgetVisible();

	UFUNCTION()
	void SetIsChanging(float length, FRotator rot, bool b);

	UFUNCTION()
	AMyObject* GetCurrentHitObject();

	UFUNCTION()
	FString GetCurrentHitObjectName();

	UFUNCTION()
	void SpawnCannonBall();	

	UFUNCTION()
	void DestroyCannonBall();

	UFUNCTION()
	void DragObject();

	UFUNCTION()
	void DropObject(AActor* ship);

	UFUNCTION()
	unsigned int GetPlayerHP();

	UFUNCTION()
	void SetPlayerHP(unsigned int hp);
	
	UFUNCTION()
	void IncreaseHP(int plusHP);

	UFUNCTION()
	void DecreaseHP(unsigned int minusHP);

	UFUNCTION()
	unsigned int GetPlayerMaxHP();

	UFUNCTION()
	void SetPlayerMaxHP(unsigned int hp);
	
	UFUNCTION()
	void IncreaseMaxHP(int plusHP);

	UFUNCTION()
	void DecreaseMaxHP(int minusHP);

	UFUNCTION()
	void PlayerDead();

};
