/*******************************************************************//**
 *	@file	bar.h
 *
 *	bar library header
 *
 *	@author	Alexander Dahl <post@lespocky.de>
 *	@date	Created: 2012-03-06
 **********************************************************************/

#ifndef _BAR_H_
#define _BAR_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 *	Just say hello from this lib!
 */
void bar_hello( void );

/**
 *	Call one function from foo library!
 */
void bar_call_foo( void );

#ifdef __cplusplus
}
#endif

#endif  /* _BAR_H_ */

/* vim: set noet sts=0 ts=4 sw=4 sr: */
