#include "Mesh.h"
#include <iostream>

Mesh::Mesh()
{
	m_nVertexNum = 0;
}

Mesh::~Mesh()
{
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
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
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	glGenVertexArrays(1, &m_vaoId);
	glBindVertexArray(m_vaoId);

	glGenBuffers(1, &m_vboId);
	glBindBuffer(GL_ARRAY_BUFFER, m_vboId);

	glBufferData(GL_ARRAY_BUFFER, (m_nColorNum + m_nVertexNum)*sizeof(GLfloat), 0, GL_STATIC_DRAW);

	glBufferSubData(GL_ARRAY_BUFFER, 0, m_nVertexNum*sizeof(GLfloat), m_pData);
	glBufferSubData(GL_ARRAY_BUFFER, m_nVertexNum*sizeof(GLfloat), (m_nColorNum + m_nVertexNum) * sizeof(GLfloat), m_pColor);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,0, 0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
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
