// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FHitResult;
#ifdef BPANDCPP_Sample_01_generated_h
#error "Sample_01.generated.h already included, missing '#pragma once' in Sample_01.h"
#endif
#define BPANDCPP_Sample_01_generated_h

#define BPandCPP_Source_BPandCPP_Public_Sample_01_h_14_SPARSE_DATA
#define BPandCPP_Source_BPandCPP_Public_Sample_01_h_14_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execisExtra); \
	DECLARE_FUNCTION(execisActive); \
	DECLARE_FUNCTION(execOnCollision_Start);


#define BPandCPP_Source_BPandCPP_Public_Sample_01_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execisExtra); \
	DECLARE_FUNCTION(execisActive); \
	DECLARE_FUNCTION(execOnCollision_Start);


#define BPandCPP_Source_BPandCPP_Public_Sample_01_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesASample_01(); \
	friend struct Z_Construct_UClass_ASample_01_Statics; \
public: \
	DECLARE_CLASS(ASample_01, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/BPandCPP"), NO_API) \
	DECLARE_SERIALIZER(ASample_01)


#define BPandCPP_Source_BPandCPP_Public_Sample_01_h_14_INCLASS \
private: \
	static void StaticRegisterNativesASample_01(); \
	friend struct Z_Construct_UClass_ASample_01_Statics; \
public: \
	DECLARE_CLASS(ASample_01, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/BPandCPP"), NO_API) \
	DECLARE_SERIALIZER(ASample_01)


#define BPandCPP_Source_BPandCPP_Public_Sample_01_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ASample_01(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ASample_01) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASample_01); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASample_01); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASample_01(ASample_01&&); \
	NO_API ASample_01(const ASample_01&); \
public:


#define BPandCPP_Source_BPandCPP_Public_Sample_01_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ASample_01(ASample_01&&); \
	NO_API ASample_01(const ASample_01&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ASample_01); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ASample_01); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ASample_01)


#define BPandCPP_Source_BPandCPP_Public_Sample_01_h_14_PRIVATE_PROPERTY_OFFSET
#define BPandCPP_Source_BPandCPP_Public_Sample_01_h_12_PROLOG
#define BPandCPP_Source_BPandCPP_Public_Sample_01_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BPandCPP_Source_BPandCPP_Public_Sample_01_h_14_PRIVATE_PROPERTY_OFFSET \
	BPandCPP_Source_BPandCPP_Public_Sample_01_h_14_SPARSE_DATA \
	BPandCPP_Source_BPandCPP_Public_Sample_01_h_14_RPC_WRAPPERS \
	BPandCPP_Source_BPandCPP_Public_Sample_01_h_14_INCLASS \
	BPandCPP_Source_BPandCPP_Public_Sample_01_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define BPandCPP_Source_BPandCPP_Public_Sample_01_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BPandCPP_Source_BPandCPP_Public_Sample_01_h_14_PRIVATE_PROPERTY_OFFSET \
	BPandCPP_Source_BPandCPP_Public_Sample_01_h_14_SPARSE_DATA \
	BPandCPP_Source_BPandCPP_Public_Sample_01_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	BPandCPP_Source_BPandCPP_Public_Sample_01_h_14_INCLASS_NO_PURE_DECLS \
	BPandCPP_Source_BPandCPP_Public_Sample_01_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> BPANDCPP_API UClass* StaticClass<class ASample_01>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID BPandCPP_Source_BPandCPP_Public_Sample_01_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
