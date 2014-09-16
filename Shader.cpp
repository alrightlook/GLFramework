#include "Shader.h"
#include <string>
#include <iostream>
#include <fstream>
#include <GL/gl.h>

using namespace std;
Shader::Shader()
{
	m_vertexShader = 0;
	m_fragmentShader = 0;
}

Shader::~Shader()
{
}

void Shader::load(const char* filename, GLenum shaderMode)
{
	fstream f(filename);
	if(! f.is_open() ) {
		cout<<"Cannot open the file"<<endl;
		return;
	}

	string fileLine;
	string fileContent;
	while(getline(f,fileLine)) {
		fileContent += fileLine;
		fileContent += "\n";
	}
	f.close();
	cout<<"The File content:"<<endl<<fileContent<<endl;

	
	m_programId = glCreateProgram();
	char logBuffer[256];
	int written = 0;
	
	if( GL_VERTEX_SHADER == shaderMode) {
		m_vertexShader = glCreateShader(GL_VERTEX_SHADER);
		const char* psource = fileContent.c_str();
		glShaderSource (m_vertexShader, 1, &psource, 0);
		glCompileShader(m_vertexShader);
		glAttachShader(m_programId, m_vertexShader);
		glGetShaderInfoLog(m_vertexShader, 256, &written, logBuffer);
		cout<<"The output log is:"<<logBuffer<<endl;
		cout<<"The vertex shader id :" <<m_vertexShader<<endl;
	}
	else {
		m_fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		const char* psource = fileContent.c_str();
		glShaderSource(m_fragmentShader, 1, &psource, 0);
		glCompileShader(m_fragmentShader);
		glGetShaderInfoLog(m_vertexShader, 256, &written, logBuffer);
		cout<<"The output Log "<<logBuffer<<endl;
		glAttachShader(m_programId, m_fragmentShader);
		cout<<"The fragement shader id :" <<m_fragmentShader<<endl;

	}
}

void Shader::bind()
{
	char logBuffer[256];
	int written = 0;
	glLinkProgram(m_programId);
	glGetProgramInfoLog(m_programId, 256, &written, logBuffer);
	cout<<"The output log is:"<<logBuffer<<endl;
	glUseProgram(m_programId);
}

bool Shader::checkStatus(GLuint program, GLenum pname)
{
}
