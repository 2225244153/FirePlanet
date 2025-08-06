// Fill out your copyright notice in the Description page of Project Settings.


#include "Framework/MainMenuLevel/MainMenuHUD.h"

#include "Blueprint/UserWidget.h"
#include "UMG/Mainui/MainUIUserWidget.h"

void AMainMenuHUD::BeginPlay()
{
	Super::BeginPlay();

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
	GetOwningPlayerController()->SetShowMouseCursor(true);
	
}
