#include "prefix.h"
#include "wheel.h"
#include "platform.h"
#include "utility.h"

extern vector<object3d*> gShapeVector;

wheel::wheel(int density) {

	vertexCount = (density * 2) + 2;
	polygonCount = faceCount = density * 3;

	vertices.resize(vertexCount);
	faces.resize(faceCount);

	int vertex = 0;
	float radius = 2.5;

	for (int i = 0; i < density; i++) {

		float yRot = i * (360.0 / (float)density);

		float x = cos_d(yRot) * radius;
		float z = sin_d(yRot) * radius;

		vertices[vertex].set(x, 1.0, z);
		vertices[vertex + density].set(x, -1.0, z);
		vertex++;
	}

	vertex *= 2;

	vertices[vertex++].set(0, 1.0, 0);
	vertices[vertex++].set(0, -1.0, 0);

	int faceCounter = 0;

	for (int i = 0; i < density; i++) {

		int j = (i + 1) % density;
		faces[faceCounter].init(density * 2, j, i);
		faces[faceCounter + density].init(density * 2 + 1, i + density, j + density);
		faces[faceCounter + density * 2].init(i, j, j + density, i + density);
		faceCounter++;
	}

	calculateNormals();

	gShapeVector.push_back(this);
}