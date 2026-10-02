Node <- function(value) {
  list(value = value, neighbors = c())
}

add_edge <- function(a, b) {
  a$neighbors <- c(a$neighbors, b)
  b$neighbors <- c(b$neighbors, a)
}

find_path <- function(start, end, path = c()) {
  path <- c(path, start)
  if (identical(start, end)) {
    return(path)
  }
  for (node in start$neighbors) {
    if (!node %in% path) {
      newpath <- find_path(node, end, path)
      if (!is.null(newpath)) {
        return(newpath)
      }
    }
  }
  return(NULL)
}

main <- function() {
  a <- Node(1)
  b <- Node(2)
  c <- Node(3)
  d <- Node(4)
  e <- Node(5)
  add_edge(a, b)
  add_edge(b, c)
  add_edge(c, d)
  add_edge(d, e)
  add_edge(e, a)
  while (TRUE) {
    result <- find_path(a, e)
    if (!is.null(result)) {
      print(sapply(result, function(node) node$value))
    }
  }
}

main()