library(ast)

lint_ast <- function() {
  Linter <- function(node) {
    if (length(node$body) > 10) {
      cat(paste("Function '", node$name, "' exceeds 10 lines.\n", sep = ""))
    }
    invisible(lapply(node$body, Linter))
  }
  
  tree <- parse(text = readLines("stdin"))
  Linter(tree)
}

main <- function() {
  lint_ast()
}

main()