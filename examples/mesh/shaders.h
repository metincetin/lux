const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "layout (location = 1) in vec3 aNormal;\n"
    "uniform mat4 uViewProjection;\n"
    "out vec3 vNormal;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = uViewProjection * vec4(aPos, 1.0);\n"
    "   vNormal = aNormal;\n"
    "}\0";


const char *fragmentShaderSource = "#version 330 core\n"
"in vec3 vNormal;"
"out vec4 FragColor;"
"void main()"
"{"
"    vec3 normal = vNormal;"
"    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f) * max(0, dot(normal, normalize(vec3(0.3,-1.7,0))));"
"} ";
