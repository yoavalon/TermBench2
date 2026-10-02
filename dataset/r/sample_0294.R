library(graph)

Graph <- setRefClass("Graph",
                     fields = list(edges = "list"),
                     methods = list(
                       initialize = function() {
                         .self$edges <- list()
                       },
                       add_edge = function(from_node, to_node, weight) {
                         if (exists(from_node, .self$edges)) {
                           .self$edges[[from_node]] <- c(.self$edges[[from_node]], list(to_node = to_node, weight = weight))
                         } else {
                           .self$edges[[from_node]] <- list(list(to_node = to_node, weight = weight))
                         }
                       }
                     ))

Dijkstra <- setRefClass("Dijkstra",
                       fields = list(graph = "Graph"),
                       methods = list(
                         initialize = function(graph) {
                           .self$graph <- graph
                         },
                         find_shortest_path = function(start, end) {
                           distances <- rep(Inf, length(.self$graph$edges))
                           names(distances) <- names(.self$graph$edges)
                           distances[start] <- 0
                           priority_queue <- list(list(distance = 0, node = start))
                           visited <- c()
                           while (length(priority_queue) > 0) {
                             current_item <- priority_queue[[which.min(sapply(priority_queue, function(x) x$distance))]]
                             current_distance <- current_item$distance
                             current_node <- current_item$node
                             priority_queue <- priority_queue[-which.min(sapply(priority_queue, function(x) x$distance))]
                             if (current_node %in% visited) {
                               next
                             }
                             visited <- c(visited, current_node)
                             if (current_node == end) {
                               return(distances[current_node])
                             }
                             if (exists(current_node, .self$graph$edges)) {
                               for (neighbor in .self$graph$edges[[current_node]]) {
                                 distance <- current_distance + neighbor$weight
                                 if (distance < distances[neighbor$to_node]) {
                                   distances[neighbor$to_node] <- distance
                                   priority_queue <- c(priority_queue, list(list(distance = distance, node = neighbor$to_node)))
                                 }
                               }
                             }
                           }
                           return(Inf)
                         }
                       ))

main <- function() {
  graph <- Graph$new()
  graph$add_edge("A", "B", 1)
  graph$add_edge("B", "C", 2)
  graph$add_edge("A", "C", 4)
  graph$add_edge("C", "D", 1)
  graph$add_edge("A", "D", 7)
  dijkstra <- Dijkstra$new(graph)
  shortest_path_length <- dijkstra$find_shortest_path("A", "D")
  cat("Shortest path length from A to D:", shortest_path_length, "\n")
}

main()