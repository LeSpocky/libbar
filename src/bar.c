/*******************************************************************//**
 *	@file	bar.c
 *
 *	bar library implementation
 *
 *	@author	Alexander Dahl <post@lespocky.de>
 *	@date	Created: 2012-03-06
 **********************************************************************/

#include "bar.h"

#include <stdio.h>

#include "foo.h"

void bar_hello( void ) {
	(void) puts( "This is bar library speaking." );
}

void bar_call_foo( void ) {
	(void) puts( "Next line comes from foo library:" );
	foo_hello();
}

/* vim: set noet sts=0 ts=4 sw=4 sr: */
