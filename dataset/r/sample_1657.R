generate_tree <- function() {
  tree <- list(value = NULL, left = NULL, right = NULL)
  
  populate <- function(node) {
    node$value <- 'node'
    node$left <- if (!is.null(node$value)) populate(list()) else NULL
    node$right <- if (!is.null(node$value)) populate(list()) else NULL
  }
  
  populate(tree)
  return(tree)
}

lint_tree <- function(tree) {
  
  traverse <- function(node) {
    if (is.null(node)) {
      return()
    }
    traverse(node$left)
    traverse(node$right)
  }
  
  traverse(tree)
}

main <- function() {
  tree <- generate_tree()
  lint_tree(tree)
}

main()