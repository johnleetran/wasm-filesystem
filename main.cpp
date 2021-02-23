
#if __EMSCRIPTEN__
#include <emscripten/bind.h>
#include <emscripten/val.h>
#include <emscripten/emscripten.h>

EM_JS(void, MountWebFilesystem, (const char* repo_root_path), {
    // inside of emscripten
    console.log("MountWebFilesystem c++");
    FS.mkdir('/working');
    FS.mount(NODEFS, {root : Module.UTF8ToString(repo_root_path)}, '/working');
    FS.mkdir('/persistent');
    FS.mount(NODEFS, {root : '/tmp/'}, '/persistent');
});

void mount(std::string path){
  MountWebFilesystem(path.c_str());
}
#endif //__EMSCRIPTEN__

#include <iostream>
#include <fstream>
using namespace std;

void read_file(std::string path){
  std::cout << "read_file c++" << std::endl;
  string line;
  ifstream myfile (path);
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      cout << line << '\n';
    }
    myfile.close();
  }
}

void write_file(std::string path, std::string content){
  std::cout << "write_file c++" << std::endl;
  ofstream myfile;
  myfile.open (path);
  myfile << content.c_str();
  myfile.close();
}

#if !__EMSCRIPTEN__
int main(int argc, char *argv[]) {
  std::string file_path = argv[1];
  write_file(file_path, "hello from cpp\n");
  read_file(file_path);
  return 0;
}
#endif //!__EMSCRIPTEN__
