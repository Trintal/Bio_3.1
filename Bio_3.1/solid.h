#pragma once
#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;
#define PI 3.14159265f
#define PI_2 6.28318530f




void makeCylinder(std::string filename, int trianglesQty, float radius)
{
	float x = radius, y = 0, z = 0, z4 = 2;
	float x1, y1, z1 = 0;
	float x2, y2, z2 = 0;
	float x3, y3, z3 = 0;
	float angle = PI_2 / trianglesQty;

	std::ofstream fout(filename);
	fout << "solid ascii" << std::endl;;

	for (float a = angle; a <= (PI_2 + angle / 2); a += angle)
	{
		x1 = radius * cos(a);
		y1 = radius * sin(a);

		x2 = x;
		y2 = y;
		z2 = 2;

		x3 = x1;
		y3 = y1;
		z3 = 2;
		//-------низ----------
		fout << "facet normal 0 0 1" << endl;
		fout << "outer loop" << std::endl;
		fout << "vertex 0 0 0" << std::endl;
		fout << "vertex " << x << " " << y << " " << z << std::endl;
		fout << "vertex " << x1 << " " << y1 << " " << z1 << std::endl;
		fout << "endloop" << std::endl;
		fout << "endfacet" << std::endl;
		//--------бока------------
		fout << "facet normal 0 0 1" << std::endl;
		fout << "outer loop" << std::endl;
		fout << "vertex " << x2 << " " << y2 << " " << z2 << std::endl;
		fout << "vertex " << x << " " << y << " " << z << std::endl;
		fout << "vertex " << x1 << " " << y1 << " " << z1 << std::endl;
		fout << "endloop" << std::endl;
		fout << "endfacet" << std::endl;
		//---------бока------------
		fout << "facet normal 0 0 1" << std::endl;
		fout << "outer loop" << std::endl;
		fout << "vertex " << x2 << " " << y2 << " " << z2 << std::endl;
		fout << "vertex " << x3 << " " << y3 << " " << z3 << std::endl;
		fout << "vertex " << x1 << " " << y1 << " " << z1 << std::endl;
		fout << "endloop" << std::endl;
		fout << "endfacet" << std::endl;
		//---------верх----------
		fout << "facet normal 0 0 1" << std::endl;
		fout << "outer loop" << std::endl;
		fout << "vertex 0 0 2" << std::endl;
		fout << "vertex " << x << " " << y << " " << z4 << std::endl;
		fout << "vertex " << x1 << " " << y1 << " " << z4 << std::endl;
		fout << "endloop" << std::endl;
		fout << "endfacet" << std::endl;

		x = x1;
		y = y1;
		z = z1;
	}

	fout << "endsolid" << std::endl;
	fout.close();
}