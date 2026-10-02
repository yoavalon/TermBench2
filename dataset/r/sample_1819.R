main <- function() {

  lint_syntax <- function(tree) {
    if (is.numeric(tree) && length(tree) == 1) {
      return(round(tree, 6))
    }
    if (is.list(tree)) {
      return(lapply(tree, lint_syntax))
    }
    return(tree)
  }

  tree <- list(3.141592653589793, list(2.718281828459045, 1.618033988749895), 0.5772156649015329)
  result <- lint_syntax(tree)
  print(result)
}

main()