#ifdef POPULATE_MAP
#define DECLARE(base_name, string_name, ordinal) \
  { "_" string_name, XBOX_##base_name }

#define END ,
#define LAST_END
#else
#define DECLARE(base_name, string_name, ordinal) \
  static constexpr uint32_t XBOX_##base_name = (ordinal)
#define END ;
#define LAST_END ;
#endif

DECLARE(AvGetSavedDataAddress, "AvGetSavedDataAddress@0", 1)
END DECLARE(AvSendTVEncoderOption, "AvSendTVEncoderOption@16", 2) END
    DECLARE(AvSetDisplayMode, "AvSetDisplayMode@24", 3) END
    DECLARE(AvSetSavedDataAddress, "AvSetSavedDataAddress@4", 4) END
    DECLARE(DbgBreakPoint, "DbgBreakPoint@0", 5) END
    DECLARE(DbgBreakPointWithStatus, "DbgBreakPointWithStatus@4", 6) END
    DECLARE(DbgLoadImageSymbols, "DbgLoadImageSymbols@12", 7) END
    DECLARE(DbgPrint, "DbgPrint", 8) END
    DECLARE(HalReadSMCTrayState, "HalReadSMCTrayState@8", 9) END
    DECLARE(DbgPrompt, "DbgPrompt@12", 10) END
    DECLARE(DbgUnLoadImageSymbols, "DbgUnLoadImageSymbols@12", 11) END
    DECLARE(ExAcquireReadWriteLockExclusive,
            "ExAcquireReadWriteLockExclusive@4", 12) END
    DECLARE(ExAcquireReadWriteLockShared, "ExAcquireReadWriteLockShared@4",
            13) END DECLARE(ExAllocatePool, "ExAllocatePool@4", 14) END
    DECLARE(ExAllocatePoolWithTag, "ExAllocatePoolWithTag@8", 15) END
    DECLARE(ExEventObjectType, "ExEventObjectType", 16) END
    DECLARE(ExFreePool, "ExFreePool@4", 17) END
    DECLARE(ExInitializeReadWriteLock, "ExInitializeReadWriteLock@4", 18) END
    DECLARE(ExInterlockedAddLargeInteger, "ExInterlockedAddLargeInteger@16",
            19) END DECLARE(ExInterlockedAddLargeStatistic,
                            "@ExInterlockedAddLargeStatistic@8", 20) END
    DECLARE(ExInterlockedCompareExchange64,
            "@ExInterlockedCompareExchange64@12", 21) END
    DECLARE(ExMutantObjectType, "ExMutantObjectType", 22) END
    DECLARE(ExQueryPoolBlockSize, "ExQueryPoolBlockSize@4", 23) END
    DECLARE(ExQueryNonVolatileSetting, "ExQueryNonVolatileSetting@20", 24) END
    DECLARE(ExReadWriteRefurbInfo, "ExReadWriteRefurbInfo@12", 25) END
    DECLARE(ExRaiseException, "ExRaiseException@4", 26) END
    DECLARE(ExRaiseStatus, "ExRaiseStatus@4", 27) END
    DECLARE(ExReleaseReadWriteLock, "ExReleaseReadWriteLock@4", 28) END
    DECLARE(ExSaveNonVolatileSetting, "ExSaveNonVolatileSetting@16", 29) END
    DECLARE(ExSemaphoreObjectType, "ExSemaphoreObjectType", 30) END
    DECLARE(ExTimerObjectType, "ExTimerObjectType", 31) END
    DECLARE(ExfInterlockedInsertHeadList, "@ExfInterlockedInsertHeadList@8",
            32) END DECLARE(ExfInterlockedInsertTailList,
                            "@ExfInterlockedInsertTailList@8", 33) END
    DECLARE(ExfInterlockedRemoveHeadList, "@ExfInterlockedRemoveHeadList@4",
            34) END DECLARE(FscGetCacheSize, "FscGetCacheSize@0", 35) END
    DECLARE(FscInvalidateIdleBlocks, "FscInvalidateIdleBlocks@0", 36) END
    DECLARE(FscSetCacheSize, "FscSetCacheSize@4", 37) END
    DECLARE(HalClearSoftwareInterrupt, "@HalClearSoftwareInterrupt@4", 38) END
    DECLARE(HalDisableSystemInterrupt, "HalDisableSystemInterrupt@4", 39) END
    DECLARE(HalDiskCachePartitionCount, "HalDiskCachePartitionCount", 40) END
    DECLARE(HalDiskModelNumber, "HalDiskModelNumber", 41) END
    DECLARE(HalDiskSerialNumber, "HalDiskSerialNumber", 42) END
    DECLARE(HalEnableSystemInterrupt, "HalEnableSystemInterrupt@8", 43) END
    DECLARE(HalGetInterruptVector, "HalGetInterruptVector@8", 44) END
    DECLARE(HalReadSMBusValue, "HalReadSMBusValue@16", 45) END
    DECLARE(HalReadWritePCISpace, "HalReadWritePCISpace@24", 46) END
    DECLARE(HalRegisterShutdownNotification,
            "HalRegisterShutdownNotification@8", 47) END
    DECLARE(HalRequestSoftwareInterrupt, "@HalRequestSoftwareInterrupt@4",
            48) END
    DECLARE(HalReturnToFirmware, "HalReturnToFirmware@4", 49) END
    DECLARE(HalWriteSMBusValue, "HalWriteSMBusValue@16", 50) END
    DECLARE(InterlockedCompareExchange, "@InterlockedCompareExchange@12",
            51) END
    DECLARE(InterlockedDecrement, "@InterlockedDecrement@4", 52) END
    DECLARE(InterlockedIncrement, "@InterlockedIncrement@4", 53) END
    DECLARE(InterlockedExchange, "@InterlockedExchange@8", 54) END
    DECLARE(InterlockedExchangeAdd, "@InterlockedExchangeAdd@8", 55) END
    DECLARE(InterlockedFlushSList, "@InterlockedFlushSList@4", 56) END
    DECLARE(InterlockedPopEntrySList, "@InterlockedPopEntrySList@4", 57) END
    DECLARE(InterlockedPushEntrySList, "@InterlockedPushEntrySList@8", 58) END
    DECLARE(IoAllocateIrp, "IoAllocateIrp@4", 59) END
    DECLARE(IoBuildAsynchronousFsdRequest, "IoBuildAsynchronousFsdRequest@24",
            60) END DECLARE(IoBuildDeviceIoControlRequest,
                            "IoBuildDeviceIoControlRequest@36", 61) END
    DECLARE(IoBuildSynchronousFsdRequest, "IoBuildSynchronousFsdRequest@28",
            62) END DECLARE(IoCheckShareAccess, "IoCheckShareAccess@20", 63) END
    DECLARE(IoCompletionObjectType, "IoCompletionObjectType", 64) END
    DECLARE(IoCreateDevice, "IoCreateDevice@24", 65) END
    DECLARE(IoCreateFile, "IoCreateFile@40", 66) END
    DECLARE(IoCreateSymbolicLink, "IoCreateSymbolicLink@8", 67) END
    DECLARE(IoDeleteDevice, "IoDeleteDevice@4", 68) END
    DECLARE(IoDeleteSymbolicLink, "IoDeleteSymbolicLink@4", 69) END
    DECLARE(IoDeviceObjectType, "IoDeviceObjectType", 70) END
    DECLARE(IoFileObjectType, "IoFileObjectType", 71) END
    DECLARE(IoFreeIrp, "IoFreeIrp@4", 72) END
    DECLARE(IoInitializeIrp, "IoInitializeIrp@12", 73) END
    DECLARE(IoInvalidDeviceRequest, "IoInvalidDeviceRequest@8", 74) END
    DECLARE(IoQueryFileInformation, "IoQueryFileInformation@20", 75) END
    DECLARE(IoQueryVolumeInformation, "IoQueryVolumeInformation@20", 76) END
    DECLARE(IoQueueThreadIrp, "IoQueueThreadIrp@4", 77) END
    DECLARE(IoRemoveShareAccess, "IoRemoveShareAccess@8", 78) END
    DECLARE(IoSetIoCompletion, "IoSetIoCompletion@20", 79) END
    DECLARE(IoSetShareAccess, "IoSetShareAccess@16", 80) END
    DECLARE(IoStartNextPacket, "IoStartNextPacket@4", 81) END
    DECLARE(IoStartNextPacketByKey, "IoStartNextPacketByKey@8", 82) END
    DECLARE(IoStartPacket, "IoStartPacket@12", 83) END
    DECLARE(IoSynchronousDeviceIoControlRequest,
            "IoSynchronousDeviceIoControlRequest@32", 84) END
    DECLARE(IoSynchronousFsdRequest, "IoSynchronousFsdRequest@20", 85) END
    DECLARE(IofCallDriver, "@IofCallDriver@8", 86) END
    DECLARE(IofCompleteRequest, "@IofCompleteRequest@8", 87) END
    DECLARE(KdDebuggerEnabled, "KdDebuggerEnabled", 88) END
    DECLARE(KdDebuggerNotPresent, "KdDebuggerNotPresent", 89) END
    DECLARE(IoDismountVolume, "IoDismountVolume@4", 90) END
    DECLARE(IoDismountVolumeByName, "IoDismountVolumeByName@4", 91) END
    DECLARE(KeAlertResumeThread, "KeAlertResumeThread@4", 92) END
    DECLARE(KeAlertThread, "KeAlertThread@8", 93) END
    DECLARE(KeBoostPriorityThread, "KeBoostPriorityThread@8", 94) END
    DECLARE(KeBugCheck, "KeBugCheck@4", 95) END
    DECLARE(KeBugCheckEx, "KeBugCheckEx@20", 96) END
    DECLARE(KeCancelTimer, "KeCancelTimer@4", 97) END
    DECLARE(KeConnectInterrupt, "KeConnectInterrupt@4", 98) END
    DECLARE(KeDelayExecutionThread, "KeDelayExecutionThread@12", 99) END
    DECLARE(KeDisconnectInterrupt, "KeDisconnectInterrupt@4", 100) END
    DECLARE(KeEnterCriticalRegion, "KeEnterCriticalRegion@0", 101) END
    DECLARE(MmGlobalData, "MmGlobalData", 102) END
    DECLARE(KeGetCurrentIrql, "KeGetCurrentIrql@0", 103) END
    DECLARE(KeGetCurrentThread, "KeGetCurrentThread@0", 104) END
    DECLARE(KeInitializeApc, "KeInitializeApc@28", 105) END
    DECLARE(KeInitializeDeviceQueue, "KeInitializeDeviceQueue@4", 106) END
    DECLARE(KeInitializeDpc, "KeInitializeDpc@12", 107) END
    DECLARE(KeInitializeEvent, "KeInitializeEvent@12", 108) END
    DECLARE(KeInitializeInterrupt, "KeInitializeInterrupt@28", 109) END
    DECLARE(KeInitializeMutant, "KeInitializeMutant@8", 110) END
    DECLARE(KeInitializeQueue, "KeInitializeQueue@8", 111) END
    DECLARE(KeInitializeSemaphore, "KeInitializeSemaphore@12", 112) END
    DECLARE(KeInitializeTimerEx, "KeInitializeTimerEx@8", 113) END
    DECLARE(KeInsertByKeyDeviceQueue, "KeInsertByKeyDeviceQueue@12", 114) END
    DECLARE(KeInsertDeviceQueue, "KeInsertDeviceQueue@8", 115) END
    DECLARE(KeInsertHeadQueue, "KeInsertHeadQueue@8", 116) END
    DECLARE(KeInsertQueue, "KeInsertQueue@8", 117) END
    DECLARE(KeInsertQueueApc, "KeInsertQueueApc@16", 118) END
    DECLARE(KeInsertQueueDpc, "KeInsertQueueDpc@12", 119) END
    DECLARE(KeInterruptTime, "KeInterruptTime", 120) END
    DECLARE(KeIsExecutingDpc, "KeIsExecutingDpc@0", 121) END
    DECLARE(KeLeaveCriticalRegion, "KeLeaveCriticalRegion@0", 122) END
    DECLARE(KePulseEvent, "KePulseEvent@12", 123) END
    DECLARE(KeQueryBasePriorityThread, "KeQueryBasePriorityThread@4", 124) END
    DECLARE(KeQueryInterruptTime, "KeQueryInterruptTime@0", 125) END
    DECLARE(KeQueryPerformanceCounter, "KeQueryPerformanceCounter@0", 126) END
    DECLARE(KeQueryPerformanceFrequency, "KeQueryPerformanceFrequency@0",
            127) END DECLARE(KeQuerySystemTime, "KeQuerySystemTime@4", 128) END
    DECLARE(KeRaiseIrqlToDpcLevel, "KeRaiseIrqlToDpcLevel@0", 129) END
    DECLARE(KeRaiseIrqlToSynchLevel, "KeRaiseIrqlToSynchLevel@0", 130) END
    DECLARE(KeReleaseMutant, "KeReleaseMutant@16", 131) END
    DECLARE(KeReleaseSemaphore, "KeReleaseSemaphore@16", 132) END
    DECLARE(KeRemoveByKeyDeviceQueue, "KeRemoveByKeyDeviceQueue@8", 133) END
    DECLARE(KeRemoveDeviceQueue, "KeRemoveDeviceQueue@4", 134) END
    DECLARE(KeRemoveEntryDeviceQueue, "KeRemoveEntryDeviceQueue@8", 135) END
    DECLARE(KeRemoveQueue, "KeRemoveQueue@12", 136) END
    DECLARE(KeRemoveQueueDpc, "KeRemoveQueueDpc@4", 137) END
    DECLARE(KeResetEvent, "KeResetEvent@4", 138) END
    DECLARE(KeRestoreFloatingPointState, "KeRestoreFloatingPointState@4",
            139) END DECLARE(KeResumeThread, "KeResumeThread@4", 140) END
    DECLARE(KeRundownQueue, "KeRundownQueue@4", 141) END
    DECLARE(KeSaveFloatingPointState, "KeSaveFloatingPointState@4", 142) END
    DECLARE(KeSetBasePriorityThread, "KeSetBasePriorityThread@8", 143) END
    DECLARE(KeSetDisableBoostThread, "KeSetDisableBoostThread@8", 144) END
    DECLARE(KeSetEvent, "KeSetEvent@12", 145) END
    DECLARE(KeSetEventBoostPriority, "KeSetEventBoostPriority@8", 146) END
    DECLARE(KeSetPriorityProcess, "KeSetPriorityProcess@8", 147) END
    DECLARE(KeSetPriorityThread, "KeSetPriorityThread@8", 148) END
    DECLARE(KeSetTimer, "KeSetTimer@16", 149) END
    DECLARE(KeSetTimerEx, "KeSetTimerEx@20", 150) END
    DECLARE(KeStallExecutionProcessor, "KeStallExecutionProcessor@4", 151) END
    DECLARE(KeSuspendThread, "KeSuspendThread@4", 152) END
    DECLARE(KeSynchronizeExecution, "KeSynchronizeExecution@12", 153) END
    DECLARE(KeSystemTime, "KeSystemTime", 154) END
    DECLARE(KeTestAlertThread, "KeTestAlertThread@4", 155) END
    DECLARE(KeTickCount, "KeTickCount", 156) END
    DECLARE(KeTimeIncrement, "KeTimeIncrement", 157) END
    DECLARE(KeWaitForMultipleObjects, "KeWaitForMultipleObjects@32", 158) END
    DECLARE(KeWaitForSingleObject, "KeWaitForSingleObject@20", 159) END
    DECLARE(KfRaiseIrql, "@KfRaiseIrql@4", 160) END
    DECLARE(KfLowerIrql, "@KfLowerIrql@4", 161) END
    DECLARE(KiBugCheckData, "KiBugCheckData", 162) END
    DECLARE(KiUnlockDispatcherDatabase, "@KiUnlockDispatcherDatabase@4",
            163) END DECLARE(LaunchDataPage, "LaunchDataPage", 164) END
    DECLARE(MmAllocateContiguousMemory, "MmAllocateContiguousMemory@4", 165) END
    DECLARE(MmAllocateContiguousMemoryEx, "MmAllocateContiguousMemoryEx@20",
            166) END
    DECLARE(MmAllocateSystemMemory, "MmAllocateSystemMemory@8", 167) END
    DECLARE(MmClaimGpuInstanceMemory, "MmClaimGpuInstanceMemory@8", 168) END
    DECLARE(MmCreateKernelStack, "MmCreateKernelStack@8", 169) END
    DECLARE(MmDeleteKernelStack, "MmDeleteKernelStack@8", 170) END
    DECLARE(MmFreeContiguousMemory, "MmFreeContiguousMemory@4", 171) END
    DECLARE(MmFreeSystemMemory, "MmFreeSystemMemory@8", 172) END
    DECLARE(MmGetPhysicalAddress, "MmGetPhysicalAddress@4", 173) END
    DECLARE(MmIsAddressValid, "MmIsAddressValid@4", 174) END
    DECLARE(MmLockUnlockBufferPages, "MmLockUnlockBufferPages@12", 175) END
    DECLARE(MmLockUnlockPhysicalPage, "MmLockUnlockPhysicalPage@8", 176) END
    DECLARE(MmMapIoSpace, "MmMapIoSpace@12", 177) END
    DECLARE(MmPersistContiguousMemory, "MmPersistContiguousMemory@12", 178) END
    DECLARE(MmQueryAddressProtect, "MmQueryAddressProtect@4", 179) END
    DECLARE(MmQueryAllocationSize, "MmQueryAllocationSize@4", 180) END
    DECLARE(MmQueryStatistics, "MmQueryStatistics@4", 181) END
    DECLARE(MmSetAddressProtect, "MmSetAddressProtect@12", 182) END
    DECLARE(MmUnmapIoSpace, "MmUnmapIoSpace@8", 183) END
    DECLARE(NtAllocateVirtualMemory, "NtAllocateVirtualMemory@20", 184) END
    DECLARE(NtCancelTimer, "NtCancelTimer@8", 185) END
    DECLARE(NtClearEvent, "NtClearEvent@4", 186) END
    DECLARE(NtClose, "NtClose@4", 187) END
    DECLARE(NtCreateDirectoryObject, "NtCreateDirectoryObject@8", 188) END
    DECLARE(NtCreateEvent, "NtCreateEvent@16", 189) END
    DECLARE(NtCreateFile, "NtCreateFile@36", 190) END
    DECLARE(NtCreateIoCompletion, "NtCreateIoCompletion@16", 191) END
    DECLARE(NtCreateMutant, "NtCreateMutant@12", 192) END
    DECLARE(NtCreateSemaphore, "NtCreateSemaphore@16", 193) END
    DECLARE(NtCreateTimer, "NtCreateTimer@12", 194) END
    DECLARE(NtDeleteFile, "NtDeleteFile@4", 195) END
    DECLARE(NtDeviceIoControlFile, "NtDeviceIoControlFile@40", 196) END
    DECLARE(NtDuplicateObject, "NtDuplicateObject@12", 197) END
    DECLARE(NtFlushBuffersFile, "NtFlushBuffersFile@8", 198) END
    DECLARE(NtFreeVirtualMemory, "NtFreeVirtualMemory@12", 199) END
    DECLARE(NtFsControlFile, "NtFsControlFile@40", 200) END
    DECLARE(NtOpenDirectoryObject, "NtOpenDirectoryObject@8", 201) END
    DECLARE(NtOpenFile, "NtOpenFile@24", 202) END
    DECLARE(NtOpenSymbolicLinkObject, "NtOpenSymbolicLinkObject@8", 203) END
    DECLARE(NtProtectVirtualMemory, "NtProtectVirtualMemory@16", 204) END
    DECLARE(NtPulseEvent, "NtPulseEvent@8", 205) END
    DECLARE(NtQueueApcThread, "NtQueueApcThread@20", 206) END
    DECLARE(NtQueryDirectoryFile, "NtQueryDirectoryFile@40", 207) END
    DECLARE(NtQueryDirectoryObject, "NtQueryDirectoryObject@24", 208) END
    DECLARE(NtQueryEvent, "NtQueryEvent@8", 209) END
    DECLARE(NtQueryFullAttributesFile, "NtQueryFullAttributesFile@8", 210) END
    DECLARE(NtQueryInformationFile, "NtQueryInformationFile@20", 211) END
    DECLARE(NtQueryIoCompletion, "NtQueryIoCompletion@8", 212) END
    DECLARE(NtQueryMutant, "NtQueryMutant@8", 213) END
    DECLARE(NtQuerySemaphore, "NtQuerySemaphore@8", 214) END
    DECLARE(NtQuerySymbolicLinkObject, "NtQuerySymbolicLinkObject@12", 215) END
    DECLARE(NtQueryTimer, "NtQueryTimer@8", 216) END
    DECLARE(NtQueryVirtualMemory, "NtQueryVirtualMemory@8", 217) END
    DECLARE(NtQueryVolumeInformationFile, "NtQueryVolumeInformationFile@20",
            218) END DECLARE(NtReadFile, "NtReadFile@32", 219) END
    DECLARE(NtReadFileScatter, "NtReadFileScatter@32", 220) END
    DECLARE(NtReleaseMutant, "NtReleaseMutant@8", 221) END
    DECLARE(NtReleaseSemaphore, "NtReleaseSemaphore@12", 222) END
    DECLARE(NtRemoveIoCompletion, "NtRemoveIoCompletion@20", 223) END
    DECLARE(NtResumeThread, "NtResumeThread@8", 224) END
    DECLARE(NtSetEvent, "NtSetEvent@8", 225) END
    DECLARE(NtSetInformationFile, "NtSetInformationFile@20", 226) END
    DECLARE(NtSetIoCompletion, "NtSetIoCompletion@20", 227) END
    DECLARE(NtSetSystemTime, "NtSetSystemTime@8", 228) END
    DECLARE(NtSetTimerEx, "NtSetTimerEx@32", 229) END
    DECLARE(NtSignalAndWaitForSingleObjectEx,
            "NtSignalAndWaitForSingleObjectEx@20", 230) END
    DECLARE(NtSuspendThread, "NtSuspendThread@8", 231) END
    DECLARE(NtUserIoApcDispatcher, "NtUserIoApcDispatcher@12", 232) END
    DECLARE(NtWaitForSingleObject, "NtWaitForSingleObject@12", 233) END
    DECLARE(NtWaitForSingleObjectEx, "NtWaitForSingleObjectEx@16", 234) END
    DECLARE(NtWaitForMultipleObjectsEx, "NtWaitForMultipleObjectsEx@24",
            235) END DECLARE(NtWriteFile, "NtWriteFile@32", 236) END
    DECLARE(NtWriteFileGather, "NtWriteFileGather@32", 237) END
    DECLARE(NtYieldExecution, "NtYieldExecution@0", 238) END
    DECLARE(ObCreateObject, "ObCreateObject@16", 239) END
    DECLARE(ObDirectoryObjectType, "ObDirectoryObjectType", 240) END
    DECLARE(ObInsertObject, "ObInsertObject@16", 241) END
    DECLARE(ObMakeTemporaryObject, "ObMakeTemporaryObject@4", 242) END
    DECLARE(ObOpenObjectByName, "ObOpenObjectByName@16", 243) END
    DECLARE(ObOpenObjectByPointer, "ObOpenObjectByPointer@12", 244) END
    DECLARE(ObpObjectHandleTable, "ObpObjectHandleTable", 245) END
    DECLARE(ObReferenceObjectByHandle, "ObReferenceObjectByHandle@12", 246) END
    DECLARE(ObReferenceObjectByName, "ObReferenceObjectByName@20", 247) END
    DECLARE(ObReferenceObjectByPointer, "ObReferenceObjectByPointer@8", 248) END
    DECLARE(ObSymbolicLinkObjectType, "ObSymbolicLinkObjectType", 249) END
    DECLARE(ObfDereferenceObject, "@ObfDereferenceObject@4", 250) END
    DECLARE(ObfReferenceObject, "@ObfReferenceObject@4", 251) END
    DECLARE(PhyGetLinkState, "PhyGetLinkState@4", 252) END
    DECLARE(PhyInitialize, "PhyInitialize@8", 253) END
    DECLARE(PsCreateSystemThread, "PsCreateSystemThread@20", 254) END
    DECLARE(PsCreateSystemThreadEx, "PsCreateSystemThreadEx@40", 255) END
    DECLARE(PsQueryStatistics, "PsQueryStatistics@4", 256) END
    DECLARE(PsSetCreateThreadNotifyRoutine, "PsSetCreateThreadNotifyRoutine@4",
            257) END
    DECLARE(PsTerminateSystemThread, "PsTerminateSystemThread@4", 258) END
    DECLARE(PsThreadObjectType, "PsThreadObjectType", 259) END
    DECLARE(RtlAnsiStringToUnicodeString, "RtlAnsiStringToUnicodeString@12",
            260) END
    DECLARE(RtlAppendStringToString, "RtlAppendStringToString@8", 261) END
    DECLARE(RtlAppendUnicodeStringToString, "RtlAppendUnicodeStringToString@8",
            262) END
    DECLARE(RtlAppendUnicodeToString, "RtlAppendUnicodeToString@8", 263) END
    DECLARE(RtlAssert, "RtlAssert@16", 264) END
    DECLARE(RtlCaptureContext, "RtlCaptureContext@4", 265) END
    DECLARE(RtlCaptureStackBackTrace, "RtlCaptureStackBackTrace@16", 266) END
    DECLARE(RtlCharToInteger, "RtlCharToInteger@12", 267) END
    DECLARE(RtlCompareMemory, "RtlCompareMemory@12", 268) END
    DECLARE(RtlCompareMemoryUlong, "RtlCompareMemoryUlong@12", 269) END
    DECLARE(RtlCompareString, "RtlCompareString@12", 270) END
    DECLARE(RtlCompareUnicodeString, "RtlCompareUnicodeString@12", 271) END
    DECLARE(RtlCopyString, "RtlCopyString@8", 272) END
    DECLARE(RtlCopyUnicodeString, "RtlCopyUnicodeString@8", 273) END
    DECLARE(RtlCreateUnicodeString, "RtlCreateUnicodeString@8", 274) END
    DECLARE(RtlDowncaseUnicodeChar, "RtlDowncaseUnicodeChar@4", 275) END
    DECLARE(RtlDowncaseUnicodeString, "RtlDowncaseUnicodeString@12", 276) END
    DECLARE(RtlEnterCriticalSection, "RtlEnterCriticalSection@4", 277) END
    DECLARE(RtlEnterCriticalSectionAndRegion,
            "RtlEnterCriticalSectionAndRegion@4", 278) END
    DECLARE(RtlEqualString, "RtlEqualString@12", 279) END
    DECLARE(RtlEqualUnicodeString, "RtlEqualUnicodeString@12", 280) END
    DECLARE(RtlExtendedIntegerMultiply, "RtlExtendedIntegerMultiply@12",
            281) END DECLARE(RtlExtendedLargeIntegerDivide,
                             "RtlExtendedLargeIntegerDivide@16", 282) END
    DECLARE(RtlExtendedMagicDivide, "RtlExtendedMagicDivide@20", 283) END
    DECLARE(RtlFillMemory, "RtlFillMemory@12", 284) END
    DECLARE(RtlFillMemoryUlong, "RtlFillMemoryUlong@12", 285) END
    DECLARE(RtlFreeAnsiString, "RtlFreeAnsiString@4", 286) END
    DECLARE(RtlFreeUnicodeString, "RtlFreeUnicodeString@4", 287) END
    DECLARE(RtlGetCallersAddress, "RtlGetCallersAddress@8", 288) END
    DECLARE(RtlInitAnsiString, "RtlInitAnsiString@8", 289) END
    DECLARE(RtlInitUnicodeString, "RtlInitUnicodeString@8", 290) END
    DECLARE(RtlInitializeCriticalSection, "RtlInitializeCriticalSection@4",
            291) END DECLARE(RtlIntegerToChar, "RtlIntegerToChar@16", 292) END
    DECLARE(RtlIntegerToUnicodeString, "RtlIntegerToUnicodeString@12", 293) END
    DECLARE(RtlLeaveCriticalSection, "RtlLeaveCriticalSection@4", 294) END
    DECLARE(RtlLeaveCriticalSectionAndRegion,
            "RtlLeaveCriticalSectionAndRegion@4", 295) END
    DECLARE(RtlLowerChar, "RtlLowerChar@4", 296) END
    DECLARE(RtlMapGenericMask, "RtlMapGenericMask@8", 297) END
    DECLARE(RtlMoveMemory, "RtlMoveMemory@12", 298) END
    DECLARE(RtlMultiByteToUnicodeN, "RtlMultiByteToUnicodeN@20", 299) END
    DECLARE(RtlMultiByteToUnicodeSize, "RtlMultiByteToUnicodeSize@12", 300) END
    DECLARE(RtlNtStatusToDosError, "RtlNtStatusToDosError@4", 301) END
    DECLARE(RtlRaiseException, "RtlRaiseException@4", 302) END
    DECLARE(RtlRaiseStatus, "RtlRaiseStatus@4", 303) END
    DECLARE(RtlTimeFieldsToTime, "RtlTimeFieldsToTime@8", 304) END
    DECLARE(RtlTimeToTimeFields, "RtlTimeToTimeFields@8", 305) END
    DECLARE(RtlTryEnterCriticalSection, "RtlTryEnterCriticalSection@4", 306) END
    DECLARE(RtlUlongByteSwap, "@RtlUlongByteSwap@4", 307) END
    DECLARE(RtlUnicodeStringToAnsiString, "RtlUnicodeStringToAnsiString@12",
            308) END
    DECLARE(RtlUnicodeStringToInteger, "RtlUnicodeStringToInteger@12", 309) END
    DECLARE(RtlUnicodeToMultiByteN, "RtlUnicodeToMultiByteN@20", 310) END
    DECLARE(RtlUnicodeToMultiByteSize, "RtlUnicodeToMultiByteSize@12", 311) END
    DECLARE(RtlUnwind, "RtlUnwind@16", 312) END
    DECLARE(RtlUpcaseUnicodeChar, "RtlUpcaseUnicodeChar@4", 313) END
    DECLARE(RtlUpcaseUnicodeString, "RtlUpcaseUnicodeString@12", 314) END
    DECLARE(RtlUpcaseUnicodeToMultiByteN, "RtlUpcaseUnicodeToMultiByteN@20",
            315) END DECLARE(RtlUpperChar, "RtlUpperChar@4", 316) END
    DECLARE(RtlUpperString, "RtlUpperString@8", 317) END
    DECLARE(RtlUshortByteSwap, "@RtlUshortByteSwap@4", 318) END
    DECLARE(RtlWalkFrameChain, "RtlWalkFrameChain@12", 319) END
    DECLARE(RtlZeroMemory, "RtlZeroMemory@8", 320) END
    DECLARE(XboxEEPROMKey, "XboxEEPROMKey", 321) END
    DECLARE(XboxHardwareInfo, "XboxHardwareInfo", 322) END
    DECLARE(XboxHDKey, "XboxHDKey", 323) END
    DECLARE(XboxKrnlVersion, "XboxKrnlVersion", 324) END
    DECLARE(XboxSignatureKey, "XboxSignatureKey", 325) END
    DECLARE(XeImageFileName, "XeImageFileName", 326) END
    DECLARE(XeLoadSection, "XeLoadSection@4", 327) END
    DECLARE(XeUnloadSection, "XeUnloadSection@4", 328) END
    DECLARE(READ_PORT_BUFFER_UCHAR, "READ_PORT_BUFFER_UCHAR@12", 329) END
    DECLARE(READ_PORT_BUFFER_USHORT, "READ_PORT_BUFFER_USHORT@12", 330) END
    DECLARE(READ_PORT_BUFFER_ULONG, "READ_PORT_BUFFER_ULONG@12", 331) END
    DECLARE(WRITE_PORT_BUFFER_UCHAR, "WRITE_PORT_BUFFER_UCHAR@12", 332) END
    DECLARE(WRITE_PORT_BUFFER_USHORT, "WRITE_PORT_BUFFER_USHORT@12", 333) END
    DECLARE(WRITE_PORT_BUFFER_ULONG, "WRITE_PORT_BUFFER_ULONG@12", 334) END
    DECLARE(XcSHAInit, "XcSHAInit@4", 335) END
    DECLARE(XcSHAUpdate, "XcSHAUpdate@12", 336) END
    DECLARE(XcSHAFinal, "XcSHAFinal@8", 337) END
    DECLARE(XcRC4Key, "XcRC4Key@12", 338) END
    DECLARE(XcRC4Crypt, "XcRC4Crypt@12", 339) END
    DECLARE(XcHMAC, "XcHMAC@28", 340) END
    DECLARE(XcPKEncPublic, "XcPKEncPublic@12", 341) END
    DECLARE(XcPKDecPrivate, "XcPKDecPrivate@12", 342) END
    DECLARE(XcPKGetKeyLen, "XcPKGetKeyLen@4", 343) END
    DECLARE(XcVerifyPKCS1Signature, "XcVerifyPKCS1Signature@12", 344) END
    DECLARE(XcModExp, "XcModExp@20", 345) END
    DECLARE(XcDESKeyParity, "XcDESKeyParity@8", 346) END
    DECLARE(XcKeyTable, "XcKeyTable@12", 347) END
    DECLARE(XcBlockCrypt, "XcBlockCrypt@20", 348) END
    DECLARE(XcBlockCryptCBC, "XcBlockCryptCBC@28", 349) END
    DECLARE(XcCryptService, "XcCryptService@8", 350) END
    DECLARE(XcUpdateCrypto, "XcUpdateCrypto@8", 351) END
    DECLARE(RtlRip, "RtlRip@12", 352) END
    DECLARE(XboxLANKey, "XboxLANKey", 353) END
    DECLARE(XboxAlternateSignatureKeys, "XboxAlternateSignatureKeys", 354) END
    DECLARE(XePublicKeyData, "XePublicKeyData", 355) END
    DECLARE(HalBootSMCVideoMode, "HalBootSMCVideoMode", 356) END
    DECLARE(IdexChannelObject, "IdexChannelObject", 357) END
    DECLARE(HalIsResetOrShutdownPending, "HalIsResetOrShutdownPending@0",
            358) END
    DECLARE(IoMarkIrpMustComplete, "IoMarkIrpMustComplete@4", 359) END
    DECLARE(HalInitiateShutdown, "HalInitiateShutdown@0", 360) END
    DECLARE(RtlSnprintf, "RtlSnprintf", 361) END
    DECLARE(RtlSprintf, "RtlSprintf", 362) END
    DECLARE(RtlVsnprintf, "RtlVsnprintf", 363) END
    DECLARE(RtlVsprintf, "RtlVsprintf", 364) END
    DECLARE(HalEnableSecureTrayEject, "HalEnableSecureTrayEject@0", 365) END
    DECLARE(HalWriteSMCScratchRegister, "HalWriteSMCScratchRegister@4", 366) END
    DECLARE(MmDbgAllocateMemory, "MmDbgAllocateMemory@8", 374) END
    DECLARE(MmDbgFreeMemory, "MmDbgFreeMemory@8", 375) END
    DECLARE(MmDbgQueryAvailablePages, "MmDbgQueryAvailablePages@0", 376) END
    DECLARE(MmDbgReleaseAddress, "MmDbgReleaseAddress@8", 377) END
    DECLARE(MmDbgWriteCheck, "MmDbgWriteCheck@8", 378) LAST_END

#undef END
#undef LAST_END
#undef DECLARE