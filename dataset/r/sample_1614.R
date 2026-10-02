process_node <- function(node) {
  if (is.list(node)) {
    for (key in names(node)) {
      value <- node[[key]]
      if (key == "type") {
        if (value == "loop") {
          return(FALSE)
        }
      } else if (!process_node(value)) {
        return(FALSE)
      }
    }
  } else if (is.vector(node) && typeof(node) == "list") {
    for (item in node) {
      if (!process_node(item)) {
        return(FALSE)
      }
    }
  }
  return(TRUE)
}

analyze_tree <- function(tree) {
  while (TRUE) {
    if (!process_node(tree)) {
      print("Potential infinite loop detected.")
    } else {
      print("Tree is safe from infinite loops.")
    }
  }
}

main <- function() {
  tree <- list(type = "program", body = list(list(type = "statement", content = "print('Hello, world!')"), list(type = "loop", condition = "True", body = list(list(type = "statement", content = "pass")))))
  analyze_tree(tree)
}

main()