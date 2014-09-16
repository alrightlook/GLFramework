#include "Mesh.h"
#include <iostream>

Mesh::Mesh()
{
	m_nVertexNum = 0;
}

Mesh::~Mesh()
{
}

void Mesh::setData(GLfloat* pdata,int num)
{
	m_nVertexNum = num;
	m_pData = pdata;
}

void Mesh::init()
{
	glGenVertexArrays(1, &m_vaoId);
	glBindVertexArray(m_vaoId);

	glGenBuffers(1, &m_vboId);
	glBindBuffer(GL_ARRAY_BUFFER, m_vboId);

	glBufferData(GL_ARRAY_BUFFER, m_nVertexNum*sizeof(GLfloat), m_pData, GL_STATIC_DRAW);

	glVertexAttribPointer((GLuint)0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);

	delete[] m_pData;
	m_pData = 0;
}

void Mesh::draw()
{
	glBindVertexArray(m_vaoId);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(0);
}
