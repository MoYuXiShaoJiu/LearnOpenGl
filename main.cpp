// #include "Shader.h"
// #include <cmath>
// #include<glad/glad.h>
// #include<GLFW/glfw3.h>
// #include <glm/ext/matrix_clip_space.hpp>
// #include <glm/ext/matrix_float4x4.hpp>
// #include <glm/ext/matrix_transform.hpp>
// #include <glm/ext/quaternion_geometric.hpp>
// #include <glm/ext/vector_float3.hpp>
// #include <glm/fwd.hpp>
// #include <glm/geometric.hpp>
// #include <glm/trigonometric.hpp>
// #include<iostream>
// #include <math.h>
// #include <string>
// #include "Shader.h"
// #include "stb_image.h"
// #include <glm/glm.hpp>
// #include <glm/gtc/matrix_transform.hpp>
// #include <glm/gtc/type_ptr.hpp>
// #include "Camera.h"
// using namespace std;
// void processInput(GLFWwindow * window);

// float vertices[]={
//      // positions                             // colors                            // texture coords
//     0.5f,  0.5f, 0.0f,          1.0f, 0.0f, 0.0f,           1.0f, 1.0f, // top right
//     0.5f, -0.5f, 0.0f,        0.0f, 1.0f, 0.0f,        1.0f, 0.0f, // bottom right
//     -0.5f, -0.5f, 0.0f,     0.0f, 0.0f, 1.0f,        0.0f, 0.0f, // bottom left
//     -0.5f,  0.5f, 0.0f,     1.0f, 1.0f, 0.0f,        0.0f, 1.0f  // top left

// };
// unsigned int indices[]={
//     0,1,3,
//     1,2,3
// };
// float cube[]={
//     0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
//      0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
//      0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//      0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//     -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//     -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

//     -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//      0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//      0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//      0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
//     -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
//     -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

//     -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//     -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//     -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//     -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//     -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//     -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

//      0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//      0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//      0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//      0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//      0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//      0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

//     -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
//      0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
//      0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//      0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
//     -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
//     -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

//     -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
//      0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
//      0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//      0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
//     -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
//     -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
// };
// glm::vec3 cubePositions[] = {
//   glm::vec3( 0.0f,  0.0f,  0.0f), 
//   glm::vec3( 2.0f,  5.0f, -15.0f), 
//   glm::vec3(-1.5f, -2.2f, -2.5f),  
//   glm::vec3(-3.8f, -2.0f, -12.3f),  
//   glm::vec3( 2.4f, -0.4f, -3.5f),  
//   glm::vec3(-1.7f,  3.0f, -7.5f),  
//   glm::vec3( 1.3f, -2.0f, -2.5f),  
//   glm::vec3( 1.5f,  2.0f, -2.5f), 
//   glm::vec3( 1.5f,  0.2f, -1.5f), 
//   glm::vec3(-1.3f,  1.0f, -1.5f)  
// };
// glm::vec3 cameraPosition(0.0,0.0,3.0);
// glm::vec3 cameraFront(0.0,0.0,-1.0);
// glm::vec3 cameraUp(0.0,1.0,0.0);

// int main()
// {
//     cameraPosition=glm::vec3(0.0,0.0,3.0);
//     glfwInit();//初始化glfw
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,4);//指定opengl版本
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,6);
//     glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
//     const int screenWidth=800;
//     const int screenHeight=600;
//     GLFWwindow *  window=glfwCreateWindow(800,600,"LearnOpenGl",NULL,NULL);//创建窗口大小
//     if(window==NULL)//如果初始化窗口失败
//     {
//         cout<<"fail to creat window"<<endl;
//         glfwTerminate();
//         return -1;
//     }
//     glfwMakeContextCurrent(window);//将窗口的contex设为当前contex

//     if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))//控制函数指针
//     {
//         std::cout << "Failed to initialize GLAD" << std::endl;
//         return -1;
//     }
//     glViewport(0,0,800,600);//前两个参数控制窗口左下角的位置，第三个和第四个参数控制渲染窗口的宽度和高度

//     unsigned int VBO;//定义顶点缓冲
//     //vao
//     unsigned int VAO;
//     //EBO
//     //unsigned int EBO;
//     glGenVertexArrays(1,&VAO);
//     glGenBuffers(1,&VBO);//生成一个缓冲id和一个VBO对象
//     //glGenBuffers(1,&EBO);


//     glBindVertexArray(VAO);

//     glBindBuffer(GL_ARRAY_BUFFER,VBO);//绑定一个缓冲
//     glBufferData(GL_ARRAY_BUFFER,sizeof(cube),cube,GL_STATIC_DRAW);
//     //设置EBO
//     //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
//     //glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(indices),indices,GL_STATIC_DRAW);

//     //解析顶点数据
//     glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,5*sizeof(float),(void*)0);
//     //上面这一个是用来解析顶点数据的
//     glEnableVertexAttribArray(0);//以顶点属性位置为参数，启用顶点属性

//     //glVertexAttribPointer(1,2,GL_FLOAT,GL_FALSE,5*sizeof(float),(void*)(3*sizeof(float)));
//     //glEnableVertexAttribArray(1);

//     //glVertexAttribPointer(2,2,GL_FLOAT,GL_FALSE,8*sizeof(float),(void*)(6*sizeof(float)));
//     //glEnableVertexAttribArray(2);

//     //生成纹理
//     unsigned int texture,texture1;
//     glGenTextures(1,&texture);
//     glBindTexture(GL_TEXTURE_2D,texture);
//     //为当前纹理设置过滤，环绕方式
//     glTextureParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
//     glTextureParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);//指定纹理轴盒环绕方式
//     glTextureParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);//缩小时设置过滤选项
//     glTextureParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);//放大时设置过滤选项
//     int width,height,nrChannels;
//     unsigned char * data=stbi_load("container.jpg", &width, &height, &nrChannels, 0);
//     if(data)
//     {
//         glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,width,height,0,GL_RGB,GL_UNSIGNED_BYTE,data);//生成纹理
//         glGenerateMipmap(GL_TEXTURE_2D);//生成mipmap
//     }
//     else
//     {
//         std::cout<<"read jpg fail\n"<<std::endl;
//     }
//     stbi_image_free(data);//释放空间
//     //第二张图片
//     glGenTextures(1,&texture1);
//     glBindTexture(GL_TEXTURE_2D,texture1);
//     glTextureParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
//     glTextureParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);//指定纹理轴盒环绕方式
//     glTextureParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);//缩小时设置过滤选项
//     glTextureParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);//放大时设置过滤选项
//     //加载图片
//     int width1,height1,nrChannels1;
//     stbi_set_flip_vertically_on_load(true);
//     //通过文件路径，将图片的宽高和颜色通道个数赋予三个变量
//     unsigned char * data1=stbi_load("awesomeface.png", &width1, &height1, &nrChannels1, 0);
//     if(data1)
//     {
//         glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,width1,height1,0,GL_RGBA,GL_UNSIGNED_BYTE,data1);//生成纹理
//         glGenerateMipmap(GL_TEXTURE_2D);//生成mipmap
//     }
//     else 
//     {
//         std::cout<<"read jpg fail\n"<<std::endl;
//     }
//     stbi_image_free(data1);

//    //生成shader
//     std::string vPath,fPath;
//     vPath="vertexShader.glsl";
//     fPath="fragmentShader.glsl";
//     const char * c_vPath,*c_fPath;
//     c_vPath=vPath.c_str();
//     c_fPath=fPath.c_str();
//     Shader ourShader(c_vPath,c_fPath);
//     ourShader.use();
//     ourShader.set_Uniform_Int("ourTexture", 0);
//     ourShader.set_Uniform_Int("ourTexture1", 1);
//     glEnable(GL_DEPTH_TEST);

//     Camera myCamera(cameraPosition,cameraFront,cameraUp);
//     //渲染循环
//     while(!glfwWindowShouldClose(window))//render loop
//     {
//         myCamera.set_current_time(glfwGetTime());
//         myCamera.processInput_component(window);
//     //每一次渲染迭代开始之前我们都希望清空屏幕，这里只清除了颜色缓冲
//         glClearColor(0.2f,0.3f,0.3f,1.0f);
//         glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//         glActiveTexture(GL_TEXTURE0);
//         glBindTexture(GL_TEXTURE_2D,texture);
//         glActiveTexture(GL_TEXTURE1);            
//         glBindTexture(GL_TEXTURE_2D,texture1);
//         ourShader.use();
//         //旋转和放缩矩阵
//         glm::mat4 view(1.0f);
//         view=myCamera.getLookAt_Matrix();
//         glm::mat4 projection(1.0f);
//         projection=glm::perspective((float)glm::radians(45.0f),(float) ((float)screenWidth/screenHeight), 0.1f, 100.0f);
//         int modelLocation,viewLocation,projectionLocation;
       
//         viewLocation=glGetUniformLocation(ourShader.ID,"view");
//         glUniformMatrix4fv(viewLocation,1,GL_FALSE,glm::value_ptr(view));
//         projectionLocation=glGetUniformLocation(ourShader.ID,"projection");
//         glUniformMatrix4fv(projectionLocation,1,GL_FALSE,glm::value_ptr(projection));
//         //绘制
//         glBindVertexArray(VAO);   
//         for(int i=0;i<10;i++)
//         {
//             //修改model
//             glm::mat4 model(1.0f);//初始化标准矩阵
//             model=glm::translate(model, cubePositions[i]);
//             model=glm::rotate(model, (float)glfwGetTime()*glm::radians(-55.0f),glm::vec3(1.0f,0.0,0.0) );
//             modelLocation=glGetUniformLocation(ourShader.ID,"model");
//             glUniformMatrix4fv(modelLocation,1,GL_FALSE,glm::value_ptr(model));

//             //绘制    
//             glDrawArrays(GL_TRIANGLES,0,36);
//         }
        
//         glfwSwapBuffers(window);//使用双缓冲，这里是交换前后缓冲
//         glfwPollEvents();//检查触发事件
//     }
//     glfwTerminate();//释放所有资源



//     return 0;
// }

