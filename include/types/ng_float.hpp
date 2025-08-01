#pragma once

class NG_Float {
private:
	float value;

public:
	NG_Float() : value(0.0f) {}
	NG_Float(float v) : value(v) {}

	operator float() const { return value; }

	NG_Float operator+(const NG_Float& other) const { return NG_Float(value + other.value); }
	NG_Float operator-(const NG_Float& other) const { return NG_Float(value - other.value); }
	NG_Float operator*(const NG_Float& other) const { return NG_Float(value * other.value); }
	NG_Float operator/(const NG_Float& other) const { return NG_Float(value / other.value); }

	NG_Float operator+=(const NG_Float& other) { value += other.value; return *this; }
	NG_Float operator-=(const NG_Float& other) { value -= other.value; return *this; }
	NG_Float operator*=(const NG_Float& other) { value *= other.value; return *this; }
	NG_Float operator/=(const NG_Float& other) { value /= other.value; return *this; }

	bool operator==(const NG_Float& other) const { return value == other.value; }
	bool operator!=(const NG_Float& other) const { return value != other.value; }
	bool operator>=(const NG_Float& other) const { return value >= other.value; }
	bool operator<=(const NG_Float& other) const { return value <= other.value; }
	bool operator>(const NG_Float& other) const { return value > other.value; }
	bool operator<(const NG_Float& other) const { return value < other.value; }

	float get() const { return value; }
};
