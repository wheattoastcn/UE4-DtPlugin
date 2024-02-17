// Code By pengcheng.zhang ChiMoHuanJing.


#include "ChangeLogWid.h"
#include "Engine/DataTable.h"

void UChangeLogWid::InitializeDt()
{
	ChangeLogDt = LoadObject<UDataTable>(nullptr,TEXT("DataTable'/MyAsset/BaseDataTable/ChangeLog.ChangeLog'"));
}

TArray<FString> UChangeLogWid::GetOneRowByIndex(int32 index)
{
	TArray<TArray<FString>> Temp;

	check(ChangeLogDt);
	TArray<FProperty*> StructProps;
	for (TFieldIterator<FProperty> PropertyIt(ChangeLogDt->RowStruct); PropertyIt; ++PropertyIt)
	{
		FProperty* Property = *PropertyIt;
		StructProps.Add(Property);

	}
	for (auto RowIt = ChangeLogDt->GetRowMap().CreateConstIterator(); RowIt; ++RowIt)
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

int32 UChangeLogWid::GetRowNum()
{
	check(ChangeLogDt);
	return (ChangeLogDt->GetRowNames().Num())-1;
}
