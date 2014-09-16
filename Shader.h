#ifndef SHADER_HEADER
#define SHADER_HEADER
#include <GL/glew.h>

class Shader
{
	public:
		Shader();
		~Shader();

		void load(const char* filename, GLenum shaderMode);
		void bind();
		bool checkStatus(GLuint program, GLenum pname);
	private:
		GLuint m_vertexShader;
		GLuint m_fragmentShader;
		GLuint m_programId;
};
#endif
