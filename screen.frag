varying vec3 normal, lightDir, eye;

void main()
{
	float Frequency = 20.0;
	float Density = 0.5;

	vec4 final_color = (gl_FrontLightModelProduct.sceneColor) + (gl_LightSource[0].ambient * gl_FrontMaterial.ambient);
	vec3 N = normalize(normal);
	vec3 L = normalize(lightDir);
	float lambertTerm = dot(N,L);
	if(lambertTerm > 0.0)
	{
		final_color += gl_LightSource[0].diffuse * gl_FrontMaterial.diffuse * lambertTerm;	
		vec3 E = normalize(eye);
		vec3 R = reflect(-L, N);
		float specular = pow( max(dot(R, E), 0.0), gl_FrontMaterial.shininess);
		final_color += gl_LightSource[0].specular * gl_FrontMaterial.specular * specular;	
	}

	float s = gl_TexCoord[0].s;
	float t = gl_TexCoord[0].t;
	float sf = s * Frequency;
	float tf = t * Frequency;
	
	if (fract(sf) >= Density  &&  fract(tf) >= Density)
		discard;
	gl_FragColor = final_color;
}
