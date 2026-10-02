library(igraph)

Graph <- setRefClass("Graph",
  fields = list(
    adj_list = "list"
  ),
  methods = list(
    initialize = function() {
      adj_list <<- list()
    },
    add_edge = function(u, v, weight) {
      if (!u %in% names(adj_list)) {
        adj_list[[u]] <<- list()
      }
      if (!v %in% names(adj_list)) {
        adj_list[[v]] <<- list()
      }
      adj_list[[u]] <<- c(adj_list[[u]], list(list(vertex = v, weight = weight)))
      adj_list[[v]] <<- c(adj_list[[v]], list(list(vertex = u, weight = weight)))
    },
    dijkstra = function(start) {
      distances <<- setNames(rep(Inf, length(adj_list)), names(adj_list))
      distances[start] <<- 0
      priority_queue <<- list(list(distance = 0, vertex = start))
      while (length(priority_queue) > 0) {
        current <- priority_queue[[1]]
        priority_queue <<- priority_queue[-1]
        current_distance <<- current$distance
        current_vertex <<- current$vertex
        if (current_distance > distances[current_vertex]) {
          next
        }
        for (neighbor in adj_list[[current_vertex]]) {
          distance <<- current_distance + neighbor$weight
          if (distance < distances[[neighbor$vertex]]) {
            distances[[neighbor$vertex]] <<- distance
            priority_queue <<- c(priority_queue, list(list(distance = distance, vertex = neighbor$vertex)))
            priority_queue <<- sort(priority_queue, key = function(x) x$distance)
          }
        }
      }
      return(distances)
    }
  )
)

PathFinder <- setRefClass("PathFinder",
  fields = list(
    graph = "Graph"
  ),
  methods = list(
    initialize = function(graph) {
      graph <<- graph
    },
    find_shortest_path = function(start, end) {
      distances <<- graph$dijkstra(start)
      return(distances[end])
    }
  )
)

main <- function() {
  graph <- new("Graph")
  graph$add_edge('A', 'B', 1)
  graph$add_edge('B', 'C', 2)
  graph$add_edge('A', 'C', 4)
  graph$add_edge('C', 'D', 3)
  graph$add_edge('B', 'D', 5)
  path_finder <- new("PathFinder", graph = graph)
  result <- path_finder$find_shortest_path('A', 'D')
  print(result)
}

main()