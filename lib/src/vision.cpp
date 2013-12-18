#include <vision.hpp>
#include <camera.hpp>

#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cmath>
#include <glm/glm.hpp>

static const Uint32 FRAMERATE_MILLISECONDS = 1000 / 60;
namespace gca {
	void drawAxis (){
		glBegin(GL_LINES);
			glColor3ub(0, 255 ,0);
			glVertex3f(0,0,0);
			glVertex3f(0,1,0);
			glColor3ub(255, 0 ,0);
			glVertex3f(0,0,0);
			glVertex3f(1,0,0);
			glColor3ub(0,0,255);
			glVertex3f(0,0,0);
			glVertex3f(0,0,1);
		glEnd();
	}

	void draw(const GCA_vector& point){
		glBegin(GL_POINTS);
			glColor3ub(255,0,0);
			glVertex4f(point.get(e1).value(), point.get(e2).value(), point.get(e3).value(), point.get(e4).value());				 
		glEnd();
	}

	void draw(const GCA_bivector& droite){
		glBegin(GL_LINES);
			glColor3ub(0,0,255);
			glVertex3f(droite.get(e14).value(), droite.get(e24).value(), droite.get(e34).value());				 
			glVertex3f(-droite.get(e23).value(), droite.get(e13).value(), -droite.get(e12).value());				 

		glEnd();			 

	}

	void draw(const GCA_trivector& plan){
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glBegin(GL_QUADS);
			glColor3ub(0,255,0);


			float x = plan.get(e234).value(), y= -plan.get(e134).value(), z=plan.get(e124).value();
			float w = plan.get(e123).value();
			float dist = sqrt(x*x+y*y+z*z);
			float x2 = x/dist*w;
			float y2 = y/dist*w;
			float z2 = z/dist*w;
			glm::vec3 n(x,y,z);
			glm::vec3 a = glm::normalize(glm::cross(n,glm::vec3(z,x,y)));
			glm::vec3 b = glm::normalize(glm::cross(n,a));

			for(int i = -5; i<5; ++i) {
				for(int j = -5;j<5; ++j) {
					glVertex3f(x2+a.x*i+b.x*j, y2+a.y*i+b.y*j, z2+a.z*i+b.z*j);
					glVertex3f(x2+a.x*(i+1)+b.x*j, y2+a.y*(i+1)+b.y*j, z2+a.z*(i+1)+b.z*j);
					glVertex3f(x2+a.x*(i+1)+b.x*(j+1), y2+a.y*(i+1)+b.y*(j+1), z2+a.z*(i+1)+b.z*(j+1));
					glVertex3f(x2+a.x*i+b.x*(j+1), y2+a.y*i+b.y*(j+1), z2+a.z*i+b.z*(j+1));
				}
			}
			

		glEnd();
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}

	Visualiseur::Visualiseur(int width, int height){
		if(-1 == SDL_Init(SDL_INIT_VIDEO)) {
			fprintf(stderr, "Impossible d'initialiser la SDL. Fin du programme.\n");
			exit(-1);
		}

		if(NULL == SDL_SetVideoMode(width, height, 32, SDL_OPENGL | SDL_RESIZABLE)) {
			fprintf(stderr, "Impossible d'ouvrir la fenetre. Fin du programme.\n");
			exit(-1);
		}

		glViewport(0, 0, width, height);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(70, (double)width/height, 1, 1000);

		glClear(GL_COLOR_BUFFER_BIT);
		SDL_GL_SwapBuffers();

		glPointSize(15.f);

		SDL_WM_SetCaption("GrassmannCayley", NULL);
	}

	int Visualiseur::render(){
		Camera camera;
		int loop = 1;
		while(loop){
			glClearColor(0, 0, 0, 0);
			Uint32 startTime = SDL_GetTicks();
			glClear(GL_COLOR_BUFFER_BIT);
				
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			camera.draw();

			//Dessin
			drawAxis();
			for (size_t i=0; i<vectors.size(); i++){
				draw(vectors[i]);
			}
			for (size_t i=0; i<bivectors.size(); i++){
				draw(bivectors[i]);
			}
			for (size_t i=0; i<trivectors.size(); i++){
				draw(trivectors[i]);
			}

			SDL_GL_SwapBuffers();
		
			SDL_Event e;
			while(SDL_PollEvent(&e)) {
				switch(e.type) {
					case SDL_QUIT:
						loop = 0;
						break;
					
					case SDL_MOUSEMOTION:
						if(SDL_GetMouseState(NULL, NULL)&SDL_BUTTON(3)){
							//std::cout << e.motion.xrel*0.3f << std::endl;
							camera.rotateLeft(e.motion.xrel*0.3f);
							camera.rotateUp(e.motion.yrel*0.3f);
						}		
						break;
					
					case SDL_KEYDOWN:
						switch(e.key.keysym.sym){
							case SDLK_z:
								camera.moveFront(0.1f);
								break;

							case SDLK_s:
								camera.moveFront(-0.1f);
								break;

							default:
								break;
						}
						break;

					default:
						break;
				}
			}

			Uint32 elapsedTime = SDL_GetTicks() - startTime;
			if(elapsedTime < FRAMERATE_MILLISECONDS) {
				SDL_Delay(FRAMERATE_MILLISECONDS - elapsedTime);
			}

		}

		SDL_Quit();

		return 0;
	}

	void Visualiseur::addVector(const GCA_vector& v){
		vectors.push_back(v);
	}

	void Visualiseur::addBiVector(const GCA_bivector& b){
		bivectors.push_back(b);
	}

	void Visualiseur::addTriVector(const GCA_trivector& t){
		trivectors.push_back(t);
	}
}