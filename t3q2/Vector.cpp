#include "Vector.h"



Vector::Vector()
{
	//putting 10 max size as requierd
	data = new int[10];
	capacity = 10;
	size = 0;
}

Vector::Vector(int mCapacity)
{
	//putting mCapacity max size as requierd
	data = new int[mCapacity];
	capacity = mCapacity;
	size = 0;
}

Vector::Vector(const Vector& vec)
{
	size = vec.size;
	capacity = vec.capacity;
	data = new int[capacity];
	for (int i = 0; i < size; i++)
	{
		data[i] = vec.data[i];
	}
}


Vector::~Vector()
{
	delete[] this->data;
}

int Vector::getCapacity()
{
	return capacity;
}

int Vector::getSize()
{
	return size;
}

void Vector::print()
{
	//check if there is data
	if (capacity == 0)
	{
		cout << "Error" << endl;
		return;
	}
	//printing as reqiered
	cout << "capacity: " << capacity << " size: "<<size<< " val:";
	for (int i = 0; i < size; i++)
	{
		cout << " " << data[i];
	}
	cout << endl;
}

Vector& Vector::operator=(const Vector& vec)//allocating new size if the capcacity is smallaer
{
	delete[] data;
	size = vec.size;
	capacity = vec.capacity;
	data = new int[capacity];
	for (int i = 0; i < size; i++)
	{
		data[i] = vec.data[i];
	}
	return *this;
}

bool Vector::operator==(const Vector vec)
{
	if (vec.size == size)
	{
		for (int i = 0; i < vec.size; i++) {
			if (vec[0] != data[0])
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

int Vector::operator[](int idx) const
{
	return data[idx];
}

int& Vector::operator[](int idx)
{
	return data[idx];
}

int Vector::operator*(const Vector vec)
{
	if (size != vec.size)
	{
		throw "Error\n";
	}
	int sum = 0;
	for (int i = 0; i < size; i++)
		sum += vec[i] * data[i];
	return sum;
}

Vector Vector::operator+(const Vector vec) const
{
	int const newCapacity = capacity + vec.capacity;
	Vector tempVec(newCapacity);
	if ((size + vec.size) <= capacity)
	{
		int* temp = new int[newCapacity];
		int i = 0;
		while (i < size)
		{
			temp[i] = data[i];
			i++;
		}
		int j = 0;
		while (i<(size+vec.size))
		{
			temp[i] = vec[j];
			j++;
			i++;
		}
		tempVec.data = temp;
		tempVec.capacity= capacity + vec.capacity;
		tempVec.size = size + vec.size;
		return tempVec;
	}
	else
	{
		cout<< "Error\n";
		return *this;
	}
}

void Vector::clear()
{
	for (int i = 0; i < size; i++)
	{
		data[i] = 0;
	}
	size = 0;
}

void Vector::delLast()
{
	//empty
	if (size == 0) {
		cout << "Error\n";
		return;
	}
	else
	{
		data[size] = 0;
		size--;
	}
}

void Vector::insert(int num)
{
	//full
	if (size == capacity) {
		cout<< "Error\n";
		return;
	}
	else
	{
		data[size] = num;
		size++;
	}
}
