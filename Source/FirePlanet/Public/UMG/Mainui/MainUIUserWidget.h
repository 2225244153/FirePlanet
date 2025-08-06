// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainUIUserWidget.generated.h"

class UButton;
/**
 * 
 */
UCLASS()
class FIREPLANET_API UMainUIUserWidget : public UUserWidget
{
	GENERATED_BODY()

protected:

	
public:
	UPROPERTY(meta = (BindWidget="Button_50"))
	UButton* Button_50;

	UFUNCTION(BlueprintCallable,BlueprintNativeEvent)
	void ButtonClickedCallBack();
	
};
