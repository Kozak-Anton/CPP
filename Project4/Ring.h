
class Ring {
	float r;                                                                   //inner radius
	float R;                                                                   //outer radius
	float x;                                                                   //x axis center
	float y;                                                                   //y axis center

public:
	~Ring() {};
	Ring() : r(1), R(2), x(0), y(0) {};
	Ring(float new_r, float new_R, float new_x, float new_y);
	Ring(Ring& NewRing);
	float get_x() const;
	float get_y() const;
	float get_r() const;
	float get_R() const;
	float get_width() const;                                                   //returns width of a ring
	void set_values(float new_r, float new_R, float new_x, float new_y);       //sets new values for a ring
	void operator++();                                                         //increments inner radius
	void operator++(int);                                                      //increments outer radius
	void operator*=(int);                                                      //miltiplies outer radius by value
};