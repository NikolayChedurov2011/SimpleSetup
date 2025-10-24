#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "Input/SS_InputConfig.h"
#include "SS_InputComponent.generated.h"

UCLASS()
class SIMPLESETUP_API USS_InputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
	template<class UserObject, typename CallbackFunc>
	void BindNativeInputAction(const USS_InputConfig* InInputConfig, const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Func);

	template<class UserObject, typename CallbackFunc>
	void BindNativeInputActionLambda(const USS_InputConfig* InInputConfig, const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Func);

	template<class UserClass, typename PressedFuncType, typename ReleasedFuncType, typename HeldFuncType>
	void BindAbilityActions(const USS_InputConfig* InputConfig, UserClass* Object, PressedFuncType PressedFunc, ReleasedFuncType ReleasedFunc, HeldFuncType HeldFunc);
};

template <class UserObject, typename CallbackFunc>
void USS_InputComponent::BindNativeInputAction(const USS_InputConfig* InInputConfig, const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Func)
{
	if(const UInputAction* FoundAction = InInputConfig->FindInputActionByTag(InInputTag))
	{
		BindAction(FoundAction, TriggerEvent, ContextObject, Func);
	}
}

template <class UserObject, typename CallbackFunc>
void USS_InputComponent::BindNativeInputActionLambda(const USS_InputConfig* InInputConfig, const FGameplayTag& InInputTag, ETriggerEvent TriggerEvent, UserObject* ContextObject, CallbackFunc Func)
{
	if(const UInputAction* FoundAction = InInputConfig->FindInputActionByTag(InInputTag))
	{
		BindActionInstanceLambda(FoundAction, TriggerEvent, Func);
	}
}

template <class UserClass, typename PressedFuncType, typename ReleasedFuncType, typename HeldFuncType>
void USS_InputComponent::BindAbilityActions(const USS_InputConfig* InputConfig, UserClass* Object, PressedFuncType PressedFunc, ReleasedFuncType ReleasedFunc, HeldFuncType HeldFunc)
{
	for (const auto& [InputAction, GameplayTag] : InputConfig->InputActionsConfig)
	{
		if (InputAction && GameplayTag.IsValid())
		{
			if (PressedFunc)
			{
				BindAction(InputAction, ETriggerEvent::Started, Object, PressedFunc, GameplayTag);
			}
			if (ReleasedFunc)
			{
				BindAction(InputAction, ETriggerEvent::Completed, Object, ReleasedFunc, GameplayTag);
			}
			if (HeldFunc)
			{
				BindAction(InputAction, ETriggerEvent::Triggered, Object, HeldFunc, GameplayTag);
			}
		}
	}
}