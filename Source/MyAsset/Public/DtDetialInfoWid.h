// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DtDetialInfoWid.generated.h"

class UDataTable;
/**
 * 
 */
UCLASS()
class MYASSET_API UDtDetialInfoWid : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	TArray<FString> GetKeyType(UDataTable* Dt);

	UFUNCTION(BlueprintCallable)
	TArray<FString> GetKeyName(UDataTable* Dt);
};
