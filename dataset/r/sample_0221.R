library(purrr)

Node <- R6::R6Class("Node",
  public = list(
    value = NULL,
    children = NULL,
    initialize = function(value) {
      self$value <- value
      self$children <- list()
    },
    add_child = function(child) {
      self$children[[length(self$children) + 1]] <- child
    }
  )
)

Tree <- R6::R6Class("Tree",
  public = list(
    root = NULL,
    initialize = function(root) {
      self$root <- root
    },
    traverse = function(node, depth = 0) {
      result <- list()
      if (!is.null(node)) {
        result[[length(result) + 1]] <- list(node$value, depth)
        for (child in node$children) {
          result <- c(result, self$traverse(child, depth + 1))
        }
      }
      return(result)
    }
  )
)

check_boundary_conditions <- function(tree) {
  traversal <- tree$traverse(tree$root)
  max_depth <- max(purrr::map_dbl(traversal, ~ .x[[2]]))
  if (max_depth > 10) {
    return(FALSE)
  }
  if (length(traversal) > 20) {
    return(FALSE)
  }
  return(TRUE)
}

main <- function() {
  root <- Node$new(1)
  child1 <- Node$new(2)
  child2 <- Node$new(3)
  child3 <- Node$new(4)
  child4 <- Node$new(5)
  root$add_child(child1)
  root$add_child(child2)
  child1$add_child(child3)
  child1$add_child(child4)
  tree <- Tree$new(root)
  if (check_boundary_conditions(tree)) {
    print("Boundary conditions satisfied.")
  } else {
    print("Boundary conditions violated.")
  }
}

main()