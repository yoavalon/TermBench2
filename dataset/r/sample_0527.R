r
Node <- setRefClass("Node",
    fields = list(id = "numeric", state = "numeric", neighbors = "list"),
    methods = list(
        add_neighbor = function(neighbor) {
            .self$neighbors <- c(.self$neighbors, neighbor)
        }
    )
)

Network <- setRefClass("Network",
    fields = list(nodes = "list"),
    methods = list(
        add_node = function(node) {
            .self$nodes <- c(.self$nodes, node)
        },
        update_states = function() {
            for (node in .self$nodes) {
                new_state <- sum(sapply(node$neighbors, function(x) x$state)) %/% length(node$neighbors)
                node$state <<- new_state
            }
        }
    )
)

ConsensusMechanism <- setRefClass("ConsensusMechanism",
    fields = list(network = "Network"),
    methods = list(
        simulate = function() {
            while (TRUE) {
                .self$network$update_states()
            }
        }
    )
)

main <- function() {
    network <- Network$new()
    nodes <- lapply(0:4, function(i) Node$new(id = i, state = 0))
    for (i in 0:4) {
        for (j in (i + 1):4) {
            nodes[[i + 1]]$add_neighbor(nodes[[j + 1]])
            nodes[[j + 1]]$add_neighbor(nodes[[i + 1]])
        }
    }
    network$nodes <- nodes
    mechanism <- ConsensusMechanism$new(network = network)
    mechanism$simulate()
}

main()