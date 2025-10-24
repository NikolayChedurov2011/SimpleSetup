#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "SS_InputConfig.generated.h"

class UInputAction;
class UInputMappingContext;

USTRUCT(Blueprintable)
struct FInputActionConfig
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	const UInputAction* InputAction {};
	
	UPROPERTY(EditDefaultsOnly)
	FGameplayTag GameplayTag = FGameplayTag();
};

UCLASS()
class SIMPLESETUP_API USS_InputConfig : public UDataAsset
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<FInputActionConfig> InputActionsConfig {};
	
	const UInputAction* FindInputActionByTag(const FGameplayTag& InputTag) const;
};