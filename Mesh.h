#ifndef MESH_HEADER
#define MESH_HEADER
#include <GL/glew.h>
class Mesh
{
	public:
		Mesh();
		~Mesh();
		void init();
		void setData(GLfloat* pdata, int num);
		void setColor(GLfloat* pdata, int num);
		void draw();
	private:
		int m_nVertexNum;
		int m_nColorNum;
		GLuint m_vboId;
		GLuint m_vaoId;
		GLfloat* m_pData;
		GLfloat* m_pColor;
};
#endif
