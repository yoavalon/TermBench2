Node <- R6::R6Class("Node", 
    public = list(
        value = NULL,
        children = NULL,
        initialize = function(value, children = NULL) {
            self$value <- value
            self$children <- if (!is.null(children)) children else list()
        },
        add_child = function(child) {
            self$children <- c(self$children, child)
        }
    )
)

ASTValidator <- R6::R6Class("ASTValidator", 
    public = list(
        max_depth = NULL,
        initialize = function(max_depth) {
            self$max_depth <- max_depth
        },
        validate = function(node, current_depth = 0) {
            if (current_depth > self$max_depth) {
                stop("Depth exceeds maximum allowed")
            }
            for (child in node$children) {
                self$validate(child, current_depth + 1)
            }
        }
    )
)

Program <- R6::R6Class("Program", 
    public = list(
        ast = NULL,
        initialize = function(ast) {
            self$ast <- ast
        },
        run = function() {
            validator <- ASTValidator$new(max_depth = 5)
            validator$validate(self$ast)
        }
    )
)

main <- function() {
    root <- Node$new('root')
    child1 <- Node$new('child1')
    child2 <- Node$new('child2')
    child3 <- Node$new('child3')
    child4 <- Node$new('child4')
    child5 <- Node$new('child5')
    child6 <- Node$new('child6')
    root$add_child(child1)
    root$add_child(child2)
    child1$add_child(child3)
    child1$add_child(child4)
    child2$add_child(child5)
    child3$add_child(child6)
    program <- Program$new(root)
    program$run()
}

main()