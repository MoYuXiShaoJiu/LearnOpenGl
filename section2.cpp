#include <cstddef>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Camera.h"
#include "Shader.h"
#include <glm/ext/matrix_float4x4.hpp>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/vector_float3.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

float cube[]={
    -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,

        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
         0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,

        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,
        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,

         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,

        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f
 
};
int main()
{

   //光源位置
   glm::vec3 lightPos(1.2,1.0,2.0); 
   glfwInit();
   glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
   glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
   glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
   const int screenWidth=800;
   const int screenHeight=600;
   GLFWwindow *window=glfwCreateWindow(screenWidth, screenHeight, "section2", NULL, NULL);
    if(window==NULL)
    {
        std::cout<<"creat window fail\n"<<std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout<<"fail to initialize glad\n"<<std::endl;
        return -1;
    }
    glViewport(0,0,screenWidth,screenHeight);
    //定义缓冲
   unsigned int VBO,cubeVAO,lightVAO;
   glGenVertexArrays(1,&cubeVAO);
   glGenBuffers(1,&VBO);
   glBindBuffer(GL_ARRAY_BUFFER,VBO);
   glBufferData(GL_ARRAY_BUFFER,sizeof(cube),cube,GL_STATIC_DRAW);
   glBindVertexArray(cubeVAO);
   //设置顶点参数
   glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,6*sizeof(float),(void*)0);
   glEnableVertexAttribArray(0);
   glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,6*(sizeof(float)),(void*)(3*sizeof(float)));
   glEnableVertexAttribArray(1);
   //另一个shader
   glGenVertexArrays(1,&lightVAO);
   glBindVertexArray(lightVAO);
   glBindBuffer(GL_ARRAY_BUFFER,VBO);
   glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,6*sizeof(float),(void*)0);
   glEnableVertexAttribArray(0);


    Shader cubeShader("cubeVertex.glsl","cubeFrag.glsl");//用来渲染立方体
    Shader lightShader("lightVertex.glsl","lightFrag.glsl");//用来渲染光源
    glEnable(GL_DEPTH_TEST);
    //设置model view projection
    glm::mat4 model(1.0f);
    model=glm::translate(model, lightPos);
    model=glm::scale(model, glm::vec3(0.2f));
    glm::vec3 cameraPosition(0.0,0.0,3.0);
    glm::vec3 cameraFront(0.0,0.0,-1.0);
    glm::vec3 cameraUp(0.0,1.0,0.0);
    Camera camera2(cameraPosition,cameraFront,cameraUp);
    glm::mat4 projection(1.0f);
    projection=glm::perspective((float)glm::radians(45.0f),(float) ((float)screenWidth/screenHeight), 0.1f, 100.0f);

   
  
    while (!glfwWindowShouldClose(window))//render loop
    {
        glClearColor(0.2f,0.3f,0.3f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//清除缓存
        camera2.set_current_time(glfwGetTime());
        camera2.processInput_component(window);
        
        //cube
        cubeShader.use();
        cubeShader.set_Uniform_vec3("objectColor", glm::vec3(1.0f,0.5f,0.31f));
        cubeShader.set_Uniform_vec3("lightColor", glm::vec3(1.0,1.0,1.0));
        glm::mat4 cubeModel(1.0);
        cubeShader.set_Uniform_mat4("model", cubeModel);
        cubeShader.set_Uniform_mat4("view", camera2.getLookAt_Matrix());
        cubeShader.set_Uniform_mat4("projection", projection);
        cubeShader.set_Uniform_vec3("lightPos", lightPos);
        cubeShader.set_Uniform_vec3("viewPos",camera2.get_camera_position());
        glBindVertexArray(cubeVAO);
        glDrawArrays(GL_TRIANGLES,0,36);
        //ligth
        lightShader.use();
        lightShader.set_Uniform_mat4("model", model);
        lightShader.set_Uniform_mat4("view", camera2.getLookAt_Matrix());
        lightShader.set_Uniform_mat4("projection", projection);
        glBindVertexArray(lightVAO);
        glDrawArrays(GL_TRIANGLES,0,36);

        glfwSwapBuffers(window);//使用双缓冲，这里是交换前后缓冲
        glfwPollEvents();//检查触发事件
        
    }
    glfwTerminate();//释放所有资源
    return 0;

}