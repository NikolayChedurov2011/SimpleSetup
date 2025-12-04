#include "SS_InputInstaller.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "EnhancedInputSubsystems.h"
#include "Components/Input/SS_InputComponent.h"
#include "Interfaces/SS_InputInterface.h"
#include "Settings/SS_InputSettings.h"
#include "Tags/SS_GameplayTags.h"


void USS_InputInstaller::SetupInput(APlayerController* NewPlayerController)
{
	CachedPlayerController = NewPlayerController;

	const USS_InputSettings* InputSettings { GetDefault<USS_InputSettings>() };

	UEnhancedInputLocalPlayerSubsystem* EnhancedInputSubsystem { ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(CachedPlayerController->GetLocalPlayer()) };

	if (!IsValid(EnhancedInputSubsystem))
	{
		return;
	}

	USS_InputComponent* SS_InputComponent { CastChecked<USS_InputComponent>(CachedPlayerController->InputComponent) };

	if (!IsValid(SS_InputComponent))
	{
		return;
	}

	for (TObjectPtr<UInputMappingContext> MappingContext : InputSettings->GetInputMappingContextsChecked())
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

	SS_InputComponent->BindNativeInputAction(InputSettings->GetMovementInputConfigChecked(), SSGameplayTags::Input_Move, ETriggerEvent::Triggered, this, &ThisClass::OnInputMove);
	SS_InputComponent->BindNativeInputAction(InputSettings->GetMovementInputConfigChecked(), SSGameplayTags::Input_Move, ETriggerEvent::Completed, this, &ThisClass::OnInputMove);
	SS_InputComponent->BindNativeInputAction(InputSettings->GetMovementInputConfigChecked(), SSGameplayTags::Input_Look, ETriggerEvent::Triggered, this, &ThisClass::OnInputLook);

	SS_InputComponent->BindAbilityActions(InputSettings->GetAbilityInputConfigChecked(), this, &ThisClass::OnActionPressed, &ThisClass::OnActionReleased, &ThisClass::OnActionHeld);
}

void USS_InputInstaller::OnInputMove(const FInputActionValue& Value)
{
	if (!IsValid(CachedPlayerController->GetPawn()) || !CachedPlayerController->GetPawn()->Implements<USS_InputInterface>())
	{
		return;
	}

	ISS_InputInterface::Execute_Input_Move(CachedPlayerController->GetPawn(), Value);
}

void USS_InputInstaller::OnInputLook(const FInputActionValue& Value)
{
	if (!IsValid(CachedPlayerController->GetPawn()) || !CachedPlayerController->GetPawn()->Implements<USS_InputInterface>())
	{
		return;
	}

	ISS_InputInterface::Execute_Input_Look(CachedPlayerController->GetPawn(), Value);
}

void USS_InputInstaller::OnActionPressed(const FGameplayTag InputTag)
{
	const IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(CachedPlayerController->PlayerState);

	if (!ASCInterface)
	{
		return;
	}

	ISS_InputInterface::Execute_Input_AbilityActionPressed(ASCInterface->GetAbilitySystemComponent(), InputTag);
}

void USS_InputInstaller::OnActionReleased(const FGameplayTag InputTag)
{
	const IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(CachedPlayerController->PlayerState);

	if (!ASCInterface)
	{
		return;
	}

	ISS_InputInterface::Execute_Input_AbilityActionReleased(ASCInterface->GetAbilitySystemComponent(), InputTag);
}

void USS_InputInstaller::OnActionHeld(const FGameplayTag InputTag)
{
	const IAbilitySystemInterface* ASCInterface = Cast<IAbilitySystemInterface>(CachedPlayerController->PlayerState);

	if (!ASCInterface)
	{
		return;
	}

	ISS_InputInterface::Execute_Input_AbilityActionHeld(ASCInterface->GetAbilitySystemComponent(), InputTag);
}