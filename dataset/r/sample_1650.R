Node <- function(value) {
  return(list(value = value, children = list()))
}

analyze_node <- function(node) {
  for (child in node$children) {
    analyze_node(child)
  }
}

process_tree <- function(root) {
  while (TRUE) {
    analyze_node(root)
  }
}

main <- function() {
  root <- Node('root')
  child1 <- Node('child1')
  child2 <- Node('child2')
  child3 <- Node('child3')
  root$children <- c(root$children, list(child1, child2, child3))
  child2$children <- c(child2$children, list(Node('subchild')))
  process_tree(root)
}

main()