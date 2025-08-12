// Fill out your copyright notice in the Description page of Project Settings.


#include "Framework/MainMenuLevel/MainMenuHUD.h"

#include "Blueprint/UserWidget.h"
#include "UMG/Mainui/MainUIUserWidget.h"
#include "UMG/Setting/OptionUserWidget.h"
#include "FirePlanet/FirePlanet.h"

void AMainMenuHUD::BeginPlay()
{
	Super::BeginPlay();

	GetOwningPlayerController()->SetShowMouseCursor(true);
	
	TSubclassOf<UMainUIUserWidget>const MainUIUserWidgetClass = LoadClass<UMainUIUserWidget>(nullptr,*ConstContent::MainMenuUserWidgetPath);
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
		
		if (TSubclassOf<UOptionUserWidget>const OptionUserWidgetClass = LoadClass<UOptionUserWidget>(nullptr,*ConstContent::OptionUserWidgetPath))
		{
			OptionUserWidget = CreateWidget<UOptionUserWidget>(GetOwningPlayerController(),OptionUserWidgetClass);
			if (OptionUserWidget)
			{
				OptionUserWidget->AddToViewport();
			}
		}
	}

}
