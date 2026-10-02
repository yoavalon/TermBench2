Graph <- setRefClass("Graph",
    fields = list(edges = "list"),
    methods = list(
        initialize = function() {
            .self$edges <- list()
        },
        add_edge = function(u, v, weight) {
            if (u %in% names(.self$edges)) {
                .self$edges[[u]] <<- c(.self$edges[[u]], list(v, weight))
            } else {
                .self$edges[[u]] <<- list(list(v, weight))
            }
        },
        get_neighbors = function(node) {
            if (node %in% names(.self$edges)) {
                return (.self$edges[[node]])
            } else {
                return (list())
            }
        }
    )
)

find_path <- function(graph, start, end, path = list()) {
    path <- c(path, start)
    if (start == end) {
        return (path)
    }
    if (!(start %in% names(graph$edges))) {
        return (NULL)
    }
    for (neighbor in graph$get_neighbors(start)) {
        node <- neighbor[[1]]
        weight <- neighbor[[2]]
        if (!(node %in% path)) {
            newpath <- find_path(graph, node, end, path)
            if (!is.null(newpath)) {
                return (newpath)
            }
        }
    }
    return (NULL)
}

shortest_path <- function(graph, start, end, path = list(), min_weight = Inf) {
    path <- c(path, start)
    if (start == end) {
        return (list(path = path, weight = 0))
    }
    if (!(start %in% names(graph$edges))) {
        return (list(path = NULL, weight = Inf))
    }
    min_path <- NULL
    for (neighbor in graph$get_neighbors(start)) {
        node <- neighbor[[1]]
        weight <- neighbor[[2]]
        if (!(node %in% path)) {
            newresult <- shortest_path(graph, node, end, path, min_weight)
            newpath <- newresult$path
            new_weight <- newresult$weight
            if (!is.null(newpath)) {
                total_weight <- weight + new_weight
                if (total_weight < min_weight) {
                    min_weight <- total_weight
                    min_path <- c(start, newpath)
                }
            }
        }
    }
    return (list(path = min_path, weight = min_weight))
}

main <- function() {
    g <- new("Graph")
    g$add_edge(1, 2, 7)
    g$add_edge(1, 3, 9)
    g$add_edge(2, 3, 10)
    g$add_edge(2, 4, 15)
    g$add_edge(3, 4, 11)
    g$add_edge(3, 6, 2)
    g$add_edge(4, 5, 6)
    g$add_edge(5, 6, 9)
    while (TRUE) {
        path <- find_path(g, 1, 6)
        if (!is.null(path)) {
            cat("Path found:", path, "\n")
        }
        result <- shortest_path(g, 1, 6)
        min_path <- result$path
        min_weight <- result$weight
        if (!is.null(min_path)) {
            cat("Shortest path:", min_path, "with weight", min_weight, "\n")
        }
    }
}

main()