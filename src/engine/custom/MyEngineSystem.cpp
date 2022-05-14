#ifndef __MY_ENGINE_H__
#define __MY_ENGINE_H__

#include <SDL_mixer.h>

#include "../EngineCommon.h"

class MyEngineSystem {
	friend class XCube2Engine;
	private:
		int sound(int argc, char** argv);

	public:
};
#endif
