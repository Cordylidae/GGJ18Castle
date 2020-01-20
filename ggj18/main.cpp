#include<SFML\Graphics.hpp>
#include<SFML\Audio.hpp>
#include"flover1.h"
#include"flover2.h"
#include"boss.h"
#include"view.h"
#include <sstream>
using namespace sf;
using namespace std;
//level1
int bochn,bag[4]={0};
bool ggg=true,zakruto1=true,zakruto2=true,vol=false;
enum State
{
	Menu,level1,level2,level3,victory,boss,bonus
};

String  math(RenderWindow &window){
Font font; 
font.loadFromFile("brushshopregular.otf");
Text text("", font, 20);
text.setColor(Color::Black);
string s,s1,s2;
int c;
int b=rand()%10000+1;
int a=rand()%10000+1;
int d=rand()%3;
s1="( ";
s2=" )%9+1";
switch(d)
{
case 0:
	{
		s="+";
		c=(a+b)%9+1;
	ostringstream a_,b_;
		        a_ << a;
				b_<< b;
				text.setString(s1+a_.str()+s+b_.str()+s2);
	}
break;

case 1:
	{
		s="-";
		c=abs((a-b))%9+1;
	ostringstream a_,b_;
		        a_ << a;
				b_<< b;
				text.setString(s1+"|"+a_.str()+s+b_.str()+"|"+s2);
	}
break;

case 2:
	{
		{
		s="*";
		c=(a*b)%9+1;
	ostringstream a_,b_;
		        a_ << a;
				b_<< b;
				text.setString(s1+a_.str()+s+b_.str()+s2);
	}
	}
break;}
bochn=c;
return text.getString();
}

int kk=1,kg=1;
bool pergf=false,l1f=false,b1f=false,re1f=false,s1f=false;
State state=Menu;
bool cherry=false,flour=false,plate=false,sugar=false;

class Player {
private: float x, y;
		 int a,b;
public:
	float dx, dy, speed;
	int dir;
	String File;
	Image image;
	Texture texture;
	Sprite sprite;
	Player(float X, float Y)
	{
        dx=0; dy=0; speed=0; dir =0;
		image.loadFromFile("player.png");
		texture.loadFromImage(image);
		sprite.setTexture(texture);
		x = X; y = Y;
		sprite.setTextureRect(IntRect(32, 0, 32, 32));
	}
	void update(float time)
	{
		a=31;b=31;
		if(dir==0)
		{
			dx = speed;
			dy = 0;
			b=32;
		}
		if(dir==1)
		{
			dx = -speed;
			dy = 0;
		} 
		if(dir==2)
		{
			dx = 0;
			dy = speed;
			a=32;
		} 
		if(dir==3)
		{
			dx = 0;
			dy = -speed;
		}
		
 x += dx*time;
 y += dy*time;
		
		
 
		speed = 0;
		sprite.setPosition(x,y);
		interactionWithMap();
	}
	void interactionWithMap()
	{

		for (int i = y / 32; i < (y + a) / 32; i++)
			for (int j = x / 32; j<(x + b) / 32; j++)
			{
				switch(state)
				{
				case level1:
					{
						if ((TileMap[i][j] != ' ' && TileMap[i][j] != 'j' && TileMap[i][j] != 'k' && TileMap[i][j] != '0'))
						{
								if (dy>0 && i<(y+32)/32)
							{
								y = i * 32 - 32;
							}
							if (dy<0)
							{
								y = i * 32 + 32;
							}
							if (dx>0)
							{
								x = j * 32 - 32;
							}
							if (dx < 0)
							{
								x = j * 32 + 32;
							}
						}
					}
					break;
				case level2:
					{
						if ((TileMap2[i][j] != ' ' && TileMap2[i][j] != 'j' && TileMap2[i][j] != 'k' && TileMap2[i][j] != '0'))
						{
								if (dy>0 && i<(y+32)/32)
							{
								y = i * 32 - 32;
							}
							if (dy<0)
							{
								y = i * 32 + 32;
							}
							if (dx>0)
							{
								x = j * 32 - 32;
							}
							if (dx < 0)
							{
								x = j * 32 + 32;
							}
						}
					}
					break;
					case boss:
					{
						if ((TileMap3[i][j] != ' '))
						{
								if (dy>0 && i<(y+32)/32)
							{
								y = i * 32 - 32;
							}
							if (dy<0)
							{
								y = i * 32 + 32;
							}
							if (dx>0)
							{
								x = j * 32 - 32;
							}
							if (dx < 0)
							{
								x = j * 32 + 32;
							}
						}
					}
					break;
				}
				
				
			}
	}
    float getPlayerCoordinateX()
	{	
		return x;
	}
	float getPlayerCoordinateY()
	{	
		return y;
	}
	void setPlayerCoordinateX(float a)
	{	
		 x=a;
	}
	void setPlayerCoordinateY(float b)
	{	
		y=b;
	}
};

int main()
{

	srand(time(0));

Music music;
	music.openFromFile("music.ogg");
	music.setLoop(true);

	//47 136 166 40
	//47 204 166 40

Font font; 
font.loadFromFile("brushshopregular.otf");
Text text("", font, 20);
text.setColor(Color::Black);

Player shape(5*32,4*32);
shape.sprite.setPosition(5*32,4*32);


	RenderWindow window(VideoMode(640,352),"Castle");
	view1.reset(FloatRect(35*32,32 , 640, 352));

	
	Texture m1;
	m1.loadFromFile("menu.png");
	Sprite menu;
	menu.setTexture(m1);

	
	Texture t1;
	t1.loadFromFile("bochka.png");
	Sprite bochka;
	bochka.setTexture(t1);

	Texture t2;
	t2.loadFromFile("pol1.png");
	Sprite l1;
	l1.setTexture(t2);

	Texture t22;
	t22.loadFromFile("pol2.png");
	Sprite l2;
	l2.setTexture(t22);

	Texture t21;
	t21.loadFromFile("gold1.png");
	Sprite g2;
	g2.setTexture(t21);

	Texture t3;
	t3.loadFromFile("door.png");
	Sprite door;
	door.setTexture(t3);

	Texture t4;
	t4.loadFromFile("window1.png");
	Sprite window1;
	window1.setTexture(t4);

	Texture t42;
	t42.loadFromFile("window2.png");
	Sprite window2;
	window2.setTexture(t42);


	Texture t5;
	t5.loadFromFile("table1.png");
	Sprite table1;
	table1.setTexture(t5);

	Texture t6;
	t6.loadFromFile("inter1.png");
	Sprite inter1;
	inter1.setTexture(t6);

	Texture t7;
	t7.loadFromFile("mech.png");
	Sprite mech;
	mech.setTexture(t7);
	mech.setPosition(32,32*10);

	Texture t8;
	t8.loadFromFile("box.png");
	Sprite box;
	box.setTexture(t8);
	box.setPosition(32*12,32*5);

	Texture t9;
	t9.loadFromFile("menug.png");
	Sprite menug;
	menug.setTexture(t9);
	menug.setPosition(0,0);

	Texture t10;
	t10.loadFromFile("bygay.png");
	Sprite bygay;
	bygay.setTexture(t10);
	
	Texture t11;
	t11.loadFromFile("kitchen.png");
	Sprite kitchen;
	kitchen.setTexture(t11);
	
	Texture t12;
	t12.loadFromFile("stols.png");
	Sprite stols;
	stols.setTexture(t12);
	
	Texture t13;
	t13.loadFromFile("fruit1.png");
	Sprite fruit1;
	fruit1.setTexture(t13);
	
	Texture t132;
	t132.loadFromFile("fruit2.png");
	Sprite fruit2;
	fruit2.setTexture(t132);

	Texture t14;
	t14.loadFromFile("meshok.png");
	Sprite meshok;
	meshok.setTexture(t14);

	Texture t15;
	t15.loadFromFile("trees.png");
	Sprite tree;
	tree.setTexture(t15);

	Texture t16;
	t16.loadFromFile("xyz.png");
	Sprite xyz;
	xyz.setTexture(t16);

	Texture t17;
	t17.loadFromFile("key1.png");
	Sprite key1;
	key1.setTexture(t17);
	key1.setPosition(40,20);

	Texture q1;
	q1.loadFromFile("q.png");
	Sprite q;
	q.setTexture(q1);
	q.setPosition(360,8);

	Texture tl1;
	tl1.loadFromFile("perg.png");
	Sprite perg;
	perg.setTexture(tl1);
	perg.setPosition(100,50);

	Texture tl2;
	tl2.loadFromFile("l1.png");
	Sprite ll1;
	ll1.setTexture(tl2);
	ll1.setPosition(100,50);

	Texture tl3;
	tl3.loadFromFile("l2.png");
	Sprite ll2;
	ll2.setTexture(tl3);
	ll2.setPosition(100,50);

	Texture tl4;
	tl4.loadFromFile("re2.png");
	Sprite re2;
	re2.setTexture(tl4);
	re2.setPosition(100,50);

	Texture tl5;
	tl5.loadFromFile("last.png");
	Sprite last;
	last.setTexture(tl5);
	last.setPosition(100,50);

	Texture u1;
	u1.loadFromFile("drago.png");
	Sprite drago;
	drago.setTexture(u1);
	drago.setPosition(36*32,32);

	Texture u2;
	u2.loadFromFile("2.png");
	Sprite prins;
	prins.setTexture(u2);
	prins.setPosition(36*32,32);

	Texture j1;
	j1.loadFromFile("Ps.png");
	Sprite Ps;
	Ps.setTexture(j1);
	Ps.setPosition(0,0);

	Texture df1;
	df1.loadFromFile("pie.png");
	Sprite pie;
	pie.setTexture(df1);

	Texture ta2;
	ta2.loadFromFile("table3.png");
	Sprite table3;
	table3.setTexture(ta2);
	table3.setPosition(18*32,5*32);

	
	Texture v2;
	v2.loadFromFile("volume.png");
	Sprite volume;
	volume.setTexture(v2);
	volume.setPosition(523-64,8);

	    float CurrentFrame = 0;
    Clock clock;

	while(window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 800;


		 Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
			{
                window.close();
			}
        }
		CurrentFrame += 0.005 * time;
					if (CurrentFrame > 3)CurrentFrame -= 3;

		Vector2i pozition1 = Mouse :: getPosition(window);

		switch(state)
		{		
		case Menu:
			{
				
			window.clear();
			if(pozition1.x>=47 && pozition1.x<=47+166 && pozition1.y>=136 && pozition1.y<=136+47 && Mouse::isButtonPressed(Mouse::Left))state=level1;
			if(pozition1.x>=47 && pozition1.x<=47+166 && pozition1.y>=204 && pozition1.y<=204+47 && Mouse::isButtonPressed(Mouse::Left))window.close();
			//window.setView(window.getDefaultView());
			menu.setPosition(0,0);	
			window.draw(menu);
				window.display();
			}
			break;
		case level1:
			{		
				//523 17 103 30
				if(pozition1.x>=523 && pozition1.x<=523+103 && pozition1.y>=17 && pozition1.y<=17+30 && Mouse::isButtonPressed(Mouse::Left))state=Menu;
				if(kk==1 && shape.sprite.getPosition().x<=64+48 && shape.sprite.getPosition().x>=64+16 && shape.sprite.getPosition().y<=32*5+16 && shape.sprite.getPosition().y>=32*3+16 && (Keyboard::isKeyPressed(Keyboard::Q)))
				{
					pergf=true;kk=2;
				}
				if(kk==2 && shape.sprite.getPosition().x<=15*32+68 && shape.sprite.getPosition().x>=14*32+4 && shape.sprite.getPosition().y<=9*32+32 && shape.sprite.getPosition().y>=9*32 && (Keyboard::isKeyPressed(Keyboard::Q)))
				{
					l1f=true;kk=3;
				}
				if(bag[0]==1 && kk==4 && shape.sprite.getGlobalBounds().intersects(door.getGlobalBounds()) && Keyboard::isKeyPressed(Keyboard::Q))
				{
					kk=5;
					bag[0]=0;
					zakruto1=false;
				}
				if(!zakruto1 && shape.sprite.getGlobalBounds().intersects(door.getGlobalBounds()) && Keyboard::isKeyPressed(Keyboard::Q))
				{
					state=level2;
				}

					if (Keyboard::isKeyPressed(Keyboard::D) && shape.sprite.getPosition().x<592 )
				{ 
					shape.dir = 0; shape.speed = 0.1;
					shape.sprite.setTextureRect(IntRect(32 * int(CurrentFrame), 64, 32, 32));
					shape.update(time);
				}   
                       
            
				if (Keyboard::isKeyPressed(Keyboard::A) && shape.sprite.getPosition().x>16)
				{
					shape.dir = 1; shape.speed = 0.1;
					shape.sprite.setTextureRect(IntRect(32 * int(CurrentFrame), 32, 32, 32));
					shape.update(time);
				}
            

			    if (Keyboard::isKeyPressed(Keyboard::W) && shape.sprite.getPosition().y>96)
				{
					shape.dir = 3; shape.speed = 0.1;
					shape.sprite.setTextureRect(IntRect(32 * int(CurrentFrame), 96, 32, 32));
					shape.update(time);
				}

				if (Keyboard::isKeyPressed(Keyboard::S) && shape.sprite.getPosition().y<=304) 
				{
					shape.dir = 2; shape.speed = 0.1;
					shape.sprite.setTextureRect(IntRect(32 * int(CurrentFrame), 0, 32, 32));
					shape.update(time);
				}
			window.clear();

			for (int i = 0;i<HEIGHT_MAP;i++)
				    for (int j = 0;j<WIDTH_MAP;j++)
					{
						if (TileMap[i][j] == ' ' || TileMap[i][j] == '*') {l1.setTextureRect(IntRect(96,0,32,32));l1.setPosition(j * 32, i * 32);window.draw(l1);}
						if (TileMap[i][j] == '0') {l1.setTextureRect(IntRect(0,0,32,32));l1.setPosition(j * 32, i * 32);window.draw(l1); }
						if (TileMap[i][j] == 'j') {l1.setTextureRect(IntRect(32,0,32,32));l1.setPosition(j * 32, i * 32);window.draw(l1); }
						if (TileMap[i][j] == 'k') {l1.setTextureRect(IntRect(64,0,32,32));l1.setPosition(j * 32, i * 32);window.draw(l1); }
					}
			window1.setPosition(3*32,2*32);
			window.draw(window1);

			if(kk==1){
			xyz.setPosition(4*32,2*32);
			window.draw(xyz);
			}

			door.setTextureRect(IntRect(92,0,46,62));
			door.setPosition(15*32,2*32+2);
			window.draw(door);

			if(zakruto1){
			door.setTextureRect(IntRect(0,0,46,62));
			door.setPosition(5*32,2*32+2);
			window.draw(door);
			}
			if(!zakruto1){
			door.setTextureRect(IntRect(46,0,46,62));
			door.setPosition(5*32,2*32+2);
			window.draw(door);
			}

			inter1.setTextureRect(IntRect(0,0,26,77));
			inter1.setPosition(0,5*32);
			window.draw(inter1);

			for(int i=0;i<2;i++)
			{
			inter1.setTextureRect(IntRect(26,0,30,43));
			inter1.setPosition(32+i*520,72);
			window.draw(inter1);
			}

			inter1.setTextureRect(IntRect(28,83,62,64));
			inter1.setPosition(9*32,32*2);
			window.draw(inter1);

			inter1.setTextureRect(IntRect(0,121,28,26));
			inter1.setPosition(11*32,32*3+4);
			window.draw(inter1);

			inter1.setTextureRect(IntRect(57,3,32,31));
			inter1.setPosition(8*32,32*3+4);
			window.draw(inter1);
			
			for(int i=0;i<2;i++)
			{
				box.setPosition(32*4+32*8*i,32*5+i*32);
			window.draw(box);
			}
			window.draw(shape.sprite);

			window.draw(mech);

			inter1.setTextureRect(IntRect(0,77,28,20));
			inter1.setPosition(3*32+16,32*10+8);
			window.draw(inter1);

			table1.setPosition(15*32+4,10*32);
			window.draw(table1);

			for(int i=0;i<9;i++)
			{
				bochka.setPosition(5*32+i*35,10*32 + 4);
				window.draw(bochka);
				if((i==bochn-1)&& shape.sprite.getGlobalBounds().intersects(bochka.getGlobalBounds()) && Keyboard::isKeyPressed(Keyboard::Q))
				{
					bag[0]=1;
					kk=4;
				}
			}

			window.draw(menug);

			if(!vol){volume.setTextureRect(IntRect(0,48,48,48));window.draw(volume);
			if(pozition1.x>=523-64 && pozition1.x<=523-64+48 && pozition1.y>=8 && pozition1.y<=8+48 && (Mouse::isButtonPressed(Mouse::Left)))
			{
				vol=true;
			music.play();}
			}
			
			if(vol){volume.setTextureRect(IntRect(0,0,48,48));window.draw(volume);
			if(pozition1.x>=523-64 && pozition1.x<=523-64+48 && pozition1.y>=8 && pozition1.y<=8+48 && (Mouse::isButtonPressed(Mouse::Right)))
			{
				vol=false;
			music.pause();}
			}


			if(bag[0]==1){window.draw(key1);}
			if(pergf){
			window.draw(perg);
			if(Keyboard::isKeyPressed(Keyboard::Escape))pergf=false;
			}
			if(l1f){
			window.draw(ll1);
			if(Keyboard::isKeyPressed(Keyboard::Escape))l1f=false;
			if(ggg){
				text.setString(math(window));
				ggg=false;
			}
			text.setPosition(150,160);
			window.draw(text);

			}


			if(kk==1 && shape.sprite.getPosition().x<=64+48 && shape.sprite.getPosition().x>=64+16 && shape.sprite.getPosition().y<=32*5+16 && shape.sprite.getPosition().y>=32*3+16)
			{
				window.draw(q);
			}
			if(kk==2 && shape.sprite.getPosition().x<=15*32+68 && shape.sprite.getPosition().x>=14*32+4 && shape.sprite.getPosition().y<=9*32+32 && shape.sprite.getPosition().y>=9*32)
			{
				window.draw(q);
			}
			if(kk==3 && shape.sprite.getPosition().x<=9*32+5*32 && shape.sprite.getPosition().x>=4*32 && shape.sprite.getPosition().y<=10*32+16 && shape.sprite.getPosition().y>=9*32+16)
			{
				window.draw(q);
			}
			if(bag[0]==1 && kk==4 && shape.sprite.getGlobalBounds().intersects(door.getGlobalBounds()))
			{
				window.draw(q);
			}
			
			window.display();
				}
			break;

		case level2:
		{
			if(pozition1.x>=523 && pozition1.x<=523+103 && pozition1.y>=17 && pozition1.y<=17+30 && Mouse::isButtonPressed(Mouse::Left))state=Menu;
			if(kg==1 && shape.sprite.getPosition().x<=19*32 && shape.sprite.getPosition().x>=16*32 && shape.sprite.getPosition().y<=128 && shape.sprite.getPosition().y>=64 && Keyboard::isKeyPressed(Keyboard::Q))
			{
				b1f=true;kg=2;
			}
			if(kg==2 && shape.sprite.getPosition().x<=19*32 && shape.sprite.getPosition().x>=18*32 && shape.sprite.getPosition().y<=192 && shape.sprite.getPosition().y>=160 && Keyboard::isKeyPressed(Keyboard::Q))
			{
				re1f=true;kg=3;
			}
			if(kg==3 && shape.sprite.getPosition().x<=8*32 && shape.sprite.getPosition().x>=7*32 && shape.sprite.getPosition().y<=5*32 && shape.sprite.getPosition().y>=4*32 && Keyboard::isKeyPressed(Keyboard::Q))
			{
				bag[0]=2;
			}
			if(kg==3 && shape.sprite.getPosition().x<=3*32 && shape.sprite.getPosition().x>=2*32 && shape.sprite.getPosition().y<=7*32 && shape.sprite.getPosition().y>=6*32 && Keyboard::isKeyPressed(Keyboard::Q))
			{
				bag[2]=2;
			}
			if(kg==3 && shape.sprite.getPosition().x<=4*32 && shape.sprite.getPosition().x>=2*32 && shape.sprite.getPosition().y<=4*32 && shape.sprite.getPosition().y>=3*32 && Keyboard::isKeyPressed(Keyboard::Q))
			{
				bag[1]=2;
			}
			if(kg==3 && shape.sprite.getPosition().x<=7*32 && shape.sprite.getPosition().x>=5*32 && shape.sprite.getPosition().y<=7*32 && shape.sprite.getPosition().y>=6*32 && Keyboard::isKeyPressed(Keyboard::Q))
			{
				bag[3]=2;
			}
			if(bag[0]==2 && bag[1]==2 && bag[2]==2 && bag[3]==2)
			{
				kg=4;zakruto2=false;
			}

			if (Keyboard::isKeyPressed(Keyboard::D) && shape.sprite.getPosition().x<592 )
				{ 
					shape.dir = 0; shape.speed = 0.1;
					shape.sprite.setTextureRect(IntRect(32 * int(CurrentFrame), 64, 32, 32));
					shape.update(time);
				}   
                       
            
				if (Keyboard::isKeyPressed(Keyboard::A) && shape.sprite.getPosition().x>16)
				{
					shape.dir = 1; shape.speed = 0.1;
					shape.sprite.setTextureRect(IntRect(32 * int(CurrentFrame), 32, 32, 32));
					shape.update(time);
				}
            

			    if (Keyboard::isKeyPressed(Keyboard::W) && shape.sprite.getPosition().y>96)
				{
					shape.dir = 3; shape.speed = 0.1;
					shape.sprite.setTextureRect(IntRect(32 * int(CurrentFrame), 96, 32, 32));
					shape.update(time);
				}

				if (Keyboard::isKeyPressed(Keyboard::S) && shape.sprite.getPosition().y<=304) 
				{
					shape.dir = 2; shape.speed = 0.1;
					shape.sprite.setTextureRect(IntRect(32 * int(CurrentFrame), 0, 32, 32));
					shape.update(time);
				}
			window.clear();

			for (int i = 0;i<HEIGHT_MAP2;i++)
				    for (int j = 0;j<WIDTH_MAP2;j++)
					{
						if (TileMap2[i][j] == ' ' || TileMap2[i][j] == '*') {l2.setTextureRect(IntRect(96,0,32,32));l2.setPosition(j * 32, i * 32);window.draw(l2);}
						if (TileMap2[i][j] == '0') {l2.setTextureRect(IntRect(0,0,32,32));l2.setPosition(j * 32, i * 32);window.draw(l2); }
						if (TileMap2[i][j] == 'j') {l2.setTextureRect(IntRect(32,0,32,32));l2.setPosition(j * 32, i * 32);window.draw(l2); }
						if (TileMap2[i][j] == 'k') {l2.setTextureRect(IntRect(64,0,32,32));l2.setPosition(j * 32, i * 32);window.draw(l2); }
					}
			window2.setPosition(17*32-16,3*32-16);
			window.draw(window2);

			door.setTextureRect(IntRect(92,0,46,62));
			door.setPosition(5*32,2*32+2);
			window.draw(door);
			
			if(zakruto2){
			door.setTextureRect(IntRect(0,0,46,62));
			door.setPosition(14*32,2*32+2);
			window.draw(door);

			bygay.setPosition(13*32+16,2*32);
			window.draw(bygay);
			}
			else
			{
			door.setTextureRect(IntRect(46,0,46,62));
			door.setPosition(14*32,2*32+2);
			window.draw(door);
			if(shape.sprite.getGlobalBounds().intersects(door.getGlobalBounds())){state=boss;
			shape.sprite.setPosition(0,26*32);
			shape.setPlayerCoordinateX(0);
			shape.setPlayerCoordinateY(26*32);
			}
			}
			kitchen.setTextureRect(IntRect(0,0,64,64));
			kitchen.setPosition(2*32,2*32);
			window.draw(kitchen);

			kitchen.setTextureRect(IntRect(64,0,257-64,64));
			kitchen.setPosition(7*32,2*32);
			window.draw(kitchen);

			fruit1.setPosition(96,32*5);
			window.draw(fruit1);
			
			fruit2.setPosition(12*32,32*5);
			window.draw(fruit2);

			meshok.setPosition(8*32,32*5);
			window.draw(meshok);

			stols.setPosition(6*32,7*32);
			window.draw(stols);

			window.draw(shape.sprite);

			tree.setTextureRect(IntRect(0,0,40,63));
			tree.setPosition(18*32+16,9*32);
			window.draw(tree);

			
			tree.setTextureRect(IntRect(40,0,29,63));
			tree.setPosition(0,9*32);
			window.draw(tree);

			window.draw(table3);

			window.draw(menug);

			if(!vol){volume.setTextureRect(IntRect(0,48,48,48));window.draw(volume);
			if(pozition1.x>=523-64 && pozition1.x<=523-64+48 && pozition1.y>=8 && pozition1.y<=8+48 && (Mouse::isButtonPressed(Mouse::Left)))
			{
				vol=true;
			music.play();}
			}
			
			if(vol){volume.setTextureRect(IntRect(0,0,48,48));window.draw(volume);
			if(pozition1.x>=523-64 && pozition1.x<=523-64+48 && pozition1.y>=8 && pozition1.y<=8+48 && (Mouse::isButtonPressed(Mouse::Right)))
			{
				vol=false;
			music.pause();}
			}

			if(kg==3){
			if(bag[0]==2)
			{
				pie.setTextureRect(IntRect(0,0,28,28));
				pie.setPosition(40,20);
				window.draw(pie);
			}
			if(bag[1]==2)
			{
				pie.setTextureRect(IntRect(28,0,24,26));
				pie.setPosition(98,20);
				window.draw(pie);
			}
			if(bag[2]==2)
			{
				
				pie.setTextureRect(IntRect(48,0,26,24));
				pie.setPosition(146,20);
				window.draw(pie);
			}
			if(bag[3]==2)
			{
				
				pie.setTextureRect(IntRect(76,4,15,19));
				pie.setPosition(214,20);
				window.draw(pie);
			}
			}
			if(b1f)
			{
				window.draw(ll2);
				if(Keyboard::isKeyPressed(Keyboard::Escape))
				{
					b1f=false;
				}
			}
			if(re1f)
			{
				window.draw(re2);
				if(Keyboard::isKeyPressed(Keyboard::Escape))
				{
					re1f=false;
				}
			}

			
			if(kg==1 && shape.sprite.getPosition().x<=19*32 && shape.sprite.getPosition().x>=16*32 && shape.sprite.getPosition().y<=128 && shape.sprite.getPosition().y>=64)
			{
				window.draw(q);
			}
			if(kg==2 && shape.sprite.getPosition().x<=19*32 && shape.sprite.getPosition().x>=18*32 && shape.sprite.getPosition().y<=192 && shape.sprite.getPosition().y>=160)
			{
				window.draw(q);
			}
			if(kg==3 && ((shape.sprite.getPosition().x<=8*32 && shape.sprite.getPosition().x>=7*32 && shape.sprite.getPosition().y<=5*32 && shape.sprite.getPosition().y>=4*32)
				|| (shape.sprite.getPosition().x<=3*32 && shape.sprite.getPosition().x>=2*32 && shape.sprite.getPosition().y<=7*32 && shape.sprite.getPosition().y>=6*32)
				|| (shape.sprite.getPosition().x<=4*32 && shape.sprite.getPosition().x>=2*32 && shape.sprite.getPosition().y<=4*32 && shape.sprite.getPosition().y>=3*32)
				|| (shape.sprite.getPosition().x<=7*32 && shape.sprite.getPosition().x>=5*32 && shape.sprite.getPosition().y<=7*32 && shape.sprite.getPosition().y>=6*32)
				))
			{window.draw(q);}
			window.display();
		}
		break;
		case boss:
		{
			cordinate1(shape.getPlayerCoordinateX(), shape.getPlayerCoordinateY());
            window.setView(view1);

			if (Keyboard::isKeyPressed(Keyboard::D) && shape.sprite.getPosition().x<32*39)
				{ 
					shape.dir = 0; shape.speed = 0.1;
					shape.sprite.setTextureRect(IntRect(32 * int(CurrentFrame), 64, 32, 32));
					shape.update(time);
				}   
                       
            
				if (Keyboard::isKeyPressed(Keyboard::A) && shape.sprite.getPosition().x>0)
				{
					shape.dir = 1; shape.speed = 0.1;
					shape.sprite.setTextureRect(IntRect(32 * int(CurrentFrame), 32, 32, 32));
					shape.update(time);
				}
            

			    if (Keyboard::isKeyPressed(Keyboard::W) && shape.sprite.getPosition().y>0)
				{
					shape.dir = 3; shape.speed = 0.1;
					shape.sprite.setTextureRect(IntRect(32 * int(CurrentFrame), 96, 32, 32));
					shape.update(time);
				}

				if (Keyboard::isKeyPressed(Keyboard::S) && shape.sprite.getPosition().y<32*26-16) 
				{
					shape.dir = 2; shape.speed = 0.1;
					shape.sprite.setTextureRect(IntRect(32 * int(CurrentFrame), 0, 32, 32));
					shape.update(time);
				}
			window.clear();
			for (int i = 0;i<HEIGHT_MAP3;i++)
				    for (int j = 0;j<WIDTH_MAP3;j++)
					{
						if (TileMap3[i][j] == ' ') {g2.setTextureRect(IntRect(0,0,32,32));g2.setPosition(j * 32, i * 32);window.draw(g2);}
						if (TileMap3[i][j] == 'P') {g2.setTextureRect(IntRect(96,0,32,32));g2.setPosition(j * 32, i * 32);window.draw(g2); }
						if (TileMap3[i][j] == 'L') {g2.setTextureRect(IntRect(32,0,32,32));g2.setPosition(j * 32, i * 32);window.draw(g2); }
						if (TileMap3[i][j] == 'Z') {g2.setTextureRect(IntRect(64,0,32,32));g2.setPosition(j * 32, i * 32);window.draw(g2); }
					}

			window.draw(prins);
			window.draw(shape.sprite);
			window.draw(drago);
			
			if(shape.sprite.getGlobalBounds().intersects(prins.getGlobalBounds())){state=victory;}

			window.display();
		}
		break;
		case victory:
		{
			window.clear();
			window.setView(window.getDefaultView());
				window.draw(Ps);
				window.display();
		}
		break;
		}
}
	return 0;
}