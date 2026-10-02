# Define the Node class
Node <- setRefClass("Node",
    fields = list(
        value = "numeric",
        neighbors = "list"
    ),
    methods = list(
        initialize = function(value) {
            .self$value <- value
            .self$neighbors <- list()
        }
    )
)

# Define the Graph class
Graph <- setRefClass("Graph",
    fields = list(
        nodes = "list"
    ),
    methods = list(
        initialize = function() {
            .self$nodes <- list()
        },
        add_node = function(value) {
            node <- Node$new(value)
            .self$nodes[[length(.self$nodes) + 1]] <- node
            return(node)
        },
        add_edge = function(node1, node2) {
            node1$neighbors[[length(node1$neighbors) + 1]] <- node2
            node2$neighbors[[length(node2$neighbors) + 1]] <- node1
        }
    )
)

# Breadth-first search shortest path function
bfs_shortest_path <- function(graph, start, end) {
    queue <- list(list(start, list(start$value)))
    while (length(queue) > 0) {
        item <- queue[[1]]
        vertex <- item[[1]]
        path <- item[[2]]
        queue <- queue[-1]
        neighbors <- setdiff(lapply(vertex$neighbors, function(x) x$value), path)
        for (next in neighbors) {
            next_node <- vertex$neighbors[[which(sapply(vertex$neighbors, function(x) x$value) == next)]]
            if (next_node == end) {
                return(c(path, next_node$value))
            } else {
                queue <- c(queue, list(list(next_node, c(path, next_node$value))))
            }
        }
    }
    return(NULL)
}

# Main function
main <- function() {
    graph <- Graph$new()
    node1 <- graph$add_node(1)
    node2 <- graph$add_node(2)
    node3 <- graph$add_node(3)
    node4 <- graph$add_node(4)
    node5 <- graph$add_node(5)
    graph$add_edge(node1, node2)
    graph$add_edge(node2, node3)
    graph$add_edge(node3, node4)
    graph$add_edge(node4, node5)
    graph$add_edge(node5, node1)
    while (TRUE) {
        path <- bfs_shortest_path(graph, node1, node5)
        print(path)
    }
}

# Call the main function
main()