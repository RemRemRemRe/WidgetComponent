﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "ComponentBasedWidget.h"

#include "WidgetComponentAsExtension.h"
#include "WidgetComponentStatics.h"
#include "Macro/AssertionMacros.h"

TArray<UWidgetComponentBase*> UComponentBasedWidget::GetComponents() const
{
	return Components;
}

TArray<TObjectPtr<UWidgetComponentBase>> UComponentBasedWidget::GetComponentsPtr() const
{
	return Components;
}

FArrayProperty* UComponentBasedWidget::GetComponentsProperty() const
{
	static FArrayProperty* Prop = FindFieldChecked<FArrayProperty>(GetClass(),
		GET_MEMBER_NAME_CHECKED(UComponentBasedWidget, Components));
	return Prop;
}

bool UComponentBasedWidget::Initialize()
{
	UWidgetComponentAsExtension* Extension = AddExtension<UWidgetComponentAsExtension>();
	CheckPointer(Extension, return {});

	Extension->SetComponentsFiledPath(GetComponentsProperty());
	
	WidgetComponentStatics::AddComponentsToWidgetExtension(Extension);
	
	return Super::Initialize();
}
