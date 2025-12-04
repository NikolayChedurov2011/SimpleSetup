#pragma once

#include "CoreMinimal.h"
#include "InputMappingContext.h"
#include "Engine/DeveloperSettings.h"
#include "Input/SS_InputConfig.h"
#include "SS_InputSettings.generated.h"

UCLASS(Config = Game, DefaultConfig, meta=(DisplayName="Simple Setup Input Settings"))
class SIMPLESETUP_API USS_InputSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	TArray<TObjectPtr<UInputMappingContext>> GetInputMappingContextsChecked() const;
	TObjectPtr<USS_InputConfig> GetMovementInputConfigChecked() const;
	TObjectPtr<USS_InputConfig> GetAbilityInputConfigChecked() const;
	
	UPROPERTY(Config, EditAnywhere, Category = "Input Settings")
	TArray<TSoftObjectPtr<UInputMappingContext>> SoftMappingContexts {};
	
	UPROPERTY(Config, EditAnywhere, Category = "Input Settings")
	TSoftObjectPtr<USS_InputConfig> SoftMovementInputConfig {};

	UPROPERTY(Config, EditAnywhere, Category = "Input Settings")
	TSoftObjectPtr<USS_InputConfig> SoftAbilityInputConfig {};
};
