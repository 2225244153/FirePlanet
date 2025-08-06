// Fill out your copyright notice in the Description page of Project Settings.


#include "UMG/Mainui/MainUIUserWidget.h"

#include "Components/Border.h"
#include "Components/Button.h"


void UMainUIUserWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	/*//获取蓝图添加的控件
	if (UButton* Btn = Cast<UButton>(GetWidgetFromName(TEXT("Button_50"))))
	{
		Btn->OnClicked.AddDynamic(this, &UMainUIUserWidget::CallFunction);
	}*/

	//TestButton->OnClicked.AddDynamic(this,&UMainUIUserWidget::CallFunction);


	
}

void UMainUIUserWidget::CallFunction()
{
	/*if (GetBorder())
	{
		GetBorder()->SetBrushColor(FLinearColor(FMath::FRand(),FMath::FRand(),FMath::FRand(),1));
	}*/
	UE_LOG(LogTemp,Warning,TEXT("UMainUIUserWidget::CallFunction"));
}
