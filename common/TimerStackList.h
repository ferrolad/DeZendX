/*
///////////////////////////////////////////////////////////////////////////////
//
//  FileName    :   TimerStackList.h
//  Version     :   1.0
//  Creator     :   RM
//  Create Date :   2006-01-01
//  Comment     :
//
///////////////////////////////////////////////////////////////////////////////
*/

#ifndef __TIMERSTACKLIST_H__
#define __TIMERSTACKLIST_H__

/*
///////////////////////////////////////////////////////////////////////////////
// D E F I N E S
///////////////////////////////////////////////////////////////////////////////
*/
#define STACK_FLAGS_SEEK_EMPTY 0x1
#define STACK_FLAGS_CREATE_NEW 0x2
#define STACK_FLAGS_CREATE_NEW_PERMANENT 0x4

/*
///////////////////////////////////////////////////////////////////////////////
// S T R U C T U R E S
///////////////////////////////////////////////////////////////////////////////
*/
#ifndef _KERNEL_MODE_

typedef LONG NTSTATUS;
typedef LPTHREAD_START_ROUTINE PKSTART_ROUTINE;

#endif /* _KERNEL_MODE_ */

/*
///////////////////////////////////////////////////////////////////////////////
// F U N C T I O N S
///////////////////////////////////////////////////////////////////////////////
*/
#ifdef __cplusplus
extern "C" {
#endif

/*
///////////////////////////////////////////////////////////////////////////////
// GetTotalTimerStackItem
///////////////////////////////////////////////////////////////////////////////
*/
ULONG GetTotalTimerStackItem(
    VOID
    );

/*
///////////////////////////////////////////////////////////////////////////////
// RemoveTimerStackItem
///////////////////////////////////////////////////////////////////////////////
*/
ULONG RemoveTimerStackItem(
    IN ULONG ThreadId
    );

/*
///////////////////////////////////////////////////////////////////////////////
// RemoveTimerStackItemEx
///////////////////////////////////////////////////////////////////////////////
*/
ULONG RemoveTimerStackItemEx(
    IN ULONG ThreadId,
    IN BOOL Cancel
    );

/*
///////////////////////////////////////////////////////////////////////////////
// QueueTimerStackItem
///////////////////////////////////////////////////////////////////////////////
*/
ULONG QueueTimerStackItem(
    IN ULONG ThreadId,
    IN HANDLE Thread,
    IN ULONG Flags
    );

/*
///////////////////////////////////////////////////////////////////////////////
// QueueTimerStackItemEx
///////////////////////////////////////////////////////////////////////////////
*/
ULONG QueueTimerStackItemEx(
    IN ULONG ThreadId,
    IN HANDLE Thread,
    IN ULONG Flags,
    IN PKSTART_ROUTINE CancelRoutine,
    IN PVOID Context,
    IN PLARGE_INTEGER Timeout
    );

/*
///////////////////////////////////////////////////////////////////////////////
// DequeueTimerStackItem
///////////////////////////////////////////////////////////////////////////////
*/
ULONG DequeueTimerStackItem(
    IN ULONG ThreadId
    );

/*
///////////////////////////////////////////////////////////////////////////////
// DequeueTimerStackItemEx
///////////////////////////////////////////////////////////////////////////////
*/
ULONG DequeueTimerStackItemEx(
    IN ULONG ThreadId,
    IN BOOL Cancel
    );

/*
///////////////////////////////////////////////////////////////////////////////
// TimerStackListRoutine
///////////////////////////////////////////////////////////////////////////////
*/
ULONG TimerStackListRoutine(
    IN PLARGE_INTEGER Time
    );

/*
///////////////////////////////////////////////////////////////////////////////
// InitTimerStackList
///////////////////////////////////////////////////////////////////////////////
*/
VOID InitTimerStackList(
    VOID
    );

/*
///////////////////////////////////////////////////////////////////////////////
// UninitTimerStackList
///////////////////////////////////////////////////////////////////////////////
*/
VOID UninitTimerStackList(
    VOID
    );

#ifdef __cplusplus
}
#endif
/*
///////////////////////////////////////////////////////////////////////////////
// E N D  O F  F I L E
///////////////////////////////////////////////////////////////////////////////
*/
#endif /* __TIMERSTACKLIST_H__ */