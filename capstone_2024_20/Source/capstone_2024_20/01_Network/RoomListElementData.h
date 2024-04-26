// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "OnlineSessionSettings.h"
#include "RoomListElementData.generated.h"

class URoomPasswordInputPopupWidget;

UCLASS()
class CAPSTONE_2024_20_API URoomListElementData : public UObject
{
	GENERATED_BODY()
	
public:
	FText RoomText;
	void SetRoomName(const FText& roomName);

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	class ANetworkService* NetworkService;
	
	FOnlineSessionSearchResult Result;

	URoomPasswordInputPopupWidget* RoomPasswordInputPopupWidget;
};
