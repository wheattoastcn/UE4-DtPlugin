// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ToolMainWid.generated.h"

class UDataTable;
/**
 * 
 */
UCLASS()
class MYASSET_API UToolMainWid : public UUserWidget
{
	GENERATED_BODY()
public:
	/**
		*返回:数据表的引用路径字符串
	*/
	UFUNCTION(BlueprintCallable)
	TArray<FString> GetAllDtPath(FString DtAssetPath);

	//对应表名称的表路径
	TArray<FString> DtPaths;

	//选中的表
	UDataTable* CurrentDt=nullptr;

	//更改选中的数据表
	UFUNCTION(BlueprintCallable)
	void SetCurrenDt(int index);

	/**	
		*返回:数据表的表头字符串数组
	*/
	UFUNCTION(BlueprintCallable)
	TArray<FString> GetDtTitle();

	/**
		*参数:查找表的对应的行的行数
		*返回:除了行名称的其他行内容字符串数组
	*/
	UFUNCTION(BlueprintCallable)
	TArray<FString> GetRowByIndex(int index);

	/**
		*返回:对应数据表的所有行名称 
	*/
	UFUNCTION(BlueprintCallable)
	TArray<FName> GetAllRowName();

	/**
		*参数：行名称和行内容
		*返回：行名称和行内容结合的字符串
	*/
	UFUNCTION(BlueprintCallable)
	TArray<FString> GetOneRow(FString rn,TArray<FString> detail);

	UFUNCTION(BlueprintCallable)
	UDataTable* GetCurrentDT();
};
