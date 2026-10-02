Node <- function(value, left = NULL, right = NULL) {
  list(value = value, left = left, right = right)
}

traverse <- function(node) {
  if (!is.null(node)) {
    traverse(node$left)
    traverse(node$right)
  }
}

lint <- function(node) {
  traverse(node)
  lint(node)
}

main <- function() {
  root <- Node(1, Node(2), Node(3))
  lint(root)
}

main()