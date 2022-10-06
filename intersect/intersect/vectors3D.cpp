#include "vectors3D.h"


bool Segment3D::Intersect(const Segment3D &s2, Vector3D &point) const
{
	double distance = getDistance(s2); //distance between skew lines
	if (distance == 0.0) { // lines are on the same plane
		Vector3D e = end - start;
		Vector3D f = s2.end - s2.start;
		Vector3D g = s2.end - end;
		Vector3D cross_fg = f^g;
		Vector3D cross_fe = f^e;
		double cross_fg_len = cross_fg.lenght();
		double cross_fe_len = cross_fe.lenght();
		if ( cross_fe_len == 0.0) {//parallel or belong to the same line
			//check if belong to the same line
			double g_lenght = g.lenght();
			if (cross_fg_len == 0.0) {
				std::cout << "Segments belong to the same line.\n";
				bool inter = this->IntersectSegmentsOnOneLine(s2);
				if (!inter)
					inter = s2.IntersectSegmentsOnOneLine(*this);
				if (!inter)
					std::cout << "There is no point of intersection.\n\n";
				
				return false;
			}
			std::cout << "Segments are parallel.\n";
			std::cout << "There is no point of intersection.\n\n";
			return false;
		}
		cross_fg = cross_fg / cross_fg_len;
		cross_fe = cross_fe / cross_fe_len;
		int direction = -1;
		if (cross_fg == cross_fe) // same direction
			direction *= -1;
		
		double s = direction * cross_fg_len / cross_fe_len;
		point = end + (e * s);

		bool is_in_s1 = this->isInsideSegment(point);
		bool is_in_s2 = s2.isInsideSegment(point);
		if (is_in_s1 && is_in_s2)
			return true;
		else {
			std::cout << "Point is outside of segments.\n";
			std::cout << "There is no point of intersection.\n\n";
			return false;
		}
	}
	else
	{
		std::cout << "Segments lie in different planes.\n";
		std::cout << "There is no point of intersection.\n\n";
		return false;
	}
}


double Segment3D::getDistance(const Segment3D& s2) const
{
	Vector3D e1 = end - start;
	Vector3D e2 = s2.end - s2.start;
	Vector3D e3 = e1^e2;
	double lenght_e3 = e3.lenght();
	if (lenght_e3 == 0) return 0;
	e3 = e3 / lenght_e3;
	Vector3D d = start - s2.start;
	return fabs(d*e3);
}

void Segment3D::printIntersSegment(const Vector3D& start, const Vector3D& end) const
{
	if (!(start == end)) {
		std::cout << "Intersect segment:\n";
		std::cout << "Start: " << start << '\n';
		std::cout << "End: " << end << "\n\n";
	}
	else
		std::cout << "Point of intersection is: " << start << "\n\n";
	
}

bool Segment3D::isInsideSegment(const Vector3D& p) const
{
	//is point between start and end of segment
	Vector3D c = this->start - p;
	Vector3D d = this->end - p;
	double dot_cd = c * d;
	if (dot_cd <= 0)
		return true;
	else
		return false;
}

int Segment3D::IntersectSegmentsOnOneLine(const Segment3D& s2) const
{
	
	bool start_is_in_s1 = this->isInsideSegment(s2.start);
	bool end_is_in_s1 = this->isInsideSegment(s2.end);
	if (start_is_in_s1) {
		if (end_is_in_s1)
		{
			std::cout << "Intersect segment:\n" << s2 << '\n';
			return 1;

		}
		else {
			bool near_end = this->PositionOfPoint(s2.end);
			if (near_end)
			{
				printIntersSegment(s2.start, this->end);
				return 1;
			}
			else
			{
				printIntersSegment(this->start, s2.start);
				return 1;
			}
		}

	}
	else
	{
		if (end_is_in_s1)
		{
			bool near_end = this->PositionOfPoint(s2.start);
			if (near_end)
			{
				printIntersSegment(s2.end, this->end);
				return 1;
			}
			else
			{
				printIntersSegment(this->start, s2.end);
				return 1;
			}
		}
		else {
			return 0;
		}
	}
	return 0;
}

bool Segment3D::PositionOfPoint(const Vector3D& p) const
{
	Vector3D s = this->end - this->start;
	Vector3D e = p - this->start;

	if (s*e >= 0)
		return 1; //point is near the end outside of segment
	else
		return 0; //point is near the start outside of segment
}


Vector3D Vector3D::operator^(const Vector3D& b) const
{
	Vector3D a;
	a.X = Y * b.Z - Z * b.Y;
	a.Y = Z * b.X - X * b.Z;
	a.Z = X * b.Y - Y * b.X;
	return a;
}

double Vector3D::operator*(const Vector3D& b) const
{
	return X * b.X + Y * b.Y + Z * b.Z;
}

Vector3D Vector3D::operator-(const Vector3D& b) const
{
	Vector3D a;
	a.X = X - b.X;
	a.Y = Y - b.Y;
	a.Z = Z - b.Z;
	return a;
}

Vector3D Vector3D::operator+(const Vector3D& b) const
{
	Vector3D a;
	a.X = X + b.X;
	a.Y = Y + b.Y;
	a.Z = Z + b.Z;
	return a;
}

Vector3D Vector3D::operator*(double a) const
{
	Vector3D v;
	v.X = X * a;
	v.Y = Y * a;
	v.Z = Z * a;
	return v;
}

Vector3D Vector3D::operator/(double a) const
{
	Vector3D v;
	v.X = X / a;
	v.Y = Y / a;
	v.Z = Z / a;
	return v;
}

bool Vector3D::operator==(const Vector3D& a) const
{
	if (X == a.X && Y == a.Y && Z == a.Z)
		return true;
	else
		return false;
	
}

double Vector3D::lenght() const
{
	return sqrt(X * X + Y * Y + Z * Z);
}

std::ostream& operator<<(std::ostream& os, const Vector3D& V) 
{
	os << "[" << V.X << " " << V.Y << " " << V.Z << "]";
	return os;
}

std::ostream& operator<<(std::ostream& os, const Segment3D& s)
{
	os << "Start: " << s.start << "\n";
	os << "End: " << s.end << "\n";
	return os;
}
