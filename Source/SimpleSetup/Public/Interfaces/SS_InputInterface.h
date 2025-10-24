#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Interface.h"
#include "SS_InputInterface.generated.h"

struct FInputActionValue;

UINTERFACE()
class USS_InputInterface : public UInterface
{
	GENERATED_BODY()
};

class SIMPLESETUP_API ISS_InputInterface
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Input_Move(const FInputActionValue& InputActionValue);
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Input_Look(const FInputActionValue& InputActionValue);
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Input_AbilityActionPressed(const FGameplayTag InputTag);
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Input_AbilityActionReleased(const FGameplayTag InputTag);
	
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Input_AbilityActionHeld(const FGameplayTag InputTag);
};
