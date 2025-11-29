#include "Tags/SS_GameplayTags.h"

namespace SSGameplayTags
{
	/**** Input Tags ****/
	UE_DEFINE_GAMEPLAY_TAG(Input,											"Input")
	UE_DEFINE_GAMEPLAY_TAG(Input_Move,										"Input.Move")
	UE_DEFINE_GAMEPLAY_TAG(Input_Look,										"Input.Look")
	UE_DEFINE_GAMEPLAY_TAG(Input_Esc,										"Input.Esc")
	UE_DEFINE_GAMEPLAY_TAG(Input_RMB,										"Input.RMB")
	UE_DEFINE_GAMEPLAY_TAG(Input_LMB,										"Input.LMB")
	UE_DEFINE_GAMEPLAY_TAG(Input_Acceleration,								"Input.Acceleration")
	UE_DEFINE_GAMEPLAY_TAG(Input_Alt,										"Input.Alt")
	UE_DEFINE_GAMEPLAY_TAG(Input_Jump,										"Input.Jump")
	UE_DEFINE_GAMEPLAY_TAG(Input_Interaction,								"Input.Interaction")
	UE_DEFINE_GAMEPLAY_TAG(Input_Slot1,										"Input.Slot1")
	UE_DEFINE_GAMEPLAY_TAG(Input_Slot2,										"Input.Slot2")
	UE_DEFINE_GAMEPLAY_TAG(Input_Slot3,										"Input.Slot3")
	UE_DEFINE_GAMEPLAY_TAG(Input_Slot4,										"Input.Slot4")
	UE_DEFINE_GAMEPLAY_TAG(Input_Slot5,										"Input.Slot5")
	UE_DEFINE_GAMEPLAY_TAG(Input_Slot6,										"Input.Slot6")
	UE_DEFINE_GAMEPLAY_TAG(Input_Slot7,										"Input.Slot7")
	UE_DEFINE_GAMEPLAY_TAG(Input_Slot8,										"Input.Slot8")
	UE_DEFINE_GAMEPLAY_TAG(Input_Slot9,										"Input.Slot9")
	UE_DEFINE_GAMEPLAY_TAG(Input_Slot0,										"Input.Slot0")

	/**** Message Tags ****/
	UE_DEFINE_GAMEPLAY_TAG(Message,											"Message")

	/**** Attributes Tags ****/
	UE_DEFINE_GAMEPLAY_TAG(Attribute_Primary,								"Attribute.Primary")
	
	UE_DEFINE_GAMEPLAY_TAG(Attribute_Main_Health,							"Attribute.Main.Health")
	UE_DEFINE_GAMEPLAY_TAG(Attribute_Main_MaxHealth,						"Attribute.Main.MaxHealth")
	UE_DEFINE_GAMEPLAY_TAG(Attribute_Main_Mana,								"Attribute.Main.Mana")
	UE_DEFINE_GAMEPLAY_TAG(Attribute_Main_MaxMana,							"Attribute.Main.MaxMana")
	
	UE_DEFINE_GAMEPLAY_TAG(Attribute_Main_MovementSpeed,					"Attribute.Main.MovementSpeed")
	UE_DEFINE_GAMEPLAY_TAG(Attribute_Main_MaxMovementSpeed,					"Attribute.Main.MaxMovementSpeed")

	/**** Event Tags ****/
	UE_DEFINE_GAMEPLAY_TAG(Event_Montage_SpawnEffect,						"Event.Montage.SpawnEffect")
	UE_DEFINE_GAMEPLAY_TAG(Event_Montage_StartWeaponHit,					"Event.Montage.StartWeaponHit")
	UE_DEFINE_GAMEPLAY_TAG(Event_Montage_StopWeaponHit,						"Event.Montage.StopWeaponHit")

	/**** Effect Tags ****/
	UE_DEFINE_GAMEPLAY_TAG(Effect,											"Effect")
	UE_DEFINE_GAMEPLAY_TAG(Effect_HitReact,									"Effect.HitReact")
	UE_DEFINE_GAMEPLAY_TAG(Effect_DamageImmunity,							"Effect.DamageImmunity")
	UE_DEFINE_GAMEPLAY_TAG(Effect_Immortality,								"Effect.Immortality")

	/**** Menu Tags ****/
	UE_DEFINE_GAMEPLAY_TAG(Menu_SaveSlot,									"Menu.SaveSlot")

	/**** Ability cooldown Tags ****/
	UE_DEFINE_GAMEPLAY_TAG(Cooldown,										"Cooldown")
	UE_DEFINE_GAMEPLAY_TAG(Cooldown_Weapon,									"Cooldown.Weapon")
	
	/**** Ability cost Tags ****/
	UE_DEFINE_GAMEPLAY_TAG(Cost,											"Cost")
	UE_DEFINE_GAMEPLAY_TAG(Cost_Mana,										"Cost.Mana")
	UE_DEFINE_GAMEPLAY_TAG(Cost_Health,										"Cost.Health")
}