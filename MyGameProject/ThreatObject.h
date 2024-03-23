
#ifndef THREAT_OBJECT_H
#define THREAT_OBJECT_H

#include "BaseObject.h"
#define ThreatWidth  200 // 200
#define ThreatHeight 131 // 131

using namespace std;


class ThreatObject : public BaseObject
{
public:

	int x_Threat;
	int y_Threat;

	ThreatObject();
	~ThreatObject();

	void moveControl();

private:

	int v;
};

#endif
