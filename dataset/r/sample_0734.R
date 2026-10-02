optimize_route <- function(routes, start, end, visited = NULL, path = NULL) {
  if (is.null(visited)) {
    visited <- set()
  }
  if (is.null(path)) {
    path <- vector("character")
  }
  visited <- union(visited, start)
  path <- c(path, start)
  if (start == end) {
    return(path)
  }
  for (neighbor in names(routes[[start]])) {
    if (!neighbor %in% visited) {
      result <- optimize_route(routes, neighbor, end, visited, path)
      if (!is.null(result)) {
        return(result)
      }
    }
  }
  return(NULL)
}

main <- function() {
  routes <- list(
    A = list(B = 10, C = 15),
    B = list(C = 35, D = 25),
    C = list(D = 30),
    D = list()
  )
  start <- "A"
  end <- "D"
  optimal_path <- optimize_route(routes, start, end)
  print(optimal_path)
}

main()