// Fill out your copyright notice in the Description page of Project Settings.


#include "UMG/Mainui/MainUIUserWidget.h"
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

	//PlayAnimation()

	Button_StartGame->OnClicked.AddDynamic(this,&UMainUIUserWidget::StartGameClicked);
	Button_SettingGame->OnClicked.AddDynamic(this,&UMainUIUserWidget::SettingGameClicked);
	Button_AboutGame->OnClicked.AddDynamic(this,&UMainUIUserWidget::AboutGameClicked);

	PlayAnimation(DX_In);
	
}

void UMainUIUserWidget::StartGameClicked()
{
}

void UMainUIUserWidget::SettingGameClicked()
{
	
}

void UMainUIUserWidget::AboutGameClicked()
{
}


/*
void UMainUIUserWidget::CallFunction()
{
	/*if (GetBorder())
	{
		GetBorder()->SetBrushColor(FLinearColor(FMath::FRand(),FMath::FRand(),FMath::FRand(),1));
	}#1#
	UE_LOG(LogTemp,Warning,TEXT("UMainUIUserWidget::CallFunction"));
}
*/
