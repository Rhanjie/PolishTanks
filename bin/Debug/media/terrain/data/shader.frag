uniform sampler2D terrainTex1;
uniform sampler2D terrainTex2;

float he = 10.0;

void main()
{
	vec 4 tex1 = texture2D(terrainTex1, gl_TexCoord[0].xy*he);
	vec 4 tex2 = texture2D(terrainTex2, gl_TexCoord[0].xy*he);

	vec 4 t = tex1 + tex2;

        gl_FragColor = t;
}