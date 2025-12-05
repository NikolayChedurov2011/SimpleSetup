# SimpleSetup
I was simply too lazy to do the initial input setup every time for any new project, so I made this plugin.
This is simple plugin with flexible input binding and automatic tag-based mapping that forwards input tags to the Ability System Component for easy ability activation.

## Installation:

- Execute this from the project root:
```
git submodule init
```
```
git submodule add https://github.com/NikolayChedurov2011/SimpleSetup.git Plugins/SimpleSetup/
```

- Add the SimpleSetup plugin as public module in your Build.cs
- Make sure the SimpleSetup is enabled in Plugin section of your .uproject
- In the "Project Settings->Engine->Input->Default Input Component Class" switch to SS_InputComponent
- Save pointer to **USS_InputInstaller** object in your player controller
- Override the **APlayerController**'s ```virtual void SetupInputComponent() override;```
- After the **Super** call create new object ```SS_InputInstaller = NewObject<USS_InputInstaller>();```
- Call ```SS_InputInstaller->SetupInput(this);``` to setup inputs 
- Implement ISS_InputInterface for your character and, if needed, Ability System Component
- Implement ISS_InputInterface's functions **Input_Move()**, **Input_Look()**, **Input_AbilityActionPressed()**, **Input_AbilityActionReleased()**, **Input_AbilityActionHeld()**

Assume, the functions **Input_Move()**, **Input_Look()** will be used for the character and **Input_AbilityActionPressed()**, **Input_AbilityActionReleased()**, **Input_AbilityActionHeld()** for the Ability System Component, as I do, but the place really no matter.


## How to activate Abilitites:

As input tag was sent to Ability System Component (or whenever you decided), you can find certain ability from Ability System Component by **GetActivatableAbilities()->GetDynamicSpecSouceTags()**, as I do, for example.


## How to add own Input Actions:

All settings contains in "ProjectSettings->SimpleSetupInputSettings"

If you want to use this system, then you will be need the **GameplayTag** and **InputAction** for that.
(I already added some **GameplayTags** that can be used into **SimpleSetup->Source->Tag->SS_GameplayTags**)

Inside the SimpleSetup plugin, you'll find the **DA_SS_AbilityActions_InputConfig** and **DA_SS_MovementActions_InputConfig**. Use any of them, depends of needs.
(I guess, that DA_SS_MovementActions is not the best naming as here can be not only movement inputs, but Alt, Esc and etc..)

**Make sure that your the InputAction bind with GameplayTag in DA_SS_InputConfig and added into IMC_SS_ that located in SimpleSetup->Inputs**
