
class Ring {
	float r;
	float R;
	float x;
	float y;

public:
	~Ring() {};
	Ring() : r(1), R(2), x(0), y(0) {};
	Ring(float new_r, float new_R, float new_x, float new_y);
	Ring(Ring& NewRing);
	float get_x() const;
	float get_y() const;
	float get_r() const;
	float get_R() const;
	float get_width() const;
	void set_values(float new_r, float new_R, float new_x, float new_y);
	void operator++();
	void operator++(int);
	void operator*=(int);
};