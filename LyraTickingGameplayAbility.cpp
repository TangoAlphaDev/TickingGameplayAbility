// Copyright Tango Alpha LLC. All Rights Reserved.

#include "LyraTickingGameplayAbility.h"

void ULyraTickingGameplayAbility::SetAbilityTickEnabled(bool bEnable)
{
	if (bEnable && !bIsTicking)
	{
		UE_LOG(LogTemp, Log, TEXT("Enabling Ability Tick"));

		GetWorld()->GetTimerManager().SetTimer(
			TickTimerHandle,
			this,
			&ULyraTickingGameplayAbility::Tick,
			0.008f,
			true
		);
		bIsTicking = true;
	}
	else if (!bEnable && bIsTicking)
	{
		UE_LOG(LogTemp, Log, TEXT("Disabling Ability Tick"));

		GetWorld()->GetTimerManager().ClearTimer(TickTimerHandle);
		bIsTicking = false;
	}
}


void ULyraTickingGameplayAbility::Tick()
{
	OnAbilityTick(GetWorld()->GetDeltaSeconds());
}


void ULyraTickingGameplayAbility::OnAbilityTick_Implementation(float DeltaTime)
{
	// Default behavior, can be overridden in Blueprints
	UE_LOG(LogTemp, Log, TEXT("Ability Tick: %f"), DeltaTime);
}
