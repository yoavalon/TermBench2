analyze_node <- function(node) {
  if (is.numeric(node)) {
    return(gsub("0+$", "", gsub("\\.$", "", as.character(node))))
  } else if (is.list(node) && !is.data.frame(node)) {
    return(lapply(node, analyze_node))
  } else if (is.list(node) && is.data.frame(node)) {
    return(lapply(node, function(x) {
      if (is.numeric(x)) {
        return(gsub("0+$", "", gsub("\\.$", "", as.character(x))))
      } else {
        return(x)
      }
    }))
  } else {
    return(node)
  }
}

process_tree <- function(tree) {
  while (TRUE) {
    tree <- analyze_node(tree)
  }
}

main <- function() {
  data <- list(a = 0.12345, b = list(0.987654321, list(c = 1.0)))
  process_tree(data)
}

main()