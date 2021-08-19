
// C++ Includes
#include <string>
#include <stdexcept>

// OpenGL
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main() {

  /* GLFW library initialisieren */
  if (!glfwInit()) {
    throw std::runtime_error("glfwInit() fails");
  }

  uint32_t gl_major{4};
  uint32_t gl_minor{6};
  uint32_t gl_samples{8};

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, gl_major);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, gl_minor);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_SAMPLES, gl_samples);
  glfwWindowHint(GLFW_VISIBLE, GLFW_TRUE);

  uint32_t width{1280};
  uint32_t height{1024};
  bool fullscreen{false};
  std::string title{"Simple Renderkontext"};

  /* OpenGL Renderfenster erstellen */
  GLFWwindow *window = glfwCreateWindow(width, height,
                            title.c_str(),
                            fullscreen ? glfwGetPrimaryMonitor() : nullptr, nullptr);
  if (!window) {
    glfwTerminate();
    throw std::runtime_error("glfwCreateWindow() fails");
  }

  /* erstelltes Fenster als aktuellen OpenGL Kontext festlegen */
  glfwMakeContextCurrent(window);

  /* GLAD Library initialisieren */
  if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
    glfwTerminate();
    throw std::runtime_error("GLAD Init() fails");
  }
  /* OpenGL Fehlerliste zurücksetzen */
  glGetError();

  /* solange wiederholen bis das Fenster geschlossen wird */
  while (!glfwWindowShouldClose(window)) {
    /* zeichnen */
    glClear(GL_COLOR_BUFFER_BIT);

    /* Hintergrund und Vordergrund tauschen*/
    glfwSwapBuffers(window);

    /* Ereignisse abholen */
    glfwPollEvents();
  }

  glfwTerminate();

  return EXIT_SUCCESS;
}