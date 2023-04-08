#include "Ring.h"

Ring::Ring(float new_r, float new_R, float new_x, float new_y) {
	float temp;
	if (new_r < 0)
		r = 0;
	if (new_R < 0)
		R = 0;
	if (r > R) {
		temp = r;
		r = R;
		R = temp;
	}
	else
		r = new_r, R = new_R, x = new_x, y = new_y;
}
Ring::Ring(Ring& NewRing) {
	r = NewRing.r, R = NewRing.R, x = NewRing.x, y = NewRing.y;
}
float Ring::get_x() const {
	return x;
}
float Ring::get_y() const {
	return y;
}
float Ring::get_r() const {
	return r;
}
float Ring::get_R() const {
	return R;
}
//returns width of a ring
float Ring::get_width() const {
	return R - r;
}
//sets new values for a ring
void Ring::set_values(float new_r, float new_R, float new_x, float new_y) {
	float temp;
	if (new_r < 0)
		r = 0;
	if (new_R < 0)
		R = 0;
	if (r > R) {
		temp = r;
		r = R;
		R = temp;
	}
	else
		r = new_r, R = new_R, x = new_x, y = new_y;
}
//increments inner radius
void Ring::operator++() {
	float temp;
	r += 1;
	if (r > R) {
		temp = r;
		r = R;
		R = temp;
	}
}
//increments outer radius
void Ring::operator++(int unused) {
	R += 1;
}
//miltiplies outer radius by value
void Ring::operator*=(int multiplier) {
	float temp;
	R *= multiplier;
	if (R < r) {
		temp = r;
		r = R;
		R = temp;
	}
}
