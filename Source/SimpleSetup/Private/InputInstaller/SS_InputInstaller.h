#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SS_InputInstaller.generated.h"

struct FGameplayTag;
struct FInputActionValue;

UCLASS()
class SIMPLESETUP_API USS_InputInstaller : public UObject
{
	GENERATED_BODY()

public:
	USS_InputInstaller(){}
	
	void SetupInput(APlayerController* NewPlayerController);

protected:
	void OnInputMove(const FInputActionValue& Value);
	void OnInputLook(const FInputActionValue& Value);
	void OnActionPressed(const FGameplayTag InputTag);
	void OnActionReleased(const FGameplayTag InputTag);
	void OnActionHeld(const FGameplayTag InputTag);
	
private:

	UPROPERTY()
	TObjectPtr<APlayerController> CachedPlayerController{};
};
