library(methods)

Graph <- setRefClass("Graph",
                    fields = list(nodes = "list", edges = "list"),
                    methods = list(
                      initialize = function(nodes) {
                        .self$nodes <- nodes
                        .self$edges <- list()
                      },
                      add_edge = function(u, v, weight) {
                        if (is.null(.self$edges[[u]])) {
                          .self$edges[[u]] <- list()
                        }
                        .self$edges[[u]] <- c(.self$edges[[u]], list(v = v, weight = weight))
                        
                        if (is.null(.self$edges[[v]])) {
                          .self$edges[[v]] <- list()
                        }
                        .self$edges[[v]] <- c(.self$edges[[v]], list(v = u, weight = weight))
                      }
                    )
)

PriorityQueue <- setRefClass("PriorityQueue",
                          fields = list(elements = "list"),
                          methods = list(
                            initialize = function() {
                              .self$elements <- list()
                            },
                            add = function(item, priority) {
                              .self$elements <- c(.self$elements, list(priority = priority, item = item))
                              .self$elements <- .self$elements[order(sapply(.self$elements, function(x) x$priority)), ]
                            },
                            remove = function() {
                              removed_item <- .self$elements[[1]]$item
                              .self$elements <- .self$elements[-1]
                              return(removed_item)
                            },
                            empty = function() {
                              return(length(.self$elements) == 0)
                            }
                          )
)

dijkstra <- function(graph, start, end) {
  queue <- PriorityQueue$new()
  queue$add(start, 0)
  came_from <- list()
  cost_so_far <- list()
  cost_so_far[[start]] <- 0
  
  while (!queue$empty()) {
    current <- queue$remove()
    if (current == end) {
      break
    }
    
    neighbors <- graph$edges[[current]]
    if (!is.null(neighbors)) {
      for (neighbor in neighbors) {
        new_cost <- cost_so_far[[current]] + neighbor$weight
        if (is.null(cost_so_far[[neighbor$v]]) || new_cost < cost_so_far[[neighbor$v]]) {
          cost_so_far[[neighbor$v]] <- new_cost
          priority <- new_cost
          queue$add(neighbor$v, priority)
          came_from[[neighbor$v]] <- current
        }
      }
    }
  }
  
  return(list(came_from, cost_so_far))
}

reconstruct_path <- function(came_from, start, end) {
  path <- list()
  current <- end
  while (current != start) {
    path <- c(path, current)
    current <- came_from[[current]]
  }
  path <- c(path, start)
  path <- rev(path)
  return(path)
}

main <- function() {
  nodes <- c('A', 'B', 'C', 'D', 'E')
  graph <- Graph$new(nodes)
  graph$add_edge('A', 'B', 1)
  graph$add_edge('B', 'C', 2)
  graph$add_edge('C', 'D', 1)
  graph$add_edge('D', 'E', 3)
  graph$add_edge('A', 'E', 10)
  
  start <- 'A'
  end <- 'E'
  
  result <- dijkstra(graph, start, end)
  came_from <- result[[1]]
  cost_so_far <- result[[2]]
  
  path <- reconstruct_path(came_from, start, end)
  cat(sprintf("Shortest path from %s to %s: %s\n", start, end, paste(path, collapse = " -> ")))
  cat(sprintf("Cost of the path: %s\n", cost_so_far[[end]]))
}

main()