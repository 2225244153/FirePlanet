// Fill out your copyright notice in the Description page of Project Settings.


#include "UMG/Setting/NormalOptionWidget.h"

#include "Components/CheckBox.h"
#include "Components/ComboBoxString.h"
#include "Kismet/KismetInternationalizationLibrary.h"
#include "Kismet/KismetSystemLibrary.h"


void UNormalOptionWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	ComboBoxString_Language->OnSelectionChanged.AddDynamic(this,&UNormalOptionWidget::OnLanguageSelectionChanged);
	ComboBoxString_Resolution->OnSelectionChanged.AddDynamic(this,&UNormalOptionWidget::OnResolutionSelectionChanged);
	CheckBox_FullScreen->OnCheckStateChanged.AddDynamic(this,&UNormalOptionWidget::OnFullScreenCheck);
	
	FString const Str = UKismetInternationalizationLibrary::GetCurrentCulture();
	ComboBoxString_Language->SetSelectedOption(Str);

	
}

void UNormalOptionWidget::OnLanguageSelectionChanged(FString SelectedItem, ESelectInfo::Type SelectionType)
{
	if (SelectedItem == FString( TEXT("中文")))
	{
		UKismetInternationalizationLibrary::SetCurrentCulture("zh");
	}
	else if (SelectedItem == FString(TEXT("English")))
	{
		UKismetInternationalizationLibrary::SetCurrentCulture("en");
	}
	else
	{
		//默认是中文
		UKismetInternationalizationLibrary::SetCurrentCulture("zh");
	}
}

void UNormalOptionWidget::OnResolutionSelectionChanged(FString SelectedItem, ESelectInfo::Type SelectionType)
{
	FString Result;
	Result.Append(FString(TEXT("setRes ")));
	Result.Append(SelectedItem);
	Result.Append(GetScreenState());
	UKismetSystemLibrary::ExecuteConsoleCommand(GetWorld(),Result);
	/*if (UGameUserSettings* GameUserSettings = UGameUserSettings::GetGameUserSettings())
	{
		FString LeftStr;
		FString RightStr;
		UKismetStringLibrary::Split(SelectedItem,FString(TEXT("x")),LeftStr,RightStr);
		int32 const Width = UKismetStringLibrary::Conv_StringToInt(LeftStr);
		int32 const Height = UKismetStringLibrary::Conv_StringToInt(RightStr);
		GameUserSettings->SetScreenResolution(FIntPoint(Width,Height));
		GameUserSettings->ApplySettings(false);
		GameUserSettings->SetFullscreenMode(GetWindowMode());
		GameUserSettings->SaveSettings();
	}*/
}

void UNormalOptionWidget::OnFullScreenCheck(bool bIsChecked)
{
	if (bIsChecked)
	{
		UKismetSystemLibrary::ExecuteConsoleCommand(GetWorld(),FString(TEXT("setRes 1920x1080f")));
	}
	else
	{
		FString Result;
		Result.Append(FString(TEXT("setRes ")));
		Result.Append(ComboBoxString_Resolution->GetSelectedOption());
		Result.Append(GetScreenState());
		UKismetSystemLibrary::ExecuteConsoleCommand(GetWorld(),Result);
	}
}

FString UNormalOptionWidget::GetScreenState()
{
	if (CheckBox_FullScreen->IsChecked())
	{
		return FString(TEXT("f"));
	}
	else
	{
		return FString(TEXT("w"));
	}
}

EWindowMode::Type UNormalOptionWidget::GetWindowMode()
{
	if (CheckBox_FullScreen->IsChecked())
	{
		return EWindowMode::Type::Fullscreen;
	}
	else
	{
		return EWindowMode::Type::Windowed;
	}
}




