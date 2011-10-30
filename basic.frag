varying vec3 normal, lightDir, eyeVec;

uniform int do_fog;
uniform float fog_start;
uniform float fog_end;

void main (void)
{
	vec4 final_color = (gl_FrontLightModelProduct.sceneColor) + (gl_LightSource[0].ambient * gl_FrontMaterial.ambient);
							
	vec3 N = normalize(normal);
	vec3 L = normalize(lightDir);
	
	float lambertTerm = dot(N,L);
	
	if(lambertTerm > 0.0)
	{
		final_color += gl_LightSource[0].diffuse * gl_FrontMaterial.diffuse * lambertTerm;	
		
		vec3 E = normalize(eyeVec);
		vec3 R = reflect(-L, N);
		float specular = pow( max(dot(R, E), 0.0), gl_FrontMaterial.shininess);
		final_color += gl_LightSource[0].specular * gl_FrontMaterial.specular * specular;	
	}
	float fog_factor = 1;
	
	if (do_fog == 1 && gl_FogFragCoord >= fog_start)
		fog_factor = (fog_end - gl_FogFragCoord) / (fog_end - fog_start);

	gl_FragColor = mix(gl_Fog.color, final_color, fog_factor);
}
