#include "pch-cpp.hpp"





template <typename T1>
struct VirtualActionInvoker1
{
	typedef void (*Action)(void*, T1, const RuntimeMethod*);

	static inline void Invoke (Il2CppMethodSlot slot, RuntimeObject* obj, T1 p1)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		((Action)invokeData.methodPtr)(obj, p1, invokeData.method);
	}
};
template <typename R>
struct VirtualFuncInvoker0
{
	typedef R (*Func)(void*, const RuntimeMethod*);

	static inline R Invoke (Il2CppMethodSlot slot, RuntimeObject* obj)
	{
		const VirtualInvokeData& invokeData = il2cpp_codegen_get_virtual_invoke_data(slot, obj);
		return ((Func)invokeData.methodPtr)(obj, invokeData.method);
	}
};

struct CharU5BU5D_t799905CF001DD5F13F7DBB310181FC4D8B7D0AAB;
struct TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB;
struct AdaptivePerformanceSubsystem_tBE818A622D29C1A560C740447BA4F0D7343B5214;
struct AdaptivePerformanceSubsystemDescriptor_t626A06E24BC33D89FEFD1A8D66983890D153EF16;
struct BasicAdaptivePerformanceSubsystem_t4A078575FEAD3F7D4530468B087BB18C9A468664;
struct Binder_t91BFCE95A7057FADF4D8A1A342AFE52872246235;
struct IApplicationLifecycle_tE4A6629F5CE872BC1DE34AB00522E212F66214A3;
struct IDevicePerformanceLevelControl_tFD3F70587A17ABE0DCCBDA1F3A1D63224B03C85A;
struct MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553;
struct String_t;
struct SubsystemProvider_tE1865B8FE698C81A59AED35E0E536BD53F402455;
struct Type_t;
struct Version_tE426DB5655D0F22920AE16A2AA9AB7781B8255A7;
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915;
struct APProvider_t68A181100C0A38B4BB91BEF637FCDDCC9BF59D6B;
struct BasicProvider_tDF77359CE2123F60C810DDA5ACBDA479BBEB012D;

IL2CPP_EXTERN_C RuntimeClass* Version_tE426DB5655D0F22920AE16A2AA9AB7781B8255A7_il2cpp_TypeInfo_var;
IL2CPP_EXTERN_C RuntimeField* Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA____U3CproviderTypeU3Ek__BackingField_FieldInfo_var;
IL2CPP_EXTERN_C String_t* _stringLiteral03D5C271551A28BF44745629A92B7E0E74585419;
IL2CPP_EXTERN_C String_t* _stringLiteral711CD86ED4432DF0220A669CFAC925F9949D5C48;
IL2CPP_EXTERN_C const RuntimeType* BasicAdaptivePerformanceSubsystem_t4A078575FEAD3F7D4530468B087BB18C9A468664_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* BasicProvider_tDF77359CE2123F60C810DDA5ACBDA479BBEB012D_0_0_0_var;
IL2CPP_EXTERN_C const RuntimeType* Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA_0_0_0_var;


IL2CPP_EXTERN_C_BEGIN
IL2CPP_EXTERN_C_END

#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
struct BasicProviderDescriptorRegistration_tAE488A1B10DECD8779ABC70BF9C8C2B1DAC1E245  : public RuntimeObject
{
};
struct MemberInfo_t  : public RuntimeObject
{
};
struct String_t  : public RuntimeObject
{
	int32_t ____stringLength;
	Il2CppChar ____firstChar;
};
struct SubsystemDescriptorWithProvider_t2A61A2C951A4A179E898CF207726BF6B5AF474D5  : public RuntimeObject
{
	String_t* ___U3CidU3Ek__BackingField;
	Type_t* ___U3CproviderTypeU3Ek__BackingField;
	Type_t* ___U3CsubsystemTypeOverrideU3Ek__BackingField;
};
struct SubsystemProvider_tE1865B8FE698C81A59AED35E0E536BD53F402455  : public RuntimeObject
{
	bool ___m_Running;
};
struct SubsystemWithProvider_tC72E35EE2D413A4B0635B058154BABF265F31242  : public RuntimeObject
{
	bool ___U3CrunningU3Ek__BackingField;
	SubsystemProvider_tE1865B8FE698C81A59AED35E0E536BD53F402455* ___U3CproviderBaseU3Ek__BackingField;
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F  : public RuntimeObject
{
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_pinvoke
{
};
struct ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F_marshaled_com
{
};
struct Version_tE426DB5655D0F22920AE16A2AA9AB7781B8255A7  : public RuntimeObject
{
	int32_t ____Major;
	int32_t ____Minor;
	int32_t ____Build;
	int32_t ____Revision;
};
struct SubsystemDescriptorWithProvider_2_t0ED3136D58032F3B2C26ABE5BEBCA17BEBEB16B2  : public SubsystemDescriptorWithProvider_t2A61A2C951A4A179E898CF207726BF6B5AF474D5
{
};
struct SubsystemProvider_1_t23B1212EE93CDE7A93AC42422CEE3D03362A28A9  : public SubsystemProvider_tE1865B8FE698C81A59AED35E0E536BD53F402455
{
};
struct SubsystemWithProvider_3_t6D46FA89F0C5C3D13496BD54E4F94F94859596BB  : public SubsystemWithProvider_tC72E35EE2D413A4B0635B058154BABF265F31242
{
	AdaptivePerformanceSubsystemDescriptor_t626A06E24BC33D89FEFD1A8D66983890D153EF16* ___U3CsubsystemDescriptorU3Ek__BackingField;
	APProvider_t68A181100C0A38B4BB91BEF637FCDDCC9BF59D6B* ___U3CproviderU3Ek__BackingField;
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22 
{
	bool ___m_value;
};
struct ClusterInfo_tEB8CE53228687A1E926DEF3AB47DEC36DD5AC26F 
{
	int32_t ___U3CBigCoreU3Ek__BackingField;
	int32_t ___U3CMediumCoreU3Ek__BackingField;
	int32_t ___U3CLittleCoreU3Ek__BackingField;
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2  : public ValueType_t6D9B272BD21782F0A9A14F2E41F85A50E97A986F
{
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_marshaled_pinvoke
{
};
struct Enum_t2A1A94B24E3B776EEF4E5E485E290BB9D4D072E2_marshaled_com
{
};
struct Int32_t680FF22E76F6EFAD4375103CBBFFA0421349384C 
{
	int32_t ___m_value;
};
struct IntPtr_t 
{
	void* ___m_value;
};
struct Single_t4530F2FF86FCB0DC29F35385CA1BD21BE294761C 
{
	float ___m_value;
};
struct Void_t4861ACF8F4594C3437BB48B6E56783494B843915 
{
	union
	{
		struct
		{
		};
		uint8_t Void_t4861ACF8F4594C3437BB48B6E56783494B843915__padding[1];
	};
};
struct Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA 
{
	String_t* ___U3CidU3Ek__BackingField;
	Type_t* ___U3CproviderTypeU3Ek__BackingField;
	Type_t* ___U3CsubsystemTypeOverrideU3Ek__BackingField;
	Type_t* ___U3CsubsystemImplementationTypeU3Ek__BackingField;
};
struct Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA_marshaled_pinvoke
{
	char* ___U3CidU3Ek__BackingField;
	Type_t* ___U3CproviderTypeU3Ek__BackingField;
	Type_t* ___U3CsubsystemTypeOverrideU3Ek__BackingField;
	Type_t* ___U3CsubsystemImplementationTypeU3Ek__BackingField;
};
struct Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA_marshaled_com
{
	Il2CppChar* ___U3CidU3Ek__BackingField;
	Type_t* ___U3CproviderTypeU3Ek__BackingField;
	Type_t* ___U3CsubsystemTypeOverrideU3Ek__BackingField;
	Type_t* ___U3CsubsystemImplementationTypeU3Ek__BackingField;
};
struct AdaptivePerformanceSubsystemBase_3_t293E823C3F3068E541C187D465B11F5A60FA60A5  : public SubsystemWithProvider_3_t6D46FA89F0C5C3D13496BD54E4F94F94859596BB
{
};
struct AdaptivePerformanceSubsystemDescriptor_t626A06E24BC33D89FEFD1A8D66983890D153EF16  : public SubsystemDescriptorWithProvider_2_t0ED3136D58032F3B2C26ABE5BEBCA17BEBEB16B2
{
};
struct Feature_t14B22D2C6D80E39AF461A39216C1F4334AA7CBD0 
{
	int32_t ___value__;
};
struct PerformanceMode_tBDB12E5FD689EDF6BA365B3318A6F87665043827 
{
	int32_t ___value__;
};
struct RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B 
{
	intptr_t ___value;
};
struct WarningLevel_t1406F2B2A0444D6071DB04DF3F8062CD70098698 
{
	int32_t ___value__;
};
struct APProvider_t68A181100C0A38B4BB91BEF637FCDDCC9BF59D6B  : public SubsystemProvider_1_t23B1212EE93CDE7A93AC42422CEE3D03362A28A9
{
	bool ___m_Running;
};
struct AdaptivePerformanceSubsystem_tBE818A622D29C1A560C740447BA4F0D7343B5214  : public AdaptivePerformanceSubsystemBase_3_t293E823C3F3068E541C187D465B11F5A60FA60A5
{
};
struct PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D 
{
	int32_t ___U3CChangeFlagsU3Ek__BackingField;
	float ___U3CTemperatureLevelU3Ek__BackingField;
	float ___U3CTemperatureTrendU3Ek__BackingField;
	int32_t ___U3CWarningLevelU3Ek__BackingField;
	int32_t ___U3CCpuPerformanceLevelU3Ek__BackingField;
	int32_t ___U3CGpuPerformanceLevelU3Ek__BackingField;
	bool ___U3CPerformanceLevelControlAvailableU3Ek__BackingField;
	float ___U3CCpuFrameTimeU3Ek__BackingField;
	float ___U3CGpuFrameTimeU3Ek__BackingField;
	float ___U3COverallFrameTimeU3Ek__BackingField;
	bool ___U3CCpuPerformanceBoostU3Ek__BackingField;
	bool ___U3CGpuPerformanceBoostU3Ek__BackingField;
	ClusterInfo_tEB8CE53228687A1E926DEF3AB47DEC36DD5AC26F ___U3CClusterInfoU3Ek__BackingField;
	int32_t ___U3CPerformanceModeU3Ek__BackingField;
};
struct PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D_marshaled_pinvoke
{
	int32_t ___U3CChangeFlagsU3Ek__BackingField;
	float ___U3CTemperatureLevelU3Ek__BackingField;
	float ___U3CTemperatureTrendU3Ek__BackingField;
	int32_t ___U3CWarningLevelU3Ek__BackingField;
	int32_t ___U3CCpuPerformanceLevelU3Ek__BackingField;
	int32_t ___U3CGpuPerformanceLevelU3Ek__BackingField;
	int32_t ___U3CPerformanceLevelControlAvailableU3Ek__BackingField;
	float ___U3CCpuFrameTimeU3Ek__BackingField;
	float ___U3CGpuFrameTimeU3Ek__BackingField;
	float ___U3COverallFrameTimeU3Ek__BackingField;
	int32_t ___U3CCpuPerformanceBoostU3Ek__BackingField;
	int32_t ___U3CGpuPerformanceBoostU3Ek__BackingField;
	ClusterInfo_tEB8CE53228687A1E926DEF3AB47DEC36DD5AC26F ___U3CClusterInfoU3Ek__BackingField;
	int32_t ___U3CPerformanceModeU3Ek__BackingField;
};
struct PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D_marshaled_com
{
	int32_t ___U3CChangeFlagsU3Ek__BackingField;
	float ___U3CTemperatureLevelU3Ek__BackingField;
	float ___U3CTemperatureTrendU3Ek__BackingField;
	int32_t ___U3CWarningLevelU3Ek__BackingField;
	int32_t ___U3CCpuPerformanceLevelU3Ek__BackingField;
	int32_t ___U3CGpuPerformanceLevelU3Ek__BackingField;
	int32_t ___U3CPerformanceLevelControlAvailableU3Ek__BackingField;
	float ___U3CCpuFrameTimeU3Ek__BackingField;
	float ___U3CGpuFrameTimeU3Ek__BackingField;
	float ___U3COverallFrameTimeU3Ek__BackingField;
	int32_t ___U3CCpuPerformanceBoostU3Ek__BackingField;
	int32_t ___U3CGpuPerformanceBoostU3Ek__BackingField;
	ClusterInfo_tEB8CE53228687A1E926DEF3AB47DEC36DD5AC26F ___U3CClusterInfoU3Ek__BackingField;
	int32_t ___U3CPerformanceModeU3Ek__BackingField;
};
struct Type_t  : public MemberInfo_t
{
	RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B ____impl;
};
struct BasicAdaptivePerformanceSubsystem_t4A078575FEAD3F7D4530468B087BB18C9A468664  : public AdaptivePerformanceSubsystem_tBE818A622D29C1A560C740447BA4F0D7343B5214
{
};
struct BasicProvider_tDF77359CE2123F60C810DDA5ACBDA479BBEB012D  : public APProvider_t68A181100C0A38B4BB91BEF637FCDDCC9BF59D6B
{
	PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D ___m_UpdatedPerfRecord;
	bool ___U3CInitializedU3Ek__BackingField;
	int32_t ___U3CCapabilitiesU3Ek__BackingField;
};
struct String_t_StaticFields
{
	String_t* ___Empty;
};
struct Boolean_t09A6377A54BE2F9E6985A8149F19234FD7DDFE22_StaticFields
{
	String_t* ___TrueString;
	String_t* ___FalseString;
};
struct Type_t_StaticFields
{
	Binder_t91BFCE95A7057FADF4D8A1A342AFE52872246235* ___s_defaultBinder;
	Il2CppChar ___Delimiter;
	TypeU5BU5D_t97234E1129B564EB38B8D85CAC2AD8B5B9522FFB* ___EmptyTypes;
	RuntimeObject* ___Missing;
	MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553* ___FilterAttribute;
	MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553* ___FilterName;
	MemberFilter_tF644F1AE82F611B677CE1964D5A3277DDA21D553* ___FilterNameIgnoreCase;
};
#ifdef __clang__
#pragma clang diagnostic pop
#endif



IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR String_t* Cinfo_get_id_m65946F15BF304FEAAD403ED3EDC213CD9369554B_inline (Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Cinfo_set_id_m84D2153E2A1BDECFE6493B5E5FA8776F7913DB70_inline (Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA* __this, String_t* ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Type_t* Cinfo_get_providerType_mCADBAB20C4FA5BE5D0578C0DCF82512690A9312F_inline (Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Cinfo_set_providerType_mEFBA8B8060FF6D27D59585F09D0F26A1C5F69AF9_inline (Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA* __this, Type_t* ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Type_t* Cinfo_get_subsystemTypeOverride_m46B1FA46EF70E4BBCFA83B3EBB6A39F5FA852AF9_inline (Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Cinfo_set_subsystemTypeOverride_m79DBC8798C850ADD6DC96CF64DE6509356C1217A_inline (Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA* __this, Type_t* ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Type_t* Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57 (RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B ___0_handle, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AdaptivePerformanceSubsystemDescriptor_t626A06E24BC33D89FEFD1A8D66983890D153EF16* AdaptivePerformanceSubsystemDescriptor_RegisterDescriptor_m4827B36442D4E792CB9192D5B4DA0E3734872773 (Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA ___0_cinfo, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void AdaptivePerformanceSubsystem__ctor_m345DCFBE5D449D24BBFBBDFD1373DE112BA0E71B (AdaptivePerformanceSubsystem_tBE818A622D29C1A560C740447BA4F0D7343B5214* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void APProvider__ctor_m6513EC5733422321D9673F0876F098510A6A9FBD (APProvider_t68A181100C0A38B4BB91BEF637FCDDCC9BF59D6B* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void PerformanceDataRecord_set_PerformanceLevelControlAvailable_m2CC4B0A75E3AFD5BC120AF54616CD414711D6C43_inline (PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D* __this, bool ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void PerformanceDataRecord_set_CpuPerformanceBoost_m3E92E90A8057FC58D14F8C3F5DC3145D1FB22B00_inline (PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D* __this, bool ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void PerformanceDataRecord_set_GpuPerformanceBoost_mD2BF46BD6AC8C2AADAB68CF2BD18C40B0C4178F4_inline (PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D* __this, bool ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void PerformanceDataRecord_set_TemperatureLevel_m555EBE87D974B33FEF190D7C2840D0EB74F3F73D_inline (PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D* __this, float ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void PerformanceDataRecord_set_TemperatureTrend_m73694AFE0CEA81D0DC5111AE58EA8987618A6A80_inline (PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D* __this, float ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t PerformanceDataRecord_get_ChangeFlags_m16CFF24389B0D33368CDE68198379619E0EEFBCA_inline (PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void PerformanceDataRecord_set_ChangeFlags_mF8B8F3339A8BE3D98ADC7A99EC7D19D2F404939B_inline (PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool PerformanceDataRecord_get_PerformanceLevelControlAvailable_m3AA579DD438FCA8CD6B6CFE65D769F6CBCDB1A25_inline (PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D* __this, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void PerformanceDataRecord_set_CpuPerformanceLevel_mA326744A851E95BA8E849DAD1E37578AAFD99435_inline (PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void PerformanceDataRecord_set_GpuPerformanceLevel_m231FA3B8CA050FDB3762ECC3338570CB511E989B_inline (PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D* __this, int32_t ___0_value, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t BasicProvider_get_MaxCpuPerformanceLevel_m84992F94F4D29ED088A9758ED6032E308037AD10 (BasicProvider_tDF77359CE2123F60C810DDA5ACBDA479BBEB012D* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t BasicProvider_get_MaxGpuPerformanceLevel_m379755AD000DA60FAC2BE9797FDE10630CE190AE (BasicProvider_tDF77359CE2123F60C810DDA5ACBDA479BBEB012D* __this, const RuntimeMethod* method) ;
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Version__ctor_m7D8EE608025AE8D7AD8867718BC0AC96A2CFC1F5 (Version_tE426DB5655D0F22920AE16A2AA9AB7781B8255A7* __this, int32_t ___0_major, int32_t ___1_minor, int32_t ___2_build, const RuntimeMethod* method) ;
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
IL2CPP_EXTERN_C void Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA_marshal_pinvoke(const Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA& unmarshaled, Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA_marshaled_pinvoke& marshaled)
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA____U3CproviderTypeU3Ek__BackingField_FieldInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Exception_t* ___U3CproviderTypeU3Ek__BackingFieldException = il2cpp_codegen_get_marshal_directive_exception("Cannot marshal field '%s' of type '%s': Reference type field marshaling is not supported.", Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA____U3CproviderTypeU3Ek__BackingField_FieldInfo_var, Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA_0_0_0_var);
	IL2CPP_RAISE_MANAGED_EXCEPTION(___U3CproviderTypeU3Ek__BackingFieldException, NULL);
}
IL2CPP_EXTERN_C void Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA_marshal_pinvoke_back(const Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA_marshaled_pinvoke& marshaled, Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA& unmarshaled)
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA____U3CproviderTypeU3Ek__BackingField_FieldInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Exception_t* ___U3CproviderTypeU3Ek__BackingFieldException = il2cpp_codegen_get_marshal_directive_exception("Cannot marshal field '%s' of type '%s': Reference type field marshaling is not supported.", Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA____U3CproviderTypeU3Ek__BackingField_FieldInfo_var, Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA_0_0_0_var);
	IL2CPP_RAISE_MANAGED_EXCEPTION(___U3CproviderTypeU3Ek__BackingFieldException, NULL);
}
IL2CPP_EXTERN_C void Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA_marshal_pinvoke_cleanup(Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA_marshaled_pinvoke& marshaled)
{
}
IL2CPP_EXTERN_C void Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA_marshal_com(const Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA& unmarshaled, Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA_marshaled_com& marshaled)
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA____U3CproviderTypeU3Ek__BackingField_FieldInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Exception_t* ___U3CproviderTypeU3Ek__BackingFieldException = il2cpp_codegen_get_marshal_directive_exception("Cannot marshal field '%s' of type '%s': Reference type field marshaling is not supported.", Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA____U3CproviderTypeU3Ek__BackingField_FieldInfo_var, Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA_0_0_0_var);
	IL2CPP_RAISE_MANAGED_EXCEPTION(___U3CproviderTypeU3Ek__BackingFieldException, NULL);
}
IL2CPP_EXTERN_C void Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA_marshal_com_back(const Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA_marshaled_com& marshaled, Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA& unmarshaled)
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA____U3CproviderTypeU3Ek__BackingField_FieldInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Exception_t* ___U3CproviderTypeU3Ek__BackingFieldException = il2cpp_codegen_get_marshal_directive_exception("Cannot marshal field '%s' of type '%s': Reference type field marshaling is not supported.", Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA____U3CproviderTypeU3Ek__BackingField_FieldInfo_var, Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA_0_0_0_var);
	IL2CPP_RAISE_MANAGED_EXCEPTION(___U3CproviderTypeU3Ek__BackingFieldException, NULL);
}
IL2CPP_EXTERN_C void Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA_marshal_com_cleanup(Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA_marshaled_com& marshaled)
{
}
// Method Definition Index: 68257
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* Cinfo_get_id_m65946F15BF304FEAAD403ED3EDC213CD9369554B (Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA* __this, const RuntimeMethod* method) 
{
	{
		String_t* L_0 = __this->___U3CidU3Ek__BackingField;
		return L_0;
	}
}
IL2CPP_EXTERN_C  String_t* Cinfo_get_id_m65946F15BF304FEAAD403ED3EDC213CD9369554B_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA*>(__this + _offset);
	String_t* _returnValue;
	_returnValue = Cinfo_get_id_m65946F15BF304FEAAD403ED3EDC213CD9369554B_inline(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 68258
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Cinfo_set_id_m84D2153E2A1BDECFE6493B5E5FA8776F7913DB70 (Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA* __this, String_t* ___0_value, const RuntimeMethod* method) 
{
	{
		String_t* L_0 = ___0_value;
		__this->___U3CidU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CidU3Ek__BackingField), (void*)L_0);
		return;
	}
}
IL2CPP_EXTERN_C  void Cinfo_set_id_m84D2153E2A1BDECFE6493B5E5FA8776F7913DB70_AdjustorThunk (RuntimeObject* __this, String_t* ___0_value, const RuntimeMethod* method)
{
	Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA*>(__this + _offset);
	Cinfo_set_id_m84D2153E2A1BDECFE6493B5E5FA8776F7913DB70_inline(_thisAdjusted, ___0_value, method);
}
// Method Definition Index: 68259
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Type_t* Cinfo_get_providerType_mCADBAB20C4FA5BE5D0578C0DCF82512690A9312F (Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA* __this, const RuntimeMethod* method) 
{
	{
		Type_t* L_0 = __this->___U3CproviderTypeU3Ek__BackingField;
		return L_0;
	}
}
IL2CPP_EXTERN_C  Type_t* Cinfo_get_providerType_mCADBAB20C4FA5BE5D0578C0DCF82512690A9312F_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA*>(__this + _offset);
	Type_t* _returnValue;
	_returnValue = Cinfo_get_providerType_mCADBAB20C4FA5BE5D0578C0DCF82512690A9312F_inline(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 68260
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Cinfo_set_providerType_mEFBA8B8060FF6D27D59585F09D0F26A1C5F69AF9 (Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA* __this, Type_t* ___0_value, const RuntimeMethod* method) 
{
	{
		Type_t* L_0 = ___0_value;
		__this->___U3CproviderTypeU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CproviderTypeU3Ek__BackingField), (void*)L_0);
		return;
	}
}
IL2CPP_EXTERN_C  void Cinfo_set_providerType_mEFBA8B8060FF6D27D59585F09D0F26A1C5F69AF9_AdjustorThunk (RuntimeObject* __this, Type_t* ___0_value, const RuntimeMethod* method)
{
	Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA*>(__this + _offset);
	Cinfo_set_providerType_mEFBA8B8060FF6D27D59585F09D0F26A1C5F69AF9_inline(_thisAdjusted, ___0_value, method);
}
// Method Definition Index: 68261
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Type_t* Cinfo_get_subsystemTypeOverride_m46B1FA46EF70E4BBCFA83B3EBB6A39F5FA852AF9 (Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA* __this, const RuntimeMethod* method) 
{
	{
		Type_t* L_0 = __this->___U3CsubsystemTypeOverrideU3Ek__BackingField;
		return L_0;
	}
}
IL2CPP_EXTERN_C  Type_t* Cinfo_get_subsystemTypeOverride_m46B1FA46EF70E4BBCFA83B3EBB6A39F5FA852AF9_AdjustorThunk (RuntimeObject* __this, const RuntimeMethod* method)
{
	Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA*>(__this + _offset);
	Type_t* _returnValue;
	_returnValue = Cinfo_get_subsystemTypeOverride_m46B1FA46EF70E4BBCFA83B3EBB6A39F5FA852AF9_inline(_thisAdjusted, method);
	return _returnValue;
}
// Method Definition Index: 68262
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void Cinfo_set_subsystemTypeOverride_m79DBC8798C850ADD6DC96CF64DE6509356C1217A (Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA* __this, Type_t* ___0_value, const RuntimeMethod* method) 
{
	{
		Type_t* L_0 = ___0_value;
		__this->___U3CsubsystemTypeOverrideU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CsubsystemTypeOverrideU3Ek__BackingField), (void*)L_0);
		return;
	}
}
IL2CPP_EXTERN_C  void Cinfo_set_subsystemTypeOverride_m79DBC8798C850ADD6DC96CF64DE6509356C1217A_AdjustorThunk (RuntimeObject* __this, Type_t* ___0_value, const RuntimeMethod* method)
{
	Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA* _thisAdjusted;
	int32_t _offset = 1;
	_thisAdjusted = reinterpret_cast<Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA*>(__this + _offset);
	Cinfo_set_subsystemTypeOverride_m79DBC8798C850ADD6DC96CF64DE6509356C1217A_inline(_thisAdjusted, ___0_value, method);
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 68263
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR AdaptivePerformanceSubsystemDescriptor_t626A06E24BC33D89FEFD1A8D66983890D153EF16* BasicProviderDescriptorRegistration_RegisterDescriptor_m7192EAA47CFF27C8962FB35EEA9C3E14F450392F (const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BasicAdaptivePerformanceSubsystem_t4A078575FEAD3F7D4530468B087BB18C9A468664_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&BasicProvider_tDF77359CE2123F60C810DDA5ACBDA479BBEB012D_0_0_0_var);
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral03D5C271551A28BF44745629A92B7E0E74585419);
		s_Il2CppMethodInitialized = true;
	}
	Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA V_0;
	memset((&V_0), 0, sizeof(V_0));
	AdaptivePerformanceSubsystemDescriptor_t626A06E24BC33D89FEFD1A8D66983890D153EF16* V_1 = NULL;
	{
		il2cpp_codegen_initobj((&V_0), sizeof(Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA));
		Cinfo_set_id_m84D2153E2A1BDECFE6493B5E5FA8776F7913DB70_inline((&V_0), _stringLiteral03D5C271551A28BF44745629A92B7E0E74585419, NULL);
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_0 = { reinterpret_cast<intptr_t> (BasicProvider_tDF77359CE2123F60C810DDA5ACBDA479BBEB012D_0_0_0_var) };
		il2cpp_codegen_runtime_class_init_inline(il2cpp_defaults.systemtype_class);
		Type_t* L_1;
		L_1 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_0, NULL);
		Cinfo_set_providerType_mEFBA8B8060FF6D27D59585F09D0F26A1C5F69AF9_inline((&V_0), L_1, NULL);
		RuntimeTypeHandle_t332A452B8B6179E4469B69525D0FE82A88030F7B L_2 = { reinterpret_cast<intptr_t> (BasicAdaptivePerformanceSubsystem_t4A078575FEAD3F7D4530468B087BB18C9A468664_0_0_0_var) };
		Type_t* L_3;
		L_3 = Type_GetTypeFromHandle_m6062B81682F79A4D6DF2640692EE6D9987858C57(L_2, NULL);
		Cinfo_set_subsystemTypeOverride_m79DBC8798C850ADD6DC96CF64DE6509356C1217A_inline((&V_0), L_3, NULL);
		Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA L_4 = V_0;
		AdaptivePerformanceSubsystemDescriptor_t626A06E24BC33D89FEFD1A8D66983890D153EF16* L_5;
		L_5 = AdaptivePerformanceSubsystemDescriptor_RegisterDescriptor_m4827B36442D4E792CB9192D5B4DA0E3734872773(L_4, NULL);
		V_1 = L_5;
		goto IL_0043;
	}

IL_0043:
	{
		AdaptivePerformanceSubsystemDescriptor_t626A06E24BC33D89FEFD1A8D66983890D153EF16* L_6 = V_1;
		return L_6;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 68264
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BasicAdaptivePerformanceSubsystem__ctor_m6CCFACE0BB429A3F7F8E245823BC8A6DCDF4F3B1 (BasicAdaptivePerformanceSubsystem_t4A078575FEAD3F7D4530468B087BB18C9A468664* __this, const RuntimeMethod* method) 
{
	{
		AdaptivePerformanceSubsystem__ctor_m345DCFBE5D449D24BBFBBDFD1373DE112BA0E71B(__this, NULL);
		return;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#pragma clang diagnostic ignored "-Wunused-variable"
#endif
// Method Definition Index: 68265
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BasicProvider__ctor_m92EBBC24528BC731BF620E71A2EF0C203CFBC1BC (BasicProvider_tDF77359CE2123F60C810DDA5ACBDA479BBEB012D* __this, const RuntimeMethod* method) 
{
	{
		APProvider__ctor_m6513EC5733422321D9673F0876F098510A6A9FBD(__this, NULL);
		VirtualActionInvoker1< int32_t >::Invoke(7, __this, 0);
		PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D* L_0 = (PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D*)(&__this->___m_UpdatedPerfRecord);
		PerformanceDataRecord_set_PerformanceLevelControlAvailable_m2CC4B0A75E3AFD5BC120AF54616CD414711D6C43_inline(L_0, (bool)0, NULL);
		PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D* L_1 = (PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D*)(&__this->___m_UpdatedPerfRecord);
		PerformanceDataRecord_set_CpuPerformanceBoost_m3E92E90A8057FC58D14F8C3F5DC3145D1FB22B00_inline(L_1, (bool)0, NULL);
		PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D* L_2 = (PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D*)(&__this->___m_UpdatedPerfRecord);
		PerformanceDataRecord_set_GpuPerformanceBoost_mD2BF46BD6AC8C2AADAB68CF2BD18C40B0C4178F4_inline(L_2, (bool)0, NULL);
		PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D* L_3 = (PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D*)(&__this->___m_UpdatedPerfRecord);
		PerformanceDataRecord_set_TemperatureLevel_m555EBE87D974B33FEF190D7C2840D0EB74F3F73D_inline(L_3, (-1.0f), NULL);
		PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D* L_4 = (PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D*)(&__this->___m_UpdatedPerfRecord);
		PerformanceDataRecord_set_TemperatureTrend_m73694AFE0CEA81D0DC5111AE58EA8987618A6A80_inline(L_4, (-1.0f), NULL);
		return;
	}
}
// Method Definition Index: 68266
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* BasicProvider_get_ApplicationLifecycle_mE2013AC2784874270C1F648BDC32604DEE26A9BA (BasicProvider_tDF77359CE2123F60C810DDA5ACBDA479BBEB012D* __this, const RuntimeMethod* method) 
{
	{
		return __this;
	}
}
// Method Definition Index: 68267
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR RuntimeObject* BasicProvider_get_PerformanceLevelControl_m3F1B5717BCE7C3F7F647F910C5A892BA997E22F3 (BasicProvider_tDF77359CE2123F60C810DDA5ACBDA479BBEB012D* __this, const RuntimeMethod* method) 
{
	{
		return __this;
	}
}
// Method Definition Index: 68268
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR String_t* BasicProvider_get_Stats_mE949607012A6AD68092B8D992C05A3EB1523335B (BasicProvider_tDF77359CE2123F60C810DDA5ACBDA479BBEB012D* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&_stringLiteral711CD86ED4432DF0220A669CFAC925F9949D5C48);
		s_Il2CppMethodInitialized = true;
	}
	{
		return _stringLiteral711CD86ED4432DF0220A669CFAC925F9949D5C48;
	}
}
// Method Definition Index: 68269
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool BasicProvider_get_Initialized_m4F58D2623E1722B1E260CA94499EB4FB0E196424 (BasicProvider_tDF77359CE2123F60C810DDA5ACBDA479BBEB012D* __this, const RuntimeMethod* method) 
{
	{
		bool L_0 = __this->___U3CInitializedU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 68270
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BasicProvider_set_Initialized_m6B6B478FE00E1406D95B9C84A9DD803C123FCA09 (BasicProvider_tDF77359CE2123F60C810DDA5ACBDA479BBEB012D* __this, bool ___0_value, const RuntimeMethod* method) 
{
	{
		bool L_0 = ___0_value;
		__this->___U3CInitializedU3Ek__BackingField = L_0;
		return;
	}
}
// Method Definition Index: 68271
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t BasicProvider_get_Capabilities_m6AFEB11024337A50D9C760AFBCF0F23D0802C05E (BasicProvider_tDF77359CE2123F60C810DDA5ACBDA479BBEB012D* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->___U3CCapabilitiesU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 68272
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BasicProvider_set_Capabilities_mFB410C93F3D7D36190C9C73ADCDAB3B17EA4C6B3 (BasicProvider_tDF77359CE2123F60C810DDA5ACBDA479BBEB012D* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_value;
		__this->___U3CCapabilitiesU3Ek__BackingField = L_0;
		return;
	}
}
// Method Definition Index: 68273
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BasicProvider_Stop_mC159368BF90A1429B3A5F572BED12067EDCD34A6 (BasicProvider_tDF77359CE2123F60C810DDA5ACBDA479BBEB012D* __this, const RuntimeMethod* method) 
{
	{
		((APProvider_t68A181100C0A38B4BB91BEF637FCDDCC9BF59D6B*)__this)->___m_Running = (bool)0;
		return;
	}
}
// Method Definition Index: 68274
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BasicProvider_Destroy_m786F60AB10C91D25890276E4C394FB2A3D017501 (BasicProvider_tDF77359CE2123F60C810DDA5ACBDA479BBEB012D* __this, const RuntimeMethod* method) 
{
	{
		VirtualActionInvoker1< bool >::Invoke(14, __this, (bool)0);
		return;
	}
}
// Method Definition Index: 68275
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D BasicProvider_Update_m7E217C3CCD4B25E68620479946BED085AA8895B5 (BasicProvider_tDF77359CE2123F60C810DDA5ACBDA479BBEB012D* __this, const RuntimeMethod* method) 
{
	PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D V_0;
	memset((&V_0), 0, sizeof(V_0));
	PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D V_1;
	memset((&V_1), 0, sizeof(V_1));
	{
		PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D* L_0 = (PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D*)(&__this->___m_UpdatedPerfRecord);
		PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D* L_1 = L_0;
		int32_t L_2;
		L_2 = PerformanceDataRecord_get_ChangeFlags_m16CFF24389B0D33368CDE68198379619E0EEFBCA_inline(L_1, NULL);
		int32_t L_3;
		L_3 = VirtualFuncInvoker0< int32_t >::Invoke(6, __this);
		PerformanceDataRecord_set_ChangeFlags_mF8B8F3339A8BE3D98ADC7A99EC7D19D2F404939B_inline(L_1, ((int32_t)((int32_t)L_2&(int32_t)L_3)), NULL);
		PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D L_4 = __this->___m_UpdatedPerfRecord;
		V_0 = L_4;
		PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D* L_5 = (PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D*)(&__this->___m_UpdatedPerfRecord);
		PerformanceDataRecord_set_ChangeFlags_mF8B8F3339A8BE3D98ADC7A99EC7D19D2F404939B_inline(L_5, 0, NULL);
		PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D L_6 = V_0;
		V_1 = L_6;
		goto IL_0032;
	}

IL_0032:
	{
		PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D L_7 = V_1;
		return L_7;
	}
}
// Method Definition Index: 68276
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BasicProvider_ApplicationPause_m26D99596CDD103D5A3994D0EED5F6CF3324AECC3 (BasicProvider_tDF77359CE2123F60C810DDA5ACBDA479BBEB012D* __this, const RuntimeMethod* method) 
{
	{
		return;
	}
}
// Method Definition Index: 68277
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR void BasicProvider_ApplicationResume_mCDCEB3C994BD579314DE72FA74C540BA29FEB551 (BasicProvider_tDF77359CE2123F60C810DDA5ACBDA479BBEB012D* __this, const RuntimeMethod* method) 
{
	{
		return;
	}
}
// Method Definition Index: 68278
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool BasicProvider_SetPerformanceLevel_m956C55DAAE85D0DB0C0A607A1562FF874D2883FD (BasicProvider_tDF77359CE2123F60C810DDA5ACBDA479BBEB012D* __this, int32_t* ___0_cpuLevel, int32_t* ___1_gpuLevel, const RuntimeMethod* method) 
{
	bool V_0 = false;
	bool V_1 = false;
	int32_t G_B7_0 = 0;
	{
		PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D* L_0 = (PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D*)(&__this->___m_UpdatedPerfRecord);
		bool L_1;
		L_1 = PerformanceDataRecord_get_PerformanceLevelControlAvailable_m3AA579DD438FCA8CD6B6CFE65D769F6CBCDB1A25_inline(L_0, NULL);
		V_0 = (bool)((((int32_t)L_1) == ((int32_t)0))? 1 : 0);
		bool L_2 = V_0;
		if (!L_2)
		{
			goto IL_005b;
		}
	}
	{
		PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D* L_3 = (PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D*)(&__this->___m_UpdatedPerfRecord);
		PerformanceDataRecord_set_CpuPerformanceLevel_mA326744A851E95BA8E849DAD1E37578AAFD99435_inline(L_3, (-1), NULL);
		PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D* L_4 = (PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D*)(&__this->___m_UpdatedPerfRecord);
		PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D* L_5 = L_4;
		int32_t L_6;
		L_6 = PerformanceDataRecord_get_ChangeFlags_m16CFF24389B0D33368CDE68198379619E0EEFBCA_inline(L_5, NULL);
		PerformanceDataRecord_set_ChangeFlags_mF8B8F3339A8BE3D98ADC7A99EC7D19D2F404939B_inline(L_5, ((int32_t)((int32_t)L_6|8)), NULL);
		PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D* L_7 = (PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D*)(&__this->___m_UpdatedPerfRecord);
		PerformanceDataRecord_set_GpuPerformanceLevel_m231FA3B8CA050FDB3762ECC3338570CB511E989B_inline(L_7, (-1), NULL);
		PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D* L_8 = (PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D*)(&__this->___m_UpdatedPerfRecord);
		PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D* L_9 = L_8;
		int32_t L_10;
		L_10 = PerformanceDataRecord_get_ChangeFlags_m16CFF24389B0D33368CDE68198379619E0EEFBCA_inline(L_9, NULL);
		PerformanceDataRecord_set_ChangeFlags_mF8B8F3339A8BE3D98ADC7A99EC7D19D2F404939B_inline(L_9, ((int32_t)((int32_t)L_10|((int32_t)16))), NULL);
		V_1 = (bool)0;
		goto IL_0082;
	}

IL_005b:
	{
		int32_t* L_11 = ___0_cpuLevel;
		int32_t L_12 = *((int32_t*)L_11);
		if ((((int32_t)L_12) < ((int32_t)0)))
		{
			goto IL_007e;
		}
	}
	{
		int32_t* L_13 = ___1_gpuLevel;
		int32_t L_14 = *((int32_t*)L_13);
		if ((((int32_t)L_14) < ((int32_t)0)))
		{
			goto IL_007e;
		}
	}
	{
		int32_t* L_15 = ___0_cpuLevel;
		int32_t L_16 = *((int32_t*)L_15);
		int32_t L_17;
		L_17 = BasicProvider_get_MaxCpuPerformanceLevel_m84992F94F4D29ED088A9758ED6032E308037AD10(__this, NULL);
		if ((((int32_t)L_16) > ((int32_t)L_17)))
		{
			goto IL_007e;
		}
	}
	{
		int32_t* L_18 = ___1_gpuLevel;
		int32_t L_19 = *((int32_t*)L_18);
		int32_t L_20;
		L_20 = BasicProvider_get_MaxGpuPerformanceLevel_m379755AD000DA60FAC2BE9797FDE10630CE190AE(__this, NULL);
		G_B7_0 = ((((int32_t)((((int32_t)L_19) > ((int32_t)L_20))? 1 : 0)) == ((int32_t)0))? 1 : 0);
		goto IL_007f;
	}

IL_007e:
	{
		G_B7_0 = 0;
	}

IL_007f:
	{
		V_1 = (bool)G_B7_0;
		goto IL_0082;
	}

IL_0082:
	{
		bool L_21 = V_1;
		return L_21;
	}
}
// Method Definition Index: 68279
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool BasicProvider_EnableCpuBoost_mC5C2D4A9CC709481799E61A4BFBF5D31E12F5D22 (BasicProvider_tDF77359CE2123F60C810DDA5ACBDA479BBEB012D* __this, const RuntimeMethod* method) 
{
	bool V_0 = false;
	{
		V_0 = (bool)0;
		goto IL_0005;
	}

IL_0005:
	{
		bool L_0 = V_0;
		return L_0;
	}
}
// Method Definition Index: 68280
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR bool BasicProvider_EnableGpuBoost_m733459F101BD311D92C446AD044BA2F4351DDF65 (BasicProvider_tDF77359CE2123F60C810DDA5ACBDA479BBEB012D* __this, const RuntimeMethod* method) 
{
	bool V_0 = false;
	{
		V_0 = (bool)0;
		goto IL_0005;
	}

IL_0005:
	{
		bool L_0 = V_0;
		return L_0;
	}
}
// Method Definition Index: 68281
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR Version_tE426DB5655D0F22920AE16A2AA9AB7781B8255A7* BasicProvider_get_Version_m66ADE22347A16C3646B6278CD3A9EA9E020957DE (BasicProvider_tDF77359CE2123F60C810DDA5ACBDA479BBEB012D* __this, const RuntimeMethod* method) 
{
	static bool s_Il2CppMethodInitialized;
	if (!s_Il2CppMethodInitialized)
	{
		il2cpp_codegen_initialize_runtime_metadata((uintptr_t*)&Version_tE426DB5655D0F22920AE16A2AA9AB7781B8255A7_il2cpp_TypeInfo_var);
		s_Il2CppMethodInitialized = true;
	}
	Version_tE426DB5655D0F22920AE16A2AA9AB7781B8255A7* V_0 = NULL;
	{
		Version_tE426DB5655D0F22920AE16A2AA9AB7781B8255A7* L_0 = (Version_tE426DB5655D0F22920AE16A2AA9AB7781B8255A7*)il2cpp_codegen_object_new(Version_tE426DB5655D0F22920AE16A2AA9AB7781B8255A7_il2cpp_TypeInfo_var);
		Version__ctor_m7D8EE608025AE8D7AD8867718BC0AC96A2CFC1F5(L_0, 6, 0, 0, NULL);
		V_0 = L_0;
		goto IL_000c;
	}

IL_000c:
	{
		Version_tE426DB5655D0F22920AE16A2AA9AB7781B8255A7* L_1 = V_0;
		return L_1;
	}
}
// Method Definition Index: 68282
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t BasicProvider_get_MaxCpuPerformanceLevel_m84992F94F4D29ED088A9758ED6032E308037AD10 (BasicProvider_tDF77359CE2123F60C810DDA5ACBDA479BBEB012D* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		V_0 = (-1);
		goto IL_0005;
	}

IL_0005:
	{
		int32_t L_0 = V_0;
		return L_0;
	}
}
// Method Definition Index: 68283
IL2CPP_EXTERN_C IL2CPP_METHOD_ATTR int32_t BasicProvider_get_MaxGpuPerformanceLevel_m379755AD000DA60FAC2BE9797FDE10630CE190AE (BasicProvider_tDF77359CE2123F60C810DDA5ACBDA479BBEB012D* __this, const RuntimeMethod* method) 
{
	int32_t V_0 = 0;
	{
		V_0 = (-1);
		goto IL_0005;
	}

IL_0005:
	{
		int32_t L_0 = V_0;
		return L_0;
	}
}
#ifdef __clang__
#pragma clang diagnostic pop
#endif
// Method Definition Index: 68257
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR String_t* Cinfo_get_id_m65946F15BF304FEAAD403ED3EDC213CD9369554B_inline (Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA* __this, const RuntimeMethod* method) 
{
	{
		String_t* L_0 = __this->___U3CidU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 68258
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Cinfo_set_id_m84D2153E2A1BDECFE6493B5E5FA8776F7913DB70_inline (Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA* __this, String_t* ___0_value, const RuntimeMethod* method) 
{
	{
		String_t* L_0 = ___0_value;
		__this->___U3CidU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CidU3Ek__BackingField), (void*)L_0);
		return;
	}
}
// Method Definition Index: 68259
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Type_t* Cinfo_get_providerType_mCADBAB20C4FA5BE5D0578C0DCF82512690A9312F_inline (Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA* __this, const RuntimeMethod* method) 
{
	{
		Type_t* L_0 = __this->___U3CproviderTypeU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 68260
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Cinfo_set_providerType_mEFBA8B8060FF6D27D59585F09D0F26A1C5F69AF9_inline (Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA* __this, Type_t* ___0_value, const RuntimeMethod* method) 
{
	{
		Type_t* L_0 = ___0_value;
		__this->___U3CproviderTypeU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CproviderTypeU3Ek__BackingField), (void*)L_0);
		return;
	}
}
// Method Definition Index: 68261
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR Type_t* Cinfo_get_subsystemTypeOverride_m46B1FA46EF70E4BBCFA83B3EBB6A39F5FA852AF9_inline (Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA* __this, const RuntimeMethod* method) 
{
	{
		Type_t* L_0 = __this->___U3CsubsystemTypeOverrideU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 68262
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void Cinfo_set_subsystemTypeOverride_m79DBC8798C850ADD6DC96CF64DE6509356C1217A_inline (Cinfo_t4533336D3DE54B9AFC00E345EFF135D0E4C6CFEA* __this, Type_t* ___0_value, const RuntimeMethod* method) 
{
	{
		Type_t* L_0 = ___0_value;
		__this->___U3CsubsystemTypeOverrideU3Ek__BackingField = L_0;
		Il2CppCodeGenWriteBarrier((void**)(&__this->___U3CsubsystemTypeOverrideU3Ek__BackingField), (void*)L_0);
		return;
	}
}
// Method Definition Index: 68210
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void PerformanceDataRecord_set_PerformanceLevelControlAvailable_m2CC4B0A75E3AFD5BC120AF54616CD414711D6C43_inline (PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D* __this, bool ___0_value, const RuntimeMethod* method) 
{
	{
		bool L_0 = ___0_value;
		__this->___U3CPerformanceLevelControlAvailableU3Ek__BackingField = L_0;
		return;
	}
}
// Method Definition Index: 68215
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void PerformanceDataRecord_set_CpuPerformanceBoost_m3E92E90A8057FC58D14F8C3F5DC3145D1FB22B00_inline (PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D* __this, bool ___0_value, const RuntimeMethod* method) 
{
	{
		bool L_0 = ___0_value;
		__this->___U3CCpuPerformanceBoostU3Ek__BackingField = L_0;
		return;
	}
}
// Method Definition Index: 68217
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void PerformanceDataRecord_set_GpuPerformanceBoost_mD2BF46BD6AC8C2AADAB68CF2BD18C40B0C4178F4_inline (PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D* __this, bool ___0_value, const RuntimeMethod* method) 
{
	{
		bool L_0 = ___0_value;
		__this->___U3CGpuPerformanceBoostU3Ek__BackingField = L_0;
		return;
	}
}
// Method Definition Index: 68201
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void PerformanceDataRecord_set_TemperatureLevel_m555EBE87D974B33FEF190D7C2840D0EB74F3F73D_inline (PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D* __this, float ___0_value, const RuntimeMethod* method) 
{
	{
		float L_0 = ___0_value;
		__this->___U3CTemperatureLevelU3Ek__BackingField = L_0;
		return;
	}
}
// Method Definition Index: 68203
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void PerformanceDataRecord_set_TemperatureTrend_m73694AFE0CEA81D0DC5111AE58EA8987618A6A80_inline (PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D* __this, float ___0_value, const RuntimeMethod* method) 
{
	{
		float L_0 = ___0_value;
		__this->___U3CTemperatureTrendU3Ek__BackingField = L_0;
		return;
	}
}
// Method Definition Index: 68198
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR int32_t PerformanceDataRecord_get_ChangeFlags_m16CFF24389B0D33368CDE68198379619E0EEFBCA_inline (PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D* __this, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = __this->___U3CChangeFlagsU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 68199
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void PerformanceDataRecord_set_ChangeFlags_mF8B8F3339A8BE3D98ADC7A99EC7D19D2F404939B_inline (PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_value;
		__this->___U3CChangeFlagsU3Ek__BackingField = L_0;
		return;
	}
}
// Method Definition Index: 68209
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR bool PerformanceDataRecord_get_PerformanceLevelControlAvailable_m3AA579DD438FCA8CD6B6CFE65D769F6CBCDB1A25_inline (PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D* __this, const RuntimeMethod* method) 
{
	{
		bool L_0 = __this->___U3CPerformanceLevelControlAvailableU3Ek__BackingField;
		return L_0;
	}
}
// Method Definition Index: 68206
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void PerformanceDataRecord_set_CpuPerformanceLevel_mA326744A851E95BA8E849DAD1E37578AAFD99435_inline (PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_value;
		__this->___U3CCpuPerformanceLevelU3Ek__BackingField = L_0;
		return;
	}
}
// Method Definition Index: 68208
IL2CPP_MANAGED_FORCE_INLINE IL2CPP_METHOD_ATTR void PerformanceDataRecord_set_GpuPerformanceLevel_m231FA3B8CA050FDB3762ECC3338570CB511E989B_inline (PerformanceDataRecord_t837B5F2229CCB31F9C8E14024EE735AB127E189D* __this, int32_t ___0_value, const RuntimeMethod* method) 
{
	{
		int32_t L_0 = ___0_value;
		__this->___U3CGpuPerformanceLevelU3Ek__BackingField = L_0;
		return;
	}
}
