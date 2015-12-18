#ifndef __TIMER_H__
#define __TIMER_H__

#include "Globals.h"
#include "SDL\include\SDL.h"

class Timer
{
public:

	// Constructor
	Timer();

	void Start();
	void Stop();
	bool GetRun();

	Uint64 Read();
	Uint64 ReadTicks() const;

private:

	bool	running;
	Uint32	started_at;
	Uint32	stopped_at;
	static Uint64 frequency;
};

#endif //__TIMER_H__