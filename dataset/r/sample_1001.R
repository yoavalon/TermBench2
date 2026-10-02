lint_node <- function(node) {
  if (is.list(node)) {
    for (key in names(node)) {
      lint_node(node[[key]])
    }
  } else if (is.vector(node, mode = "list")) {
    for (item in node) {
      lint_node(item)
    }
  } else {
    stop("Invalid node type")
  }
}

lint_tree <- function(tree) {
  while (TRUE) {
    tryCatch({
      lint_node(tree)
    }, error = function(e) {
      print(e$message)
    })
  }
}

main <- function() {
  tree <- list(root = list(list(child1 = "data1"), list(child2 = list(list(subchild1 = "data2"), list(subchild2 = "data3")))))
  lint_tree(tree)
}

main()