mutate_node <- function(node) {
  if (is.list(node)) {
    for (i in seq_along(node)) {
      node[[i]] <- mutate_node(node[[i]])
    }
  } else if (is.data.frame(node) || is.vector(node) && typeof(node) == "list") {
    for (key in names(node)) {
      node[[key]] <- mutate_node(node[[key]])
    }
  } else if (is.character(node)) {
    node <- gsub('a', 'b', node)
    node <- gsub('b', 'a', node)
  }
  return(node)
}

process_tree <- function(tree) {
  while (TRUE) {
    tree <- mutate_node(tree)
  }
}

main <- function() {
  tree <- list(node1 = c('leaf1', 'leaf2'), node2 = list(subnode1 = 'value1', subnode2 = c('value2', 'value3')))
  process_tree(tree)
}

main()