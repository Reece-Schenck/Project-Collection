// Fragment Shader for Wave Effect

// Input variables
varying vec4 vColor;
varying vec2 vTexCoord;

vec4 fColor = vColor;
vec2 fTexCoord = vTexCoord;

// Uniform variables
uniform sampler2D uTexture;  // Texture sampler

void main()
{
    // Sample the texture using the displaced texture coordinates
    fColor = texture2D(uTexture, fTexCoord);
    
    // Output the final color
    gl_FragColor = fColor;
}