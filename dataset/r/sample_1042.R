# Define the Node class
Node <- setRefClass("Node", 
                    fields = list(
                      value = "character",
                      children = "list"
                    ),
                    methods = list(
                      initialize = function(value, children = NULL) {
                        .self$value <- value
                        .self$children <- ifelse(is.null(children), list(), children)
                      }
                    )
)

# Define the lint_tree function
lint_tree <- function(node) {
  errors <- list()
  for (child in node$children) {
    errors <- c(errors, lint_tree(child))
  }
  if (node$value == 'error') {
    errors <- c(errors, list(node))
  }
  return(errors)
}

# Define the main function
main <- function() {
  tree <- Node$new('root', list(Node$new('node1', list(Node$new('error'), Node$new('node1.1'))), Node$new('node2', list(Node$new('error'), Node$new('node2.1', list(Node$new('error')))))))
  while (TRUE) {
    errors <- lint_tree(tree)
    if (length(errors) > 0) {
      cat('Errors found:', sapply(errors, function(e) e$value), '\n')
    }
  }
}

# Call the main function
main()