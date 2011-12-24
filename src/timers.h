// Copyright (c) 2011 Zeex
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef SAMPGDK_TIMERS_H
#define SAMPGDK_TIMERS_H

#include <sampgdk/config.h>
#include <sampgdk/samp.h>

#include <set>

class Timer {
public:
	Timer(int interval, bool repeat, TimerHandler hander, void *param);
	~Timer();

	int GetInterval() const 
		{ return interval_; }
	bool IsRepeating() const 
		{ return repeating_; }
	int GetStartTime() const 
		{ return startTime_; }
	bool IsAlive() const
		{ return isAlive_; }

	void Fire(int elapsedTime);

	static int GetTime();

private:
	int interval_;
	bool repeating_;
	TimerHandler handler_;
	void *param_;
	int startTime_;
	bool isAlive_;
};

class Timers {
public:
	static void CreateTimer(Timer *timer);
	static void DestroyTimer(Timer *timer);

	static void ProcessTimers();

private:
	static std::set<Timer*> timers_;
};

#endif // SAMPGDK_TIMERS_H
