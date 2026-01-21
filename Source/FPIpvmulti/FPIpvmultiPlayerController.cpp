// Fill out your copyright notice in the Description page of Project Settings.
#include "FPIpvmultiPlayerController.h"
#include "Blueprint/UserWidget.h"
#include "FPIpvmultiGameState.h"

void AFPIpvmultiPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	if (!IsLocalController())
		return;

	AFPIpvmultiGameState* GS =
		GetWorld()->GetGameState<AFPIpvmultiGameState>();

	if (GS)
	{
		GS->OnGameFinished.AddUObject(
			this,
			&AFPIpvmultiPlayerController::HandleGameFinished
		);
	}
}

void AFPIpvmultiPlayerController::HandleGameFinished()
{
	if (!IsLocalController()) return;

	UUserWidget* WinWidget =
		CreateWidget(this, WinWidgetClass);

	if (WinWidget)
	{
		WinWidget->AddToViewport();
	}
}
