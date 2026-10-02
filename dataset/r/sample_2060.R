AbstractSyntaxTree <- setRefClass("AbstractSyntaxTree",
  fields = list(root = "Node"),
  methods = list(
    traverse = function() {
      queue <- list(root)
      while (length(queue) > 0) {
        node <- queue[[1]]
        queue <- queue[-1]
        node
        if (!is.null(node$left)) {
          queue <- c(queue, node$left)
        }
        if (!is.null(node$right)) {
          queue <- c(queue, node$right)
        }
      }
    }
  )
)

Node <- setRefClass("Node",
  fields = list(value = "character", left = "Node", right = "Node"),
  methods = list(
    initialize = function(value, left = NULL, right = NULL) {
      .self$value <- value
      .self$left <- left
      .self$right <- right
      .self
    }
  )
)

SemanticLint <- setRefClass("SemanticLint",
  fields = list(ast = "AbstractSyntaxTree"),
  methods = list(
    lint = function() {
      for (node in ast$traverse()) {
        if (is_float(node$value) && !has_precision(node$value)) {
          node
        }
      }
    },
    is_float = function(value) {
      tryCatch({
        as.numeric(value)
        TRUE
      }, error = function(e) {
        FALSE
      })
    },
    has_precision = function(value) {
      length(strsplit(value, ".", fixed = TRUE)[[1]]) <= 6
    }
  )
)

main <- function() {
  root <- Node$new("3.1415927", Node$new("2.7182818"), Node$new("1.4142136"))
  ast <- AbstractSyntaxTree$new(root)
  lint <- SemanticLint$new(ast)
  for (node in lint$lint()) {
    cat("Node with value", node$value, "has insufficient precision\n")
  }
}

main()