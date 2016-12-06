#include "Wiimote.h"
#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>


using namespace std;

//Constructor
Wiimote::Wiimote()
{
	// Open Wiimote event file
 	fd = open("/dev/input/event0", O_RDONLY);
 	if (fd == -1)
 	{
 		cerr << "Error: Could not open event file - forgot sudo?\n";
 		exit(1);
	} 
}
//Destructor
Wiimote::~Wiimote()
{
	close(fd);
}
void Wiimote::Listen()
{
	cout << "Let's listen\n";
	while (true)
 	{	

		// Read a packet of 32 bytes from Wiimote
		char buffer[32];
		read(fd, buffer, 32);
 		// Extract code (byte 10) and value (byte 12) from packet
 		int code = buffer[10];
		short acceleration = * (short *) (buffer + 12);
		// Print them
		this->AccelerationEvent(code, acceleration);
		usleep(10000); 
 	} 

}

//Button Event handler
void Wiimote::ButtonEvent(int code, int value)
{
	cout << "Code = " << code << ", value = " << value << '\n'; 
}

//Acceleration Event handler
void Wiimote::AccelerationEvent(int code, short acceleration)
{
	cout<<"Code = "<<code<<", acceleration = "<<acceleration<<"\n";
}
