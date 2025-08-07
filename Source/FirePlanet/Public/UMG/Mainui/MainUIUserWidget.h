// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainUIUserWidget.generated.h"

class UBorder;
class UButton;
/**
 * 
 */
UCLASS()
class FIREPLANET_API UMainUIUserWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeOnInitialized() override;

	UFUNCTION()
	void StartGameClicked();
	UFUNCTION()
	void SettingGameClicked();
	UFUNCTION()
	void AboutGameClicked();
	
public:
	UPROPERTY(meta = (BindWidget))
	UButton* Button_StartGame;
	UPROPERTY(meta = (BindWidget))
	UButton* Button_SettingGame;
	UPROPERTY(meta = (BindWidget))
	UButton* Button_AboutGame;

	UPROPERTY(meta = (BindWidgetAnim), Transient)
	UWidgetAnimation* DX_In;
};
