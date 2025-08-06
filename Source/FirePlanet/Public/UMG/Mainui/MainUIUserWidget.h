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
	
public:
	/*UPROPERTY(meta = (BindWidget))
	UButton* TestButton;

	UPROPERTY(meta = (BindWidget))
	UBorder* TestBorder;*/

	//纯虚函数  用于子类重写 不能再cpp文件里进行实现
	/*UFUNCTION(BlueprintImplementableEvent,BlueprintCallable)
	UBorder* GetBorder();*/

	UFUNCTION(BlueprintCallable)
	void CallFunction();
	
};
