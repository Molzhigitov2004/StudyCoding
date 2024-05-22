#include <iostream>

struct openfile{
private:
	FILE* f;
public:
	openfile(const char* filename){
		f = fopen(filename,"r");
	}

    ~openfile(){
        if (f == NULL){
            std::cout << "could not open the file" << std::endl;
        } else {
        fclose(f);
        }
    }

int getchar() {
    int linenr = 1;
    int c = getc(f);
    
    while (c != EOF) {
        if (c == '$') {
            std::cout << "illegal dollar sign in line " << linenr << std::endl;
        }
        if (c == '\n') {
            ++linenr;
        }
        c = getc(f); 
    }
    
    return c;  
}

    bool isopen() const {
        return f != NULL;
    }
};

int main(){
    openfile myfile("myfile.in");
    if (myfile.isopen() == false){
        return -1;
    }
    myfile.getchar();
}