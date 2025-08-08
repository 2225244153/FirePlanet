// Fill out your copyright notice in the Description page of Project Settings.


#include "UMG/Setting/NormalOptionWidget.h"

#include "Components/ComboBoxString.h"
#include "Kismet/KismetInternationalizationLibrary.h"



void UNormalOptionWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	ComboBoxString_Language->OnSelectionChanged.AddDynamic(this,&UNormalOptionWidget::OnLanguageSelectionChanged);
	ComboBoxString_Resolution->OnSelectionChanged.AddDynamic(this,&UNormalOptionWidget::OnResolutionSelectionChanged);
	FString Str = UKismetInternationalizationLibrary::GetCurrentCulture();
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
	if (SelectedItem == FString(TEXT("1920x1080")))
	{
		
	}
	else if (SelectedItem == FString(TEXT("1280x720")))
	{
		
	}
	else if (SelectedItem == FString(TEXT("640x480")))
	{
		
	}
	else if (SelectedItem == FString(TEXT("320x200")))
	{
		
	}
	else
	{
		
	}
	
}
