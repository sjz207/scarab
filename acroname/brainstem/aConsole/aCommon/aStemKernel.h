/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* file: aStemKernel.h						   */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* description: Implementation of a platform-independent BrainStem */
/*		console object.					   */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Copyright 1994-2008. Acroname Inc.                              */
/*                                                                 */
/* This software is the property of Acroname Inc.  Any             */
/* distribution, sale, transmission, or re-use of this code is     */
/* strictly forbidden except with permission from Acroname Inc.    */
/*                                                                 */
/* To the full extent allowed by law, Acroname Inc. also excludes  */
/* for itself and its suppliers any liability, wheither based in   */
/* contract or tort (including negligence), for direct,            */
/* incidental, consequential, indirect, special, or punitive       */
/* damages of any kind, or for loss of revenue or profits, loss of */
/* business, loss of information or data, or other financial loss  */
/* arising out of or in connection with this software, even if     */
/* Acroname Inc. has been advised of the possibility of such       */
/* damages.                                                        */
/*                                                                 */
/* Acroname Inc.                                                   */
/* www.acroname.com                                                */
/* 720-564-0373                                                    */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef _aStemTask_H_
#define _aStemTask_H_

#include "aStem.h"

typedef struct aStemTask {
  aPacketRef		packet;
  struct aStemTask*	pNext;
} aStemTask;

typedef struct aStemKernel {
  aIOLib	ioRef;
  aMemPoolRef	taskPool;
  aStemTask*	pHead;
  aStemTask*	pTail;
} aStemKernel;


aErr aStemKernel_Create(aIOLib ioRef,
			aStemKernel** ppKernel);
aErr aStemKernel_AddPacket(aStemKernel* pKernel,
			   aPacketRef packet);
aBool aStemKernel_PacketAvailable(aStemKernel* pKernel,
			         aPacketRef* pPacket);
aErr aStemKernel_Destroy(aStemKernel* pKernel);

#endif /* _aStemTask_H_ */