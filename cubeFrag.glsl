#version 460 core
in vec3 Normal;
in vec3 FragPos;
out vec4 FragColor;
uniform vec3 lightPos;
uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 viewPos;

void main()
{
    //ambint
    float ambintStrength=0.2;
    vec3 ambint=ambintStrength*lightColor;
    //diffuse
    vec3 norm=normalize(Normal);
    vec3 lightDir=normalize(lightPos-FragPos);
    float diff=max(dot(norm,lightDir),0.0);
    vec3 diffuse=diff*lightColor;   
    //specular
    float specularStrength=0.5;
    vec3 viewDir=normalize(viewPos-FragPos);//从当前位置到相机位置
    vec3 reflectLight=reflect(-lightDir,norm);
    float spec=pow(max(dot(viewDir,reflectLight),0.0),32);
    vec3 specular=specularStrength*spec*lightColor;
    //total
    vec3 result=(ambint+diffuse+specular)*objectColor;
    FragColor=vec4(result,1.0);
}