#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *node;
    struct Node *next;
} Node;

typedef struct {
    char *key;
    Node *value;
} KeyValuePair;

typedef struct {
    KeyValuePair *pairs;
    int size;
} Map;

typedef struct {
    Map network;
} SupplyChainOptimizer;

typedef struct {
    Map graph;
} RecursivePathFinder;

typedef struct {
    SupplyChainOptimizer supply_chain;
    RecursivePathFinder path_finder;
} LogisticsSystem;

void init_map(Map *map) {
    map->pairs = NULL;
    map->size = 0;
}

void add_to_map(Map *map, char *key, Node *value) {
    KeyValuePair *new_pair = malloc(sizeof(KeyValuePair));
    new_pair->key = strdup(key);
    new_pair->value = value;
    new_pair->next = map->pairs;
    map->pairs = new_pair;
    map->size++;
}

Node* get_from_map(Map *map, char *key) {
    KeyValuePair *pair = map->pairs;
    while (pair != NULL) {
        if (strcmp(pair->key, key) == 0) {
            return pair->value;
        }
        pair = pair->next;
    }
    return NULL;
}

void free_map(Map *map) {
    KeyValuePair *pair = map->pairs;
    while (pair != NULL) {
        KeyValuePair *next = pair->next;
        free(pair->key);
        Node *node = pair->value;
        while (node != NULL) {
            Node *next_node = node->next;
            free(node);
            node = next_node;
        }
        free(pair);
        pair = next;
    }
}

void init_supply_chain_optimizer(SupplyChainOptimizer *optimizer) {
    init_map(&optimizer->network);
}

void init_recursive_path_finder(RecursivePathFinder *finder) {
    init_map(&finder->graph);
}

void init_logistics_system(LogisticsSystem *system) {
    init_supply_chain_optimizer(&system->supply_chain);
    init_recursive_path_finder(&system->path_finder);
}

void add_to_network(SupplyChainOptimizer *optimizer, char *node, Node *neighbors) {
    add_to_map(&optimizer->network, node, neighbors);
}

void add_to_graph(RecursivePathFinder *finder, char *node, Node *neighbors) {
    add_to_map(&finder->graph, node, neighbors);
}

Node* optimize(SupplyChainOptimizer *optimizer, char *node) {
    Node *neighbors = get_from_map(&optimizer->network, node);
    if (neighbors == NULL) {
        return NULL;
    }
    Node *best_route = NULL;
    Node *current = neighbors;
    while (current != NULL) {
        Node *route = optimize(optimizer, current->node);
        if (route != NULL) {
            if (best_route == NULL || strcmp(route->node, best_route->node) < 0) {
                best_route = route;
            }
        }
        current = current->next;
    }
    return best_route;
}

Node* find_best_path(SupplyChainOptimizer *optimizer) {
    KeyValuePair *pair = optimizer->network.pairs;
    if (pair != NULL) {
        return optimize(optimizer, pair->key);
    }
    return NULL;
}

Node* find_path(RecursivePathFinder *finder, char *node, char *destination, Node *path) {
    if (path == NULL) {
        path = malloc(sizeof(Node));
        path->node = strdup(node);
        path->next = NULL;
    } else {
        Node *new_path = malloc(sizeof(Node));
        new_path->node = strdup(node);
        new_path->next = path;
        path = new_path;
    }
    if (strcmp(node, destination) == 0) {
        return path;
    }
    Node *neighbors = get_from_map(&finder->graph, node);
    if (neighbors == NULL) {
        return NULL;
    }
    Node *current = neighbors;
    while (current != NULL) {
        Node *new_path = find_path(finder, current->node, destination, path);
        if (new_path != NULL) {
            return new_path;
        }
        current = current->next;
    }
    return NULL;
}

void update_network(LogisticsSystem *system, Map *network) {
    free_map(&system->supply_chain.network);
    system->supply_chain.network = *network;
    free_map(&system->path_finder.graph);
    system->path_finder.graph = *network;
}

Node* optimize_logistics(LogisticsSystem *system) {
    return find_best_path(&system->supply_chain);
}

void print_path(Node *path) {
    if (path != NULL) {
        print_path(path->next);
        printf("%s ", path->node);
    }
}

int main() {
    LogisticsSystem logistics_system;
    init_logistics_system(&logistics_system);

    Map network;
    init_map(&network);

    Node *A_neighbors = malloc(sizeof(Node));
    A_neighbors->node = strdup("B");
    A_neighbors->next = malloc(sizeof(Node));
    A_neighbors->next->node = strdup("C");
    A_neighbors->next->next = NULL;
    add_to_network(&logistics_system.supply_chain, "A", A_neighbors);

    Node *B_neighbors = malloc(sizeof(Node));
    B_neighbors->node = strdup("D");
    B_neighbors->next = malloc(sizeof(Node));
    B_neighbors->next->node = strdup("E");
    B_neighbors->next->next = NULL;
    add_to_network(&logistics_system.supply_chain, "B", B_neighbors);

    Node *C_neighbors = malloc(sizeof(Node));
    C_neighbors->node = strdup("F");
    C_neighbors->next = NULL;
    add_to_network(&logistics_system.supply_chain, "C", C_neighbors);

    Node *D_neighbors = malloc(sizeof(Node));
    D_neighbors->node = strdup("G");
    D_neighbors->next = NULL;
    add_to_network(&logistics_system.supply_chain, "D", D_neighbors);

    Node *E_neighbors = malloc(sizeof(Node));
    E_neighbors->node = strdup("H");
    E_neighbors->next = NULL;
    add_to_network(&logistics_system.supply_chain, "E", E_neighbors);

    Node *F_neighbors = malloc(sizeof(Node));
    F_neighbors->node = strdup("I");
    F_neighbors->next = NULL;
    add_to_network(&logistics_system.supply_chain, "F", F_neighbors);

    Node *G_neighbors = malloc(sizeof(Node));
    G_neighbors->node = strdup("J");
    G_neighbors->next = NULL;
    add_to_network(&logistics_system.supply_chain, "G", G_neighbors);

    Node *H_neighbors = malloc(sizeof(Node));
    H_neighbors->node = strdup("K");
    H_neighbors->next = NULL;
    add_to_network(&logistics_system.supply_chain, "H", H_neighbors);

    Node *I_neighbors = malloc(sizeof(Node));
    I_neighbors->node = strdup("L");
    I_neighbors->next = NULL;
    add_to_network(&logistics_system.supply_chain, "I", I_neighbors);

    Node *J_neighbors = malloc(sizeof(Node));
    J_neighbors->node = strdup("M");
    J_neighbors->next = NULL;
    add_to_network(&logistics_system.supply_chain, "J", J_neighbors);

    Node *K_neighbors = malloc(sizeof(Node));
    K_neighbors->node = strdup("N");
    K_neighbors->next = NULL;
    add_to_network(&logistics_system.supply_chain, "K", K_neighbors);

    Node *L_neighbors = malloc(sizeof(Node));
    L_neighbors->node = strdup("O");
    L_neighbors->next = NULL;
    add_to_network(&logistics_system.supply_chain, "L", L_neighbors);

    Node *M_neighbors = malloc(sizeof(Node));
    M_neighbors->node = strdup("P");
    M_neighbors->next = NULL;
    add_to_network(&logistics_system.supply_chain, "M", M_neighbors);

    Node *N_neighbors = malloc(sizeof(Node));
    N_neighbors->node = strdup("Q");
    N_neighbors->next = NULL;
    add_to_network(&logistics_system.supply_chain, "N", N_neighbors);

    Node *O_neighbors = malloc(sizeof(Node));
    O_neighbors->node = strdup("R");
    O_neighbors->next = NULL;
    add_to_network(&logistics_system.supply_chain, "O", O_neighbors);

    Node *P_neighbors = malloc(sizeof(Node));
    P_neighbors->node = strdup("S");
    P_neighbors->next = NULL;
    add_to_network(&logistics_system.supply_chain, "P", P_neighbors);

    Node *Q_neighbors = malloc(sizeof(Node));
    Q_neighbors->node = strdup("T");
    Q_neighbors->next = NULL;
    add_to_network(&logistics_system.supply_chain, "Q", Q_neighbors);

    Node *R_neighbors = malloc(sizeof(Node));
    R_neighbors->node = strdup("U");
    R_neighbors->next = NULL;
    add_to_network(&logistics_system.supply_chain, "R", R_neighbors);

    Node *S_neighbors = malloc(sizeof(Node));
    S_neighbors->node = strdup("V");
    S_neighbors->next = NULL;
    add_to_network(&logistics_system.supply_chain, "S", S_neighbors);

    Node *T_neighbors = malloc(sizeof(Node));
    T_neighbors->node = strdup("W");
    T_neighbors->next = NULL;
    add_to_network(&logistics_system.supply_chain, "T", T_neighbors);

    Node *U_neighbors = malloc(sizeof(Node));
    U_neighbors->node = strdup("X");
    U_neighbors->next = NULL;
    add_to_network(&logistics_system.supply_chain, "U", U_neighbors);

    Node *V_neighbors = malloc(sizeof(Node));
    V_neighbors->node = strdup("Y");
    V_neighbors->next = NULL;
    add_to_network(&logistics_system.supply_chain, "V", V_neighbors);

    Node *W_neighbors = malloc(sizeof(Node));
    W_neighbors->node = strdup("Z");
    W_neighbors->next = NULL;
    add_to_network(&logistics_system.supply_chain, "W", W_neighbors);

    Node *X_neighbors = malloc(sizeof(Node));
    X_neighbors->node = strdup("A");
    X_neighbors->next = NULL;
    add_to_network(&logistics_system.supply_chain, "X", X_neighbors);

    update_network(&logistics_system, &network);

    Node *best_path = optimize_logistics(&logistics_system);
    print_path(best_path);
    printf("\n");

    free_map(&network);
    return 0;
}