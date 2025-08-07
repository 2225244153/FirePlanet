// Fill out your copyright notice in the Description page of Project Settings.


#include "UMG/Setting/OptionUserWidget.h"

#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Framework/MainMenuLevel/MainMenuHUD.h"

void UOptionUserWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	Button_NormalOption->OnClicked.AddDynamic(this,&UOptionUserWidget::NormalOptionClicked);
	Button_InputOption->OnClicked.AddDynamic(this,&UOptionUserWidget::InputOptionClicked);
	Button_Esc->OnClicked.AddDynamic(this,&UOptionUserWidget::EscClicked);
}

void UOptionUserWidget::NormalOptionClicked()
{
	Button_InputOption->SetRenderOpacity(1.0f);
	Button_NormalOption->SetRenderOpacity(0.5f);
	Switcher_Option->SetActiveWidgetIndex(0);
}

void UOptionUserWidget::InputOptionClicked()
{
	Button_NormalOption->SetRenderOpacity(1.0f);
	Button_InputOption->SetRenderOpacity(0.5f);
	Switcher_Option->SetActiveWidgetIndex(1);
}

void UOptionUserWidget::EscClicked()
{
	if (AMainMenuHUD* MainMenuHUD =  Cast<AMainMenuHUD>(GetOwningPlayer()->GetHUD()))
	{
		MainMenuHUD->OptionUserWidget = nullptr;
	}
}
