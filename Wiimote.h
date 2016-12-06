#ifndef Wiimote_H
#define Wiimote_H


class Wiimote
{
protected:
	int fd;

public:
	Wiimote();
	~Wiimote();
	virtual void Listen();
	void ButtonEvent(int code, int value);
	virtual void AccelerationEvent(int code, short acceleration);
};

#endif
