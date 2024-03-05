
#ifndef THREAT_OBJECT_H
#define THREAT_OBJECT_H

#include "BaseObject.h"
#define ThreatWidth  200
#define ThreatHeight 131

using namespace std;


class ThreatObject : public BaseObject
{
public:

	ThreatObject();
	~ThreatObject();


	void moveControl(const double xBorder, const double yBorder);
	void HandleInputAction(SDL_Event &e);

	void setX(double& val);
	void setY(double& val);
	double getX() const;
	double getY() const;
};

#endif
