#include<Sfml\Graphics.hpp>
using namespace sf;
View view1;


View cordinate1(float x,float y)
{
	float a=x,b=y;
	if(x<320)a=320;
	if(x>928)a=928;
	if(y<176)b=176;
	if(y>688)b=688;

	view1.setCenter(a,b);
	return view1;
}
