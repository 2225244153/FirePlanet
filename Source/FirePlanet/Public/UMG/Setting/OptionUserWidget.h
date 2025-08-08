// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "OptionUserWidget.generated.h"

class UWidgetSwitcher;
class UButton;
/**
 * 
 */
UCLASS()
class FIREPLANET_API UOptionUserWidget : public UUserWidget
{
	GENERATED_BODY()

protected:

	virtual void NativeOnInitialized() override;

	virtual void NativeDestruct() override;

	UFUNCTION()
	void NormalOptionClicked();
	UFUNCTION()
	void InputOptionClicked();
	
	UFUNCTION()
	void EscClicked();

	
	void DelayDestruct();

	FTimerHandle OutTimer;
	

public:
	UPROPERTY(meta = (BindWidget))
	UButton* Button_NormalOption;

	UPROPERTY(meta = (BindWidget))
	UButton* Button_InputOption;

	UPROPERTY(meta = (BindWidget))
	UButton* Button_Esc;

	UPROPERTY(meta = (BindWidget))
	UWidgetSwitcher* Switcher_Option;

	UPROPERTY(meta = (BindWidgetAnim), Transient)
	UWidgetAnimation* DX_In;

	UPROPERTY(meta = (BindWidgetAnim), Transient)
	UWidgetAnimation* DX_Out;
};
