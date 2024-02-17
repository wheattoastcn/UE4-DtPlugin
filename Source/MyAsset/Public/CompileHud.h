// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CompileHud.generated.h"

class UDataTable;
/**
 * 
 */
UCLASS()
class MYASSET_API UCompileHud : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable)
	void WriteToTable(UDataTable* Dt,TArray<FString> KeyName, TArray<FString> KeyValue,FName RowName,TArray<int32> CanChangeIndex);
};
