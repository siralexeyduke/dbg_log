/**
  * @file    dbg_log_platform.h
  * @author  Alexey Serdyuk
  * @version V0.0.1
  * @date    23-March-2016
  * @brief   Debug log platform interface
  *          
  *          This header represents interface to platform function for outputting 
  *          debug log strings.
  */
#ifndef _DBG_LOG_PLATFORM_H_
#define _DBG_LOG_PLATFORM_H_

#include <string.h>

/*
 * This function is used for output preformatted string to the
 * platform dependent device ( e.g. UART, Flash, ... ).
 */
void dbg_log_platform_write( char * dbg_str, int size );

#endif // _DBG_LOG_PLATFORM_H_
