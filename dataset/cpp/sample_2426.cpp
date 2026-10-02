#include <iostream>
#include <string>
#include <vector>
#include <ast.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

class Linter : public ast::NodeVisitor {
public:
    void visit_FunctionDef(ast::FunctionDef* node) {
        if (node->body.size() > 10) {
            std::cout << "Function '" << node->name << "' exceeds 10 lines." << std::endl;
        }
        this->generic_visit(node);
    }
};

void main() {
    int fd = 0; // stdin
    struct stat sb;
    if (fstat(fd, &sb) == -1) {
        perror("fstat");
        exit(EXIT_FAILURE);
    }

    std::vector<char> buffer(sb.st_size);
    if (read(fd, buffer.data(), sb.st_size) != sb.st_size) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    std::string code(buffer.data(), buffer.size());
    ast::Module* tree = ast::parse(code);
    Linter linter;
    linter.visit(tree);
}

int main() {
    main();
    return 0;
}