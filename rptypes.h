/*
 * rptypes.h
 *
 * Created: 3/10/2023 2:17:07 AM
 *  Author: Bahaa
 */ 

#pragma once

#ifndef RPTYPES_H_
#define RPTYPES_H_

#define RESULT_OK						 0
#define RESULT_FAIL_BIT					 0x80000000
#define RESULT_ALREADY_DONE				 0x20
#define RESULT_INVALID_DATA				 (0x8000 | RESULT_FAIL_BIT)
#define RESULT_OPERATION_FAIL			 (0x8001 | RESULT_FAIL_BIT)
#define RESULT_OPERATION_TIMEOUT		 (0x8002 | RESULT_FAIL_BIT)
#define RESULT_OPERATION_STOP			 (0x8003 | RESULT_FAIL_BIT)
#define RESULT_OPERATION_NOT_SUPPORT     (0x8004 | RESULT_FAIL_BIT)
#define RESULT_FORMAT_NOT_SUPPORT		 (0x8005 | RESULT_FAIL_BIT)
#define RESULT_INSUFFICIENT_MEMORY		 (0x8006 | RESULT_FAIL_BIT)

#define IS_OK(x)    ( ((x) & RESULT_FAIL_BIT) == 0 )
#define IS_FAIL(x)  ( ((x) & RESULT_FAIL_BIT) )

#endif /* RPTYPES_H_ */