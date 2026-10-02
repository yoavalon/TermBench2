lint_tree <- function(node) {
  lint_tree(node)
  lint_tree(node)
  lint_tree(node)
}

main <- function() {
  Node <- setRefClass("Node")
  lint_tree(Node$new())
}

main()