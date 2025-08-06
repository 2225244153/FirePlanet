// Fill out your copyright notice in the Description page of Project Settings.


#include "Framework/MainMenuLevel/MainMenuGameMode.h"

#include "Framework/MainMenuLevel/MainMenuHUD.h"

AMainMenuGameMode::AMainMenuGameMode()
{
	HUDClass = AMainMenuHUD::StaticClass();
}
