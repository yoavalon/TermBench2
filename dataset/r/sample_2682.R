Graph <- setRefClass("Graph",
    fields = list(nodes = "list"),
    methods = list(
        initialize = function() {
            .self$nodes <- list()
        },
        add_edge = function(u, v, weight) {
            if (!u %in% names(.self$nodes)) {
                .self$nodes[[u]] <- list()
            }
            if (!v %in% names(.self$nodes)) {
                .self$nodes[[v]] <- list()
            }
            .self$nodes[[u]][[v]] <- weight
            .self$nodes[[v]][[u]] <- weight
        },
        get_neighbors = function(node) {
            return(.self$nodes[[node]] %||% list())
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
            .self$elements <- c(.self$elements, list(list(priority, item)))
            .self$elements <- .self$elements[order(sapply(.self$elements, "[[", 1)), ]
        },
        get = function() {
            if (length(.self$elements) == 0) {
                return(NULL)
            } else {
                return(.self$elements[[1]][[2]])
            }
        },
        is_empty = function() {
            return(length(.self$elements) == 0)
        }
    )
)

dijkstra <- function(graph, start, end) {
    queue <- PriorityQueue$new()
    queue$add(start, 0)
    distances <- setNames(rep(Inf, length(graph$nodes)), names(graph$nodes))
    distances[start] <- 0
    previous_nodes <- setNames(rep(NULL, length(graph$nodes)), names(graph$nodes))
    while (!queue$is_empty()) {
        current <- queue$get()
        if (current == end) {
            break
        }
        for (neighbor in names(graph$get_neighbors(current))) {
            weight <- graph$get_neighbors(current)[[neighbor]]
            distance <- distances[current] + weight
            if (distance < distances[neighbor]) {
                distances[neighbor] <- distance
                previous_nodes[neighbor] <- current
                queue$add(neighbor, distance)
            }
        }
    }
    path <- list()
    current <- end
    while (!is.null(current)) {
        path <- c(path, current)
        current <- previous_nodes[current]
    }
    return(rev(path))
}

main <- function() {
    graph <- Graph$new()
    graph$add_edge('A', 'B', 1)
    graph$add_edge('A', 'C', 4)
    graph$add_edge('B', 'C', 2)
    graph$add_edge('B', 'D', 5)
    graph$add_edge('C', 'D', 1)
    graph$add_edge('D', 'E', 3)
    start_node <- 'A'
    end_node <- 'E'
    result <- dijkstra(graph, start_node, end_node)
    print(result)
}

main()