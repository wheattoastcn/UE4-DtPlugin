// Fill out your copyright notice in the Description page of Project Settings.


#include "ToolMainWid.h"
#include "AssetRegistryModule.h"
#include "Engine/ObjectLibrary.h"
#include "Engine/DataTable.h"

TArray<FString> UToolMainWid::GetAllDtPath(FString DtAssetPath)
{
	TArray<FString> DtNames;

	UObjectLibrary* ObjectLibrary = UObjectLibrary::CreateLibrary(UDataTable::StaticClass(), false, GIsEditor);
	if (ObjectLibrary)
	{
		ObjectLibrary->AddToRoot();
	}

	ObjectLibrary->LoadAssetDataFromPath(DtAssetPath);
	TArray<FAssetData> AssetDatas;
	ObjectLibrary->GetAssetDataList(AssetDatas);

	for (const FAssetData& Assetdata : AssetDatas)
	{
		DtNames.Add(Assetdata.AssetName.ToString());
		//获取表名称时同步存储路径
		DtPaths.Add(Assetdata.ObjectPath.ToString());
	}

	return DtNames;
}

void UToolMainWid::SetCurrenDt(int index)
{
	CurrentDt = LoadObject<UDataTable>(nullptr, *DtPaths[index]);
}

TArray<FString> UToolMainWid::GetDtTitle()
{
	check(CurrentDt);
	return CurrentDt->GetColumnTitles();
}

TArray<FString> UToolMainWid::GetRowByIndex(int index)
{
	TArray<TArray<FString>> Temp;

	check(CurrentDt);
	TArray<FProperty*> StructProps;
	for (TFieldIterator<FProperty> PropertyIt(CurrentDt->RowStruct); PropertyIt; ++PropertyIt)
	{
		FProperty* Property = *PropertyIt;
		StructProps.Add(Property);

	}

	for (auto RowIt = CurrentDt->GetRowMap().CreateConstIterator(); RowIt; ++RowIt)
	{
		TArray<FString> temp;
		uint8* RowData = RowIt.Value();
		for (int32 proindex = 0; proindex < StructProps.Num(); proindex++)
		{
			
			temp.Add(DataTableUtils::GetPropertyValueAsString(StructProps[proindex], RowData, EDataTableExportFlags::None));
			
		}
		Temp.Add(temp);

	}


	if (Temp.IsValidIndex(index))
	{
		return Temp[index];
	}
	else
	{
		return TArray<FString>();
	}
}

TArray<FName> UToolMainWid::GetAllRowName()
{
	check(CurrentDt);
	return CurrentDt->GetRowNames();
}

TArray<FString> UToolMainWid::GetOneRow(FString rn, TArray<FString> detail)
{
	TArray<FString> T;
	T.Add(rn);
	for (auto onedt : detail)
	{
		T.Add(onedt);
	}

	return T;
}

UDataTable* UToolMainWid::GetCurrentDT()
{
	check(CurrentDt);
	return CurrentDt;
}
