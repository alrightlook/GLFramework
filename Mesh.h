#ifndef MESH_HEADER
#define MESH_HEADER
#include <GL/glew.h>
class Mesh
{
	public:
		Mesh();
		~Mesh();
		void init();
		void setData(GLfloat* pdata);
		void draw();
	private:
		GLuint m_vboId;
		GLuint m_vaoId;
		GLfloat* m_pData;
};
#endif
