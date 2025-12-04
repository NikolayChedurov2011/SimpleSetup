#include "Settings/SS_InputSettings.h"

TArray<TObjectPtr<UInputMappingContext>> USS_InputSettings::GetInputMappingContextsChecked() const
{
	checkf(!SoftMappingContexts.IsEmpty(), TEXT("Forgot to assign a valid Mapping Contexts in the Simple Setup Input Settings"));

	TArray<TObjectPtr<UInputMappingContext>> LoadedInputMappingContexts{};

	for (const TSoftObjectPtr<UInputMappingContext>& SoftMappingContext : SoftMappingContexts)
	{
		LoadedInputMappingContexts.Add(SoftMappingContext.LoadSynchronous());
	}
	return LoadedInputMappingContexts;
}

TObjectPtr<USS_InputConfig> USS_InputSettings::GetMovementInputConfigChecked() const
{
	checkf(!SoftMovementInputConfig.IsNull(), TEXT("Forgot to assign a valid Soft Movement Input Config in the Simple Setup Input Settings"));
	
	TObjectPtr<USS_InputConfig> LoadedMovementInputConfig { SoftMovementInputConfig.LoadSynchronous() };

	return LoadedMovementInputConfig;
}

TObjectPtr<USS_InputConfig> USS_InputSettings::GetAbilityInputConfigChecked() const
{
	checkf(!SoftAbilityInputConfig.IsNull(), TEXT("Forgot to assign a valid Soft Ability Input Config in the Simple Setup Input Settings"));
	
	TObjectPtr<USS_InputConfig> LoadedAbilityInputConfig { SoftAbilityInputConfig.LoadSynchronous() };

	return LoadedAbilityInputConfig;
}
