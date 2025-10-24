#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Tags/SS_GameplayTags.h"
#include "SS_PlayerController.generated.h"

struct FInputActionValue;
class UInputMappingContext;
class USS_InputConfig;

UCLASS()
class SIMPLESETUP_API ASS_PlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void SetupInputComponent() override;
	
	void OnInputMove(const FInputActionValue& Value);
	void OnInputLook(const FInputActionValue& Value);
	void OnActionPressed(const FGameplayTag InputTag);
	void OnActionReleased(const FGameplayTag InputTag);
	void OnActionHeld(const FGameplayTag InputTag);

private:
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TArray<TObjectPtr<UInputMappingContext>> MappingContexts {};
	
	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<USS_InputConfig> MovementInputConfig {};

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	TObjectPtr<USS_InputConfig> AbilityInputConfig {};
};
