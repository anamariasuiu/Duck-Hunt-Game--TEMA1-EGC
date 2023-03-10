#include "lab_m1/Tema1/Tema1.h"

#include <vector>
#include <iostream>
#include <math.h>

#include "lab_m1/Tema1/transform2D.h"
#include "lab_m1/Tema1/object2D.h"

using namespace std;
using namespace m1;


/*
 *  To find out more about `FrameStart`, `Update`, `FrameEnd`
 *  and the order in which they are called, see `world.cpp`.
 */


Tema1::Tema1()
{
}


Tema1::~Tema1()
{
}

void Tema1::Init()
{
    glm::ivec2 resolution = window->GetResolution();
    auto camera = GetSceneCamera();
    camera->SetOrthographic(0, (float)resolution.x, 0, (float)resolution.y, 0.01f, 400);
    camera->SetPosition(glm::vec3(0, 0, 50));
    camera->SetRotation(glm::vec3(0, 0, 0));
    camera->Update();
    GetCameraInput()->SetActive(false);

    glm::vec3 corner = glm::vec3(0, 0, 0);
    float squareSide = 100;
    calculate_angle();
    nr_rate++;
    


    // TODO(student): Compute coordinates of a square's center, and store
    // then in the `cx` and `cy` class variables (see the header). Use
    // `corner` and `squareSide`. These two class variables will be used
    // in the `Update()` function. Think about it, why do you need them?
    cx = squareSide / 2;
    cy = squareSide / 2;


    // Initialize tx and ty (the translation steps)
    //translateX = 150;
    //translateY = 150;

    // Initialize sx and sy (the scale factors)
    scaleX = 1.3;
    scaleY = 1;


    // Initialize angularStep
    //angularStep = 10;
    //angularStep2 = 40;

    rezolutie = window->GetResolution();
    {
        vector<VertexFormat> vertices
        {
            VertexFormat(glm::vec3(70, 30,  0), glm::vec3(1, 0, 1)),
            VertexFormat(glm::vec3(200, 70,  0), glm::vec3(1, 0, 1)),
            VertexFormat(glm::vec3(70, 120,  0), glm::vec3(1, 0, 1))

        };

        vector<unsigned int> indices =
        {
            0,1,2

        };
        /**/
        meshes["corp"] = new Mesh("");
        meshes["corp"]->InitFromData(vertices, indices);

        // Actually create the mesh from the data

    }
    {
        vector<VertexFormat> vertices
        {
            VertexFormat(glm::vec3(70, 50,  0), glm::vec3(0, 1, 1)),
            VertexFormat(glm::vec3(130, 60,  0), glm::vec3(0, 1, 1)),
            VertexFormat(glm::vec3(100, 30,  0), glm::vec3(0, 1, 1))

        };

        vector<unsigned int> indices =
        {
            0,1,2

        };
        /**/
        meshes["aripa_jos"] = new Mesh("");
        meshes["aripa_jos"]->InitFromData(vertices, indices);

        // Actually create the mesh from the data

    }
    {
        vector<VertexFormat> vertices
        {
            VertexFormat(glm::vec3(80, 80,  0), glm::vec3(0, 1, 1)),
            VertexFormat(glm::vec3(130, 70,  0), glm::vec3(0, 1, 1)),
            VertexFormat(glm::vec3(100, 120 ,  0), glm::vec3(0, 1, 1))

        };

        vector<unsigned int> indices =
        {
            0,1,2

        };
        /**/
        meshes["aripa_sus"] = new Mesh("");
        meshes["aripa_sus"]->InitFromData(vertices, indices);
       // AddMeshToList
    }
    {
        vector<VertexFormat> vertices
        {
            VertexFormat(glm::vec3(220, 85,  0), glm::vec3(0.5, 0.5, 0.5)),
            VertexFormat(glm::vec3(220, 55,  0), glm::vec3(0.5, 0.5, 0.5)),
            VertexFormat(glm::vec3(245, 70 ,  0), glm::vec3(0.5, 0.5, 0.5))

        };

        vector<unsigned int> indices =
        {
            0,1,2

        };
        /**/
        meshes["cioc"] = new Mesh("");
        meshes["cioc"]->InitFromData(vertices, indices);
    }
    {
        Mesh* cap = object2D::CreateCircle("cap", glm::vec3(200, 70, 0), glm::vec3(1, 1, 0), 30);
        AddMeshToList(cap);

    }
    //dreptunghi incadrator
    {
        Mesh* dreptunghi = object2D::CreateSquare("dreptunghi", glm::vec3(60, 0, 0),160, glm::vec3(1, 0, 0), false);
        AddMeshToList(dreptunghi);

    }
    {
        Mesh* life1 = object2D::CreateCircle("life1", glm::vec3(50, 680, 0), glm::vec3(1, 1, 0), 30);
        AddMeshToList(life1);
    }
    {
        Mesh* life2 = object2D::CreateCircle("life2", glm::vec3(120, 680, 0), glm::vec3(1, 1, 0), 30);
        AddMeshToList(life2);
    }
    {
        Mesh* life3 = object2D::CreateCircle("life3", glm::vec3(190, 680, 0), glm::vec3(1, 1, 0), 30);
        AddMeshToList(life3);
    }
    {
        Mesh *glont1 = object2D::CreateSquare("glont1", glm::vec3(40, 600, 0), 30, glm::vec3(1, 0, 0), false);
        AddMeshToList(glont1);
    }
    {
        Mesh* glont2 = object2D::CreateSquare("glont2", glm::vec3(110, 600, 0), 30, glm::vec3(1, 0, 0), false);
        AddMeshToList(glont2);
    }
    {
        Mesh* glont3 = object2D::CreateSquare("glont3", glm::vec3(180, 600, 0), 30, glm::vec3(1, 0, 0), false);
        AddMeshToList(glont3);
    }
    {
        Mesh* scor_max = object2D::CreateSquare("scor_max", glm::vec3(950, 600, 0), 100, glm::vec3(1, 0, 0), false);
        AddMeshToList(scor_max);
    }
    {
        Mesh* scor = object2D::CreateSquare("scor", glm::vec3(950, 600, 0), 100, glm::vec3(1, 1, 0), true);
        AddMeshToList(scor);
    }
}


void Tema1::FrameStart()
{
    // Clears the color buffer (using the previously set color) and depth buffer
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::ivec2 resolution = window->GetResolution();
    // Sets the screen area where to draw
    glViewport(0, 0, resolution.x, resolution.y);

}


void Tema1::Update(float deltaTimeSeconds)
{
    //cout << x + translateX << " " << y+ translateY <<" "<< DEGREES(angle)<< endl;
    //cout<<glont<<endl;
    if (nr_rate % 5 == 0) {
        speed = 100 + i * 100 / 5;
    }
    // peretele 1
    if (0 > (translateY + y) ) {
        translateY = -y;
        // sens trig
         cout << "Am lovit peretele 1" << endl;
        // cout << translateX << " " << translateY << endl;
        if (x_creste && !y_creste) {
            //cout << "p1caz1" << endl;
            y_creste = true;
            caz = 2;
            /*sens_trig = true;;*/
            angle = DEGREES(alfa);
            angle = RADIANS(angle);
            
        }
        //sens invers
        if (!x_creste && !y_creste) {
            //cout << "p1caz1" << endl;
            y_creste = true;
            caz = 3;
  
            angle = 180 - DEGREES(alfa);
            angle = RADIANS(angle);

        }
    }
    // perete 2
    if (rezolutie.x <= (translateX +x) ) {
        translateX = rezolutie.x - x;
        // sens trig
        cout << "Am lovit peretele 2" << endl;
        if (x_creste && y_creste) {
            //cout << "p2caz1" << endl;
            x_creste = false;
            caz = 1;
            angle = 90 + DEGREES(alfa);
            if (angle >= 360) {
                angle -= 360;
            }
            angle = RADIANS(angle);

        }
        //sens invers
        if (x_creste && !y_creste) {
            //cout << "p2caz2" << endl;
            x_creste = false;
            caz = 2;
            //angle = DEGREES(angle) - (90 - DEGREES(angle));
            angle =  180 +  DEGREES(alfa);
            angle = RADIANS(angle);

        }
    }
    // perete 3
    if (rezolutie.y <= (y + translateY)) {
        translateY = rezolutie.y - y;
        cout << "Am lovit peretele 3" << endl;
        //sens trigonometric
        if (!x_creste && y_creste) {
            y_creste = false;
            caz = 4;
            angle = 180 + DEGREES(alfa);
            angle = RADIANS(angle);

        }
        // sens invers
        if (x_creste && y_creste) {
            y_creste = false;
            caz = 1;
            angle = 360 - DEGREES(alfa);
            angle = RADIANS(angle);

        }
    }
    //perete 4
        if (0 > (translateX + x)) {
            translateX = -x;
            cout << "Am lovit peretele 4" << endl;
            // sens trig
            if (!x_creste && !y_creste) {
                //cout << "p4caz1" << endl;
                x_creste = true;
                caz = 3;
                angle = 360 - DEGREES(alfa);
                angle = RADIANS(angle);

            }
            //sens invers
            if (!x_creste && y_creste) {
                //cout << "p4caz2" << endl;
                x_creste = true;
                caz = 4;
                angle = DEGREES(alfa);
                angle = RADIANS(angle);

            }
        }
      cout << glont << endl;
      if (onclick && !escaped) {
          glont--;
          onclick = false;

          if (mouseOx >= (60 + x + translateX) && mouseOx <= (208 + x + translateX) &&
              (720 - mouseOy) >= (y + translateY) && (720 - mouseOy) <= (160 + y + translateY) ) {
              cout << glont << endl;
              shooted = true;
              angle = RADIANS(270);
              scor++;
          }
      }
      if ((time > 5 && !shooted) || (glont == 0 && !shooted)) {
          escaped = true;
          angle = RADIANS(90);
          onclick = false;
      }
      if (escaped && (translateY + y) >= rezolutie.y) {
          nr_rate++;
          i++;
          nr_escaped++;
          glont = 3;
          nr_frame = 0;
          calculate_angle();
          time = 0;
          escaped = false;
      }
      if (shooted && (translateY + y) <= 0) {
          nr_rate++;
          i++;
          Sx += 0.2;
          glont = 3;
          nr_frame = 0;
          calculate_angle();
          time = 0;
          shooted = false;
      }
      time += 0.2 * deltaTimeSeconds;
      nr_frame++;

      if (!escaped && !shooted) {
          if (x_creste && y_creste) {
              //cout << "x creste y creste" << endl;
              translateX += deltaTimeSeconds * speed;
              translateY += deltaTimeSeconds * speed;
          }
          else if (!x_creste && y_creste) {
              //cout << "x scade y creste" << endl;
              translateX -= deltaTimeSeconds * speed;
              translateY += deltaTimeSeconds * speed;
          }
          else if (x_creste && !y_creste) {
              //cout << "x creste y scade" << endl;
              translateX += deltaTimeSeconds * speed;
              translateY -= deltaTimeSeconds * speed;
          }
          else {
              //cout << "x scade y scade" << endl;
              translateX -= deltaTimeSeconds * speed;
              translateY -= deltaTimeSeconds * speed;
          }
      }
      else if(escaped) {
          translateY += deltaTimeSeconds * 100;
      }
      else if (shooted) {
          translateY -= deltaTimeSeconds * 100;
      }
     modelMatrix = glm::mat3(1);
     modelMatrix *= transform2D::Translate(x + translateX, y + translateY);
     modelMatrix *= transform2D::Translate(x, y);
     modelMatrix *= transform2D::Rotate(angle);
     modelMatrix *= transform2D::Translate(-x, -y);
     RenderMesh2D(meshes["cap"], shaders["VertexColor"], modelMatrix);
     
     modelMatrix = glm::mat3(1);
     modelMatrix *= transform2D::Translate(x + translateX, y + translateY);
     modelMatrix *= transform2D::Translate(x, y);
     modelMatrix *= transform2D::Rotate(angle);
     modelMatrix *= transform2D::Translate(-x, -y);
     RenderMesh2D(meshes["corp"], shaders["VertexColor"], modelMatrix);
     
     modelMatrix = glm::mat3(1);

     modelMatrix *= transform2D::Translate(x + translateX, y + translateY);
     modelMatrix *= transform2D::Translate(x, y);
     modelMatrix *= transform2D::Rotate(angle);
     modelMatrix *= transform2D::Translate(-x, -y);
     if (nr_frame % 100 >= 0 && nr_frame % 100 < 50) {
         angularStep += 10 * deltaTimeSeconds;
         modelMatrix *= transform2D::Translate(130, 60);
         modelMatrix *= transform2D::Rotate(angularStep);
         modelMatrix *= transform2D::Translate(-130, -60);

     }
     else if ((nr_frame % 100 >= 50) && (nr_frame % 100 <= 99)) {
         angularStep -= 10 * deltaTimeSeconds;
         modelMatrix *= transform2D::Translate(130, 70);
         modelMatrix *= transform2D::Rotate(angularStep);
         modelMatrix *= transform2D::Translate(-130, -70 );
     }
   
     RenderMesh2D(meshes["aripa_sus"], shaders["VertexColor"], modelMatrix);
     
     modelMatrix = glm::mat3(1);
     modelMatrix *= transform2D::Translate(x + translateX, y + translateY);
     modelMatrix *= transform2D::Translate(x, y);
     modelMatrix *= transform2D::Rotate(angle);
     modelMatrix *= transform2D::Translate(-x, -y);
     if (nr_frame % 100 >= 0 && nr_frame % 100 < 50) {
         angularStep2 -= 10 * deltaTimeSeconds;
         modelMatrix *= transform2D::Translate(130, 60);
         modelMatrix *= transform2D::Rotate(angularStep2);
         modelMatrix *= transform2D::Translate(-130, -60);

     }
     else if ((nr_frame % 100 >= 50) && (nr_frame % 100 <= 99)) {
         angularStep2 += 10 * deltaTimeSeconds;
         modelMatrix *= transform2D::Translate(130, 60);
         modelMatrix *= transform2D::Rotate(angularStep2);
         modelMatrix *= transform2D::Translate(-130, -60);
     }

     RenderMesh2D(meshes["aripa_jos"], shaders["VertexColor"], modelMatrix);
     
     modelMatrix = glm::mat3(1);
     modelMatrix *= transform2D::Translate(x+ translateX,y+ translateY);
     modelMatrix *= transform2D::Translate(x, y);
     modelMatrix *= transform2D::Rotate(angle);
     modelMatrix *= transform2D::Translate(-x,- y);
     RenderMesh2D(meshes["cioc"], shaders["VertexColor"], modelMatrix);
     modelMatrix = glm::mat3(1);
     modelMatrix *= transform2D::Translate(x+translateX,y+ translateY);
     modelMatrix *= transform2D::Translate(x, y);
     modelMatrix *= transform2D::Scale(scaleX, scaleY);
     modelMatrix *= transform2D::Translate(-x, -y);
     RenderMesh2D(meshes["dreptunghi"], shaders["VertexColor"], modelMatrix);
     modelMatrix = glm::mat3(1);
     if (nr_escaped == 0) {
         RenderMesh2D(meshes["life1"], shaders["VertexColor"], modelMatrix);
         RenderMesh2D(meshes["life2"], shaders["VertexColor"], modelMatrix);
         RenderMesh2D(meshes["life3"], shaders["VertexColor"], modelMatrix);

     }
     else if (nr_escaped == 1) {
         RenderMesh2D(meshes["life1"], shaders["VertexColor"], modelMatrix);
         RenderMesh2D(meshes["life2"], shaders["VertexColor"], modelMatrix);
     }
     else if (nr_escaped == 2) {
         RenderMesh2D(meshes["life1"], shaders["VertexColor"], modelMatrix);
     }
     if (glont == 3) {
         RenderMesh2D(meshes["glont1"], shaders["VertexColor"], modelMatrix);
         RenderMesh2D(meshes["glont2"], shaders["VertexColor"], modelMatrix);
         RenderMesh2D(meshes["glont3"], shaders["VertexColor"], modelMatrix);
     }
     else if (glont == 2) {
         RenderMesh2D(meshes["glont1"], shaders["VertexColor"], modelMatrix);
         RenderMesh2D(meshes["glont2"], shaders["VertexColor"], modelMatrix);
     }
     else if (glont == 1) {
         RenderMesh2D(meshes["glont1"], shaders["VertexColor"], modelMatrix);
     }
     modelMatrix *= transform2D::Translate(950,600);
     modelMatrix *= transform2D::Scale(3, 1);
     modelMatrix *= transform2D::Translate(-950, -600);
     RenderMesh2D(meshes["scor_max"], shaders["VertexColor"], modelMatrix);
     modelMatrix = glm::mat3(1);
     modelMatrix *= transform2D::Translate(950, 600);
     modelMatrix *= transform2D::Scale(Sx, Sy);
     modelMatrix *= transform2D::Translate(-950, -600);
     RenderMesh2D(meshes["scor"], shaders["VertexColor"], modelMatrix);


}
void Tema1::calculate_angle() 
{
    int max = 80, min = 10;
    cadran = rand() % (4 - 1 + 1) + 1;
    //cadran = 1;
    if (cadran == 1) {
        max = 80;
        min = 10;
    }
    else if (cadran == 2) {
        max = 170;
        min = 100;
    }
    else if (cadran == 3) {
        max = 260;
        min = 190;
    }
    else {
        max = 350;
        min = 280;
    }
    angle = rand() % (max - min + 1) + min;
   // cout << angle << endl;
    angle = RADIANS(angle);
    if (cadran == 1) {
        //cout << "Cadran1" << endl;
        x_creste = true;
        y_creste = true;
        translateX = 0;
        translateY = 10;
        alfa = angle;


    }
    else if (cadran == 2) {
       // cout << "Cadran2" << endl;
        x_creste = false;
        y_creste = true;
        translateX = 150;
        translateY = 0;
        alfa = RADIANS(180 - DEGREES(angle));
    }
    else if (cadran == 3) {
       // cout << "Cadran3" << endl;
        x_creste = false;
        y_creste = false;
        translateX = 100;
        translateY = 100;
        alfa = RADIANS(DEGREES(angle) - 180);
    }
    else if (cadran == 4) {
        //cout << "Cadran4" << endl;
        x_creste = true;
        y_creste = false;
        translateX = 30;
        translateY = 100;
        alfa = RADIANS(360 - DEGREES(angle));
    }
    angularStep = 30;
    angularStep2 = 39;
}


void Tema1::FrameEnd()
{
}


/*
 *  These are callback functions. To find more about callbacks and
 *  how they behave, see `input_controller.h`.
 */


void Tema1::OnInputUpdate(float deltaTime, int mods)
{
}


void Tema1::OnKeyPress(int key, int mods)
{
    // Add key press event
}


void Tema1::OnKeyRelease(int key, int mods)
{
    // Add key release event
}


void Tema1::OnMouseMove(int mouseX, int mouseY, int deltaX, int deltaY)
{
    // Add mouse move event
}


void Tema1::OnMouseBtnPress(int mouseX, int mouseY, int button, int mods)
{
    // Add mouse button release event
    if (button == GLFW_MOUSE_BUTTON_2) {
        onclick = true;
        mouseOx = mouseX;
        mouseOy = mouseY;
    }
}


void Tema1::OnMouseBtnRelease(int mouseX, int mouseY, int button, int mods)
{

}


void Tema1::OnMouseScroll(int mouseX, int mouseY, int offsetX, int offsetY)
{
}


void Tema1::OnWindowResize(int width, int height)
{
}
