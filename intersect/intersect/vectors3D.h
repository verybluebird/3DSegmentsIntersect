#pragma once
#include <cmath>
#include <iostream>

class Vector3D
{
	double X;
	double Y;
	double Z;
public:
	friend std::ostream& operator<<(std::ostream& os, const Vector3D& V);
	Vector3D() { X = 0; Y = 0; Z = 0; }
	Vector3D(double x0, double y0, double z0) {	X = x0;	Y = y0;	Z = z0;}
	Vector3D(const Vector3D& v) {X = v.X;	Y = v.Y;	Z = v.Z;}
	Vector3D operator^(const Vector3D& b) const; //cross product
	double operator*(const Vector3D& b) const; //dot product
	Vector3D operator-(const Vector3D& b) const;
	Vector3D operator+(const Vector3D& b) const;
	Vector3D operator*(double a) const;
	Vector3D operator/(double a) const;
	bool operator==(const Vector3D& a) const;
	double lenght() const;


};

class Segment3D
{
	Vector3D start;
	Vector3D end;
public:
	friend std::ostream& operator<<(std::ostream& os, const Segment3D& s);
	Segment3D(Vector3D& _start, Vector3D& _end) : start(_start), end(_end) {};
	bool Intersect(const Segment3D &s2, Vector3D& point) const;
	double getDistance(const Segment3D& s2) const;
	void printIntersSegment(const Vector3D& start, const Vector3D& end) const; //print intersect segment on 1 line
	bool isInsideSegment(const Vector3D& p) const;
	int IntersectSegmentsOnOneLine(const Segment3D& s2) const;
	bool PositionOfPoint(const Vector3D& p) const;
	
};
