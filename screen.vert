varying vec3 normal;
varying vec3 eye;
varying vec3 lightDir;

void main()
{
	normal = gl_NormalMatrix * gl_Normal;
	vec3 vVertex = vec3(gl_ModelViewMatrix * gl_Vertex);
	lightDir = vec3(gl_LightSource[0].position.xyz - vVertex);
	eye = -vVertex;
	gl_TexCoord[0] = gl_MultiTexCoord0;
	gl_Position = ftransform();
}
