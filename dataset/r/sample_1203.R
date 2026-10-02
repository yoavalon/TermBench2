process_tree <- function(node) {
  if (is.null(node)) {
    return()
  }
  process_tree(node$left)
  process_tree(node$right)
}

main <- function() {
  root <- NULL
  process_tree(root)
}

main()