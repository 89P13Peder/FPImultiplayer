// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "FPIpvmultiGameState.generated.h"

/**
 * 
 */

DECLARE_MULTICAST_DELEGATE(FOnGameFinished);

UCLASS()
class FPIPVMULTI_API AFPIpvmultiGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(ReplicatedUsing = OnRep_GameFinished)
	bool bGameFinished = false;

	UPROPERTY(Replicated)
	int32 PlayersInWinZone = 0;
	
	FOnGameFinished OnGameFinished;
	
	UFUNCTION()
	void OnRep_GameFinished();

	virtual void GetLifetimeReplicatedProps(
		TArray<FLifetimeProperty>& OutLifetimeProps
	) const override;
	
	UFUNCTION()
	void SetGameFinished();

};
