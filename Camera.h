#pragma once 
#include <GLFW/glfw3.h>
#include <glm/ext/matrix_transform.hpp>
#include <glm/ext/vector_float3.hpp>
#include <glm/fwd.hpp>
#include <glm/geometric.hpp>
#include<glm/glm.hpp>



//相机类
class Camera 
{
    private:
    glm::vec3 cameraPosition;//相机位置
    glm::vec3 cameraFront;//相机面对方向
    glm::vec3 cameraUp;//相机上方
    float deltaTime=0.0;
    float lastFrame=0.0;
    float currentFrame=0.0;

    public:
    Camera(glm::vec3 cameraPos,glm::vec3 camera_front,glm::vec3 camera_up)
    {
        this->cameraPosition=glm::normalize(cameraPos) ;
        this->cameraFront=glm::normalize(camera_front) ;
        this->cameraUp=glm::normalize(camera_up) ;
    }

    glm::mat4 getLookAt_Matrix()
    {
        return glm::lookAt(this->cameraPosition, this->cameraFront+this->cameraPosition, this->cameraUp);
    }
    //修改相机位置
    void set_camera_Position(glm::vec3 new_camera_position)
    {
        this->cameraPosition=glm::normalize(new_camera_position) ;
    }
    //修改相机front
    void set_camera_front(glm::vec3 new_camera_front)
    {
        this->cameraFront=glm::normalize(new_camera_front);
    }
    //修改相机up
    void set_camera_up(glm::vec3 new_camera_up)
    {
        this->cameraUp=glm::normalize(new_camera_up);
    }
    //控制相机位置
    //设置当前帧时间
    void set_current_time(float input_current_time)
    {
        this->currentFrame=input_current_time;
        deltaTime=currentFrame-lastFrame;
        lastFrame=currentFrame;
    }
    //取得相机位置
    glm::vec3 get_camera_position()
    {
        return this->cameraPosition;
    }




    void processInput_component(GLFWwindow* window)
    {
        float cameraSpeed=2.5*deltaTime;
        if(glfwGetKey(window, GLFW_KEY_W)==GLFW_PRESS)
        {
            this->cameraPosition+=cameraSpeed*this->cameraFront;
        }
        else if(glfwGetKey(window, GLFW_KEY_S)==GLFW_PRESS)
        {
            this->cameraPosition-=cameraSpeed*this->cameraFront;
        }
        else if (glfwGetKey(window, GLFW_KEY_A))
        {
            this->cameraPosition-=glm::cross(this->cameraFront, this->cameraUp)*cameraSpeed;
        }
        else if (glfwGetKey(window, GLFW_KEY_D)==GLFW_PRESS)
        {
            cameraPosition+=glm::cross(this->cameraFront, this->cameraUp)*cameraSpeed;
        }
    }



};