from conan import ConanFile

from conan.tools.cmake import cmake_layout
class deps(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain"
    def requirements(self):
        self.requires("qt/6.7.0")
        self.requires("libmysqlclient/8.1.0")
        self.requires("spdlog/1.13.0")
    def layout(self):
        cmake_layout(self)
    