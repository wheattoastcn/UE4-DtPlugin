// Fill out your copyright notice in the Description page of Project Settings.


#include "TypeInfoWid.h"
#include "Engine/DataTable.h"
#include "LogStruct.h"

void UTypeInfoWid::VValueToJSONString(FVector value)
{

	JSONString = "(X="+ FString::SanitizeFloat(value.X)+","+"Y="+ FString::SanitizeFloat(value.Y)+","+"Z="+ FString::SanitizeFloat(value.Z)+")";
	bIsChange = true;
}

void UTypeInfoWid::IValueToJSONString(int32 value)
{
	JSONString = FString::FromInt(value);
	bIsChange = true;
}

void UTypeInfoWid::FValueToJSONString(float value)
{
	JSONString = FString::SanitizeFloat(value);
	bIsChange = true;
}

void UTypeInfoWid::CValueToJSONString(FLinearColor value)
{
	

	JSONString = "(R=" + FString::SanitizeFloat(value.R) + "," + "G=" + FString::SanitizeFloat(value.G) + "," + "B=" + FString::SanitizeFloat(value.B) + "," + "A=" + FString::SanitizeFloat(value.A)+ ")";
	bIsChange = true;
}

void UTypeInfoWid::BValueToJSONString(bool value)
{
	if (value)
	{
		JSONString = "true";
	}
	else
	{
		JSONString = "false";
	}
	bIsChange = true;
}

FString UTypeInfoWid::GetNowJSONString()
{
	
	return JSONString;
}

void UTypeInfoWid::SetJSONString(FString DefaultValue)
{
	JSONString = DefaultValue;
}

void UTypeInfoWid::SetKeyName(FString DefaultValue)
{
	KeyName = DefaultValue;
}

void UTypeInfoWid::SaveToLogDt(FString DtName, FString RowName)
{
	if (!bIsChange) return;
	UDataTable* ChangeLogDt;

	ChangeLogDt = LoadObject<UDataTable>(nullptr, TEXT("DataTable'/MyAsset/BaseDataTable/ChangeLog.ChangeLog'"));
	FLogData fd(DtName,RowName,KeyName,JSONString);

	int32 rownum = ChangeLogDt->GetRowNames().Num();

	

	ChangeLogDt->AddRow(FName(*FString::FromInt(rownum)), fd);

}
