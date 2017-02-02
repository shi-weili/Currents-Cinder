#version 150

// import 2 textures
uniform sampler2D tex0;
uniform sampler2D tex1;

in vec4 vTexCoord0;

out vec4 oColor;

void main( void )
{

	vec4 color0 = texture( tex0, vTexCoord0.st );
	vec4 color1 = texture( tex1, vTexCoord0.st );

	color0.rgb = vec3( 1.0 ) - color0.rgb;
	color1.a = 0.3;

	vec4 result = mix( color0, color1, color1.a );

	oColor.rgb = result.rgb;
	oColor.a = 1.0;
}