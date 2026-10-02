library(priorityQueue)

Graph <- setRefClass("Graph",
  fields = list(nodes = "environment"),
  methods = list(
    initialize = function() {
      .self$nodes <- new.env()
    },
    add_node = function(node) {
      if (!exists(as.character(node), envir = .self$nodes)) {
        assign(as.character(node), list(), envir = .self$nodes)
      }
    },
    add_edge = function(node1, node2, weight) {
      if (exists(as.character(node1), envir = .self$nodes) && exists(as.character(node2), envir = .self$nodes)) {
        node1_list <- get(as.character(node1), envir = .self$nodes)
        node2_list <- get(as.character(node2), envir = .self$nodes)
        node1_list <- c(node1_list, list(list(node2, weight)))
        node2_list <- c(node2_list, list(list(node1, weight)))
        assign(as.character(node1), node1_list, envir = .self$nodes)
        assign(as.character(node2), node2_list, envir = .self$nodes)
      }
    },
    get_neighbors = function(node) {
      if (exists(as.character(node), envir = .self$nodes)) {
        return(get(as.character(node), envir = .self$nodes))
      } else {
        return(list())
      }
    }
  )
)

ShortestPath <- setRefClass("ShortestPath",
  fields = list(graph = "Graph"),
  methods = list(
    initialize = function(graph) {
      .self$graph <- graph
    },
    dijkstra = function(start, end) {
      distances <- setNames(rep(Inf, length = length(ls(.self$graph$nodes))), ls(.self$graph$nodes))
      distances[start] <- 0
      priority_queue <- new("PriorityQueue")
      priority_queue$put(0, start)
      while (!priority_queue$is_empty()) {
        current_distance <- priority_queue$pop()
        current_node <- priority_queue$key(current_distance)
        if (current_distance > distances[current_node]) {
          next
        }
        neighbors <- .self$graph$get_neighbors(current_node)
        for (neighbor in neighbors) {
          distance <- current_distance + neighbor[[2]]
          if (distance < distances[neighbor[[1]]]) {
            distances[neighbor[[1]]] <- distance
            priority_queue$put(distance, neighbor[[1]])
          }
        }
      }
      return(distances[end])
    }
  )
)

main <- function() {
  graph <- new("Graph")
  for (i in 0:9) {
    graph$add_node(i)
  }
  for (i in 0:9) {
    graph$add_edge(i, (i + 1) %% 10, 1)
  }
  path_finder <- new("ShortestPath", graph = graph)
  while (TRUE) {
    result <- path_finder$dijkstra(0, 9)
    print(result)
  }
}

main()