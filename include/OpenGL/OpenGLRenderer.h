#pragma once

#include <OpenGL/Common.h>
#include <Generic/Scene.h>

class OpenGLWidget;

class OpenGLRenderer {
public:
    OpenGLRenderer(OpenGLWidget* _targetWidget);
    ~OpenGLRenderer();

    void loadShader(QString vertexShaderCode, QString fragmentShaderCode);
    void render(Scene* scene);

private:
    QOpenGLFunctions * glFuncs;
    QOpenGLShaderProgram * shader;
    OpenGLWidget * targetWidget;

    void renderModel(Model* model);
    void renderMesh(Mesh* mesh);
    void renderMaterial(Material *material);
    void renderTexture(Texture* texture);
    void renderLight(Light* light, uint32_t indx);
};