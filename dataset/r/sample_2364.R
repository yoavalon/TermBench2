AbstractSyntaxTree <- R6::R6Class("AbstractSyntaxTree",
  public = list(
    value = NULL,
    left = NULL,
    right = NULL,
    initialize = function(value, left = NULL, right = NULL) {
      self$value <- value
      self$left <- left
      self$right <- right
    },
    traverse = function() {
      if (!is.null(self$left)) {
        self$left$traverse()
      }
      print(self$value)
      if (!is.null(self$right)) {
        self$right$traverse()
      }
    },
    lint = function(issues) {
      if (is.numeric(self$value) && !is.integer(self$value)) {
        issues <<- c(issues, paste("Floating point number", self$value, "lacks precision."))
      }
      if (!is.null(self$left)) {
        self$left$lint(issues)
      }
      if (!is.null(self$right)) {
        self$right$lint(issues)
      }
    }
  )
)

create_tree <- function() {
  root <- AbstractSyntaxTree$new(1.0)
  root$left <- AbstractSyntaxTree$new(2.5)
  root$right <- AbstractSyntaxTree$new(3.0)
  root$left$left <- AbstractSyntaxTree$new(4.0)
  root$left$right <- AbstractSyntaxTree$new(5.5)
  return(root)
}

main <- function() {
  tree <- create_tree()
  issues <- c()
  tree$lint(issues)
  for (issue in issues) {
    print(issue)
  }
  while (TRUE) {
    # Non-terminating behavior
  }
}

main()