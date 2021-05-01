#include<ntddk.h>

//C-linkage
extern"C" 

//Driver Entry prototype
NTSTATUS DriverEntry(_In_ PDRIVER_OBJECT DriverObject, _In_ PUNICODE_STRING RegistryPath);

void SampleUnload(_In_ PDRIVER_OBJECT DriverObject) {
	UNREFERENCED_PARAMETER(DriverObject);
}

NTSTATUS DriverEntry(_In_ PDRIVER_OBJECT DriverObject, _In_ PUNICODE_STRING RegistryPath) {

	//UNREFERENCED_PARAMETER - C++ Macro to comment objects out
	UNREFERENCED_PARAMETER(RegistryPath);

	//Prevent Memory Leak
	DriverObject->DriverUnload = SampleUnload;

	return STATUS_SUCCESS;
}
