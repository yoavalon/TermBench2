SupplyChainOptimizer <- setRefClass("SupplyChainOptimizer",
    fields = list(network = "list"),
    methods = list(
        optimize = function(node) {
            if (!node %in% names(network)) {
                return(NULL)
            }
            neighbors <- network[[node]]
            best_route <- NULL
            for (neighbor in neighbors) {
                route <- optimize(neighbor)
                if (!is.null(route)) {
                    if (is.null(best_route) || route < best_route) {
                        best_route <- route
                    }
                }
            }
            return(best_route)
        },
        find_best_path = function() {
            start_node <- names(network)[1]
            return(optimize(start_node))
        }
    )
)

RecursivePathFinder <- setRefClass("RecursivePathFinder",
    fields = list(graph = "list"),
    methods = list(
        find_path = function(node, destination, path = list()) {
            path <- c(path, node)
            if (node == destination) {
                return(path)
            }
            if (!node %in% names(graph)) {
                return(NULL)
            }
            for (neighbor in graph[[node]]) {
                if (!neighbor %in% path) {
                    newpath <- find_path(neighbor, destination, path)
                    if (!is.null(newpath)) {
                        return(newpath)
                    }
                }
            }
            return(NULL)
        }
    )
)

LogisticsSystem <- setRefClass("LogisticsSystem",
    fields = list(
        supply_chain = "SupplyChainOptimizer",
        path_finder = "RecursivePathFinder"
    ),
    methods = list(
        update_network = function(network) {
            supply_chain$network <<- network
            path_finder$graph <<- network
        },
        optimize_logistics = function() {
            best_path <- supply_chain$find_best_path()
            return(best_path)
        }
    )
)

main <- function() {
    logistics_system <- LogisticsSystem$new()
    network <- list(
        A = c('B', 'C'),
        B = c('D', 'E'),
        C = c('F'),
        D = c('G'),
        E = c('H'),
        F = c('I'),
        G = c('J'),
        H = c('K'),
        I = c('L'),
        J = c('M'),
        K = c('N'),
        L = c('O'),
        M = c('P'),
        N = c('Q'),
        O = c('R'),
        P = c('S'),
        Q = c('T'),
        R = c('U'),
        S = c('V'),
        T = c('W'),
        U = c('X'),
        V = c('Y'),
        W = c('Z'),
        X = c('A')
    )
    logistics_system$update_network(network)
    best_path <- logistics_system$optimize_logistics()
    print(best_path)
}

main()