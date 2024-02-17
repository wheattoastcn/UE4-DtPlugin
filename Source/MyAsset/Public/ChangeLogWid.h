// Code By pengcheng.zhang ChiMoHuanJing.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ChangeLogWid.generated.h"

class UDataTable;
/**
 * 
 */
UCLASS()
class MYASSET_API UChangeLogWid : public UUserWidget
{
	GENERATED_BODY()

public:
	UDataTable* ChangeLogDt;

	UFUNCTION(BlueprintCallable)
	void InitializeDt();

	UFUNCTION(BlueprintCallable)
	TArray<FString> GetOneRowByIndex(int32 index);

	UFUNCTION(BlueprintCallable)
	int32 GetRowNum();
	
};
