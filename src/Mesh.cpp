#include "Mesh.hpp"
#include "Shader.hpp"
#include "OpenGLVertexIndexBuffer.hpp"
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/scene.h>

Mesh::Mesh()
{
    mColor = {1.0f, 0.0f, .0f};
    mRoughness = 0.2f;
    mMetallic = 0.1f;
}

Mesh::~Mesh()
{
    deleteBuffers();
}

bool Mesh::load(const std::string &filepath)
{

    const uint32_t cMeshImportFlags =
        aiProcess_CalcTangentSpace |
        aiProcess_Triangulate |
        aiProcess_SortByPType |
        aiProcess_GenNormals |
        aiProcess_GenUVCoords |
        aiProcess_OptimizeMeshes |
        aiProcess_ValidateDataStructure;

    Assimp::Importer Importer;

    const aiScene *pScene = Importer.ReadFile(filepath.c_str(),
                                              cMeshImportFlags);

    if (pScene && pScene->HasMeshes())
    {
        mVertexIndices.clear();
        mVertices.clear();

        auto *mesh = pScene->mMeshes[0];

        for (uint32_t i = 0; i < mesh->mNumVertices; i++)
        {
            VertexHolder vh;
            vh.mPos = {mesh->mVertices[i].x, mesh->mVertices[i].y, mesh->mVertices[i].z};
            vh.mNormal = {mesh->mNormals[i].x, mesh->mNormals[i].y, mesh->mNormals[i].z};

            addVertex(vh);
        }

        for (size_t i = 0; i < mesh->mNumFaces; i++)
        {
            aiFace face = mesh->mFaces[i];

            for (size_t j = 0; j < face.mNumIndices; j++)
                addVertexIndex(face.mIndices[j]);
        }

        init();
        return true;
    }
    return false;
}

void Mesh::addVertex(const VertexHolder &vertex)
{
    mVertices.push_back(vertex);
}

void Mesh::addVertexIndex(unsigned int vertexIndex)
{
    mVertexIndices.push_back(vertexIndex);
}

std::vector<unsigned int> Mesh::getVertexIndices()
{
    return mVertexIndices;
}

void Mesh::update(Shader *shader)
{
    shader->setVector3(mColor, "albedo");
    shader->setFloat1(mRoughness, "roughness");
    shader->setFloat1(1.0f, "ao");
}

void Mesh::init()
{
    mRenderBufferMgr = std::make_unique<OpenGLVertexIndexBuffer>();
    createBuffers();
}

void Mesh::createBuffers()
{
    mRenderBufferMgr->createBuffers(mVertices, mVertexIndices);
}

void Mesh::deleteBuffers()
{
    mRenderBufferMgr->deleteBuffers();
}

void Mesh::render()
{
    mRenderBufferMgr->draw(mVertexIndices.size());
}

void Mesh::bind()
{
    mRenderBufferMgr->bind();
}

void Mesh::unbind()
{
    mRenderBufferMgr->unbind();
}
