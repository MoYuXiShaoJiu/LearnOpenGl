#pragma once
#include "glad/glad.h"
#include <GL/gl.h>
#include <cstddef>
#include <glm/fwd.hpp>
#include <iostream>
#include <iterator>
#include <ostream>
#include <string>
#include <fstream>
#include <sstream>
#include <glm/glm.hpp>


class Shader 
{
    public:
    //程序id
    unsigned ID;
    //读取文件并构造着色器
    Shader(const char* vertexShaderPath,const char* fragmentShaderPath)
    {
        //从文件获取顶点/片段着色器
        std::string vertexCode;
        std::string fragmentCode;
        std::ifstream vShaderFile;
        std::ifstream fShaderFile;
        //保证ifstream对象可以抛出异常
        vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        //打开文件
        try
        {
            vShaderFile.open(vertexShaderPath);
            fShaderFile.open(fragmentShaderPath);
            std::stringstream vShaderStream,fShaderStream;
            //读文件的缓冲区内容到数据流
            vShaderStream<<vShaderFile.rdbuf();
            fShaderStream<<fShaderFile.rdbuf();
            //关闭文件处理器
            vShaderFile.close();
            fShaderFile.close();
            //转换数据流到string
            vertexCode=vShaderStream.str();
            fragmentCode=fShaderStream.str();

        
        } 
        catch (std::ifstream::failure e) 
        {
            std::cout<<"ERROR:fail to read shader source"<<std::endl;
        }
        //转换为char*
        const char* vShaderCode=vertexCode.c_str();
        const char* fShaderCode=fragmentCode.c_str();
        //创建shader
        unsigned int vertexShader,fragmentShader;
        int sucess;
        char infoLog[512];
        //顶点着色器
        vertexShader=glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader,1,&vShaderCode,NULL);
        glCompileShader(vertexShader);
        glGetShaderiv(vertexShader,GL_COMPILE_STATUS,&sucess);
        if(!sucess)
        {
            glGetShaderInfoLog(vertexShader,512,NULL,infoLog);
            std::cout<<"Error:vertex shader complie fail\n"<<infoLog<<std::endl;
        }
        //片段着色器
        fragmentShader=glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader,1,&fShaderCode,NULL);
        glCompileShader(fragmentShader);
        glGetShaderiv(fragmentShader,GL_COMPILE_STATUS,&sucess);
        if(!sucess)
        {
            glGetShaderInfoLog(fragmentShader,512,NULL,infoLog);
            std::cout<<"Error:fragment shader complie fail\n"<<infoLog<<std::endl;

        }
        //链接并删除着色器
        ID=glCreateProgram();
        glAttachShader(ID,vertexShader);
        glAttachShader(ID,fragmentShader);
        glLinkProgram(ID);
        glGetShaderiv(ID,GL_COMPILE_STATUS,&sucess);
        if(!sucess)
        {
            std::cout<<"Error: shader program complie fail\n"<<infoLog<<std::endl;
        }
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);





    }
    //激活shader
    void use()
    {
        glUseProgram(ID);
    }
    //处理uniform的值
    void set_Uniform_Bool(const std::string& name,bool value)
    {
        glUniform1i(glGetUniformLocation(ID,name.c_str()),(int)value);
    }

    void set_Uniform_float(const std::string& name,float value)
    {
        glUniform1f(glGetUniformLocation(ID,name.c_str()),value);
    }
    void set_Uniform_Int(const std::string &name,int value)
    {
        glUniform1i(glGetUniformLocation(ID,name.c_str()),value);
    }
    void set_Uniform_vec3(const std::string &name,const glm::vec3 &value)
    {
        glUniform3fv(glGetUniformLocation(ID,name.c_str()),1,&value[0]);
    }

    void set_Uniform_mat4(const std::string &name,const glm::mat4 &value)
    {
        glUniformMatrix4fv(glGetUniformLocation(ID,name.c_str()),1,GL_FALSE,&value[0][0]);
    }


};