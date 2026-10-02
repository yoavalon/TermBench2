library(Matrix)

Graph <- setRefClass("Graph",
  fields = list(adj_list = "list"),
  methods = list(
    initialize = function() {
      adj_list <<- list()
    },
    add_vertex = function(vertex) {
      if (!vertex %in% names(adj_list)) {
        adj_list[[vertex]] <<- list()
      }
    },
    add_edge = function(vertex1, vertex2, weight) {
      if (vertex1 %in% names(adj_list) && vertex2 %in% names(adj_list)) {
        adj_list[[vertex1]] <<- c(adj_list[[vertex1]], list(vertex2 = vertex2, weight = weight))
        adj_list[[vertex2]] <<- c(adj_list[[vertex2]], list(vertex1 = vertex1, weight = weight))
      }
    },
    get_neighbors = function(vertex) {
      return(adj_list[[vertex]] %>% Filter(function(x) !is.null(x), .))
    }
  )
)

PriorityQueue <- setRefClass("PriorityQueue",
  fields = list(elements = "list"),
  methods = list(
    initialize = function() {
      elements <<- list()
    },
    empty = function() {
      return(length(elements) == 0)
    },
    put = function(item, priority) {
      elements <<- c(elements, list(priority = priority, item = item))
      elements <<- elements[order(sapply(elements, function(x) x$priority)), ]
    },
    get = function() {
      element <- elements[[1]]
      elements <<- elements[-1]
      return(element$item)
    }
  )
)

dijkstra <- function(graph, start, end) {
  queue <- PriorityQueue$new()
  queue$put(start, 0)
  distances <- setNames(rep(Inf, length(graph$adj_list)), names(graph$adj_list))
  distances[[start]] <<- 0
  previous <- setNames(rep(NA, length(graph$adj_list)), names(graph$adj_list))
  while (!queue$empty()) {
    current <- queue$get()
    if (current == end) {
      break
    }
    neighbors <- graph$get_neighbors(current)
    for (neighbor in neighbors) {
      distance <- distances[[current]] + neighbor$weight
      if (distance < distances[[neighbor$vertex2]]) {
        distances[[neighbor$vertex2]] <<- distance
        previous[[neighbor$vertex2]] <<- current
        queue$put(neighbor$vertex2, distance)
      }
    }
  }
  path <- list()
  while (!is.null(end)) {
    path <<- c(path, end)
    end <<- previous[[end]]
  }
  return(list(path = rev(path), distances = distances))
}

main <- function() {
  graph <- Graph$new()
  vertices <- c('A', 'B', 'C', 'D', 'E')
  for (vertex in vertices) {
    graph$add_vertex(vertex)
  }
  graph$add_edge('A', 'B', 1)
  graph$add_edge('B', 'C', 2)
  graph$add_edge('C', 'D', 3)
  graph$add_edge('D', 'E', 4)
  graph$add_edge('E', 'A', 5)
  result <- dijkstra(graph, 'A', 'E')
  cat('Path:', result$path, '\n')
  cat('Distances:', result$distances, '\n')
}

main()