/**
  * @file    dbg_log.c
  * @author  Alexey Serdyuk
  * @version V0.0.1
  * @date    23-March-2016
  * @brief   Debug log
  *          
  *          Lightweight implementation of debug logger for low scale embedded systems.
  *          In this implementation standard streams are not used, since they are 
  *          not efficient or even not available for microcontroller based platforms.
  */
#include "dbg_log.h"
#include "dbg_log_platform.h"

#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#if defined(__STRICT_ANSI__) && (defined(__STDC_VERSION__) && 199901L > __STDC_VERSION__)
#error "vsnprintf function is not supported in standards earlier than C99. Please use C99 or newer standard."
#endif

static char debug_string[DBG_STR_MAX];

void debug( const char * fmtstr, ... ){
	va_list vararg;
	int size;
	
	va_start(vararg, fmtstr);
#ifdef DEBUG_FLOAT_PRINT_SUPPORT
	size = vsnprintf(debug_string, DBG_STR_MAX, fmtstr, vararg);
#else
	size = _vsnprintf(debug_string, DBG_STR_MAX, fmtstr, vararg);
#endif
	va_end(vararg);
	
	// Check if string was truncated
	if(size >= DBG_STR_MAX){
		debug_string[DBG_STR_MAX-1] = '\n';
		size = DBG_STR_MAX;
	}
	
	// Print resulting string to platform defined device
	dbg_log_platform_write(debug_string, size);
}
