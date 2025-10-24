#include "Input/SS_InputConfig.h"

const UInputAction* USS_InputConfig::FindInputActionByTag(const FGameplayTag& InputTag) const
{
	const FInputActionConfig* FindInputActionConfig = InputActionsConfig.FindByPredicate([InputTag](const FInputActionConfig& InputActionConfig)
	{
		return InputActionConfig.GameplayTag == InputTag;
	});

	return FindInputActionConfig->InputAction;
}