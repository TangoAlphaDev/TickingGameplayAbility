// Copyright Tango Alpha LLC. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "LyraGameplayAbility.h"
#include "LyraTickingGameplayAbility.generated.h"

UCLASS()
class LYRAGAME_API ULyraTickingGameplayAbility : public ULyraGameplayAbility
{
	GENERATED_BODY()

public:
	void Tick();
	
	// Sets ability tick enabled or disabled
	UFUNCTION(BlueprintCallable, Category = "Ability|Tick")
	void SetAbilityTickEnabled(bool bEnable);

protected:
	// Tick function that can be overridden in Blueprints
	UFUNCTION(BlueprintNativeEvent, Category = "Ability|Tick")
	void OnAbilityTick(float DeltaTime);

	virtual void OnAbilityTick_Implementation(float DeltaTime);

private:
	FTimerHandle TickTimerHandle;
	bool bIsTicking;
};
