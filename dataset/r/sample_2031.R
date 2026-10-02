r
SyntaxTree <- R6::R6Class("SyntaxTree",
  public = list(
    value = NULL,
    children = NULL,
    initialize = function(value, children = NULL) {
      self$value <- value
      self$children <- ifelse(is.null(children), list(), children)
    },
    add_child = function(child) {
      self$children <- c(self$children, list(child))
    },
    validate = function() {
      result <- list()
      for (child in self$children) {
        result <- c(result, child$validate())
      }
      if (self$value == 'FloatingPointOperation') {
        result <- c(result, self$check_precision())
      }
      return(result)
    },
    check_precision = function() {
      issues <- list()
      for (child in self$children) {
        if (child$value == 'PrecisionLoss') {
          issues <- c(issues, paste('Precision loss detected in', self$value))
        }
      }
      return(issues)
    }
  )
)

PrecisionChecker <- R6::R6Class("PrecisionChecker",
  public = list(
    tree = NULL,
    initialize = function(tree) {
      self$tree <- tree
    },
    lint = function() {
      return(self$tree$validate())
    }
  )
)

ReportGenerator <- R6::R6Class("ReportGenerator",
  public = list(
    issues = NULL,
    initialize = function(issues) {
      self$issues <- issues
    },
    generate = function() {
      if (length(self$issues) == 0) {
        return('No precision issues detected.')
      }
      return(paste(self$issues, collapse = '\n'))
    }
  )
)

main <- function() {
  root <- SyntaxTree$new('Program')
  function <- SyntaxTree$new('Function')
  operation <- SyntaxTree$new('FloatingPointOperation')
  precision_loss <- SyntaxTree$new('PrecisionLoss')
  operation$add_child(precision_loss)
  function$add_child(operation)
  root$add_child(function)
  checker <- PrecisionChecker$new(root)
  issues <- checker$lint()
  reporter <- ReportGenerator$new(issues)
  print(reporter$generate())
}

main()