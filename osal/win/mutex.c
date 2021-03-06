/*
 * MIT License
 *
 * Copyright (c) 2017 Ingenia-CAT S.L.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "mutex.h"

#include <stdlib.h>

/*******************************************************************************
 * Public
 ******************************************************************************/

osal_mutex_t *osal_mutex_create()
{
	osal_mutex_t *mutex;

	mutex = malloc(sizeof(*mutex));
	if (!mutex)
		return NULL;

	InitializeCriticalSection(&mutex->m);

	return mutex;
}

void osal_mutex_destroy(osal_mutex_t *mutex)
{
	DeleteCriticalSection(&mutex->m);
	free(mutex);
}

void osal_mutex_lock(osal_mutex_t *mutex)
{
	EnterCriticalSection(&mutex->m);
}

void osal_mutex_unlock(osal_mutex_t *mutex)
{
	LeaveCriticalSection(&mutex->m);
}
