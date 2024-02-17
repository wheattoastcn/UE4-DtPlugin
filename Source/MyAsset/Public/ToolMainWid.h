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
		*����:���ݱ������·���ַ���
	*/
	UFUNCTION(BlueprintCallable)
	TArray<FString> GetAllDtPath(FString DtAssetPath);

	//��Ӧ�����Ƶı�·��
	TArray<FString> DtPaths;

	//ѡ�еı�
	UDataTable* CurrentDt=nullptr;

	//����ѡ�е����ݱ�
	UFUNCTION(BlueprintCallable)
	void SetCurrenDt(int index);

	/**	
		*����:���ݱ�ı�ͷ�ַ�������
	*/
	UFUNCTION(BlueprintCallable)
	TArray<FString> GetDtTitle();

	/**
		*����:���ұ�Ķ�Ӧ���е�����
		*����:���������Ƶ������������ַ�������
	*/
	UFUNCTION(BlueprintCallable)
	TArray<FString> GetRowByIndex(int index);

	/**
		*����:��Ӧ���ݱ������������ 
	*/
	UFUNCTION(BlueprintCallable)
	TArray<FName> GetAllRowName();

	/**
		*�����������ƺ�������
		*���أ������ƺ������ݽ�ϵ��ַ���
	*/
	UFUNCTION(BlueprintCallable)
	TArray<FString> GetOneRow(FString rn,TArray<FString> detail);

	UFUNCTION(BlueprintCallable)
	UDataTable* GetCurrentDT();
};
