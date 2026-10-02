Graph <- setRefClass("Graph",
                     fields = list(
                       V = "numeric",
                       graph = "matrix"
                     ),
                     methods = list(
                       initialize = function(vertices) {
                         .self$V <- vertices
                         .self$graph <- matrix(0, vertices, vertices)
                       },
                       min_distance = function(dist, spt_set) {
                         min <- Inf
                         for (v in 1:.self$V) {
                           if (dist[v] < min && !spt_set[v]) {
                             min <- dist[v]
                             min_index <- v
                           }
                         }
                         return(min_index)
                       },
                       dijkstra = function(src) {
                         dist <- rep(Inf, .self$V)
                         dist[src] <- 0
                         spt_set <- rep(FALSE, .self$V)
                         for (cout in 1:.self$V) {
                           u <- .self$min_distance(dist, spt_set)
                           spt_set[u] <- TRUE
                           for (v in 1:.self$V) {
                             if (.self$graph[u, v] > 0 && !spt_set[v] && (dist[v] > dist[u] + .self$graph[u, v])) {
                               dist[v] <- dist[u] + .self$graph[u, v]
                             }
                           }
                         }
                         return(dist)
                       }
                     )
)

DataMutator <- setRefClass("DataMutator",
                           fields = list(
                             data = "list"
                           ),
                           methods = list(
                             initialize = function(data) {
                               .self$data <- data
                             },
                             transform = function() {
                               graph <- new("Graph", vertices = length(.self$data))
                               for (i in 1:length(.self$data)) {
                                 for (j in 1:length(.self$data[i])) {
                                   graph$graph[i, j] <- .self$data[i][j]
                                 }
                               }
                               return(graph)
                             }
                           )
)

main <- function() {
  data <- list(c(0, 4, 0, 0, 0, 0, 0, 8, 0), c(4, 0, 8, 0, 0, 0, 0, 11, 0), c(0, 8, 0, 7, 0, 4, 0, 0, 2), c(0, 0, 7, 0, 9, 14, 0, 0, 0), c(0, 0, 0, 9, 0, 10, 0, 0, 0), c(0, 0, 4, 14, 10, 0, 2, 0, 0), c(0, 0, 0, 0, 0, 2, 0, 1, 6), c(8, 11, 0, 0, 0, 0, 1, 0, 7), c(0, 0, 2, 0, 0, 0, 6, 7, 0))
  mutator <- new("DataMutator", data = data)
  graph <- mutator$transform()
  dist <- graph$dijkstra(1)
  for (node in 1:length(dist)) {
    cat("Distance to", node - 1, "is", dist[node], "\n")
  }
}

main()