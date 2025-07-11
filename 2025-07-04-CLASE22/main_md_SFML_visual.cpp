// g++ -std=c++17 -g particle.cpp main_md_SFML_visual.cpp -lsfml-window -lsfml-graphics -lsfml-system
#include "particle.h"
#include "integrator.h"
#include "collider.h"
#include "boundary.h"
#include <vector>
#include <random>

#include <SFML/Graphics.hpp>

void initial_conditions(std::vector<Particle> & particles);

int main(int argc, char **argv) {
  const int N = 4;
  std::vector<Particle> bodies;
  bodies.resize(N); // only one particle for now

  // parameters
  std::map<std::string, double> p;
  p["T0"] = 0.0;
  p["TF"] = 50.8767;
  p["DT"] = 0.001;
  p["G"] = -9.81; //-9.81;
  p["k"] = 2600.543;

  // window
  const int WIDTH = 800, HEIGHT = 600;
  const float METERS_TO_PIXELS = 100.0f; // 200 pixels per meter
  
  // Force collider
  Collider collider(p);

  // Time initialization
  TimeIntegrator integrator(p["DT"]);

  // Boundary conditions
  Boundary bc(2.345, 0.0, 0.0, 0.0, 1.0, 0.9); // RMAX, CX, CY, CZ, EN, ET

  // initial conditions and properties
  initial_conditions(bodies);
  collider.computeForces(bodies); // force at t = 0
  integrator.startIntegration(bodies); // start integration algorithm
  std::cout << p["T0"] << "\t";
  bodies[0].print();
  std::cout << "\n";
  std::cout << p["T0"] << "\t";
  bodies[1].print();
  std::cout << "\n";

  // --- VISUALIZATION SETUP ---
  sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "C++ Simulation & Visualization");
  window.setFramerateLimit(240);
  sf::CircleShape particle_shape(bodies[0].rad);
  particle_shape.setFillColor(sf::Color::Cyan);
  particle_shape.setOrigin(0, 0);

  // color setup
  // create array for RGB
  std::vector<sf::Uint8> R(N, 0), G(N, 0), B(N, 0);

  //random fill
  const int seed = std::stoi(argv[1]);
  std::mt19937 eng(seed);
  std::uniform_int_distribution<sf::Uint8> dist(0, 255);
  for (int ip = 0; ip < N; ip++) R[ip] = dist(eng);
  for (int ip = 0; ip < N; ip++) G[ip] = dist(eng);
  for (int ip = 0; ip < N; ip++) B[ip] = dist(eng);

  // Time iteration
  const int niter = int((p["TF"] - p["T0"])/p["DT"]);
  for(int ii = 1; ii < niter && window.isOpen(); ++ii) {
    // check close event
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) window.close();
    }
    // md simul
    collider.computeForces(bodies);
    integrator.timeStep(bodies);
    bc.apply(bodies);

    // 2. Run the C++ visualization
    window.clear(sf::Color::Black);
    int ip = 0;
    for (const auto& p : bodies) {
      float pixel_radius = p.rad * METERS_TO_PIXELS;
      // Set the radius for this specific particle, scaled to pixels
      particle_shape.setRadius(pixel_radius);
      // Center the origin so setPosition() refers to the center of the circle
      particle_shape.setOrigin(pixel_radius, pixel_radius);
      // color
      sf::Color c = {R[ip], G[ip], B[ip]};
      particle_shape.setFillColor(c);

      // Convert world coordinates to screen coordinates
      sf::Vector2f screen_pos;
      screen_pos.x = (WIDTH / 2.0f) + (p.R[0] * METERS_TO_PIXELS);
      // Flip the Y-axis: (HEIGHT - world_y_in_pixels)
      screen_pos.y = (HEIGHT / 2.0f) - (p.R[2] * METERS_TO_PIXELS);
      
      particle_shape.setPosition(screen_pos);
      window.draw(particle_shape);
      ip++;
    }
    window.display();

    // // print local info
    // double time = p["T0"] + ii*p["DT"];
    // std::cout << time << "\t";
    // bodies[0].print();
    // std::cout << "\n";
  }

  return 0;
}

void initial_conditions(std::vector<Particle> & particles)
{
  particles[0].R[2] = 0.987;  // z is upwards, x to the right
  particles[0].V[0] = 4.9876;//12.987; // z is upwards, x to the right
  particles[0].V[2] = 0.0; //4.9876; //3.987; // z is upwards, x to the right
  particles[0].rad  = 0.103;
  particles[0].mass = 0.337;

  particles[1].R[2] = -0.287;  // z is upwards, x to the right
  particles[1].V[0] = 2.9876;//12.987; // z is upwards, x to the right
  particles[1].V[2] = 3.3457; //4.9876; //3.987; // z is upwards, x to the right
  particles[1].rad  = 0.153;
  particles[1].mass = 0.337;

  particles[2].R[2] = 0.187;  // z is upwards, x to the right
  particles[2].V[0] = 4.9876;//12.987; // z is upwards, x to the right
  particles[2].V[2] = 2.0; //4.9876; //3.987; // z is upwards, x to the right
  particles[2].rad  = 0.83;
  particles[2].mass = 0.137;

  particles[3].R[2] = -0.987;  // z is upwards, x to the right
  particles[3].V[0] = 4.9876;//12.987; // z is upwards, x to the right
  particles[3].V[2] = 6.9458; //4.9876; //3.987; // z is upwards, x to the right
  particles[3].rad  = 0.303;
  particles[3].mass = 0.437;
}