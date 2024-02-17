#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "LogStruct.generated.h"

USTRUCT()
struct  FLogData :public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
public:
	FLogData() {}

	FLogData(FString dtname, FString rowname,FString keyname,FString changevalue)
		:DtName(dtname), DtRowName(rowname), KeyName(keyname), ChangeValue(changevalue)
	{}


	UPROPERTY(Editanywhere, BlueprintReadWrite)
	FString DtName;

	UPROPERTY(Editanywhere, BlueprintReadWrite)
	FString DtRowName;

	UPROPERTY(Editanywhere, BlueprintReadWrite)
	FString KeyName;

	UPROPERTY(Editanywhere, BlueprintReadWrite)
	FString ChangeValue;
};