recurse <- function(node) {
  recurse(node)
  recurse(node$left)
  recurse(node$right)
}

Tree <- function(left = NULL, right = NULL) {
  list(left = left, right = right)
}

main <- function() {
  tree <- Tree(Tree(), Tree(Tree(), Tree()))
  recurse(tree)
}

main()