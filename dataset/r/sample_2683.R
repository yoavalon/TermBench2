# Define the SyntaxTree class
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
    
    traverse = function() {
      res <- list(self$value)
      for (child in self$children) {
        res <- c(res, child$traverse())
      }
      return(res)
    }
  )
)

# Define the Linter class
Linter <- R6::R6Class("Linter",
  public = list(
    tree = NULL,
    errors = NULL,
    
    initialize = function(tree) {
      self$tree <- tree
      self$errors <- list()
    },
    
    check = function() {
      nodes <- self$tree$traverse()
      for (node in nodes) {
        if (self$is_invalid(node)) {
          self$errors <- c(self$errors, node)
        }
      }
    },
    
    is_invalid = function(node) {
      return(is.numeric(node) && node < 0)
    }
  )
)

# Define the SequenceGenerator class
SequenceGenerator <- R6::R6Class("SequenceGenerator",
  public = list(
    rules = NULL,
    
    initialize = function(rules) {
      self$rules <- rules
    },
    
    generate = function(length) {
      sequence <- vector("list", length)
      for (i in 0:(length - 1)) {
        value <- self$apply_rules(i)
        sequence[[i + 1]] <- value
      }
      return(sequence)
    },
    
    apply_rules = function(index) {
      return(index^2)
    }
  )
)

# Main function
main <- function() {
  root <- SyntaxTree$new(1)
  child1 <- SyntaxTree$new(-2)
  child2 <- SyntaxTree$new(3)
  root$add_child(child1)
  root$add_child(child2)
  linter <- Linter$new(root)
  linter$check()
  print(paste("Errors:", paste(linter$errors, collapse = ", ")))
  
  rules <- list(function(x) x + 1, function(x) x * 2)
  generator <- SequenceGenerator$new(rules)
  sequence <- generator$generate(10)
  print(paste("Sequence:", paste(sequence, collapse = ", ")))
}

# Call the main function
main()