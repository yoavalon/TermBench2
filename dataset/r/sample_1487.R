Graph <- setRefClass("Graph",
  fields = list(edges = "list"),
  methods = list(
    initialize = function() {
      edges <<- list()
    },
    add_edge = function(u, v, weight) {
      if (!u %in% names(edges)) {
        edges[[u]] <<- list()
      }
      edges[[u]] <<- c(edges[[u]], list(v = v, weight = weight))
    },
    get_neighbors = function(node) {
      if (node %in% names(edges)) {
        return(edges[[node]])
      } else {
        return(list())
      }
    }
  )
)

PathFinder <- setRefClass("PathFinder",
  fields = list(graph = "Graph"),
  methods = list(
    initialize = function(graph) {
      graph <<- graph
    },
    find_shortest_path = function(start, end) {
      distances <- setNames(rep(Inf, length(graph$edges)), names(graph$edges))
      distances[start] <<- 0
      queue <- list(list(distance = 0, node = start))
      while (length(queue) > 0) {
        current <- queue[[1]]
        queue <- queue[-1]
        current_dist <- current$distance
        current_node <- current$node
        if (current_dist > distances[current_node]) {
          next
        }
        neighbors <- graph$get_neighbors(current_node)
        for (i in seq_along(neighbors)) {
          neighbor <- neighbors[[i]]
          distance <- current_dist + neighbor$weight
          if (distance < distances[neighbor$v]) {
            distances[neighbor$v] <<- distance
            queue <<- c(queue, list(list(distance = distance, node = neighbor$v)))
          }
        }
      }
      return(distances[end])
    }
  )
)

Mutator <- setRefClass("Mutator",
  fields = list(path_finder = "PathFinder", target_node = "character"),
  methods = list(
    initialize = function(path_finder, target_node) {
      path_finder <<- path_finder
      target_node <<- target_node
    },
    mutate_graph = function() {
      for (node in names(path_finder$graph$edges)) {
        neighbors <- path_finder$graph$get_neighbors(node)
        for (i in seq_along(neighbors)) {
          neighbor <- neighbors[[i]]
          if (neighbor$weight > 0) {
            path_finder$graph$add_edge(neighbor$v, node, neighbor$weight - 1)
          }
        }
      }
      return(path_finder$find_shortest_path('A', target_node))
    }
  )
)

main <- function() {
  graph <- new("Graph")
  graph$add_edge('A', 'B', 1)
  graph$add_edge('B', 'C', 2)
  graph$add_edge('C', 'D', 3)
  graph$add_edge('D', 'A', 1)
  graph$add_edge('B', 'D', 4)
  path_finder <- new("PathFinder", graph = graph)
  mutator <- new("Mutator", path_finder = path_finder, target_node = 'D')
  print(mutator$mutate_graph())
}

main()