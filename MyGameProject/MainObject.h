

#include "BaseObject.h"
#define Width 100
#define Height 69

class MainObject : public BaseObject
{
public:
	
	MainObject();
	~MainObject();

	void HandleInputAction(SDL_Event& events);

	void Move();


	double x_val;
	double y_val;
};