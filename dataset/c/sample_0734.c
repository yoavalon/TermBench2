#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROUTES 10
#define MAX_NEIGHBORS 10

typedef struct {
    char city;
    int distance;
} Neighbor;

typedef struct {
    char city;
    Neighbor neighbors[MAX_NEIGHBORS];
    int neighbor_count;
} Route;

typedef struct {
    char cities[MAX_ROUTES];
    int count;
} Path;

typedef struct {
    Route routes[MAX_ROUTES];
    int count;
} Routes;

void add_neighbor(Route *route, char city, int distance) {
    Neighbor neighbor = {city, distance};
    route->neighbors[route->neighbor_count++] = neighbor;
}

void add_route(Routes *routes, char city) {
    Route route = {city, {{0}, 0}};
    routes->routes[routes->count++] = route;
}

int is_visited(char *visited, char city, int visited_count) {
    for (int i = 0; i < visited_count; i++) {
        if (visited[i] == city) {
            return 1;
        }
    }
    return 0;
}

void copy_path(Path *dest, Path *src) {
    dest->count = src->count;
    for (int i = 0; i < src->count; i++) {
        dest->cities[i] = src->cities[i];
    }
}

Path* optimize_route(Routes *routes, char start, char end, char *visited, int visited_count, Path *path) {
    visited[visited_count++] = start;
    path->cities[path->count++] = start;
    if (start == end) {
        return path;
    }
    for (int i = 0; i < routes->count; i++) {
        if (routes->routes[i].city == start) {
            for (int j = 0; j < routes->routes[i].neighbor_count; j++) {
                if (!is_visited(visited, routes->routes[i].neighbors[j].city, visited_count)) {
                    Path temp_path = *path;
                    Path *result = optimize_route(routes, routes->routes[i].neighbors[j].city, end, visited, visited_count, &temp_path);
                    if (result) {
                        return result;
                    }
                }
            }
        }
    }
    return NULL;
}

void main() {
    Routes routes = {{{0}, 0}};
    add_route(&routes, 'A');
    add_route(&routes, 'B');
    add_route(&routes, 'C');
    add_route(&routes, 'D');
    add_neighbor(&routes.routes[0], 'B', 10);
    add_neighbor(&routes.routes[0], 'C', 15);
    add_neighbor(&routes.routes[1], 'C', 35);
    add_neighbor(&routes.routes[1], 'D', 25);
    add_neighbor(&routes.routes[2], 'D', 30);

    char start = 'A';
    char end = 'D';
    char visited[MAX_ROUTES] = {0};
    Path path = {{0}, 0};
    Path *optimal_path = optimize_route(&routes, start, end, visited, 0, &path);

    if (optimal_path) {
        for (int i = 0; i < optimal_path->count; i++) {
            printf("%c ", optimal_path->cities[i]);
        }
    } else {
        printf("No path found\n");
    }
}