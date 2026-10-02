import Foundation

func optimizeRoute(routes: [String: [String: Int]], start: String, end: String, visited: inout Set<String>, path: inout [String]) -> [String]? {
    if visited.contains(start) {
        return nil
    }
    visited.insert(start)
    path.append(start)
    if start == end {
        return path
    }
    for (neighbor, _) in routes[start] ?? [:] {
        if !visited.contains(neighbor) {
            var newPath = path
            if let result = optimizeRoute(routes: routes, start: neighbor, end: end, visited: &visited, path: &newPath) {
                return result
            }
        }
    }
    return nil
}

func main() {
    var routes = ["A": ["B": 10, "C": 15], "B": ["C": 35, "D": 25], "C": ["D": 30], "D": [:]]
    let start = "A"
    let end = "D"
    var visited = Set<String>()
    var path = [String]()
    if let optimalPath = optimizeRoute(routes: routes, start: start, end: end, visited: &visited, path: &path) {
        print(optimalPath)
    }
}

main()