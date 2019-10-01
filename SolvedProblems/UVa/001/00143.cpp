#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-10;

int cmp(double x, double y = 0, double tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

struct Vec2 {
	double x, y;

	Vec2(double x = 0, double y = 0) : x(x), y(y) {}
	Vec2 operator+(const Vec2& q) const { return Vec2(x + q.x, y + q.y); }
	Vec2 operator-(const Vec2& q) const { return Vec2(x - q.x, y - q.y); }
	Vec2 operator*(double t) const { return Vec2(x * t, y * t); }
	Vec2 operator/(double t) const { return Vec2(x / t, y / t); }
	double operator*(const Vec2& q) const { return x * q.x + y * q.y; }
	double operator^(const Vec2& q) const { return x * q.y - y * q.x; }

	int cmp(const Vec2& q) const {
		int t = ::cmp(x, q.x);

		if (t) return t;

		return ::cmp(y, q.y);
	}

	bool operator==(const Vec2& q) const { return cmp(q) == 0; }
	bool operator!=(const Vec2& q) const { return cmp(q) != 0; }
	bool operator<(const Vec2& q) const { return cmp(q) < 0; }

	static Vec2 pivot;
};

Vec2 Vec2::pivot;
using Polygon = vector<Vec2>;

double area(const Vec2& a, const Vec2& b, const Vec2& c) {
	return ((c - a) ^ (b - a)) / 2.0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	Polygon triangle(3);

	while (cin >> triangle[0].x >> triangle[0].y
		>> triangle[1].x >> triangle[1].y
		>> triangle[2].x >> triangle[2].y &&
		(triangle[0].x != 0.0 || triangle[0].y != 0.0 ||
		triangle[1].x != 0.0 || triangle[1].y != 0.0 ||
		triangle[2].x != 0.0 || triangle[2].y != 0.0)) {

		int inix = max(1.0, ceil(min(triangle[0].x, min(triangle[1].x, triangle[2].x))));
		int endx = min(99.0, floor(max(triangle[0].x, max(triangle[1].x, triangle[2].x))));
		int iniy = max(1.0, ceil(min(triangle[0].y, min(triangle[1].y, triangle[2].y))));
		int endy = min(99.0, floor(max(triangle[0].y, max(triangle[1].y, triangle[2].y))));

		int cont = 0;

		for (int i = inix; i <= endx; ++i) {
			for (int j = iniy; j <= endy; ++j) {
				Vec2 v(i, j);

				double a1 = area(triangle[0], v, triangle[1]);
				double a2 = area(triangle[1], v, triangle[2]);
				double a3 = area(triangle[2], v, triangle[0]);

				if ((cmp(a1) != 1 && cmp(a2) != 1 && cmp(a3) != 1) ||
					(cmp(a1) != -1 && cmp(a2) != -1 && cmp(a3) != -1))
					++cont;
			}
		}

		cout << setw(4) << cont << '\n';
	}
}
