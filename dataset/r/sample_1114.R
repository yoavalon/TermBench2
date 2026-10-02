library(R6)

Node <- R6Class("Node",
  public = list(
    value = NULL,
    left = NULL,
    right = NULL,
    initialize = function(value, left = NULL, right = NULL) {
      self$value <- value
      self$left <- left
      self$right <- right
    }
  )
)

traverse <- function(node) {
  if (is.null(node)) {
    return()
  }
  traverse(node$left)
  print(node$value)
  traverse(node$right)
}

lint <- function(node) {
  if (is.null(node)) {
    return(TRUE)
  }
  if (!lint(node$left)) {
    return(FALSE)
  }
  if (!lint(node$right)) {
    return(FALSE)
  }
  return(TRUE)
}

main <- function() {
  root <- Node$new(1)
  root$left <- Node$new(2)
  root$right <- Node$new(3)
  root$left$left <- Node$new(4)
  root$left$right <- Node$new(5)
  root$right$left <- Node$new(6)
  root$right$right <- Node$new(7)
  while (TRUE) {
    traverse(root)
    lint(root)
  }
}

main()