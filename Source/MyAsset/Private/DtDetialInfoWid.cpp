// Fill out your copyright notice in the Description page of Project Settings.


#include "DtDetialInfoWid.h"
#include "Engine/DataTable.h"

TArray<FString> UDtDetialInfoWid::GetKeyType(UDataTable* Dt)
{
	TArray<FString> temp;
	if (Dt)
	{
		const UScriptStruct* RowStruct = Dt->GetRowStruct();
		if (RowStruct)
		{
			for (TFieldIterator<FProperty> PropertyIt(RowStruct); PropertyIt; ++PropertyIt)
			{
				FProperty* Property = *PropertyIt;

				temp.Add(Property->GetCPPType());
			}
		}
	}
	return temp;
}

TArray<FString> UDtDetialInfoWid::GetKeyName(UDataTable* Dt)
{
	TArray<FString> temp;
	if (Dt)
	{
		temp = Dt->GetColumnTitles();
	}
	return temp;
}
