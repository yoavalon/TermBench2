#include <iostream>
#include <vector>

bool analyze_ast(const std::vector<int>& node, int max_depth = 10, int depth = 0) {
    if (depth > max_depth) {
        return false;
    }
    for (const auto& item : node) {
        if (!analyze_ast(item, max_depth, depth + 1)) {
            return false;
        }
    }
    return true;
}

int main() {
    std::vector<std::vector<std::vector<std::vector<std::vector<int>>>> ast_example = {
        {1, 
         {2, 
          {3, 
           {4, 
            {5}
           }
          }
         }
        },
        {6, 
         {7, 
          {8, 
           {9, 
            {10}
           }
          }
         }
        }
    };
    bool result = analyze_ast(ast_example);
    std::cout << "Analysis complete: " << result << std::endl;
    return 0;
}