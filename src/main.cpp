#include <iostream>
using namespace std;

#include <GL/glew.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <OpenMesh/Core/IO/MeshIO.hh>
#include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>


// ----------------------------------------------------------------------------
typedef OpenMesh::TriMesh_ArrayKernelT<>  MyMesh;
// ----------------------------------------------------------------------------



#define INPUT_DATA "/Users/cpeng/Documents/Projects/MeshProcessing/InputData/bunny.obj"
MyMesh mesh;

// using geom shader for runtime face normal calculations
const char* vShaderFile = "/Users/cpeng/Google\ Drive/Teaching/CS445_545/GLSetup/GLTemplate/Shaders/v_shader.vert";
const char* gShaderFile = "/Users/cpeng/Google\ Drive/Teaching/CS445_545/GLSetup/GLTemplate/Shaders/g_shader.geom";
const char* fShaderFile = "/Users/cpeng/Google\ Drive/Teaching/CS445_545/GLSetup/GLTemplate/Shaders/f_shader.frag";

// using only vert and frag shaders for runtime
const char* v1ShaderFile = "/Users/cpeng/Google\ Drive/Teaching/CS445_545/GLSetup/GLTemplate/Shaders/v1_shader.vert";
const char* f1ShaderFile = "/Users/cpeng/Google\ Drive/Teaching/CS445_545/GLSetup/GLTemplate/Shaders/f1_shader.frag";


int main()
{
    if (!OpenMesh::IO::read_mesh(mesh, INPUT_DATA)){
        cerr<<"read error\n";
        exit(1);
    }
    
    cout<<"# of vertices: "<< mesh.n_vertices()<<endl;
    
    return 0;
}
