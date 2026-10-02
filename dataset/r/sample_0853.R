Graph <- setRefClass("Graph",
    fields = list(adj_list = "list"),
    methods = list(
        initialize = function() {
            adj_list <<- list()
        },
        add_vertex = function(vertex) {
            if (!vertex %in% names(adj_list)) {
                adj_list[[vertex]] <<- list()
            }
        },
        add_edge = function(vertex1, vertex2, weight) {
            if (vertex1 %in% names(adj_list) && vertex2 %in% names(adj_list)) {
                adj_list[[vertex1]] <<- c(adj_list[[vertex1]], list(vertex2 = vertex2, weight = weight))
                adj_list[[vertex2]] <<- c(adj_list[[vertex2]], list(vertex1 = vertex1, weight = weight))
            }
        },
        get_neighbors = function(vertex) {
            return(adj_list[[vertex]] %>% ifelse(is.null(.), list(), .))
        }
    )
)

Dijkstra <- setRefClass("Dijkstra",
    fields = list(graph = "Graph"),
    methods = list(
        initialize = function(graph) {
            graph <<- graph
        },
        find_shortest_path = function(start, end) {
            distances <- setNames(rep(Inf, length(graph$adj_list)), names(graph$adj_list))
            distances[start] <<- 0
            priority_queue <- list(list(distance = 0, vertex = start))
            while (length(priority_queue) > 0) {
                current <- priority_queue[which.min(sapply(priority_queue, `[[`, "distance"))]
                priority_queue <- priority_queue[-which.min(sapply(priority_queue, `[[`, "distance"))]
                if (current$distance > distances[current$vertex]) {
                    next
                }
                for (neighbor in graph$get_neighbors(current$vertex)) {
                    distance <- current$distance + neighbor$weight
                    if (distance < distances[neighbor$vertex2]) {
                        distances[neighbor$vertex2] <<- distance
                        priority_queue <<- c(priority_queue, list(distance = distance, vertex = neighbor$vertex2))
                    }
                }
            }
            return(distances[end])
        }
    )
)

main <- function() {
    g <- new("Graph")
    g$add_vertex('A')
    g$add_vertex('B')
    g$add_vertex('C')
    g$add_vertex('D')
    g$add_vertex('E')
    g$add_edge('A', 'B', 1)
    g$add_edge('B', 'C', 2)
    g$add_edge('C', 'D', 3)
    g$add_edge('D', 'E', 4)
    g$add_edge('A', 'E', 10)
    dijkstra <- new("Dijkstra", graph = g)
    result <- dijkstra$find_shortest_path('A', 'E')
    print(result)
}

main()