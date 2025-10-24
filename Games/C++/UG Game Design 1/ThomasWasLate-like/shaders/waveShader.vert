// Vertex Shader for Wave Effect
#version 110

//varying "out" variables to be used in the fragment shader
varying vec4 vColor;
varying vec2 vTexCoord;

// Input attributes
vec4 position;

vec2 fTexCoord = vTexCoord;

// Uniform variables
uniform float amplitude;  // Amplitude of the wave
uniform float frequency;  // Frequency of the wave
uniform float time;       // Time elapsed
 
void main()
{
    // Displace the Y coordinate based on a sine wave
    gl_Position = vec4(position.x, position.y + amplitude * sin(frequency * position.x + time), 0.0, 1.0);
    
    vColor = gl_Color;

    // Pass texture coordinates to the fragment shader
    fTexCoord =  (gl_TextureMatrix[0] * gl_MultiTexCoord0).xy;
}