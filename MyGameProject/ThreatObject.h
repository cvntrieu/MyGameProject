
#ifndef THREAT_OBJECT_H
#define THREAT_OBJECT_H

#include "BaseObject.h"


using namespace std;


class ThreatObject : public BaseObject
{
public:

	Mix_Chunk* threatAppearance;

	void initThreat(SDL_Renderer* renderer);
	~ThreatObject();

	void moveControl();

private:

	int v;
};

#endif
