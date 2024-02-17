// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TypeInfoWid.generated.h"

/**
 * 
 */
UCLASS()
class MYASSET_API UTypeInfoWid : public UUserWidget
{
	GENERATED_BODY()

public:
	FString JSONString;

	FString KeyName;

	UFUNCTION(BlueprintCallable)
	void VValueToJSONString(FVector value);

	UFUNCTION(BlueprintCallable)
	void IValueToJSONString(int32 value);

	UFUNCTION(BlueprintCallable)
	void FValueToJSONString(float value);

	UFUNCTION(BlueprintCallable)
	void CValueToJSONString(FLinearColor value);

	UFUNCTION(BlueprintCallable)
	void BValueToJSONString(bool value);



	UFUNCTION(BlueprintCallable)
	FString GetNowJSONString();

	UFUNCTION(BlueprintCallable)
	void SetJSONString(FString DefaultValue);

	UFUNCTION(BlueprintCallable)
	void SetKeyName(FString DefaultValue);


	UFUNCTION(BlueprintCallable)
	void SaveToLogDt(FString DtName, FString RowName);
private:
	bool bIsChange = false;
};
