// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "BPandCPP/Public/Sample_01.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeSample_01() {}
// Cross Module References
	BPANDCPP_API UClass* Z_Construct_UClass_ASample_01_NoRegister();
	BPANDCPP_API UClass* Z_Construct_UClass_ASample_01();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_BPandCPP();
	ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
	ENGINE_API UClass* Z_Construct_UClass_UBoxComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UTextRenderComponent_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(ASample_01::execisExtra)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->isExtra();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASample_01::execisActive)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->isActive();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ASample_01::execOnCollision_Start)
	{
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent);
		P_GET_OBJECT(AActor,Z_Param_OtherActor);
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp);
		P_GET_PROPERTY(FIntProperty,Z_Param_OtherBodyIndex);
		P_GET_UBOOL(Z_Param_bFromSweep);
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnCollision_Start(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult);
		P_NATIVE_END;
	}
	void ASample_01::StaticRegisterNativesASample_01()
	{
		UClass* Class = ASample_01::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "isActive", &ASample_01::execisActive },
			{ "isExtra", &ASample_01::execisExtra },
			{ "OnCollision_Start", &ASample_01::execOnCollision_Start },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ASample_01_isActive_Statics
	{
		struct Sample_01_eventisActive_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ASample_01_isActive_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Sample_01_eventisActive_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASample_01_isActive_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(Sample_01_eventisActive_Parms), &Z_Construct_UFunction_ASample_01_isActive_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASample_01_isActive_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASample_01_isActive_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASample_01_isActive_Statics::Function_MetaDataParams[] = {
		{ "Category", "ASample Functions" },
		{ "Comment", "// check activation\n" },
		{ "ModuleRelativePath", "Public/Sample_01.h" },
		{ "ToolTip", "check activation" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASample_01_isActive_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASample_01, nullptr, "isActive", nullptr, nullptr, sizeof(Sample_01_eventisActive_Parms), Z_Construct_UFunction_ASample_01_isActive_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASample_01_isActive_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASample_01_isActive_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASample_01_isActive_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASample_01_isActive()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASample_01_isActive_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASample_01_isExtra_Statics
	{
		struct Sample_01_eventisExtra_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ASample_01_isExtra_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((Sample_01_eventisExtra_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASample_01_isExtra_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(Sample_01_eventisExtra_Parms), &Z_Construct_UFunction_ASample_01_isExtra_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASample_01_isExtra_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASample_01_isExtra_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASample_01_isExtra_Statics::Function_MetaDataParams[] = {
		{ "Category", "ASample Functions" },
		{ "Comment", "// check extra \n" },
		{ "ModuleRelativePath", "Public/Sample_01.h" },
		{ "ToolTip", "check extra" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASample_01_isExtra_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASample_01, nullptr, "isExtra", nullptr, nullptr, sizeof(Sample_01_eventisExtra_Parms), Z_Construct_UFunction_ASample_01_isExtra_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASample_01_isExtra_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x14020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASample_01_isExtra_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASample_01_isExtra_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASample_01_isExtra()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASample_01_isExtra_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ASample_01_OnCollision_Start_Statics
	{
		struct Sample_01_eventOnCollision_Start_Parms
		{
			UPrimitiveComponent* OverlappedComponent;
			AActor* OtherActor;
			UPrimitiveComponent* OtherComp;
			int32 OtherBodyIndex;
			bool bFromSweep;
			FHitResult SweepResult;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OverlappedComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OverlappedComponent;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OtherComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherComp;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_OtherBodyIndex;
		static void NewProp_bFromSweep_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bFromSweep;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SweepResult_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_SweepResult;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASample_01_OnCollision_Start_Statics::NewProp_OverlappedComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ASample_01_OnCollision_Start_Statics::NewProp_OverlappedComponent = { "OverlappedComponent", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Sample_01_eventOnCollision_Start_Parms, OverlappedComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_ASample_01_OnCollision_Start_Statics::NewProp_OverlappedComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ASample_01_OnCollision_Start_Statics::NewProp_OverlappedComponent_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ASample_01_OnCollision_Start_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Sample_01_eventOnCollision_Start_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASample_01_OnCollision_Start_Statics::NewProp_OtherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ASample_01_OnCollision_Start_Statics::NewProp_OtherComp = { "OtherComp", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Sample_01_eventOnCollision_Start_Parms, OtherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_ASample_01_OnCollision_Start_Statics::NewProp_OtherComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ASample_01_OnCollision_Start_Statics::NewProp_OtherComp_MetaData)) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ASample_01_OnCollision_Start_Statics::NewProp_OtherBodyIndex = { "OtherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Sample_01_eventOnCollision_Start_Parms, OtherBodyIndex), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_ASample_01_OnCollision_Start_Statics::NewProp_bFromSweep_SetBit(void* Obj)
	{
		((Sample_01_eventOnCollision_Start_Parms*)Obj)->bFromSweep = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ASample_01_OnCollision_Start_Statics::NewProp_bFromSweep = { "bFromSweep", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(Sample_01_eventOnCollision_Start_Parms), &Z_Construct_UFunction_ASample_01_OnCollision_Start_Statics::NewProp_bFromSweep_SetBit, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASample_01_OnCollision_Start_Statics::NewProp_SweepResult_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ASample_01_OnCollision_Start_Statics::NewProp_SweepResult = { "SweepResult", nullptr, (EPropertyFlags)0x0010008008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(Sample_01_eventOnCollision_Start_Parms, SweepResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(Z_Construct_UFunction_ASample_01_OnCollision_Start_Statics::NewProp_SweepResult_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ASample_01_OnCollision_Start_Statics::NewProp_SweepResult_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ASample_01_OnCollision_Start_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASample_01_OnCollision_Start_Statics::NewProp_OverlappedComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASample_01_OnCollision_Start_Statics::NewProp_OtherActor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASample_01_OnCollision_Start_Statics::NewProp_OtherComp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASample_01_OnCollision_Start_Statics::NewProp_OtherBodyIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASample_01_OnCollision_Start_Statics::NewProp_bFromSweep,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ASample_01_OnCollision_Start_Statics::NewProp_SweepResult,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ASample_01_OnCollision_Start_Statics::Function_MetaDataParams[] = {
		{ "Comment", "/* UPROPERTY - Declaration, Description(s) and usage\n\x09https://unrealcommunity.wiki/revisions/61799c5c65f766208636d1d3\n\x09https://docs.unrealengine.com/en-us/Programming/UnrealArchitecture/Reference/Properties\n\x09*/" },
		{ "ModuleRelativePath", "Public/Sample_01.h" },
		{ "ToolTip", "UPROPERTY - Declaration, Description(s) and usage\n      https://unrealcommunity.wiki/revisions/61799c5c65f766208636d1d3\n      https://docs.unrealengine.com/en-us/Programming/UnrealArchitecture/Reference/Properties" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ASample_01_OnCollision_Start_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ASample_01, nullptr, "OnCollision_Start", nullptr, nullptr, sizeof(Sample_01_eventOnCollision_Start_Parms), Z_Construct_UFunction_ASample_01_OnCollision_Start_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ASample_01_OnCollision_Start_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ASample_01_OnCollision_Start_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ASample_01_OnCollision_Start_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ASample_01_OnCollision_Start()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ASample_01_OnCollision_Start_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ASample_01_NoRegister()
	{
		return ASample_01::StaticClass();
	}
	struct Z_Construct_UClass_ASample_01_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Frame_Box_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Frame_Box;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_infoTextRender_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_infoTextRender;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_infoText_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_infoText;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Value_01_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_Value_01;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Value_02_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Value_02;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Flag_01_MetaData[];
#endif
		static void NewProp_Flag_01_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_Flag_01;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Object_01_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Object_01;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Value_A_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_Value_A;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Value_B_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_Value_B;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Value_C_01_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_Value_C_01;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Value_C_02_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_Value_C_02;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ASample_01_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_BPandCPP,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ASample_01_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ASample_01_isActive, "isActive" }, // 178217443
		{ &Z_Construct_UFunction_ASample_01_isExtra, "isExtra" }, // 3713061520
		{ &Z_Construct_UFunction_ASample_01_OnCollision_Start, "OnCollision_Start" }, // 909386243
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASample_01_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "Sample_01.h" },
		{ "ModuleRelativePath", "Public/Sample_01.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASample_01_Statics::NewProp_Frame_Box_MetaData[] = {
		{ "Category", "Sample_01" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Sample_01.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASample_01_Statics::NewProp_Frame_Box = { "Frame_Box", nullptr, (EPropertyFlags)0x0010000000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASample_01, Frame_Box), Z_Construct_UClass_UBoxComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASample_01_Statics::NewProp_Frame_Box_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASample_01_Statics::NewProp_Frame_Box_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASample_01_Statics::NewProp_infoTextRender_MetaData[] = {
		{ "Category", "Sample_01" },
		{ "Comment", "// BoxCollision in BP\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Sample_01.h" },
		{ "ToolTip", "BoxCollision in BP" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASample_01_Statics::NewProp_infoTextRender = { "infoTextRender", nullptr, (EPropertyFlags)0x0010000000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASample_01, infoTextRender), Z_Construct_UClass_UTextRenderComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASample_01_Statics::NewProp_infoTextRender_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASample_01_Statics::NewProp_infoTextRender_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASample_01_Statics::NewProp_infoText_MetaData[] = {
		{ "Category", "Sample_01" },
		{ "Comment", "// TextRender in BP\n" },
		{ "ModuleRelativePath", "Public/Sample_01.h" },
		{ "ToolTip", "TextRender in BP" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_ASample_01_Statics::NewProp_infoText = { "infoText", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASample_01, infoText), METADATA_PARAMS(Z_Construct_UClass_ASample_01_Statics::NewProp_infoText_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASample_01_Statics::NewProp_infoText_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASample_01_Statics::NewProp_Value_01_MetaData[] = {
		{ "Category", "ASample integer" },
		{ "Comment", "/* UFUNCTION - Declaration for Blueprint, Description(s) and example\n\x09https://docs.unrealengine.com/4.26/en-US/ProgrammingAndScripting/GameplayArchitecture/Functions/\n\x09https://docs.unrealengine.com/en-US/Programming/UnrealArchitecture/Reference/Functions\n\x09https://answers.unrealengine.com/questions/543285/global-blueprint-callable-c-functions.html // bp function libraries \n\x09*/// .. your comment for Value_01\n" },
		{ "ModuleRelativePath", "Public/Sample_01.h" },
		{ "ToolTip", "UFUNCTION - Declaration for Blueprint, Description(s) and example\n      https://docs.unrealengine.com/4.26/en-US/ProgrammingAndScripting/GameplayArchitecture/Functions/\n      https://docs.unrealengine.com/en-US/Programming/UnrealArchitecture/Reference/Functions\n      https://answers.unrealengine.com/questions/543285/global-blueprint-callable-c-functions.html // bp function libraries\n      // .. your comment for Value_01" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_ASample_01_Statics::NewProp_Value_01 = { "Value_01", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASample_01, Value_01), METADATA_PARAMS(Z_Construct_UClass_ASample_01_Statics::NewProp_Value_01_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASample_01_Statics::NewProp_Value_01_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASample_01_Statics::NewProp_Value_02_MetaData[] = {
		{ "Category", "ASample Float" },
		{ "Comment", "//.. your comment for Value_02\n" },
		{ "ModuleRelativePath", "Public/Sample_01.h" },
		{ "ToolTip", ".. your comment for Value_02" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ASample_01_Statics::NewProp_Value_02 = { "Value_02", nullptr, (EPropertyFlags)0x0010000000020015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASample_01, Value_02), METADATA_PARAMS(Z_Construct_UClass_ASample_01_Statics::NewProp_Value_02_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASample_01_Statics::NewProp_Value_02_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASample_01_Statics::NewProp_Flag_01_MetaData[] = {
		{ "Category", "ASample Bool" },
		{ "ModuleRelativePath", "Public/Sample_01.h" },
	};
#endif
	void Z_Construct_UClass_ASample_01_Statics::NewProp_Flag_01_SetBit(void* Obj)
	{
		((ASample_01*)Obj)->Flag_01 = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ASample_01_Statics::NewProp_Flag_01 = { "Flag_01", nullptr, (EPropertyFlags)0x0010000000010005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ASample_01), &Z_Construct_UClass_ASample_01_Statics::NewProp_Flag_01_SetBit, METADATA_PARAMS(Z_Construct_UClass_ASample_01_Statics::NewProp_Flag_01_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASample_01_Statics::NewProp_Flag_01_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASample_01_Statics::NewProp_Object_01_MetaData[] = {
		{ "Category", "ASample Actor" },
		{ "ModuleRelativePath", "Public/Sample_01.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ASample_01_Statics::NewProp_Object_01 = { "Object_01", nullptr, (EPropertyFlags)0x0010000000000805, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASample_01, Object_01), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ASample_01_Statics::NewProp_Object_01_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASample_01_Statics::NewProp_Object_01_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASample_01_Statics::NewProp_Value_A_MetaData[] = {
		{ "Category", "ASample A" },
		{ "Comment", "// --\n" },
		{ "ModuleRelativePath", "Public/Sample_01.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_ASample_01_Statics::NewProp_Value_A = { "Value_A", nullptr, (EPropertyFlags)0x0010000000000004, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASample_01, Value_A), METADATA_PARAMS(Z_Construct_UClass_ASample_01_Statics::NewProp_Value_A_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASample_01_Statics::NewProp_Value_A_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASample_01_Statics::NewProp_Value_B_MetaData[] = {
		{ "Category", "ASample B" },
		{ "ModuleRelativePath", "Public/Sample_01.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_ASample_01_Statics::NewProp_Value_B = { "Value_B", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASample_01, Value_B), METADATA_PARAMS(Z_Construct_UClass_ASample_01_Statics::NewProp_Value_B_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASample_01_Statics::NewProp_Value_B_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASample_01_Statics::NewProp_Value_C_01_MetaData[] = {
		{ "Category", "ASample C" },
		{ "Comment", "// identity of player in level 2 \n" },
		{ "DisplayName", "Identity in System" },
		{ "ModuleRelativePath", "Public/Sample_01.h" },
		{ "ToolTip", "identity of player in level 2" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_ASample_01_Statics::NewProp_Value_C_01 = { "Value_C_01", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASample_01, Value_C_01), METADATA_PARAMS(Z_Construct_UClass_ASample_01_Statics::NewProp_Value_C_01_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASample_01_Statics::NewProp_Value_C_01_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ASample_01_Statics::NewProp_Value_C_02_MetaData[] = {
		{ "Category", "ASample C" },
		{ "ClampMax", "120" },
		{ "ClampMin", "1" },
		{ "Comment", "// range of skils on indentity in level 2\n" },
		{ "ModuleRelativePath", "Public/Sample_01.h" },
		{ "ToolTip", "range of skils on indentity in level 2" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_ASample_01_Statics::NewProp_Value_C_02 = { "Value_C_02", nullptr, (EPropertyFlags)0x0010000000000015, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ASample_01, Value_C_02), METADATA_PARAMS(Z_Construct_UClass_ASample_01_Statics::NewProp_Value_C_02_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ASample_01_Statics::NewProp_Value_C_02_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ASample_01_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASample_01_Statics::NewProp_Frame_Box,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASample_01_Statics::NewProp_infoTextRender,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASample_01_Statics::NewProp_infoText,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASample_01_Statics::NewProp_Value_01,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASample_01_Statics::NewProp_Value_02,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASample_01_Statics::NewProp_Flag_01,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASample_01_Statics::NewProp_Object_01,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASample_01_Statics::NewProp_Value_A,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASample_01_Statics::NewProp_Value_B,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASample_01_Statics::NewProp_Value_C_01,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ASample_01_Statics::NewProp_Value_C_02,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ASample_01_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ASample_01>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ASample_01_Statics::ClassParams = {
		&ASample_01::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ASample_01_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ASample_01_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ASample_01_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ASample_01_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ASample_01()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ASample_01_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ASample_01, 2008116289);
	template<> BPANDCPP_API UClass* StaticClass<ASample_01>()
	{
		return ASample_01::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ASample_01(Z_Construct_UClass_ASample_01, &ASample_01::StaticClass, TEXT("/Script/BPandCPP"), TEXT("ASample_01"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ASample_01);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
