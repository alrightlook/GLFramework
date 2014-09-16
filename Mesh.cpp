#include "Mesh.h"
#include <iostream>

Mesh::Mesh()
{
	m_pColor = 0;
	m_nVertexNum = 0;
}

Mesh::~Mesh()
{
}

void Mesh::setColor(GLfloat* pdata, int num)
{
	m_pColor = pdata;
	m_nColorNum = num;
}

void Mesh::setData(GLfloat* pdata,int num)
{
	m_nVertexNum = num;
	m_pData = pdata;
}

void Mesh::init()
{
	glGenBuffers(1, &m_vboId);
	glBindBuffer(GL_ARRAY_BUFFER, m_vboId);
	glBufferData(GL_ARRAY_BUFFER, m_nVertexNum*sizeof(GLfloat), m_pData, GL_STATIC_DRAW);

	glGenBuffers(1, &m_colorId);
	glBindBuffer(GL_ARRAY_BUFFER, m_colorId);
	glBufferData(GL_ARRAY_BUFFER, m_nColorNum * sizeof(GLfloat), m_pColor, GL_STATIC_DRAW);

	glGenVertexArrays(1, &m_vaoId);
	glBindVertexArray(m_vaoId);
}

void Mesh::draw()
{
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, m_vboId);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,0, 0);

	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, m_colorId);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

	glDrawArrays(GL_TRIANGLES, 0, 3);
}
