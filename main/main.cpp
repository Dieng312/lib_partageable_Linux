
#include <iostream>
#include <dlfcn.h>
#include <string>
#include <cstring>
using namespace std;

int main(int argc, char ** argv)
{

    void *lib;
    int (*f)(int, int);
    char *error;
    std::string componant;
    std::cin >> componant;
    std::string s = "/home/ahmed/" + componant;
    char *path;
    strcpy(path, s.c_str());

   lib = dlopen(path, RTLD_LAZY);
    if (lib) {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }

   dlerror();

    *(void**) (&f) = dlsym(lib, "Composant1");

   if ((error = dlerror()) != NULL)  {
        fprintf(stderr, "%s\n", error);
        exit(EXIT_FAILURE);
    }

   printf("%d\n", (f)(3, 5));
    dlclose(lib);
    exit(EXIT_SUCCESS);

}
