#include "Interact.h"
extern bool g_test;
extern Console g_Console;
extern SGameChar  g_sChar;
extern bool g_abKeyPressed[K_COUNT];
int Activity_feed = 0;
extern char grid[80][26];
extern double g_dElapsedTime;
extern bool setText;
extern int key;
extern int map;
extern int clear;
<<<<<<< HEAD
=======
extern int activateclear;
extern double g_dBounceTime;

>>>>>>> 0c852ab1519c55b7fe7a09d1cf5d84ee538052bc

int checkinteract(int g_number)
{
	int height = 0;
	int width = 0;
	ifstream file;

	/*if (g_sCha.Key != 0)
	{
	g_sChar.Key--;
	txt[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] = ' ';
	}*/

	if (grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == 'P')
	{
		return 2;
	}

	if (grid[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == 'P')
	{
		return 2;
	}

	if (grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == 'P')
	{
		return 2;
	}

	if (grid[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == 'P')
	{
		return 2;
	}

	if (grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == 'D' && key == 0)
	{
		return 3;
	}

	if (grid[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == 'D' && key == 0)
	{
		return 3;
	}

	if (grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == 'D' && key == 0)
	{
		return 3;
	}

	if (grid[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == 'D' && key == 0)
	{
		return 3;
	}
	if (grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == (char)194)
	{
		return 6;
	}

	if (grid[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == (char)194)
	{
		return 6;
	}
<<<<<<< HEAD

	if (grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == (char)194)
	{
		return 6;
	}

	if (grid[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == (char)194)
	{
		return 6;
	}
=======
>>>>>>> 0c852ab1519c55b7fe7a09d1cf5d84ee538052bc

	if (grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == (char)194)
	{
		return 6;
	}

	if (grid[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == (char)194)
	{
		return 6;
	}
	if (grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == 'T')
	{
		if (clear == 1)
		{
			grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] = 't';
			clear = 0;
		}
		if (clear == 0)
		{
			clear = 1;
		}
		return 4;
	}

	if (grid[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == 'T')
	{
		if (clear == 1)
		{
			grid[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] = 't';
			clear = 0;
		}
		if (clear == 0)
		{
			clear = 1;
		}
		return 4;
	}

	if (grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == 'T')
	{
		if (clear == 1)
		{
			grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] = 't';
			clear = 0;
		}
		if (clear == 0)
		{
			clear = 1;
		}
		return 4;
	}

	if (grid[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == 'T')
	{
		if (clear == 1)
		{
			grid[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] = 't';
			clear = 0;
		}
		if (clear == 0)
		{
			clear = 1;
		}
		return 4;
	}
	
	if (grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == (char)241)
	{
		return 5;
	}

	if (grid[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == (char)241)
	{
		return 5;
	}

	if (grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == (char)241)
	{
		return 5;
	}

	if (grid[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == (char)241)
	{
		return 5;
	}
	if (grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y - 1] == (char)178)//up
	{
		return 1;
	}

	if (grid[g_sChar.m_cLocation.X - 1][g_sChar.m_cLocation.Y] == (char)178) //left
	{
		return 1;
	}

	if (grid[g_sChar.m_cLocation.X][g_sChar.m_cLocation.Y + 1] == (char)178)//down
	{
		return 1;
	}

	if (grid[g_sChar.m_cLocation.X + 1][g_sChar.m_cLocation.Y] == (char)178)//right
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int Interact(int checkobj)
{
	Activity_feed = checkobj;
	return 0;
}
void renderFeed()
{
	COORD c = g_Console.getConsoleSize();
	c.X = 0;
	c.Y = 21;
	string text;
	int textSize;
	double newTime = g_dElapsedTime + 3.0;

	if (Activity_feed == 1 && !setText)
	{
		text = "Curses! A wall blocks your way.";
		textSize = sizeof(text);

		g_Console.writeToBuffer(c, text, 0x02);
		

		if (g_dElapsedTime > newTime)
		{
			for (int i = 0; i < textSize; i++)
			{
				g_Console.writeToBuffer(c, " ");
				c.X++;
			}
		}
		setText = true;
	}

	if (Activity_feed == 2 && !setText)
	{
		text = "It's a pillar.";
		textSize = sizeof(text);
		double newTime = g_dElapsedTime + 1.0;

		g_Console.writeToBuffer(c, text, 0x02);

		if (g_dElapsedTime > newTime)
		{
			for (int i = 0; i < textSize; i++)
			{
				g_Console.writeToBuffer(c, " ");
				c.X++;
			}
		}
		setText = true;
	}

	if (Activity_feed == 3 && !setText)
	{
		text = "The door's locked.";
		textSize = sizeof(text);
		double newTime = g_dElapsedTime + 1.0;

		g_Console.writeToBuffer(c, text, 0x02);

		if (g_dElapsedTime > newTime)
		{
			for (int i = 0; i < textSize; i++)
			{
				g_Console.writeToBuffer(c, " ");
				c.X++;
			}
		}
		setText = true;
	}

	if (Activity_feed == 4)
	{
		switch (map)
		{
		case 1: text = "You found a chest! The chest contains a shimmering key.";
			break;
		case 3: text = "You found a chest! A key piece lies within.";
			break;
		case 4: text = "You found a chest! A key piece lies within.";
			break;
		case 6: text = "You found a chest! It contains a key piece.";
			break;
		case 8: text = "You found a chest! A key piece shines from within.";
			break;
		case 12: text = "You found a chest! A key piece lies within.";
			break;
		case 13: text = "You found a chest! The chest has a key piece.";
			break;
		default: text = " ";
		}
		g_Console.writeToBuffer(c, text, 0x02);
	}
	if (Activity_feed == 5)
	{
		switch (map)
		{
		case 1: text = "You can push boulders by walking up to them.";
			break;
<<<<<<< HEAD
		case 3: text = "Only one contain what you are looking for...";
=======
		case 3: text = "Only one contains what you are looking for...";
>>>>>>> 0c852ab1519c55b7fe7a09d1cf5d84ee538052bc
			break;
		case 7: text = "Not all endeavours are rewarded.";
			break;
		case 8: text = "The map must be symmetrical.";
			break;
		case 10: text = "Greed will only waste your time.";
			break;
		case 11: text = "Working hard will not always bear fruit.";
			break;
		default: text = " ";
		}
		g_Console.writeToBuffer(c, text, 0x02);
	}

	if (Activity_feed == 6)
	{
		text = "You found a chest! But the chest is empty....";
		g_Console.writeToBuffer(c, text, 0x02);
	}

}