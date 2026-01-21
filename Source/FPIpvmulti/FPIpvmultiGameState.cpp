// Fill out your copyright notice in the Description page of Project Settings.


#include "FPIpvmultiGameState.h"
#include "Net/UnrealNetwork.h"
#include "Engine/Engine.h"

void AFPIpvmultiGameState::OnRep_GameFinished()
{
	GEngine->AddOnScreenDebugMessage(
		-1,
		5.f,
		FColor::Yellow,
		TEXT("JUEGO TERMINADO")
	);
	
	OnGameFinished.Broadcast();
}

void AFPIpvmultiGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME(AFPIpvmultiGameState, bGameFinished);
	DOREPLIFETIME(AFPIpvmultiGameState, PlayersInWinZone);
}

void AFPIpvmultiGameState::SetGameFinished()
{
	if (bGameFinished)
		return;

	bGameFinished = true;

	OnGameFinished.Broadcast();
}


