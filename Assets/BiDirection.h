#pragma once
#include "Float.h"


class BiDirection
{
public:
	BiDirection(const BiDirection& d) //copy constractor
	{
		dir = d.dir;
	}

	BiDirection() //default constractor
	{
		dir = Invalid;
	}

	static BiDirection MakeRight()
	{
		BiDirection d;
		d.SetRight();
		return d;
	}
					   
	static BiDirection MakeLeft()
	{
		BiDirection d;
		d.SetLeft();
		return d;
	}

	void SetLeft()
	{
		dir = Left;
	}

	void SetRight()
	{
		dir = Right;
	}

	bool IsLeft() const
	{
		return dir == Left;
	}
	
	bool IsRight() const
	{
		return dir == Right;
	}

	bool IsValid() const
	{
		return dir != Invalid;
	}

	bool operator ==(const BiDirection& rhs) //Overload operator, rhs is Right Hand Side
	{
		return dir == rhs.dir;
	}

	bool operator !=(const BiDirection& rhs) const //Overload operator, rhs is Right Hand Side
	{
		return dir != rhs.dir;
	}

	BiDirection& operator =(const BiDirection& rhs) 
	{
		dir = rhs.dir;
		return *this;
	}

	BiDirection GetOpposite() const
	{
		BiDirection o;
		if (dir == Left)
		{
			o.SetRight();
		}
		else if (dir == Right)
		{
			o.SetLeft();
		}
		return o;
	}

	void Reverse()
	{
		if (dir == Left)
		{
			SetRight();
		}
		else if (dir == Right)
		{
		    SetLeft();
		}
	}
	float Transform(float val) const
	{
		if (dir == Left)
		{
			return val * -1.0f;
		}
		else if (dir == Right)
		{
			return val;
		}
		else //Invalid
		{
			return _FPCLASS_SNAN; // NaN
		}
	}

private:
	enum BiDir
	{
		Left,
		Right,
		Invalid
	}dir;
};