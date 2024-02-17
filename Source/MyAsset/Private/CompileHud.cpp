// Fill out your copyright notice in the Description page of Project Settings.


#include "CompileHud.h"
#include "Engine/DataTable.h"

void UCompileHud::WriteToTable(UDataTable* Dt, TArray<FString> KeyName, TArray<FString> KeyValue,FName RowName,TArray<int32> CanChangeIndex)
{
	
	if (Dt )
	{
		//获取行属性
		TArray<FProperty*> StructProps;
		for (TFieldIterator<FProperty> PropertyIt(Dt->RowStruct); PropertyIt; ++PropertyIt)
		{
			FProperty* Property = *PropertyIt;
			StructProps.Add(Property);

		}
		//修改行
		for (auto RowIt = Dt->GetRowMap().CreateConstIterator(); RowIt; ++RowIt)
		{
			if (RowIt.Key() == RowName)
			{
				int32 canindex = 0;
				uint8* RowData = RowIt.Value();
				for (int32 index = 0; index < StructProps.Num(); index++)
				{
					if (CanChangeIndex[canindex] == index)
					{
						FString Error = DataTableUtils::AssignStringToProperty(KeyValue[canindex], StructProps[index], RowData);
						UE_LOG(LogTemp, Warning, TEXT("123"));
						if (Error.Len() > 0)
						{
							UE_LOG(LogTemp, Warning, TEXT("%s"), *Error);
						}
						canindex++;
					}
					else
					{
						UE_LOG(LogTemp, Warning, TEXT("321"));
					}
				}
			}

		}
	}
}
