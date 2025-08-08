// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "NormalOptionWidget.generated.h"

class UComboBoxString;
/**
 * 
 */
UCLASS()
class FIREPLANET_API UNormalOptionWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	
	virtual void NativeOnInitialized() override;
	
	UFUNCTION()
	void OnLanguageSelectionChanged(FString SelectedItem, ESelectInfo::Type SelectionType);

	UFUNCTION()
	void OnResolutionSelectionChanged(FString SelectedItem, ESelectInfo::Type SelectionType);
public:
	UPROPERTY(meta = (BindWidget))
	UComboBoxString* ComboBoxString_Language;

	UPROPERTY(meta = (BindWidget))
	UComboBoxString* ComboBoxString_Resolution;
};
