/*
    SDL - Simple DirectMedia Layer
    Copyright (C) 1997-2009 Sam Lantinga

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

    Sam Lantinga
    slouken@libsdl.org
*/
#include "SDL_config.h"

/* An implementation of semaphores using mutexes and condition variables */

#include "SDL_timer.h"
#include "SDL_thread.h"
#include "SDL_systhread_c.h"

struct SDL_semaphore {
	volatile Uint8 state;
	volatile Uint32 time;
};

SDL_sem *SDL_CreateSemaphore(Uint32 initial_value)
{
	SDL_sem *sem;

	sem = (SDL_sem *)malloc(sizeof(*sem));
	if ( sem ) {
		sem->state = 0;
	} else {
		SDL_SetError("SDL_CreateSemaphore OutOfMemory");

	}
	return sem;
}

void SDL_DestroySemaphore(SDL_sem *sem)
{
	if ( sem ) {
		SDL_free(sem);
	}
}

int SDL_SemTryWait(SDL_sem *sem)
{
	sem->state=0;
	while (!(volatile Uint8)sem->state)
	{
      sys_delay(1);	
	}
	return 0;
}

int SDL_SemWaitTimeout(SDL_sem *sem, Uint32 timeout)
{
	sem->state=0;
	sem->time=sys_ticks()+timeout;
	while (!(volatile Uint8)sem->state && (volatile Uint32)sem->time < (sys_ticks()))
	{
      sys_delay(1);	
	}
	return 0;
}

int SDL_SemWait(SDL_sem *sem)
{
	return SDL_SemTryWait(sem);
}

Uint32 SDL_SemValue(SDL_sem *sem)
{
	return 0;
}

int SDL_SemPost(SDL_sem *sem)
{
	sem->state=1;
	return 0;
}



