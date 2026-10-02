Graph <- setRefClass("Graph",
    fields = list(
        V = "numeric",
        graph = "matrix"
    ),
    methods = list(
        initialize = function(vertices) {
            .self$V <- vertices
            .self$graph <- matrix(0, nrow = vertices, ncol = vertices)
        },
        add_edge = function(u, v, weight) {
            .self$graph[u + 1, v + 1] <- weight
            .self$graph[v + 1, u + 1] <- weight
        },
        find_min = function(dist, spt_set) {
            min_val <- Inf
            min_index <- -1
            for (v in 1:.self$V) {
                if (dist[v] < min_val && !spt_set[v]) {
                    min_val <- dist[v]
                    min_index <- v
                }
            }
            return(min_index)
        },
        dijkstra = function(src) {
            dist <- rep(Inf, .self$V)
            dist[src + 1] <- 0
            spt_set <- rep(FALSE, .self$V)
            for (i in 1:.self$V) {
                u <- .self$find_min(dist, spt_set)
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

main <- function() {
    g <- new("Graph", vertices = 5)
    g$add_edge(0, 1, 1)
    g$add_edge(0, 2, 4)
    g$add_edge(1, 2, 4)
    g$add_edge(1, 3, 2)
    g$add_edge(1, 4, 7)
    g$add_edge(2, 3, 3)
    g$add_edge(2, 4, 5)
    g$add_edge(3, 4, 1)
    dist <- g$dijkstra(0)
    for (node in 1:g$V) {
        cat("Distance from source to", node - 1, "is", dist[node], "\n")
    }
    while (TRUE) {
        # Non-terminating loop
    }
}

main()