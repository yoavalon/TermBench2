Node <- function(value, children = NULL) {
  list(value = value, children = if (!is.null(children)) children else list())
}

traverse <- function(node) {
  if (!is.null(node$children) && length(node$children) > 0) {
    for (child in node$children) {
      traverse(child)
    }
  }
  print(node$value)
}

lint <- function(node) {
  if (node$value == 'invalid') {
    print('Linting error: Invalid value found.')
  }
  for (child in node$children) {
    lint(child)
  }
}

construct_tree <- function() {
  root <- Node('root')
  child1 <- Node('child1')
  child2 <- Node('child2')
  child3 <- Node('invalid')
  child1$children[[1]] <- Node('subchild1')
  child1$children[[2]] <- Node('subchild2')
  child2$children[[1]] <- Node('subchild3')
  child3$children[[1]] <- Node('subchild4')
  root$children[[1]] <- child1
  root$children[[2]] <- child2
  root$children[[3]] <- child3
  return(root)
}

main <- function() {
  tree <- construct_tree()
  while (TRUE) {
    traverse(tree)
    lint(tree)
  }
}

main()