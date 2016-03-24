/**
  * @file    dbg_log.h
  * @author  Alexey Serdyuk
  * @version V0.0.1
  * @date    23-March-2016
  * @brief   Debug log
  *          
  *          Lightweight implementation of debug logger for low scale embedded systems.
  *          In this implementation standard streams are not used, since they are 
  *          not efficient or even not available for microcontroller based platforms.
  */
#ifndef _DBG_LOG_H_
#define _DBG_LOG_H_

#include <stdio.h>
#include <string.h>
#include <stdarg.h>

/* Defines debug level of the logger:
 * 0 - no debug information
 * 1 - errors messages
 * 2 - warnings messages + level 1
 * 3 - information messages + level 1 and 2
 */
#define DEBUG_LEVEL 0 

/* Defines printf variant with or without floats printing support.
 * Switching off this option may reduce code size.
 */
#define DEBUG_FLOAT_PRINT_SUPPORT

/* The maximum length of the debug message */
#define DBG_STR_MAX 120

#if DEBUG_LEVEL >= 1
#define dbg_log_error( fmtstr, ... )   debug( "[ERROR]   (%s:%d)" fmtstr "\n", __FILE__, __LINE__, ##__VA_ARGS__ )
#else
#define dbg_log_error( fmtstr, ... )
#endif

#if DEBUG_LEVEL >= 2
#define dbg_log_warning( fmtstr, ... ) debug( "[WARNING] (%s:%d)" fmtstr "\n", __FILE__, __LINE__, ##__VA_ARGS__ )
#else
#define dbg_log_warning( fmtstr, ... )
#endif

#if DEBUG_LEVEL >= 3
#define dbg_log_info( fmtstr, ... )    debug( "[INFO]    (%s:%d)" fmtstr "\n", __FILE__, __LINE__, ##__VA_ARGS__ )
#else
#define dbg_log_info( fmtstr, ... )
#endif

/*
  This function is used as a base function for debug output. Should not be used directly by
  the applications. Macroses should be used instead.
*/
void debug( const char * fmtstr, ... );

#endif // _DGB_LOG_H_
