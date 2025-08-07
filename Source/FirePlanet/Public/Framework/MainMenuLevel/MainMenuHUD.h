// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MainMenuHUD.generated.h"

class UOptionUserWidget;
class UMainUIUserWidget;
/**
 * 
 */
UCLASS()
class FIREPLANET_API AMainMenuHUD : public AHUD
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;


	UFUNCTION(BlueprintCallable)
	void ShowOptionUI();
	
public:
	
	UPROPERTY()
	UMainUIUserWidget* MainUIUserWidget;

	UPROPERTY()
	UOptionUserWidget* OptionUserWidget;
};
