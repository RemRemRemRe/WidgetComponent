// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Stats/Stats.h"

//// Groups
DECLARE_STATS_GROUP(TEXT("WidgetComponent"), STATGROUP_WidgetComponent, STATCAT_Advanced);

//// Stats
DECLARE_CYCLE_STAT_EXTERN(TEXT("WidgetComponent Tick"), STAT_WidgetComponent, STATGROUP_WidgetComponent, WIDGETCOMPONENT_API);