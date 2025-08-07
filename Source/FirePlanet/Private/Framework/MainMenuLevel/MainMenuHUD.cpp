// Fill out your copyright notice in the Description page of Project Settings.


#include "Framework/MainMenuLevel/MainMenuHUD.h"

#include "Blueprint/UserWidget.h"
#include "UMG/Mainui/MainUIUserWidget.h"
#include "UMG/Setting/OptionUserWidget.h"

void AMainMenuHUD::BeginPlay()
{
	Super::BeginPlay();

	GetOwningPlayerController()->SetShowMouseCursor(true);
	
	TSubclassOf<UMainUIUserWidget>const MainUIUserWidgetClass = LoadClass<UMainUIUserWidget>(nullptr,
		TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/UMG/Main/WBP_MainUI.WBP_MainUI_C'"));
	if (MainUIUserWidgetClass)
	{
		MainUIUserWidget = CreateWidget<UMainUIUserWidget>(GetOwningPlayerController(),MainUIUserWidgetClass);
		if (MainUIUserWidget)
		{
			MainUIUserWidget->AddToViewport();
		}
	}
}

void AMainMenuHUD::ShowOptionUI()
{
	if (!OptionUserWidget)
	{
		TSubclassOf<UOptionUserWidget>const OptionUserWidgetClass = LoadClass<UOptionUserWidget>(nullptr,
	TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/UMG/Setting/WBP_Option.WBP_Option_C'"));
		if (OptionUserWidgetClass)
		{
			OptionUserWidget = CreateWidget<UOptionUserWidget>(GetOwningPlayerController(),OptionUserWidgetClass);
			if (OptionUserWidget)
			{
				OptionUserWidget->AddToViewport();
			}
		}
	}

}
