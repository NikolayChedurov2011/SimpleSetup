#include "Player/SS_PlayerController.h"

#include "EnhancedInputSubsystems.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "Components/Input/SS_InputComponent.h"
#include "Interfaces/SS_InputInterface.h"

void ASS_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	checkf(MovementInputConfig, TEXT("Forgot to assign valid data asset, please fill out InputConfig in the Player Controller"));
	checkf(!MappingContexts.IsEmpty(), TEXT("Forgot to assign mapping contexts, please fill out MappingContexts in the Player Controller"));

	UEnhancedInputLocalPlayerSubsystem* EnhancedInputSubsystem { ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()) };

	if (!IsValid(EnhancedInputSubsystem))
	{
		return;
	}

	USS_InputComponent* SS_InputComponent { CastChecked<USS_InputComponent>(InputComponent) };

	if (!IsValid(SS_InputComponent))
	{
		return;
	}

	for (TObjectPtr<UInputMappingContext>& MappingContext : MappingContexts)
	{
		EnhancedInputSubsystem->AddMappingContext(MappingContext, 0);
	}

	// I like this way, but at this moment the Pawn isn't ready
	/*SS_InputComponent->BindNativeInputActionLambda(InputConfig, SSGameplayTags::Input_Move, ETriggerEvent::Triggered, this, [this](const FInputActionInstance& Value)
	{
		ISS_InputInterface::Execute_Input_Move(GetPawn(), Value.GetValue());
	});
	SS_InputComponent->BindNativeInputActionLambda(InputConfig, SSGameplayTags::Input_Look, ETriggerEvent::Triggered, this, [this](const FInputActionInstance& Value)
	{
		ISS_InputInterface::Execute_Input_Look(GetPawn(), Value.GetValue());
	});*/

	SS_InputComponent->BindNativeInputAction(MovementInputConfig, SSGameplayTags::Input_Move, ETriggerEvent::Triggered, this, &ThisClass::OnInputMove);
	SS_InputComponent->BindNativeInputAction(MovementInputConfig, SSGameplayTags::Input_Move, ETriggerEvent::Completed, this, &ThisClass::OnInputMove);
	SS_InputComponent->BindNativeInputAction(MovementInputConfig, SSGameplayTags::Input_Look, ETriggerEvent::Triggered, this, &ThisClass::OnInputLook);

	if (IsValid(AbilityInputConfig))
	{
		SS_InputComponent->BindAbilityActions(AbilityInputConfig, this, &ThisClass::OnActionPressed, &ThisClass::OnActionReleased, &ThisClass::OnActionHeld);
	}
}

void ASS_PlayerController::OnInputMove(const FInputActionValue& Value)
{
	if (!IsValid(GetPawn()) || !GetPawn()->Implements<USS_InputInterface>())
	{
		return;
	}

	ISS_InputInterface::Execute_Input_Move(GetPawn(), Value);
}

void ASS_PlayerController::OnInputLook(const FInputActionValue& Value)
{
	if (!IsValid(GetPawn()) || !GetPawn()->Implements<USS_InputInterface>())
	{
		return;
	}

	ISS_InputInterface::Execute_Input_Look(GetPawn(), Value);
}

void ASS_PlayerController::OnActionPressed(const FGameplayTag InputTag)
{
	const IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(PlayerState);

	if (!ASCInterface)
	{
		return;
	}

	ISS_InputInterface::Execute_Input_AbilityActionPressed(ASCInterface->GetAbilitySystemComponent(), InputTag);
}

void ASS_PlayerController::OnActionReleased(const FGameplayTag InputTag)
{
	const IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(PlayerState);

	if (!ASCInterface)
	{
		return;
	}

	ISS_InputInterface::Execute_Input_AbilityActionReleased(ASCInterface->GetAbilitySystemComponent(), InputTag);
}

void ASS_PlayerController::OnActionHeld(const FGameplayTag InputTag)
{
	const IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(PlayerState);

	if (!ASCInterface)
	{
		return;
	}

	ISS_InputInterface::Execute_Input_AbilityActionHeld(ASCInterface->GetAbilitySystemComponent(), InputTag);
}